#include "Actor.h"
#include "ActorManager.h"

Actor::Actor()
{
	Register();
}

Actor::~Actor()
{
	for (Component* _component : components)
	{
		delete _component;
	}
}

void Actor::Register()
{
	M_ACTOR.AddActor(this);
}

void Actor::BeginPlay()
{
	for (Component* _component : components)
	{
		_component->BeginPlay();
	}
}

void Actor::Tick(const float _deltaTime)
{
	for (Component* _component : components)
	{
		_component->Tick(_deltaTime);
	}
}

void Actor::BeginDestoy()
{
	for (Component* _component : components)
	{
		_component->BeginDestoy();
	}
}

void Actor::AddComponent(Component* _component)
{
	components.insert(_component);
}

void Actor::RemoveComponent(Component* _component)
{
	components.erase(_component);
}

