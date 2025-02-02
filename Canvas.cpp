#include "Canvas.h"

UI::Canvas::Canvas(const string& _name, const RenderType& _type) : Widget(_name, _type)
{
	allWidgets = set<Widget*>();
}

UI::Canvas::Canvas(const Canvas& _other) : Widget(_other)
{
	allWidgets = _other.allWidgets;
}

void UI::Canvas::Render(RenderWindow& _window)
{
	for (Actor* _actor : allWidgets)
	{
		if (Widget* _widget = Cast<Widget>(_actor))
		{
			_widget->Render(_window);
		}
	}
}

void UI::Canvas::UpdateWidgets()
{
	for (Widget* _widget : allWidgets)
	{
		_widget->SetPosition(_widget->GetPosition() + GetPosition());
		_widget->SetRotation(_widget->GetRotation() + GetRotation());
		_widget->SetScale(Vector2f(_widget->GetScale().x * GetScale().x,
									_widget->GetScale().y * GetScale().y));
	}
}

void UI::Canvas::Construct()
{
	Super::Construct();
	for (Actor* _actor : allWidgets)
	{
		if (Widget* _widget = Cast<Widget>(_actor))
		{
			_widget->Construct();
		}
	}
}

void UI::Canvas::BeginDestroy()
{
	Super::BeginDestroy();
	for (Actor* _actor : allWidgets)
	{
		if (Widget* _widget = Cast<Widget>(_actor))
		{
			_widget->BeginDestroy();
		}
	}
}

void UI::Canvas::Destroy()
{
	Super::Destroy();
	for (Actor* _actor : allWidgets)
	{
		if (Widget* _widget = Cast<Widget>(_actor))
		{
			_widget->SetToDelete();
		}
	}
}
