#pragma once
#include "MeshActor.h"

class CircleActor : public MeshActor
{
public:
	CircleActor(const float _radius, const string& _path = "", const TextureExtensionType& _textureType = PNG, const IntRect& _rect = {}, bool _isRepeated = false, bool _isSmooth = true);
};