#pragma once

#include "Game.h"

class AsteroidGame : public Game
{
  float difficultyFactor;
	u_int wavesCount;
	u_int baseAsteroidCount;
	Vector2f windowSize;

public:
	AsteroidGame();
public:
	void GeneratePlayer();
	void GenerateAsteroid();
	void GenerateUFO();

	virtual void Start() override;
	virtual void LaunchGame() override;
	virtual bool Update() override;
	virtual void Stop() override;
};

