#pragma once

#include "MeshActor.h"
#include "SizeType.h"
#include "AnimationComponent.h"
#include "CollisionComponent.h"
#include "LifeComponent.h"
#include "Layer.h"

class Entity : public MeshActor
{
protected:
	AnimationComponent* animation;

	CollisionComponent* collision;
	LifeComponent* life;

	u_int spriteCount;
	SizeType size;
public:
	FORCEINLINE LifeComponent* GetLife() const
	{
		return life;
	}
	FORCEINLINE CollisionComponent* GetCollision() const
	{
		return collision;
	}
public:
	Entity(const u_int& _lifeCount, const SizeType& _size, const u_int& _spriteCount, const MeshActor& _mesh, 
		const string& _name);
	Entity(const Entity& _other);
protected:
	virtual void Tick(const float _deltaTime) override;
	void ComputeNewPositionIfNotInWindow();
	virtual void Construct() override;
};

