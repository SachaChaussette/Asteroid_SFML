#pragma once

#include "Level.h"
#include "HUD.h"

#include "CanvasWidget.h"

using namespace UI;

class AsteroidLevel : public Level
{
    float difficultyFactor;
	u_int wavesCount;
	u_int baseAsteroidCount;
	Vector2f windowSize;

public:
	AsteroidLevel();
public:

	virtual void InitLevel() override;
};

