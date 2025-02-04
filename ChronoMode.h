#pragma once

#include "GameMode.h"
#include "Label.h"

using namespace UI;

class ChronoMode : public GameMode
{
	u_int timerCount;
	u_int currentTime;

	Label* chrono;



public:
	ChronoMode(const u_int& _timerCount);

public:
	virtual void Start() override;
	virtual void Update() override;
};

