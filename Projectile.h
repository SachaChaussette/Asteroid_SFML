#pragma once

#include "Entity.h"
#include "EnemyMovementComponent.h"
#include "AnimationComponent.h"
#include "SizeType.h"

class Projectile : public MeshActor
{
	EnemyMovementComponent* movement;

public:
	FORCEINLINE EnemyMovementComponent* GetMovement() const
	{
		return movement;
	}
public:
	Projectile(const float _radius, const string& _path = "",
		const TextureExtensionType& _textureType = PNG, const IntRect& _rect = {}, bool _isRepeated = false, bool _isSmooth = true,
		const string& _name = "Projectile");
	Projectile(const Projectile& _other);

	void ComputeNewPositionIfNotInWindow();
	virtual void Construct() override;
	virtual void Tick(const float _deltaTime) override;
	virtual void BeginPlay() override ;
	virtual void Deconstruct() override ;

	// TODO Collision
};

