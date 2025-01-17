#include "MenuManager.h"
#include "Game.h"

void MenuManager::ShowMenuWithType(const MenuType& _type)
{
	menus[_type]->Show(true);

}

