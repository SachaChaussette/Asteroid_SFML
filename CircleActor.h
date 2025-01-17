#pragma once

#include "MeshActor.h"

class CircleActor : public MeshActor
{


public:
	CircleActor(const float _radius, const size_t& _pointCount = 30, const string& _path = "", 
				const IntRect& _rect = IntRect());
};

