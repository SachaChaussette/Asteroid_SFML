#include "Component.h"
#include "Actor.h"
#include "TimerManager.h"

Component::Component(Actor* _owner)
{
	owner = _owner;
}

