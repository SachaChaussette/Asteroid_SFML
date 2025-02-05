#include "Button.h"
#include "InputManager.h"

UI::Button::Button(Image* _image, const ButtonData& _data, const string& _name, 
	const RenderType& _type) : Widget(_name, _type)
{
	isSelected = false;
	isHeld = false;
	isHovered = false;
	foreground = _image;
	data = _data;
}

UI::Button::Button(const Button& _other) : Widget(_other)
{
	isSelected = _other.isSelected;
	isHeld = _other.isHeld;
	isHovered = _other.isHovered;
	foreground = _other.foreground;
	data = _other.data;
}

bool UI::Button::OnPressed()
{
	isSelected = true;
	isHeld = true;

	if (data.pressedCallback)
	{
		data.pressedCallback();
		return true;
	}
	
	return false;
}

void UI::Button::OnHeld()
{
	if (!isHeld) return;

	if (data.releasedCallback)
	{
		data.releasedCallback();
	}
}

void UI::Button::OnReleased()
{
	if (!isSelected) return;

	isSelected = false;
	isHeld = false;

	if (data.heldCallback)
	{
		data.heldCallback();
	}
}

void UI::Button::OnHovered()
{
	isHovered = true;

	if (data.hoveredCallback)
	{
		data.hoveredCallback();
	}
}

void UI::Button::OnUnhovered()
{
	isHovered = false;

	if (data.unHoveredCallback)
	{
		data.unHoveredCallback();
	}
}


void UI::Button::Execute(const Event& _event)
{

}

void UI::Button::Construct()
{
	Super::Construct();
	/*M_INPUT.BindAction([&](Vector2i _mousePos)

	M_INPUT.BindAction([&](Vector2i _mousePos)

	{
		const Vector2i& _buttonPos = CAST(Vector2i, GetPosition());
		const Vector2i& _buttonScale = CAST(Vector2i, foreground->GetInitialSize());
		if (_mousePos.x <= _buttonPos.x + _buttonScale.x && _mousePos.x >= _buttonPos.x
			&& _mousePos.y <= _buttonPos.y + _buttonScale.y && _mousePos.y >= _buttonPos.y)
		{
			OnPressed();
		}
	}, Mouse::Button::Left);*/

}

void UI::Button::Deconstruct()
{
	Super::Deconstruct();
}

void UI::Button::Render(RenderWindow& _window)
{
	foreground->Render(_window);
}
