#pragma once

#include "GameModel.h"
#include "LabelWidget.h"
#include "CanvasWidget.h"
#include "Player.h"

using namespace UI;

class ChronoMode : public GameModel
{
	int timerCount;
	int currentTime;

	LabelWidget* chrono;
	LabelWidget* life;
	
	CanvasWidget* canva;

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

