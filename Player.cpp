#include "Player.h"
#include "InputManager.h"
#include "TimerManager.h"
#include "Asteroid.h"
#include "UFO.h"
#include "Projectile.h"

Player::Player(const vector<Vector2f>& _point, const string& _path, const TextureExtensionType& _textureType,
	const IntRect& _rect, bool _isRepeated, bool _isSmooth, const string& _name)
	: Entity(3, SMALL, 1, MeshActor(_point, "Player/" + _path, _textureType, _rect, _isRepeated, _isSmooth, _name), "Player")
{
	movement = CreateComponent<PlayerMovementComponent>();
	shoot = CreateComponent<ShootComponent>();
}
Player::Player(const Vector2f& _size, const string& _path, const TextureExtensionType& _textureType,
	const IntRect& _rect, bool _isRepeated, bool _isSmooth, const string& _name)
	: Entity(3, SMALL, 1, MeshActor(_size, "Player/" + _path, _textureType, _rect, _isRepeated, _isSmooth, _name), "Player")
{
	movement = CreateComponent<PlayerMovementComponent>();
	shoot = CreateComponent<ShootComponent>();
}

Player::Player(const Player& _other) : Entity(_other)
{
	movement = CreateComponent<PlayerMovementComponent>(_other.movement);

	shoot = CreateComponent<ShootComponent>(_other.shoot);

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

	SetLayer(Layer::PLAYER);

	const vector<pair<string, CollisionType>>& _responses
	{
		{"Player", CT_NONE},
		{"Asteroid", CT_OVERLAP},
		{"UFO", CT_OVERLAP},
		{"Projectile", CT_OVERLAP},
	};
	collision->AddResponses(_responses);
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

	if (_data.other->GetLayer() == Layer::ASTEROID)
	{
		Asteroid* _asteroid = Cast<Asteroid>(_data.other);
		_asteroid->GetLife()->DecrementLife();
	}
	else if (_data.other->GetLayer() == Layer::PROJECTILE)
	{
		Projectile* _projectile = Cast<Projectile>(_data.other);
		if (_projectile->GetFriendlyLayer() == Layer::PLAYER) return;
		_projectile->GetLife()->DecrementLife();
	}
	else if (_data.other->GetLayer() == Layer::UFO)
	{
		UFO* _ufo = Cast<UFO>(_data.other);
		_ufo->GetLife()->DecrementLife();
	}

}


