#include "ActorManager.h"

ActorManager::~ActorManager()
{
	for (Actor* _actor : allActors)
	{
		delete _actor;
	}
}

void ActorManager::BeginPlay()
{
	for (Actor* _actor : allActors)
	{
		_actor->BeginPlay();
	}
}

void ActorManager::Tick(const float _deltaTime)
{
	for (Actor* _actor : allActors)
	{
		_actor->Tick(_deltaTime);
	}
}

void ActorManager::BeginDestoy()
{
	for (Actor* _actor : allActors)
	{
		_actor->BeginDestoy();
	}
}

