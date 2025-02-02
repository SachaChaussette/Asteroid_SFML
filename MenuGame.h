#pragma once
#include "Game.h"
#include "Canvas.h"

using namespace UI;

class MenuGame : public Game
{
	Canvas* canva;
public:
	FORCEINLINE Canvas* GetCanva() const
	{
		return canva;
	}
public:
	MenuGame();
	MenuGame(const MenuGame& _other);

public:
	virtual void Start() override;
	virtual bool Update() override;
	virtual void Stop() override;
	void Reset();

private:
	void InitMainMenu(Canvas* _canva);
	void InitStartMenu(Canvas* _canva);
	void InitLeaderBoard(Canvas* _canva);
	void InitCredits(Canvas* _canva);
	void ApplyCanva(Canvas* _canva);
};

