#pragma once
#include "MeshActor.h"
#include "AnimationComponent.h"
#include "EnemyMovementComponent.h"
#include "CollisionComponent.h"
#include "SizeType.h"

class UFO : public MeshActor
{
	EnemyMovementComponent* movement;
	AnimationComponent* animation;
	u_int spriteCount;
	SizeType size;

	//Servira pour la CollisionBox !
	vector<Vector2f> convexShapePoints;

public:
	CollisionComponent* collision;

	FORCEINLINE EnemyMovementComponent* GetMovement() const
	{
		return movement;
	}

	void ComputeNewDirection();

public:

	//point servira à la ConvexShape de la CollisionBox !
	UFO(const SizeType& _size = MEDIUM,
		const string& _path = "UFOSpriteSheet_" + to_string(GetRandomNumberInRange(1, 3)),
		const TextureExtensionType& _textureType = PNG, const IntRect& _rect = {});
	UFO(const UFO& _other);


protected:
	void ComputeNewPositionIfNotInWindow();
public:

	virtual void Construct() override;
	virtual void Tick(const float _deltaTime) override;
	virtual void BeginPlay() override;
	virtual void Deconstruct() override;
};


