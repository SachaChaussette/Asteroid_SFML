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
		{0.0f, 0.0f},
		{100.0f, -60.0f},
		{260.0f, -60.0f},
		{320.0f, 110.0f},
		{320.0f, 190.0f},
		{250.0f, 260.0f},
		{140.0f, 260.0f},
		{110.0f, 250.0f},
		{60.0f, 250.0f},
		{0.0f, 150.0f},

	};

	MeshActor* _convex = Level::SpawnActor(Asteroid(_convexPoint, "green", PNG));
	_convex->SetOriginAtMiddle();
	_convex->SetPosition({ 400.0f, 400.0f });


	Vector2f _AsteroidSize = { 320.0f,320.0f };

	MeshActor* _rectangle = Level::SpawnActor(Asteroid(_convexPoint, "asteroid", PNG, IntRect({ 0,0 },{32,32})));
	_rectangle->SetOriginAtMiddle();
	_rectangle->SetPosition({ 400.0f, 400.0f });





}
