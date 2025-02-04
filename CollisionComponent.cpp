#include "CollisionComponent.h"
#include "Entity.h"
#include "ActorManager.h"

CollisionComponent::CollisionComponent(Actor* _owner, const ActorType& _ownerType, const CollisionType& _type,
	const LayerType& _layer, const set<ActorType>& _blackList, const function<void()> _callback) 
	: Component(_owner)
{
	ownerType = _ownerType;
	type = _type;
	layer = _layer;
	blackList = _blackList;
	callback = _callback;
}

CollisionComponent::CollisionComponent(Actor* _owner, const CollisionComponent* _other) : Component(_owner)
{
	ownerType = _other->ownerType;
	type = _other->type;
	layer = _other->layer;
	blackList = _other->blackList;
	callback = _other->callback;
}

bool CollisionComponent::IsBlackListed(CollisionComponent* _otherCollision)
{
	// si le type de l'entiy est dans la blackList passe à l'entity suivant
	for (ActorType _type : blackList)
	{
		const ActorType& _otherType = _otherCollision->GetActorType();
		if (_otherType == _type) return true;
	}
	return false;
}

void CollisionComponent::Tick(const float _deltaTime)
{
	Super::Tick(_deltaTime);
	CheckCollision();
}

void CollisionComponent::CheckCollision()
{
	// si on à une collision de type NONE on return
	if (type == CT_NONE) return;

	if (!Cast<Entity>(owner))
	{
		LOG(Warning, "Actor n'est pas une Entity");
		return;
	}

	const set<Actor*>& _allActors = M_ACTOR.GetAllActors();
	
	// pour chaque actor si l'actor est un entity alors il fait partie de _allEntities
	vector<Entity*> _allEntities = vector<Entity*>();
	for (Actor* _actor : _allActors)
	{
		if (Entity* _entity = Cast<Entity>(_actor))
		{
			_allEntities.push_back(_entity);
		}
	}

	Entity* _owner = Cast<Entity>(owner);

	// TODO Changer
	const FloatRect& _ownerRect = _owner->GetMesh()->GetShape()->GetDrawable()->getGlobalBounds();

	for (Entity* _other : _allEntities)
	{
		CollisionComponent* _otherCollision = _other->GetCollision();

		// si l'entity à une collision de type NONE on return
		if (_otherCollision->GetCollisionType() == CT_NONE) continue;

		if (IsBlackListed(_otherCollision)) continue;

		// TODO Change
		const FloatRect& _otherRect = _other->GetMesh()->GetShape()->GetDrawable()->getGlobalBounds();

		// Collision
		if (_ownerRect.findIntersection(_otherRect))
		{
			callback();
		}
	}
}
