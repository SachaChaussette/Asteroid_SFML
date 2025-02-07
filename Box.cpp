#include "Box.h"
#include "Level.h"

UI::Box::Box(const BoxData& _data) : Widget("Widget")
{
	widgets = vector<Widget*>();
	data = _data;
}


void UI::Box::AddWidget(Widget* _widget)
{
	widgets.push_back(_widget);
	AddChild(_widget, AT_KEEP_RELATIVE);
	Update();

	level->GetHUD()->AddToViewport(_widget);
}

void UI::Box::RemoveWidget(Widget* _widget)
{
	using Iterator = vector<Widget*>::iterator;
	for (Iterator _it; _it != widgets.end(); ++_it)
	{
		if (*_it == _widget)
		{
			widgets.erase(_it);
			break;
		}
	}

	RemoveChild(_widget);
	Update();

	level->GetHUD()->RemoveFromViewport(_widget);
}