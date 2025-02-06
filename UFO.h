#pragma once

#include "AnimationComponent.h"
#include "EnemyMovementComponent.h"
#include "ShootComponent.h"
#include "SizeType.h"
#include "Entity.h"

class UFO : public Entity
{
	EnemyMovementComponent* movement;
	ShootComponent* shoot;

	Timer<Seconds>* shootTimer;
	Timer<Seconds>* directionTimer;

	//Servira pour la CollisionBox !
	vector<Vector2f> convexShapePoints;

public:
	FORCEINLINE EnemyMovementComponent* GetMovement() const
	{
		return movement;
	}
public:
	//point servira à la ConvexShape de la CollisionBox !
	UFO(const CircleShapeData& _data, const vector<Vector2f>& _point = vector<Vector2f>(),
		const SizeType& _size = BIG, const string& _name = "UFO"); 
	UFO(const UFO& _other);

	~UFO();
public:
	void ComputeNewDirection();
	virtual void Construct() override;
	virtual void Tick(const float _deltaTime) override;
	virtual void BeginPlay() override;
	virtual void Deconstruct() override;

	virtual void CollisionEnter(const CollisionData& _data) override;
};


