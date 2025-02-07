#include "GameMode.h"
#include "Engine.h"
#include "LevelManager.h"
#include "MeshActor.h"
#include "Particle.h"
#include "ChronoLevel.h"

void InitConfig()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Logger::Reset();
}

int main()
{
	InitConfig();

	ChronoLevel* _level = new ChronoLevel(180);
	M_LEVEL.SetLevel(_level);

	Engine::GetInstance().Start();

	return EXIT_SUCCESS;
}