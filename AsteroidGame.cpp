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
	background = nullptr;
	difficultyFactor = 1.4f;
	wavesCount = 0;
	baseAsteroidCount = 5;

}

void AsteroidGame::Start()
{
	Super::Start();

	windowSize = CAST(Vector2f, M_GAME.GetCurrent()->GetWindowSize());
	background = Level::SpawnActor(MeshActor(RectangleShapeData(windowSize, "InGameBackground_2")));
	background->SetOriginAtMiddle();
	background->SetPosition(windowSize / 2.0f);
	background->SetScale({ 2.0f,2.0f });

	M_GAMEMODE.SetCurrentMode(new ChronoMode(180));
	M_GAMEMODE.Launch();

	//TODO Temp
	//canvas = new Canvas("Upgrade");
	
	//M_HUD.AddToViewport(canvas);

}

void AsteroidGame::LaunchGame()
{
	Super::LaunchGame();

	Level::SpawnActor(MeshActor(CAST(Vector2f, GetWindowSize()), "InGameBackground"));
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
