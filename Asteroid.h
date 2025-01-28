#pragma once
#include "MeshActor.h"
#include "AnimationComponent.h"
#include "MovementComponent.h"

enum SizeType
{
	SMALL = 1,
	MEDIUM = 2,
	BIG = 4,
};

class Asteroid : public MeshActor
{
	MovementComponent* movement;
	AnimationComponent* animation;
	SizeType size;


public:
	FORCEINLINE MovementComponent* GetMovement() const
	{
		return movement;
	}
public:
	Asteroid(const SizeType& _size = MEDIUM, const vector<Vector2f>& point =
		{{30.0f, 20.0f}, {80.0f, 0.0f}, {220.0f, 20.0f}, {260.0f, 60.0f}, {260.0f, 120.0f},
		{230.0f, 180.0f}, {80.0f, 190.0f}, {60.0f, 180.0f}, {40.0f, 180.0f}, {0.0f, 100.0f},}, 
		const string& _path = "AsteroidSpriteSheet_" + to_string(GetRandomNumberInRange(1, 2)),
		const TextureExtensionType& _textureType = PNG, const IntRect& _rect = {});
	Asteroid(const Asteroid& _other);

public: 

	virtual void Construct() override;
	virtual void Deconstruct() override;
};

