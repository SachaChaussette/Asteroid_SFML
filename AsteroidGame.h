#pragma once

#include "Game.h"
#include "HUD.h"

#include "Canvas.h"

#include "MenuGame.h"

using namespace UI;


class AsteroidGame : public Game
{
  Player* player;
	set<Asteroid*> asteroids;
	set<UFO*> ufos;

  float difficultyFactor;
	u_int wavesCount;
	u_int baseAsteroidCount;
	Canvas* canvas;
	Vector2f windowSize;
	MenuGame* menus;
public:
	AsteroidGame();
public:
	void GeneratePlayer();
	void GenerateAsteroid();
	void GenerateUFO();

	virtual void Start() override;
	virtual void LaunchGame();
	virtual bool Update() override;
	virtual void Stop() override;

private:
	void InitUpgradeCanvas();
};
