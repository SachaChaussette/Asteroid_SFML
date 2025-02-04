#pragma once

#include "CoreMinimal.h"

class GameMode
{
	string name;
public:
	GameMode(const string& _name);
protected:
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Stop() = 0;
};

