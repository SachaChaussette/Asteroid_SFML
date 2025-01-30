#pragma once
#include "Game.h"

class MenuGame : public Game
{
public:
	MenuGame();

public:
	virtual void Start() override;
	virtual bool Update() override;
	virtual void Stop() override;
};

