#include "Menu.h"
#include "Game.h"

Menu::Menu(const string& _title)
{
	title = _title;
}

void Menu::DisplayMenu()
{
	/*for (ShapeObject* _shape : shapes)
	{
		Game::GetInstance().UpdateWindow(_shape);
	}
	for (TextObject* _text : texts)
	{
		Game::GetInstance().UpdateWindow(_shape);
	}*/
	Texture* _texture = new Texture("Assets/Texture/MissingTexture.png");
	RectangleShape _shape = RectangleShape(Vector2f(100.0f, 100.0f));
	_shape.setTexture(_texture);
	Game::GetInstance().UpdateWindow(dynamic_cast<Drawable*>(&_shape));

	delete _texture;
}

void Menu::Show(const bool _toAdd)
{
	if(_toAdd)
	{
		queue.push(this);
	}
}

void Menu::Hide()
{
	queue.pop();
	if (Menu* _previous = queue.back()) _previous->Show(false);
}

void Menu::Close()
{
	while (Menu* _previous = queue.back())
	{
		queue.pop();
	}
}
