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
	/*const vector<Vector2f>& _convexShapePoints =
	{
		{30.0f, 8.0f},	
		{12.0f, 48.0f},	
		{50.0f, 48.0f},	
	};*/
	Player* _player = Level::SpawnActor(Player(Vector2f(50.0f, 50.0f), "player", PNG, IntRect(Vector2i(), Vector2i(32, 32))));
	_player->SetOriginAtMiddle();
	_player->SetPosition(Vector2f(GetWindowSize().x / 2, GetWindowSize().y / 2));
}

void AsteroidGame::GenerateAsteroid()
{
	const vector<Vector2f>& _convexShapePoints =
	{
		{3.0f,14.0f}, {10.0f,5.0f},
		{18.0f,5.0f}, {29.0f,11.0f},
		{29.0f,16.0f}, {26.0f,23.0f},
		{19.0f,28.0f}, {13.0f,28.0f},
		{3.0f,19.0f}, {3.0f,14.0f},
	};
	const string& _finalPath = "AsteroidSpriteSheet_" + to_string(GetRandomNumberInRange(1, 2));
	Asteroid* _asteroid = Level::SpawnActor(Asteroid(_convexShapePoints, _finalPath, BIG));
	_asteroid->SetOriginAtMiddle();
	_asteroid->SetPosition({ 0.0f, GetRandomNumberInRange(0.0f, CAST(float, GetWindowSize().y))});
	_asteroid->ComputeNewDirection();
}

void AsteroidGame::GenerateUFO()
{
	const vector<Vector2f>& _convexShapePoints =
	{
		{0.0f,15.0f}, {8.0f,13.0f},
		{12.0f,10.0f}, {16.0f,8.0f},
		{19.0f,10.0f}, {23.0f,13.0f},
		{31.0f,15.0f}, {31.0f,19.0f},
		{26.0f,22.0f}, {22.0f,23.0f},
		{9.0f,23.0f}, {5.0f,22.0f},
		{0.0f,19.0f}, {0.0f,15.0f},

	};
	const string& _finalPath = "UFOSpriteSheet_" + to_string(GetRandomNumberInRange(1, 3));
	UFO* _ufo = Level::SpawnActor(UFO(_convexShapePoints, _finalPath));
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

	for (u_int _index = 0; _index < 30; _index++)
	{
		GenerateAsteroid();
		GenerateUFO();
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