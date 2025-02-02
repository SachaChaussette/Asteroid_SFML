#include "Player.h"
#include "InputManager.h"
#include "TimerManager.h"

Player::Player(const Vector2f& _size, const string& _path, const TextureExtensionType& _textureType, 
	const IntRect& _rect, bool _isRepeated, bool _isSmooth, const string& _name) 
	: Entity(3, _size, 1, _path, _textureType, _rect, _isRepeated, _isSmooth, _name)
{
	movement = CreateComponent<PlayerMovementComponent>();
  collision = CreateComponent<CollisionComponent>();
	shoot = CreateComponent<ShootComponent>();
}

Player::Player(const Player& _other) : Entity(_other)
{
	movement = CreateComponent<PlayerMovementComponent>(_other.movement);
collision = CreateComponent<CollisionComponent>(_other.collision);
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
	ComputeNewPositionIfNotInWindow();
}