#include "LifeComponent.h"
#include "Actor.h"

LifeComponent::LifeComponent(Actor* _owner, const u_int& _lifeCount) : Component(_owner)
{
	lifeCount = _lifeCount;

}

LifeComponent::LifeComponent(Actor* _owner, const LifeComponent& _other) : Component(_owner)
{
	lifeCount = _other.lifeCount;
}

void LifeComponent::Death()
{
	owner->Destroy();
}
