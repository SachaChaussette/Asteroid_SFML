#pragma once

#include "Game.h"
#include "HUD.h"

#include "Canvas.h"


using namespace UI;


class AsteroidGame : public Game
{
  float difficultyFactor;
	u_int wavesCount;
	u_int baseAsteroidCount;
	Canvas* canvas;
	Vector2f windowSize;

public:
	AsteroidGame();
public:
	virtual void Start() override;
	virtual void LaunchGame() override;
	virtual bool Update() override;
	virtual void Stop() override;

};

