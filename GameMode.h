#pragma once

#include "CoreMinimal.h"

class GameMode
{
	string name;
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

