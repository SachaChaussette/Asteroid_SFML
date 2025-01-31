#pragma once

#include "Game.h"

class AsteroidGame : public Game
{

	float difficultyFactor;
	u_int wavesCount;
	u_int baseAsteroidCount;

public:
	AsteroidGame();
public:
	void GeneratePlayer();
	void GenerateAsteroid();
	void GenerateUFO();

	virtual void Start() override;
	virtual bool Update() override;
	virtual void Stop() override;
};

