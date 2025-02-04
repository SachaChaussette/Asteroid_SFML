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
	windowSize = Vector2f();
}

void AsteroidGame::GeneratePlayer()
{
	Player* _player = Level::SpawnActor(Player(Vector2f(50.0f, 50.0f), "player1", PNG, IntRect(Vector2i(), Vector2i(32, 32))));
	_player->SetOriginAtMiddle();
	_player->SetPosition(Vector2f(GetWindowSize().x / 2, GetWindowSize().y / 2));
}

void AsteroidGame::GenerateAsteroid()
{
	const string& _finalPath = "AsteroidSpriteSheet_1" + to_string(GetRandomNumberInRange(1, 2));
	Asteroid* _asteroid = Level::SpawnActor(Asteroid(110.0f, BIG, _finalPath));
	_asteroid->SetOriginAtMiddle();
	_asteroid->SetPosition({ 0.0f, GetRandomNumberInRange(0.0f, CAST(float, GetWindowSize().y))});
	_asteroid->ComputeNewDirection();
}

void AsteroidGame::GenerateUFO()
{
	const string& _finalPath = "UFOSpriteSheet_" + to_string(GetRandomNumberInRange(1, 3));
	UFO* _ufo = Level::SpawnActor(UFO(110.0f, MEDIUM, _finalPath));
	_ufo->SetOriginAtMiddle();
	_ufo->SetPosition({ 0.0f, GetRandomNumberInRange(0.0f, CAST(float, GetWindowSize().y))});
	_ufo->ComputeNewDirection();
}

void AsteroidGame::Start()
{
	Super::Start();
	
	windowSize = CAST(Vector2f, M_GAME.GetCurrent()->GetWindowSize());

	LaunchGame();
}

void AsteroidGame::LaunchGame()
{
	Super::LaunchGame();

	Level::SpawnActor(MeshActor(CAST(Vector2f, GetWindowSize()), "InGameBackground"));

	for (u_int _index = 0; _index < 1; _index++)
	{
		GenerateAsteroid();
	}
	//new Timer<Seconds>([&]() { GenerateUFO(); }, seconds(10.0f), true, true);

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