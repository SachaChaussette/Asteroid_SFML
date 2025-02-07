#pragma once
#include "Game.h"
#include "CanvasWidget.h"

using namespace UI;

class MenuGame : public Game
{
	CanvasWidget* canva;
public:
	FORCEINLINE CanvasWidget* GetCanva() const
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
	void InitMainMenu(CanvasWidget* _canva);
	void InitStartMenu(CanvasWidget* _canva);
	void InitLeaderBoard(CanvasWidget* _canva);
	void InitCredits(CanvasWidget* _canva);
	void ApplyCanva(CanvasWidget* _canva);
};

