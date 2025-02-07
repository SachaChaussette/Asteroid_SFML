#pragma once

#include "LabelWidget.h"
#include "CanvasWidget.h"
#include "Player.h"

using namespace UI;

class ChronoLevel : public Level
{
	int timerCount;
	int currentTime;

	LabelWidget* chrono;
	LabelWidget* life;
	
	CanvasWidget* canva;

	Player* player;

public:
	ChronoLevel(const int _timerCount);

private:
	void ComputeTime();
	void UpdateLife();
	void ResetTime();
	void GeneratePlayer();
	void GenerateAsteroid();
	void GenerateUFO();
public:
	virtual void InitLevel() override;
};

