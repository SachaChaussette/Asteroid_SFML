#pragma once

#include "CoreMinimal.h"
#include "Player.h"

class GameModel
{
	string name;
protected:
	Player* player;
public:
	GameModel(const string& _name);
public:
	virtual void Start() {};
	virtual void Update() {};
	virtual void Stop() {};
	void GenerateAsteroid();
	void GenerateUFO();
	void GeneratePlayer();
};

