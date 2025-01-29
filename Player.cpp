#include "Player.h"
#include "InputManager.h"
#include "TimerManager.h"

Player::Player(const RectangleShapeData& _data, const string& _name) : MeshActor(_data, _name)
{
	movement = CreateComponent<PlayerMovementComponent>();
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
		//LOG(Display, "Up or Z Pressed");
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
}
