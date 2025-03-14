#include "Component.h"
#include "Actor.h"

Component::Component(Actor* _owner)
{
	owner = _owner;
}

Component::Component(Actor* _owner, const Component& _other)
{
	owner = _owner;
}


void Component::Construct()
{
	SetActive(true);
}

void Component::Deconstruct()
{
	SetActive(false);
}