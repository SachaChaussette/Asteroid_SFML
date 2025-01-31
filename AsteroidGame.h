#pragma once

#include "Game.h"

#include "Player.h"
#include "UFO.h"
#include "Asteroid.h"

class AsteroidGame : public Game
{
	Player* player;
	set<Asteroid*> asteroids;
	set<UFO*> ufos;

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

