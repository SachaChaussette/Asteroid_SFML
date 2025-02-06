#pragma once

#include "Game.h"
#include "HUD.h"
#include "MeshActor.h"
#include "Canvas.h"

using namespace UI;

class AsteroidGame : public Game
{
    float difficultyFactor;
	u_int wavesCount;
	u_int baseAsteroidCount;
	Vector2f windowSize;
	MeshActor* background;

public:
	AsteroidGame();
public:

	virtual void Start() override;
	virtual void LaunchGame() override;
	virtual bool Update() override;
	virtual void Stop() override;

};

