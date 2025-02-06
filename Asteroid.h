#pragma once
#include "MeshActor.h"
#include "Entity.h"
#include "AnimationComponent.h"
#include "EnemyMovementComponent.h"
#include "SizeType.h"
#include "CollisionComponent.h"



class Asteroid : public Entity
{
	EnemyMovementComponent* movement;

public:
	FORCEINLINE EnemyMovementComponent* GetMovement() const
	{
		return movement;
	}
public:
	Asteroid(const CircleShapeData& _data, const vector<Vector2f>& _point = vector<Vector2f>(), 
		const SizeType& _size = BIG, const string& _name = "Asteroid");
	Asteroid(const Asteroid& _other);

public: 
	void ComputeNewDirection();
	virtual void Construct() override;
	virtual void Tick(const float _deltaTime) override;
	virtual void Deconstruct() override;
	virtual void CollisionEnter(const CollisionData& _data) override;
};

