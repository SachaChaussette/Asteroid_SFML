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
	LifeComponent* life;

	MeshActor* convexHitBox;

	u_int spriteCount;
	SizeType size;

public:
	FORCEINLINE void AddCollisionResponses(const vector<pair<string, CollisionType>>& _responses)
	{
		if (CollisionComponent* _collision = convexHitBox->GetComponent<CollisionComponent>())
		{
			_collision->AddResponses(_responses);
		}
		else
		{
			LOG(Warning, "Aucun CollisionComponent Trouver");
		}
	}
	FORCEINLINE MeshActor* GetConvexHitBox() const
	{
		return convexHitBox;
	}
	FORCEINLINE LifeComponent* GetLife() const
	{
		return life;
	}
public:
	Entity(const u_int& _lifeCount, const SizeType& _size, const u_int& _spriteCount, const MeshActor& _mesh, 
		const MeshActor& _hitBoxMesh, const string& _name);
	Entity(const Entity& _other);

protected:
	virtual void Tick(const float _deltaTime) override;
	void ComputeNewPositionIfNotInWindow();
	virtual void Construct() override;
	virtual void Deconstruct() override;
	virtual void Death() override;
};

