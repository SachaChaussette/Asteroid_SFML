#pragma once
#include "Menu.h"

using namespace UI;

class LeaderboardMenu : public Menu
{
public:
	FORCEINLINE CanvasWidget* GetCanva() const
	{
		return canva;
	}
public:
	LeaderboardMenu();
	LeaderboardMenu(const LeaderboardMenu& _other);

public:
	virtual void InitLevel() override;
	void Reset();

private:
	void InitLeaderBoard(CanvasWidget* _canva);
};

