#include "AsteroidGame.h"
#include "Level.h"
#include "MeshActor.h"
#include "InputManager.h"

#include "TimerManager.h"
#include "GameManager.h"

#include "CollisionComponent.h"

AsteroidGame::AsteroidGame()
{
	player = nullptr;
	asteroids = set<Asteroid*>();
	ufos = set<UFO*>();
}


void AsteroidGame::GeneratePlayer()
{
	player = Level::SpawnActor(Player(Vector2f(50.0f, 50.0f), "player", PNG, IntRect(Vector2i(), Vector2i(32, 32))));
	player->SetOriginAtMiddle();
	player->SetPosition(Vector2f(GetWindowSize().x / 2, GetWindowSize().y / 2));
	

}
void AsteroidGame::GenerateAsteroid()
{
	Asteroid* _asteroid = Level::SpawnActor(Asteroid(BIG));
	_asteroid->SetOriginAtMiddle();
	_asteroid->SetPosition({ 0.0f, GetRandomNumberInRange(0.0f, CAST(float, GetWindowSize().y)) });
	_asteroid->ComputeNewDirection();

	asteroids.insert(_asteroid);
}
void AsteroidGame::GenerateUFO()
{
	UFO* _ufo = Level::SpawnActor(UFO(MEDIUM));
	_ufo->SetOriginAtMiddle();
	_ufo->SetPosition({ 0.0f, GetRandomNumberInRange(0.0f, CAST(float, GetWindowSize().y)) });
	_ufo->ComputeNewDirection();

	ufos.insert(_ufo);
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

	set<MeshActor*> _objects;
	for (Asteroid* _asteroid : asteroids)
	{
		_objects.insert(_asteroid);
	}
	set<MeshActor*> _ufos;
	for (UFO* _ufo : ufos)
	{
		_ufos.insert(_ufo);
	}


	player->collision->CheckCollide(player->GetMesh()->GetShape()->GetDrawable(), _objects, false);
	player->collision->CheckCollide(player->GetMesh()->GetShape()->GetDrawable(), _ufos, true);
	

	set<Asteroid*> _asteroids;
	for (MeshActor* _mesh : _objects)
	{
		_asteroids.insert(CAST(Asteroid*, _mesh));
	}
	set<UFO*> _newUfos;
	for (MeshActor* _mesh : _ufos)
	{
		_newUfos.insert(CAST(UFO*, _mesh));
	}

	asteroids = _asteroids;
	ufos = _newUfos;

	return IsOver();
}

void AsteroidGame::Stop()
{
	Super::Stop();
}
