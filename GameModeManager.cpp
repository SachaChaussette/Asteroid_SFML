#include "GameModeManager.h"

GameModeManager::~GameModeManager()
{
	delete currentMode;
}

void GameModeManager::Launch()
{
	currentMode->Start();
}

void GameModeManager::Update()
{
	currentMode->Update();
}

void GameModeManager::Stop()
{
	currentMode->Stop();
}
