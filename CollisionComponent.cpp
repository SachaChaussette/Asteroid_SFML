#include "CollisionComponent.h"
#include "ActorManager.h"
#include "Entity.h"

CollisionComponent::CollisionComponent(Actor* _owner, const string& _channelName, const int _status, 
	const CollisionType& _type) : Component(_owner)
{
	channelName = _channelName;
	type = _type;
	status = _status;
}

CollisionComponent::CollisionComponent(Actor* _owner, const CollisionComponent& _other) : Component(_owner)
{
	channelName = _other.channelName;
	type = _other.type;
	status = _other.status;
	responses = _other.responses;
}

void CollisionComponent::Tick(const float _deltaTime)
{
	Super::Tick(_deltaTime);
	CheckCollision();
}

void CollisionComponent::CheckCollision()
{
	if (!(status & IS_PHYSIC)) return;

	const set<Actor*>& _allActors = M_ACTOR.GetAllActors();
	const FloatRect& _ownerRect = Cast<Entity>(owner)->GetConvexHitBox()->GetHitbox();
	
	for (Actor* _other : _allActors)
	{
		if (Entity* _otherEntity = Cast<Entity>(_other))
		{
			if (CollisionComponent* _otherCollision = _otherEntity->GetConvexHitBox()->GetComponent<CollisionComponent>())
			{
				const string& _otherName = _otherCollision->GetChannelName();
				if (!responses.contains(_otherName)) continue;

				const CollisionType& _response = responses.at(_otherName);
				if (_response == CT_NONE) continue;

				const FloatRect& _otherRect = _otherEntity->GetConvexHitBox()->GetHitbox();
				if (const optional<FloatRect> _intersection = _ownerRect.findIntersection(_otherRect))
				{
					const CollisionData& _data = { _other, _response, *_intersection };
					owner->OnCollision(_data);
					_other->OnCollision(_data);
				}
			}
		}
	}
}