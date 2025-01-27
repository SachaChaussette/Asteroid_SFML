#include "TEST.h"
#include "InputManager.h"

TEST::TEST(const RectangleShapeData& _data, const string& _name) : MeshActor(_data, _name)
{
	movement = CreateComponent<MovementComponent>();
}

TEST::TEST(const TEST& _other) : MeshActor(_other)
{
	movement = CreateComponent<MovementComponent>(_other.movement);
}

void TEST::Construct()
{
	Super::Construct();

	M_INPUT.BindAction([&]() 
	{
		movement->RotateDirection(-3);
		LOG(Display, "Left or Q Pressed"); 
	}, { Code::Left, Code::Q 
	});
	M_INPUT.BindAction([&]() 
	{
		movement->RotateDirection(3);
		LOG(Display, "Right or D Pressed");
	}, { Code::Right, Code::D });
	M_INPUT.BindAction([&]() 
	{
		LOG(Display, "Up or Z Pressed"); 
	}, { Code::Up, Code::Z });
	M_INPUT.BindAction([&]() 
	{
		LOG(Display, "Space Pressed"); 
	}, Code::Space);
}

void TEST::Deconstruct()
{
	Super::Deconstruct();
}
