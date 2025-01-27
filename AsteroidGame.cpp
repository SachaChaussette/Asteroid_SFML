#include "AsteroidGame.h"
#include "Level.h"
#include "MeshActor.h"
#include "InputManager.h"
#include "TEST.h"

AsteroidGame::AsteroidGame()
{
}

void AsteroidGame::Start()
{
	Super::Start();
	Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(GetWindowSize()), "image")));
	TEST* _TEST = Level::SpawnActor(TEST(RectangleShapeData(Vector2f(50.0f, 50.0f), "images",JPG)));
	_TEST->SetOriginAtMiddle();
	_TEST->SetPosition(Vector2f( GetWindowSize().x / 2, GetWindowSize().y / 2 ));
}

bool AsteroidGame::Update()
{
	Super::Update();
	return IsOver();
}

void AsteroidGame::Stop()
{
	Super::Stop();
}
