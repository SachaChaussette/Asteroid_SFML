#pragma once

#include "Game.h"
#include "HUD.h"

#include "Canvas.h"

using namespace UI;

class AsteroidGame : public Game
{
	Canvas* canvas;
	Vector2f windowSize;

public:
	AsteroidGame();
public:
	void GeneratePlayer();
	void GenerateAsteroid();
	void GenerateUFO();

	virtual void Start() override;
	virtual bool Update() override;
	virtual void Stop() override;

private:
	void InitUpgradeCanvas();
};

