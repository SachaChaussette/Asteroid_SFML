#include "CoreMinimal.h"
#include "Game.h"
#include "TimerManager.h"

void InitConfig()
{
    Logger::Reset();
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
}

int main()
{
    InitConfig();


    M_GAME.Launch();

    /*LOG(Error, "Erreur");
    LOG(Warning, "Attention");
    LOG(Display, "Affichage");
    LOG(Log, "Enregistrement");
    LOG(Log, "Aled");
    LOG(Fatal, "Fatal Error");*/
   

	return EXIT_SUCCESS;
}
