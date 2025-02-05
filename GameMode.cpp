#include "GameMode.h"
#include "Player.h"
#include "Asteroid.h"
#include "UFO.h"
#include "Level.h"
#include "GameManager.h"

GameMode::GameMode(const string& _name)
{
	name = _name;
}

void GameMode::GeneratePlayer()
{
	const Vector2f& _windowSize = CAST(Vector2f, M_GAME.GetCurrent()->GetWindowSize());

	/*const vector<Vector2f>& _convexShapePoints =
	{
		{30.0f, 8.0f},
		{12.0f, 48.0f},
		{50.0f, 48.0f},
	};*/
	Player* _player = Level::SpawnActor(Player(Vector2f(50.0f, 50.0f), "Ship_" + to_string(GetRandomNumberInRange(1, 5)), PNG, IntRect(Vector2i(), Vector2i(32, 32))));
	_player->SetOriginAtMiddle();
	_player->SetPosition(Vector2f(_windowSize.x / 2, _windowSize.y / 2));
}

void GameMode::GenerateAsteroid()
{
	const Vector2f& _windowSize = CAST(Vector2f, M_GAME.GetCurrent()->GetWindowSize());

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
	_asteroid->SetPosition({ 0.0f, GetRandomNumberInRange(0.0f, _windowSize.y) });
	_asteroid->ComputeNewDirection();
}

void GameMode::GenerateUFO()
{
	const Vector2f& _windowSize = CAST(Vector2f, M_GAME.GetCurrent()->GetWindowSize());
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
	_ufo->SetPosition({ 0.0f, GetRandomNumberInRange(0.0f, _windowSize.y) });
	_ufo->ComputeNewDirection();
}