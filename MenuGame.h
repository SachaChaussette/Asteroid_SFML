#pragma once
#include "Game.h"
#include "Canvas.h"

using namespace UI;

class MenuGame : public Game
{
	vector<Canvas*> allCanvas;
	Vector2f windowSize;
public:
	MenuGame();

public:
	virtual void Start() override;
	virtual bool Update() override;
	virtual void Stop() override;

private:
	void InitMainMenu();
	void InitStartMenu();
	void InitLeaderBoard();
	void InitCredits();
};

