#include "LifeComponent.h"
#include "Actor.h"
#include "ActorManager.h"
#include "Entity.h"

LifeComponent::LifeComponent(Actor* _owner, const u_int& _lifeCount) : Component(_owner)
{
	lifeCount = _lifeCount;
	invicibilityTime = 1.0f;
	canGetDamage = false;
}

LifeComponent::LifeComponent(Actor* _owner, const LifeComponent* _other) : Component(_owner)
{
	lifeCount = _other->lifeCount;
	invicibilityTime = _other->invicibilityTime;
	canGetDamage = _other->canGetDamage;
}

void LifeComponent::BeginPlay()
{
	Super::BeginPlay();
	
	if (Entity* _owner = Cast<Entity>(owner))
	{
		if (_owner->GetConvexHitBox()->GetLayer() == Layer::PROJECTILE)
		{
			canGetDamage = true;
		}
		else
		{
			new Timer([&]() { canGetDamage = true; }, seconds(3.0f), true, false);
		}
	}
}

void LifeComponent::Death()
{
	owner->SetToDelete();
	owner->Death();
}
