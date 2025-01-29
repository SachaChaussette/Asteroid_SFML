#pragma once

#include "MeshActor.h"
#include "PlayerMovementComponent.h"

class Player : public MeshActor
{
	PlayerMovementComponent* movement;
	// TODO Shoot Component

public:
	Player(const RectangleShapeData& _data, const string& _name = "TEST");
	Player(const Player& _other);
public:

	virtual void Construct() override;
	virtual void Deconstruct() override;
	virtual void BeginPlay() override;
	virtual void Tick(const float _deltaTime) override;
	virtual void BeginDestroy() override {};
};