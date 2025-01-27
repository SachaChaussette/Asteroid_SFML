#pragma once
#include "MeshActor.h"

class TriangleActor : public MeshActor
{
public:
	TriangleActor(const float _radius, const string& _path = "", const TextureExtensionType& _textureType = PNG, const IntRect& _rect = {}, bool _isRepeated = false, bool _isSmooth = true);
};