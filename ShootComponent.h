#pragma once

#include "Component.h"
#include "Projectile.h"

class ShootComponent : public Component
{
	Vector2f currentDirection;
	Projectile* projectile;

public:
	ShootComponent(Actor* _owner);

public:
	void Shoot();
};

