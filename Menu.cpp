#include "Menu.h"
#include "GameManager.h"
#include "MeshActor.h"

Menu::Menu(const string& _title)
{
	title = _title;
	//token = M_GAME.BindOnRenderWindow(bind(&Menu::RenderText, this, placeholders::_1));

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

	//delete _texture;
}

void Menu::OpenMenu()
{
}

void Menu::Show(const bool _toAdd)
{
	if(_toAdd)
	{
		queue.push(this);
	}
	DisplayMenu();

}

void Menu::Hide()
{
	queue.pop();
	if (Menu* _previous = queue.back()) _previous->Show(false);
	//M_GAME.UnbindOnRenderWindow(token);
}

void Menu::Close()
{
	while (Menu* _previous = queue.back())
	{
		queue.pop();
	}
}

void Menu::RenderText(RenderWindow& _window)
{
	Font _font = Font("Assets/Fonts/MainMenuFont.ttf");
	for (TextObject* _text : texts)
	{
		_text->GetDrawable()->setFont(_font);
		_window.draw(*_text->GetDrawable());
		LOG(Display, "Draw d'un Text");
	}	
}