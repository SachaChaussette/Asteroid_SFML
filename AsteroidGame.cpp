#include "AsteroidGame.h"
#include "Level.h"
#include "MeshActor.h"
#include "InputManager.h"
#include "Player.h"

AsteroidGame::AsteroidGame()
{
}

void AsteroidGame::Start()
{
	Super::Start();
	//Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(GetWindowSize()), "image")));
	Player* _player = Level::SpawnActor(Player(RectangleShapeData(Vector2f(50.0f, 50.0f), "player", PNG, false, IntRect(Vector2i(), Vector2i(32, 32)))));
	_player->SetOriginAtMiddle();
	_player->SetPosition(Vector2f( GetWindowSize().x / 2, GetWindowSize().y / 2 ));
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
