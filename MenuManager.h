#pragma once

#include "Singleton.h"
#include "Menu.h"

enum MenuType
{
	MT_MAIN,
	MT_START,
	MT_UPGRADE,
};

class MenuManager : public Singleton<MenuManager>
{
	map<MenuType, Menu*> menus;

public:
	FORCEINLINE void RegisterMenu(const MenuType& _type, Menu* _menu)
	{
		menus.insert({ _type, _menu });
	}
	FORCEINLINE void RemoveMenu(const MenuType& _type)
	{
		menus.erase(_type);
	}
public:
	void ShowMenuWithType(const MenuType& _type);
};

