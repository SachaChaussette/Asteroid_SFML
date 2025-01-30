#pragma once

#include "MeshActor.h"
#include "PlayerMovementComponent.h"

class Player : public MeshActor
{
	PlayerMovementComponent* movement;
	// TODO Shoot Component

public:
	Player(const Vector2f& _size, const string& _path = "", const TextureExtensionType& _textureType = PNG,
		const IntRect& _rect = {}, bool _isRepeated = false, bool _isSmooth = true,
		const string& _name = "Player");
	Player(const Player& _other);
public:

	virtual void Construct() override;
	virtual void Deconstruct() override;
	virtual void BeginPlay() override;
	virtual void Tick(const float _deltaTime) override;
	virtual void BeginDestroy() override {};
	void ComputeNewPositionIfNotInWindow();

};