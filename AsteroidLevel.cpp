#include "AsteroidLevel.h"
#include "Level.h"
#include "MeshActor.h"
#include "InputManager.h"
#include "Player.h"
#include "UFO.h"
#include "Asteroid.h"
#include "TimerManager.h"
#include "ChronoLevel.h"
#include "LevelManager.h"


AsteroidLevel::AsteroidLevel() : Level("Asteroid Level")
{
	windowSize = Vector2f();

	difficultyFactor = 1.4f;
	wavesCount = 0;
	baseAsteroidCount = 5;

}

void AsteroidLevel::InitLevel()
{
	Super::InitLevel();

	windowSize = GetWindowSize();
	M_LEVEL.GetCurrentLevel()->SpawnActor<MeshActor>(RectangleShapeData(windowSize, "InGameBackground"));


	//M_GAMEMODE.SetCurrentMode(new ChronoLevel(180));
	//M_GAMEMODE.Launch();
}