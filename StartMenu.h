#pragma once
#include "Menu.h"

using namespace UI;

class StartMenu : public Menu
{
public:
	FORCEINLINE CanvasWidget* GetCanva() const
	{
		return canva;
	}
public:
	StartMenu();
	StartMenu(const StartMenu& _other);

public:
	virtual void InitLevel() override;

private:
	void InitStartMenu(CanvasWidget* _canva);
	
};

