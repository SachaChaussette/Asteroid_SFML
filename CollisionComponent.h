#pragma once
#include "Component.h"

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

enum ActorType
{
	AT_PLAYER,
	AT_PROJECTILE,
	AT_ASTEROID,
	AT_UFO,
	AT_COUNT,
};

class CollisionComponent : public Component
{
	LayerType layer;
	CollisionType type;
	ActorType ownerType;

	set<ActorType> blackList; // représente les actors avec qui il y aura une collision
	function<void()> callback;
public:
	FORCEINLINE ActorType GetActorType() const
	{
		return ownerType;
	}
	FORCEINLINE CollisionType GetCollisionType() const
	{
		return type;
	}
public:
	CollisionComponent(Actor* _owner, const ActorType& _ownerType, const CollisionType& _type = CT_NONE, const LayerType& _layer = LT_DYNAMIC,
		const set<ActorType>& _blackList = {}, const function<void()> _callback = {});
	CollisionComponent(Actor* _owner, const CollisionComponent* _other);
private:
	bool IsBlackListed(CollisionComponent* _otherCollision);
protected:
	virtual void Tick(const float _deltaTime) override;
public:
	void CheckCollision();
};