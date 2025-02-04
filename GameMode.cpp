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

	Player* _player = Level::SpawnActor(Player(Vector2f(50.0f, 50.0f), "player", PNG, IntRect(Vector2i(), Vector2i(32, 32))));
	_player->SetOriginAtMiddle();
	_player->SetPosition(Vector2f(_windowSize.x / 2, _windowSize.y / 2));
}

void GameMode::GenerateAsteroid()
{
	const Vector2f& _windowSize = CAST(Vector2f, M_GAME.GetCurrent()->GetWindowSize());

	const string& _finalPath = "AsteroidSpriteSheet_" + to_string(GetRandomNumberInRange(1, 2));
	Asteroid* _asteroid = Level::SpawnActor(Asteroid(110.0f, BIG, _finalPath));
	_asteroid->SetOriginAtMiddle();
	_asteroid->SetPosition({ 0.0f, GetRandomNumberInRange(0.0f, _windowSize.y) });
	_asteroid->ComputeNewDirection();
}

void GameMode::GenerateUFO()
{
	const Vector2f& _windowSize = CAST(Vector2f, M_GAME.GetCurrent()->GetWindowSize());

	const string& _finalPath = "UFOSpriteSheet_" + to_string(GetRandomNumberInRange(1, 3));
	UFO* _ufo = Level::SpawnActor(UFO(110.0f, MEDIUM, _finalPath));
	_ufo->SetOriginAtMiddle();
	_ufo->SetPosition({ 0.0f, GetRandomNumberInRange(0.0f, _windowSize.y) });
	_ufo->ComputeNewDirection();
}