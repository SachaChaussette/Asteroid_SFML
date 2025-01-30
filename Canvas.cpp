#include "Canvas.h"

UI::Canvas::Canvas(const string& _name, const RenderType& _type) : Widget(_name, _type)
{
	allWidgets = set<Widget*>();
}

void UI::Canvas::Render(RenderWindow& _window)
{
	for (Widget* _widget : allWidgets)
	{
		_widget->Render(_window);
	}
}

