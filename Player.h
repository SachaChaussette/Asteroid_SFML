#pragma once


#include "Entity.h"
#include "PlayerMovementComponent.h"
#include "ShootComponent.h"


class Player : public Entity
{
	ShootComponent* shoot;
	PlayerMovementComponent* movement;

	u_int dmgLevel;
	vector<MeshActor*> canons;


public:

	Player(Level* _level, const CircleShapeData& _data, const RectangleShapeData& _hitBoxData,
		const SizeType& _size = SMALL, const string& _name = "Player");
	Player(const Player& _other);
public:

	virtual void Construct() override;
	virtual void Deconstruct() override;
	virtual void BeginPlay() override;
	virtual void Tick(const float _deltaTime) override;
	virtual void BeginDestroy() override {};

	virtual void CollisionEnter(const CollisionData& _data) override;

	//virtual void Death() override;

};