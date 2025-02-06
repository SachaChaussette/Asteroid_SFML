#include "Player.h"
#include "InputManager.h"
#include "TimerManager.h"
#include "Asteroid.h"
#include "UFO.h"
#include "Projectile.h"
#include "Level.h"


Player::Player(const float _radius, const vector<Vector2f>& _point, const string& _path, const TextureExtensionType& _textureType,
	const IntRect& _rect, bool _isRepeated, bool _isSmooth, const string& _name)
	: Entity(3, SMALL, 1, MeshActor(_radius, "Player/" + _path, _textureType, _rect, _isRepeated, _isSmooth, 30U, _name), MeshActor(_point, "Transparent"), "Player")
{
	movement = CreateComponent<PlayerMovementComponent>();
	shoot = CreateComponent<ShootComponent>();
	canons = vector<MeshActor*>();
}
Player::Player(const float _radius, const Vector2f& _size, const string& _path, const TextureExtensionType& _textureType,
	const IntRect& _rect, bool _isRepeated, bool _isSmooth, const string& _name)
	: Entity(3, SMALL, 1, MeshActor(_radius, "Player/" + _path, _textureType, _rect, _isRepeated, _isSmooth, 30U, _name), MeshActor(_size, "Transparent"), "Player")
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

	M_INPUT.BindAction([&]() 
	{
		movement->Rotate(-10);
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
		movement->ComputeAcceleration();
	}, { Code::Up, Code::Z });

	M_INPUT.BindAction([&]() 
	{
		shoot->Shoot();
	}, Code::Space);

	MeshActor* _canon = Level::SpawnActor(MeshActor(Vector2f(200.0f, 200.0f), ""));
	//_canon->SetPosition(GetPosition());
	AddChild(_canon, AT_KEEP_RELATIVE);
	canons.push_back(_canon);

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

void Player::OnCollision(const CollisionData& _data)
{
	Super::OnCollision(_data);
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

void Player::Death()
{
	Super::Death();
	system("pause");
}


