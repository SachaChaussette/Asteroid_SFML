#pragma once

#include "GameMode.h"
#include "Label.h"

using namespace UI;

class ChronoMode : public GameMode
{
	int timerCount;
	int currentTime;

	Label* chrono;

public:
	ChronoMode(const int _timerCount);

private:
	void ComputeTime();
	void ResetTime();
	
	virtual void Stop() override;
public:
	virtual void Start() override;
	virtual void Update() override;
};

