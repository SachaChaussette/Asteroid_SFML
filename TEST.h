#pragma once

#include "MeshActor.h"
#include "MovementComponent.h"

class TEST : public MeshActor
{
	MovementComponent* movement;


public:
	TEST(const RectangleShapeData& _data, const string& _name = "TEST");
	TEST(const TEST& _other);
public:

	virtual void Construct() override;
	virtual void Deconstruct() override;
	virtual void BeginPlay() override {};
	virtual void Tick(const float _deltaTime) override {};
	virtual void BeginDestroy() override {};
};