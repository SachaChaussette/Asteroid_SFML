#pragma once

#include "Game.h"

class AsteroidGame : public Game
{


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

