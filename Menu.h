#pragma once

#include "CoreMinimal.h"

class Menu
{
	// TODO TEXT OBJECT
	//vector<TextObject*> texts;
	// TODO SHAPE OBJECT
	//vector<ShapeObject*> shapes;
	string title;
	queue<Menu*> queue;

public:
	FORCEINLINE string GetTitle() const
	{
		return title;
	}

public:
	Menu(const string& _title);
private:
	void DisplayMenu();
protected:
	void OpenMenu();
public:
	void Show(const bool _toAdd);
	void Hide();
	void Close();

};

