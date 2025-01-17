#pragma once

#include "MeshActor.h"

class RectangleActor : public MeshActor
{
	RectangleActor(const Vector2f _size, const string& _path = "", const IntRect& _rect = IntRect());
};

