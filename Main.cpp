#include "Game.h"
#include "AsteroidGame.h"
#include "MenuGame.h"
#include "GameManager.h"

void InitConfig()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    Logger::Reset();
}

int main()
{
    InitConfig();
  
    M_GAME.Launch(new MenuGame());

	return EXIT_SUCCESS;
}