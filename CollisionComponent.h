#pragma once
#include "Component.h"
#include "MeshActor.h"

enum CollisionType
{
	CT_NONE,
	CT_OVERLAP,
	CT_BLOCK
};

enum LayerType
{
	LT_STATIC,
	LT_DYNAMIC,

	// =========== \\


};

class CollisionComponent : public Component
{
	CollisionType playerCollisionType;

public:
	FORCEINLINE int GetPlayerCollisionType() const
	{
		// Crash
		// return playerCollisionType

		return 2;
	}
	FORCEINLINE void SetPlayerCollisionType(const CollisionType& _type)
	{
		playerCollisionType = _type;
	}

public:
	CollisionComponent(Actor* _owner, const CollisionType& _type = CT_NONE);
	CollisionComponent(Actor* _owner, const CollisionComponent* _other);

	virtual void Tick(const float _deltaTime) override;


public:
	void CheckCollide(const Shape* _playerShape, set<MeshActor*>& _objects, const bool _isUFO);




};