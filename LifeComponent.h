#pragma once

#include "Component.h"

class LifeComponent : Component
{
	u_int lifeCount;

public:
	FORCEINLINE void IncrementLife()
	{
		++lifeCount;
	}
	FORCEINLINE void DecrementLife()
	{
		--lifeCount;
		if (lifeCount <= 0) Death();
	}
public:
	LifeComponent(Actor* _owner, const u_int& _lifeCount);
	LifeComponent(Actor* _owner, const LifeComponent& _other);
public:
	void Death();
};

