#pragma once

#include "Component.h"
#include "Projectile.h"

class ShootComponent : public Component
{

public:
	ShootComponent(Actor* _owner);
	ShootComponent(Actor* _owner, const ShootComponent* _other);

public:
	void Shoot();
};

