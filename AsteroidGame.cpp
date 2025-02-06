#include "AsteroidGame.h"
#include "Level.h"
#include "MeshActor.h"
#include "InputManager.h"
#include "Player.h"
#include "UFO.h"
#include "Asteroid.h"
#include "TimerManager.h"
#include "GameManager.h"
#include "ChronoMode.h"
#include "GameModeManager.h"


AsteroidGame::AsteroidGame()
{
	windowSize = Vector2f();

	difficultyFactor = 1.4f;
	wavesCount = 0;
	baseAsteroidCount = 5;

}

void AsteroidGame::Start()
{
	Super::Start();

	// TODO
	/*windowSize = CAST(Vector2f, M_GAME.GetCurrent()->GetWindowSize());
	Level::SpawnActor(MeshActor(windowSize, "InGameBackground"));


	M_GAMEMODE.SetCurrentMode(new ChronoMode(180));
	M_GAMEMODE.Launch();*/

	//TODO Temp
	//canvas = new Canvas("Upgrade");
	
	//M_HUD.AddToViewport(canvas);

}

void AsteroidGame::LaunchGame()
{
	Super::LaunchGame();

	// TODO
	//Level::SpawnActor(MeshActor(CAST(Vector2f, GetWindowSize()), "InGameBackground"));
}

bool AsteroidGame::Update()
{
	Super::Update();
	// TODO
	//M_GAMEMODE.Update();
	return IsOver();
}

void AsteroidGame::Stop()
{
	Super::Stop();
}
