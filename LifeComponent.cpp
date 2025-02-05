#include "LifeComponent.h"
#include "Actor.h"
#include "ActorManager.h"

LifeComponent::LifeComponent(Actor* _owner, const u_int& _lifeCount) : Component(_owner)
{
	lifeCount = _lifeCount;
	invicibilityTime = 1.0f;
	canGetDamage = true;
}

LifeComponent::LifeComponent(Actor* _owner, const LifeComponent* _other) : Component(_owner)
{
	lifeCount = _other->lifeCount;
	invicibilityTime = _other->invicibilityTime;
	canGetDamage = _other->canGetDamage;
}

void LifeComponent::Death()
{
	owner->SetToDelete();
}
