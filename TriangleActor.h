#pragma once

#include "CircleActor.h"

class TriangleActor : public CircleActor
{


public:
	TriangleActor(const float _radius, const string& _path = "", const IntRect& _rect = IntRect());
};

