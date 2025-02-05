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
	
	windowSize = CAST(Vector2f, M_GAME.GetCurrent()->GetWindowSize());
	Level::SpawnActor(MeshActor(windowSize, "InGameBackground"));


	M_GAMEMODE.SetCurrentMode(new ChronoMode(10));
	M_GAMEMODE.Launch();

	//TODO Temp
	//canvas = new Canvas("Upgrade");
	
	//M_HUD.AddToViewport(canvas);

}

void AsteroidGame::LaunchGame()
{
	Super::LaunchGame();


	//menus->Reset();
	/*
	Level::SpawnActor(MeshActor(CAST(Vector2f, GetWindowSize()), "InGameBackground"));

	for (u_int _index = 0; _index < 30; _index++)
	{
		GenerateAsteroid();
		GenerateUFO();
	}
	//new Timer<Seconds>([&]() { GenerateUFO(); }, seconds(10.0f), true, true);

	GeneratePlayer();*/
}

bool AsteroidGame::Update()
{
	Super::Update();
	
	M_GAMEMODE.Update();
	return IsOver();
}

void AsteroidGame::Stop()
{
	Super::Stop();
}

