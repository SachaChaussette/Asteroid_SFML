#pragma once

#include "AnimationComponent.h"
#include "EnemyMovementComponent.h"
#include "ShootComponent.h"
#include "SizeType.h"
#include "Entity.h"

class UFO : public Entity
{
	EnemyMovementComponent* movement;
	ShootComponent* shoot;

	//Servira pour la CollisionBox !
	vector<Vector2f> convexShapePoints;

public:
	FORCEINLINE EnemyMovementComponent* GetMovement() const
	{
		return movement;
	}
public:
	//point servira à la ConvexShape de la CollisionBox !
	UFO(const float _radius, const SizeType& _size = MEDIUM, const string& _path = "",
		const TextureExtensionType& _textureType = PNG, const IntRect& _rect = {});
	UFO(const UFO& _other);

public:
	void ComputeNewDirection();
	virtual void Construct() override;
	virtual void Tick(const float _deltaTime) override;
	virtual void BeginPlay() override;
	virtual void Deconstruct() override;
};
