#pragma once

#include "CoreMinimal.h"
#include "Player.h"

class GameMode
{
	string name;
protected:
	Player* player;
public:
	GameMode(const string& _name);
public:
	virtual void Start() {};
	virtual void Update() {};
	virtual void Stop() {};
	void GenerateAsteroid();
	void GenerateUFO();
	void GeneratePlayer();
};

