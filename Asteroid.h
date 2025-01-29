#pragma once
#include "MeshActor.h"
#include "AnimationComponent.h"
#include "MovementComponent.h"
#include "SizeType.h"

class Asteroid : public MeshActor
{
	MovementComponent* movement;
	AnimationComponent* animation;
	SizeType size;

	//Servira pour la CollisionBox !
	vector<Vector2f> convexShapePoints;


public:
	FORCEINLINE MovementComponent* GetMovement() const
	{
		return movement;
	}

	void ComputeNewDirection();
public:
	Asteroid(const SizeType& _size = BIG, const string& _path = "AsteroidSpriteSheet_" + to_string(GetRandomNumberInRange(1, 2)),
		const TextureExtensionType& _textureType = PNG, const IntRect& _rect = {});
	Asteroid(const Asteroid& _other);

protected:
	void ComputeNewPositionIfNotInWindow();
public: 

	virtual void Construct() override;
	virtual void Tick(const float _deltaTime) override;
	virtual void Deconstruct() override;
};

