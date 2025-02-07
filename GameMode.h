#pragma once
#include "Actor.h"
#include "PlayerController.h"
#include "HUD.h"

class GameMode : public Actor
{
	SubclassOf<PlayerController> controllerRef;
	PlayerController* controller;
	SubclassOf<UI::HUD> hudRef;
	UI::HUD* hud;

public:
	GameMode(const string& _name = "GameMode");
	GameMode(const GameMode& _other);

	virtual void Construct() override;
	PlayerController* GetPlayerController();
	UI::HUD* GetHUD();
};