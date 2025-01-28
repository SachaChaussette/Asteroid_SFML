#include "AsteroidGame.h"
#include "Level.h"
#include "Asteroid.h"

AsteroidGame::AsteroidGame()
{

}

AsteroidGame::~AsteroidGame()
{

}

void AsteroidGame::Start()
{
	Super::Start();
	SpawnMeshActor();
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

void AsteroidGame::SpawnMeshActor()
{
	const vector<Vector2f>& _convexPoint =
	{
		{30.0f, 20.0f},
		{80.0f, 0.0f},
		{240.0f, 20.0f},
		{260.0f, 60.0f},
		{260.0f, 120.0f},
		{230.0f, 180.0f},
		{100.0f, 190.0f},
		{90.0f, 180.0f},
		{40.0f, 180.0f},
		{0.0f, 100.0f},

	};

	MeshActor* _convex = Level::SpawnActor(Asteroid(_convexPoint, MEDIUM, "green", PNG));
	_convex->SetOriginAtMiddle();
	_convex->SetPosition({ 400.0f, 400.0f });


	Vector2f _AsteroidSize = { 320.0f,320.0f };

	MeshActor* _medium = Level::SpawnActor(Asteroid(_convexPoint, MEDIUM, "AsteroidSpriteSheet_" + to_string(GetRandomNumberInRange(1, 2))/*, IntRect({ 0,0 },{32,32})*/));
	_medium->SetOriginAtMiddle();
	_medium->SetPosition({ 400.0f, 400.0f });

	MeshActor* _small = Level::SpawnActor(Asteroid(_convexPoint, SMALL, "AsteroidSpriteSheet_" + to_string(GetRandomNumberInRange(1, 2))/*, IntRect({ 0,0 },{32,32})*/));
	_small->SetOriginAtMiddle();
	_small->SetPosition({ 100.0f, 100.0f });

	MeshActor* _big = Level::SpawnActor(Asteroid(_convexPoint, BIG, "AsteroidSpriteSheet_" + to_string(GetRandomNumberInRange(1, 2))/*, IntRect({ 0,0 },{32,32})*/));
	_big->SetOriginAtMiddle();
	_big->SetPosition({ 600.0f, 600.0f });
}
