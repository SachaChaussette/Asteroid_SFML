#pragma once

#include "Entity.h"
#include "PlayerMovementComponent.h"
#include "ShootComponent.h"

class Player : public Entity
{
	ShootComponent* shoot;
	PlayerMovementComponent* movement;

public:
	Player(const Vector2f& _size, const string& _path = "", const TextureExtensionType& _textureType = PNG,
		const IntRect& _rect = {}, bool _isRepeated = false, bool _isSmooth = false,
		const string& _name = "Player");
	Player(const Player& _other);
public:

	virtual void Construct() override;
	virtual void Deconstruct() override;
	virtual void BeginPlay() override;
	virtual void Tick(const float _deltaTime) override;
	virtual void BeginDestroy() override {};

};