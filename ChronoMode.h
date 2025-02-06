#pragma once

#include "GameMode.h"
#include "Label.h"
#include "Canvas.h"
#include "Player.h"

using namespace UI;

class ChronoMode : public GameMode
{
	int timerCount;
	int currentTime;

	Label* chrono;
	Label* life;
	Canvas* canva;

public:
	ChronoMode(const int _timerCount);

private:
	void ComputeTime();
	void UpdateLife();
	void ResetTime();
	
	virtual void Stop() override;
public:
	virtual void Start() override;
	virtual void Update() override;
};

