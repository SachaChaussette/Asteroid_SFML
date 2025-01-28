#include "AsteroidGame.h"
#include "Level.h"
#include "Asteroid.h"
#include "TimerManager.h"
#include "GameManager.h"

AsteroidGame::AsteroidGame()
{

}

AsteroidGame::~AsteroidGame()
{

}

void AsteroidGame::Start()
{
	Super::Start();
	
	new Timer<Seconds>([&]()
		{Asteroid* _asteroid = Level::SpawnActor(Asteroid(MEDIUM));
	const Vector2f& _windowSize = M_GAME.GetCurrent()->GetWindowSize();
	_asteroid->SetOriginAtMiddle();
	_asteroid->SetPosition({ 0.0f, GetRandomNumberInRange(0.0f,_windowSize.y) });
	_asteroid->GetMovement()->SetDirection(Vector2f(
		GetRandomNumberInRange(0.01f, 1.0f), 
		GetRandomNumberInRange(-1.0f, 1.0f)));},
		seconds(1.0f), true, false);

	//SpawnMeshActor();
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
		{220.0f, 20.0f},
		{260.0f, 60.0f},
		{260.0f, 120.0f},
		{230.0f, 180.0f},
		{80.0f, 190.0f},
		{60.0f, 180.0f},
		{40.0f, 180.0f},
		{0.0f, 100.0f},
	};

	MeshActor* _convex = Level::SpawnActor(Asteroid(MEDIUM, _convexPoint, "green", PNG));
	_convex->SetOriginAtMiddle();
	_convex->SetPosition({ 400.0f, 400.0f });


	Vector2f _AsteroidSize = { 320.0f,320.0f };

	MeshActor* _medium = Level::SpawnActor(Asteroid(MEDIUM));
	_medium->SetOriginAtMiddle();
	_medium->SetPosition({ 400.0f, 400.0f });

	MeshActor* _small = Level::SpawnActor(Asteroid(SMALL));
	_small->SetOriginAtMiddle();
	_small->SetPosition({ 100.0f, 100.0f });

	MeshActor* _big = Level::SpawnActor(Asteroid(BIG));
	_big->SetOriginAtMiddle();
	_big->SetPosition({ 600.0f, 600.0f });
	if (MovementComponent* _movement = _big->GetComponent<MovementComponent>())
	{
		_movement->SetDirection(Vector2f(2.0f, 2.0f));

	}
}
