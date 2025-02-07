#pragma once
#include "Menu.h"

class CreditsMenu : public Menu
{
public:
	FORCEINLINE CanvasWidget* GetCanva() const
	{
		return canva;
	}
public:
	CreditsMenu();
	CreditsMenu(const CreditsMenu& _other);

public:
	virtual void InitLevel() override;
	void Reset();

private:
	void InitCredits(CanvasWidget* _canva);
};

