#include "Player.h"
#include "InputManager.h"
#include "TimerManager.h"

Player::Player(const Vector2f& _size, const string& _path, const TextureExtensionType& _textureType, 
	const IntRect& _rect, bool _isRepeated, bool _isSmooth, const string& _name) 
	: MeshActor(_size, _path, _textureType, _rect, _isRepeated, _isSmooth, _name)
{
	movement = CreateComponent<PlayerMovementComponent>();
	collision = CreateComponent<CollisionComponent>();

}

Player::Player(const Player& _other) : MeshActor(_other)
{
	movement = CreateComponent<PlayerMovementComponent>(_other.movement);
}

void Player::Construct()
{
	Super::Construct();

	M_INPUT.BindAction([&]() 
	{
		movement->Rotate(-10);
	}, { Code::Left, Code::Q 
	});

	M_INPUT.BindAction([&]() 
	{
		movement->Rotate(10);
	}, { Code::Right, Code::D });

	M_INPUT.BindAction([&]() 
	{
		movement->ComputeAcceleration();
	}, { Code::Up, Code::Z });

	M_INPUT.BindAction([&]() 
	{
		LOG(Display, "Space Pressed"); 
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

void Player::ComputeNewPositionIfNotInWindow()
{
	const Vector2f& _windowSize = CAST(Vector2f, M_GAME.GetCurrent()->GetWindowSize());
	const Vector2f& _playerPosition = GetPosition();
	const Vector2f& _playerScale = GetScale();
	const Vector2f& _playerSize = Vector2f(_playerScale.x, _playerScale.y) / 2.0f;
	if ((_playerPosition.x + _playerSize.x) < 0.0f)
	{
		SetPosition({ _windowSize.x + _playerSize.x, _playerPosition.y });
	}
	else if ((_playerPosition.x - _playerSize.x) > _windowSize.x)
	{
		SetPosition({ 0.0f - _playerSize.x, _playerPosition.y });
	}
	if ((_playerPosition.y + _playerSize.y) < 0.0f)
	{
		SetPosition({ _playerPosition.x , _windowSize.y + _playerSize.y });
	}
	else if ((_playerPosition.y - _playerSize.y) > _windowSize.y)
	{
		SetPosition({ _playerPosition.x, 0.0f - _playerSize.y });
	}
}