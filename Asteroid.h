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
	Asteroid(const vector<Vector2f> point, const SizeType& _size = MEDIUM, const string& _path = "asteroid"
			,const TextureExtensionType& _textureType = PNG, const IntRect& _rect = {});
	Asteroid(const Asteroid& _other);
public: 

	virtual void Construct() override;
	virtual void Deconstruct() override;
};

