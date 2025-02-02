#pragma once
#include "MeshActor.h"
#include "Entity.h"
#include "AnimationComponent.h"
#include "EnemyMovementComponent.h"
#include "SizeType.h"


class Asteroid : public MeshActor
{
	EnemyMovementComponent* movement;
	//Servira pour la CollisionBox !
	vector<Vector2f> convexShapePoints;

public:
	FORCEINLINE EnemyMovementComponent* GetMovement() const
	{
		return movement;
	}
public:
	Asteroid(const float _radius, const SizeType& _size = BIG, const string& _path = "",
		const TextureExtensionType& _textureType = PNG, const IntRect& _rect = {});
	Asteroid(const Asteroid& _other);

public: 
	void ComputeNewDirection();
	virtual void Construct() override;
	virtual void Tick(const float _deltaTime) override;
	virtual void Deconstruct() override;
};

