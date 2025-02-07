#pragma once

#include "Menu.h"

using namespace UI;

class MainMenu : public Menu
{

public:
	FORCEINLINE CanvasWidget* GetCanva() const
	{
		return canva;
	}
public:
	MainMenu();
	MainMenu(const MainMenu& _other);

public:
	virtual void InitLevel() override;

private:
	void InitMainMenu(CanvasWidget* _canva);
};

