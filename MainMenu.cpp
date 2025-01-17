#include "MainMenu.h"
#include "Game.h"

MainMenu::MainMenu() : Menu("Main Menu")
{
	Font _font = Font("Assets/Fonts/MainMenuFont.ttf");
	TextObject* _object = new TextObject(new Text(_font, "MAIN MENU TEST"));
	
	_object->SetOrigin(Vector2f(_object->GetDrawable()->getLocalBounds().size.x / 2, _object->GetDrawable()->getLocalBounds().size.y / 2));
	_object->SetPosition(Vector2f(M_GAME.GetWindowSize().x / 2, M_GAME.GetWindowSize().y / 2));
	AddTextObject(_object);
}
