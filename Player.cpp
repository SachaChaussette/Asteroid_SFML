#include "Player.h"
#include "InputManager.h"
#include "TimerManager.h"
#include "Asteroid.h"
#include "UFO.h"
#include "Projectile.h"
#include "Level.h"


Player::Player(const CircleShapeData& _data, const RectangleShapeData& _hitBoxData,
	const SizeType& _size, const string& _name)
	: Entity(3, _size, 1, MeshActor(_data), MeshActor(_hitBoxData), _name)
{
	movement = CreateComponent<PlayerMovementComponent>();
	shoot = CreateComponent<ShootComponent>();
	canons = vector<MeshActor*>();
}
Player::Player(const RectangleShapeData& _data, const vector<Vector2f>& _point,
	const SizeType& _size, const string& _name)
	: Entity(3, _size, 1, MeshActor(_data), MeshActor(_size, "Transparent"), "Player")
{
	movement = CreateComponent<PlayerMovementComponent>();
	shoot = CreateComponent<ShootComponent>();
	canons = vector<MeshActor*>();
}

Player::Player(const Player& _other) : Entity(_other)
{
	movement = CreateComponent<PlayerMovementComponent>(_other.movement);
	shoot = CreateComponent<ShootComponent>(_other.shoot);
	canons = _other.canons;
}

void Player::Construct()
{
	Super::Construct();

	ActionMap* _playerMovement = M_INPUT.CreateActionMap("Player Movement");
	const vector<Action*>& _actions =
	{
		new Action("Forward", ActionData(KeyHold, Input::Z), [&]()
		{
				LOG(Display, "Forward");
			movement->ComputeAcceleration();
		}),
		new Action("Shoot", ActionData(KeyPressed, Input::Space), [&]()
		{
				LOG(Display, "Shoot");
			shoot->Shoot();
		}),
		new Action("Left", ActionData(KeyHold, Input::Q), [&]()
		{
				LOG(Display, "Left");
			movement->Rotate(-10);
		}),
		new Action("Right", ActionData(KeyHold, Input::D), [&]()
		{
				LOG(Display, "Right");
			movement->Rotate(10);
		}),
	};
	_playerMovement->AddActions(_actions);

	// TODO InputManaer
	/*M_INPUT.BindAction([&]()
	{
		SetOriginAtMiddle();
	}, { Code::Left, Code::Q 
	});

	M_INPUT.BindAction([&]() 
	{
		movement->Rotate(10);
		SetOriginAtMiddle();
		}, { Code::Right, Code::D });


	M_INPUT.BindAction([&]() 
	{
	}, { Code::Up, Code::Z });

	M_INPUT.BindAction([&]() 
	{
	}, Code::Space);*/

	// TODO Canon
	//MeshActor* _canon = M_LEVEL.GetCurrentLevel()->SpawnActor(MeshActor(Vector2f(200.0f, 200.0f), ""));
	//_canon->SetPosition(GetPosition());
	//AddChild(_canon, AT_KEEP_RELATIVE);
	//canons.push_back(_canon);

	convexHitBox->AddComponent(new CollisionComponent(convexHitBox, "Player", IS_ALL, CT_OVERLAP));
	convexHitBox->SetLayer(Layer::PLAYER);

	const vector<pair<string, CollisionType>>& _responses
	{
		{"Player", CT_NONE},
		{"Asteroid", CT_OVERLAP},
		{"UFO", CT_OVERLAP},
		{"Projectile", CT_OVERLAP},
	};
	AddCollisionResponses(_responses);
}

void Player::Deconstruct()
{
	Super::Deconstruct();
}

void Player::BeginPlay()
{
	Super::BeginPlay();

	new Timer([&]() 
	{ 
		movement->ApplyFriction(); 
	}, seconds(0.25), true, true);

	

}

void Player::Tick(const float _deltaTime)
{
	Super::Tick(_deltaTime);
}

void Player::CollisionEnter(const CollisionData& _data)
{
	Super::CollisionEnter(_data);
	if (Entity* _entity = Cast<Entity>(_data.other))
	{
		Layer::LayerType _layerType = _entity->GetConvexHitBox()->GetLayer();
		if (_layerType == Layer::ASTEROID)
		{
			Asteroid* _asteroid = Cast<Asteroid>(_entity);
			_asteroid->GetLife()->DecrementLife();
		}
		else if (_layerType == Layer::PROJECTILE)
		{
			Projectile* _projectile = Cast<Projectile>(_entity);
			if (_projectile->GetFriendlyLayer() == Layer::PLAYER) return;
			_projectile->GetLife()->DecrementLife();
		}
		else if (_layerType == Layer::UFO)
		{
			UFO* _ufo = Cast<UFO>(_entity);
			_ufo->GetLife()->DecrementLife();
		}
	}
}

//void Player::Death()
//{
//	Super::Death();
//	system("pause");
//}
//

