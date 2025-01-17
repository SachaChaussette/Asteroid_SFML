#pragma once

#include "CoreMinimal.h"
#include "TextObject.h"
#include "ShapeObject.h"

class Menu
{
	string title;
	vector<TextObject*> texts;
	vector<ShapeObject*> shapes;
	queue<Menu*> queue;
	u_int token;

public:
	FORCEINLINE string GetTitle() const
	{
		return title;
	}
	FORCEINLINE void AddTextObject(TextObject* _text)
	{
		texts.push_back(_text);
	}
	FORCEINLINE void AddShapeObject(ShapeObject* _shape)
	{
		shapes.push_back(_shape);
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

	void RenderText(RenderWindow& _window);

};

