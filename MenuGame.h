#pragma once
#include "Game.h"
#include "Canvas.h"

using namespace UI;

class MenuGame : public Game
{
	Canvas* canva;
	Vector2f windowSize;
public:
	MenuGame();
	MenuGame(const MenuGame& _other);

public:
	virtual void Start() override;
	virtual bool Update() override;
	virtual void Stop() override;

private:
	void InitMainMenu(Canvas* _canva);
	void InitStartMenu(Canvas* _canva);
	void InitLeaderBoard(Canvas* _canva);
	void InitCredits(Canvas* _canva);
	void Reset();
	void ApplyCanva(Canvas* _canva);
};

