#include "AsteroidGame.h"
#include "Level.h"
#include "MeshActor.h"
#include "InputManager.h"
#include "Player.h"
#include "UFO.h"
#include "Asteroid.h"
#include "TimerManager.h"
#include "GameManager.h"

AsteroidGame::AsteroidGame()
{
}

void AsteroidGame::GeneratePlayer()
{
	Player* _player = Level::SpawnActor(Player(Vector2f(50.0f, 50.0f), "player", PNG, IntRect(Vector2i(), Vector2i(32, 32))));
	_player->SetOriginAtMiddle();
	_player->SetPosition(Vector2f(GetWindowSize().x / 2, GetWindowSize().y / 2));
}

void AsteroidGame::GenerateAsteroid()
{
	Asteroid* _asteroid = Level::SpawnActor(Asteroid(BIG));
	_asteroid->SetOriginAtMiddle();
	_asteroid->SetPosition({ 0.0f, GetRandomNumberInRange(0.0f, CAST(float, GetWindowSize().y))});
	_asteroid->ComputeNewDirection();
}

void AsteroidGame::GenerateUFO()
{
	UFO* _ufo = Level::SpawnActor(UFO(MEDIUM));
	_ufo->SetOriginAtMiddle();
	_ufo->SetPosition({ 0.0f, GetRandomNumberInRange(0.0f, CAST(float, GetWindowSize().y))});
	_ufo->ComputeNewDirection();
}

void AsteroidGame::Start()
{
	Super::Start();

	new Timer<Seconds>([&]() { GenerateAsteroid(); }, seconds(1.0f), true, false);
	new Timer<Seconds>([&]() { GenerateUFO(); }, seconds(1.0f), true, false);

	GeneratePlayer();
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
