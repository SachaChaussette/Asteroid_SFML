#pragma once

#include "Component.h"
#include "Actor.h"
#include "TimerManager.h"

class LifeComponent : public Component
{
	int lifeCount;
	int invicibilityTime;
	bool canGetDamage;

public:
	FORCEINLINE void IncrementLife()
	{
		++lifeCount;
	}
	FORCEINLINE void DecrementLife()
	{
		if (!canGetDamage) return;
		
		--lifeCount;
		LOG(Warning, to_string(lifeCount));
		canGetDamage = false;
		if (lifeCount <= 0) Death();
		new Timer([&]() { canGetDamage = true; }, seconds(invicibilityTime), true, false);

		// TODO Modifier Sprite Frame Invincibilit�
	}
public:
	LifeComponent(Actor* _owner, const u_int& _lifeCount);
	LifeComponent(Actor* _owner, const LifeComponent* _other);
public:
	void Death();
};

