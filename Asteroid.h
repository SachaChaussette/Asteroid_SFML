#pragma once
#include "MeshActor.h"

class Asteroid : public MeshActor
{
	Vector2f velocity;

public:
	Asteroid(const vector<Vector2f> point, const string& _path = "asteroid"
			,const TextureExtensionType& _textureType = PNG, const IntRect& _rect = {});
	
};

