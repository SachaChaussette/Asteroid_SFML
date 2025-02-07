#pragma once
#include "Level.h"
#include "CanvasWidget.h"

using namespace UI;

class Menu : public Level
{
	string name;
protected:
	CanvasWidget* canva;
public:
	FORCEINLINE CanvasWidget* GetCanva() const
	{
		return canva;
	}
public:
	Menu(const string& _name = "Menu");
	Menu(const Menu& _other);

public:
	virtual void InitLevel() override;
	virtual void Reset();

protected:
	virtual void ApplyCanva(CanvasWidget* _canva);
};

