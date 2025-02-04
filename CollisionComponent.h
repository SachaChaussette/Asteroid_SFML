#pragma once
#include "Component.h"
#include "MeshActor.h"

enum InteractStatus
{
	IS_NONE = 0,
	IS_QUERY = 1 << 0,
	IS_PHYSIC = 1 << 1,
	IS_ALL = IS_QUERY | IS_PHYSIC
};

enum CollisionType
{
	CT_NONE,
	CT_OVERLAP,
	CT_BLOCK
};

struct CollisionData
{
	Actor* other;
	CollisionType response;
	FloatRect impactRect;
};

class CollisionComponent : public Component
{
	string channelName;
	int status;
	CollisionType type; // Réponse par défaut
	map<string, CollisionType> responses; //Layer a la place du string

public:
	FORCEINLINE void AddResponses(vector<pair<string, CollisionType>> _responses)
	{
		for (pair<string, CollisionType> _pair : _responses)
		{
			responses.insert(_pair);
		}
	}
	FORCEINLINE string GetChannelName() const
	{
		return channelName;
	}
 
public:
	CollisionComponent(Actor* _owner, const string& _channelName, const int _status, 
		const CollisionType& _type);
	CollisionComponent(Actor* _owner, const CollisionComponent& _other);

protected:
	virtual void Tick(const float _deltaTime) override;

private:
	void CheckCollision();
};
