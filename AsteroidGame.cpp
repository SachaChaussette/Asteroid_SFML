#include "AsteroidGame.h"
#include "Level.h"
#include "MeshActor.h"
#include "InputManager.h"
#include "Player.h"
#include "UFO.h"
#include "Asteroid.h"
#include "TimerManager.h"
#include "GameManager.h"


#include "Image.h"
#include "Label.h"

AsteroidGame::AsteroidGame()
{
	canvas = nullptr;
	windowSize = Vector2f();
	menus = new MenuGame();

	difficultyFactor = 1.4f;
	wavesCount = 0;
	baseAsteroidCount = 5;

}

void AsteroidGame::GeneratePlayer()
{
	Player* _player = Level::SpawnActor(Player(Vector2f(50.0f, 50.0f), "player", PNG, IntRect(Vector2i(), Vector2i(32, 32))));
	_player->SetOriginAtMiddle();
	_player->SetPosition(Vector2f(GetWindowSize().x / 2, GetWindowSize().y / 2));
}

void AsteroidGame::GenerateAsteroid()
{
	const string& _finalPath = "AsteroidSpriteSheet_" + to_string(GetRandomNumberInRange(1, 2));
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

	LaunchGame();

	//menus->Start();

	windowSize = CAST(Vector2f, M_GAME.GetCurrent()->GetWindowSize());
	const string& _finalPath = "AsteroidSpriteSheet_";
	Asteroid* _asteroid = Level::SpawnActor(Asteroid(110.0f, BIG, _finalPath));
	_asteroid->SetOriginAtMiddle();
	_asteroid->SetPosition({ 0.0f, GetRandomNumberInRange(0.0f, CAST(float, GetWindowSize().y)) });
	_asteroid->ComputeNewDirection();
	_asteroid->Deconstruct();


	
	for (u_int _index = 0; _index < 25; _index++)
	{
		GenerateAsteroid();
	}
	for (u_int _index = 0; _index < 5; _index++)
	{
		GenerateUFO();
	}


	new Timer<Seconds>([&]() {  }, seconds(1.0f), true, false);
	new Timer<Seconds>([&]() { GenerateUFO(); }, seconds(1.0f), true, false);

	


	//TODO Temp
	//canvas = new Canvas("Upgrade");
	
	//M_HUD.AddToViewport(canvas);
}

void AsteroidGame::LaunchGame()
{
	Super::LaunchGame();

	//menus->Reset();
	Level::SpawnActor(MeshActor(CAST(Vector2f, GetWindowSize()), "InGameBackground"));

	/*
	for (u_int _index = 0; _index < 5; _index++)
	{
		GenerateAsteroid();
	}
	new Timer<Seconds>([&]() { GenerateUFO(); }, seconds(10.0f), true, true);
	*/

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

void AsteroidGame::InitUpgradeCanvas()
{
	//TODO Change
	Label* _player = M_HUD.CreateWidget<Label>("Player 1", Screen, "Daydream", TTF);
	_player->SetPosition(Vector2f(windowSize.x * 0.42, windowSize.y * 0.15));
	_player->SetCharacterSize(25);
	_player->SetZOrder(2);


	UI::Image* _speedFrame = M_HUD.CreateWidget<UI::Image>(RectangleShapeData(Vector2f(192.0f, 192.0f), "Frame"),"SpeedFrame");
	_speedFrame->SetPosition(Vector2f(windowSize.x * 0.21, windowSize.y * 0.34));
	_speedFrame->SetZOrder(0);

	UI::Image* _speedIcon = M_HUD.CreateWidget<UI::Image>(RectangleShapeData(Vector2f(92.0f, 92.0f), "Speed"), "SpeedIcon");
	_speedIcon->SetPosition(Vector2f(windowSize.x * 0.25, windowSize.y * 0.4));
	_speedIcon->SetZOrder(1);

	Label* _speedText = M_HUD.CreateWidget<Label>("Speed++", Screen, "Daydream", TTF);
	_speedText->SetPosition(Vector2f(windowSize.x * 0.24, windowSize.y * 0.52));
	_speedText->SetCharacterSize(15);
	_speedText->SetZOrder(2);


	UI::Image* _pvFrame = M_HUD.CreateWidget<UI::Image>( RectangleShapeData(Vector2f(192.0f, 192.0f), "Frame"), "PvFrame");
	_pvFrame->SetPosition(Vector2f(windowSize.x * 0.41, windowSize.y * 0.34));
	_pvFrame->SetZOrder(0);

	UI::Image* _pvIcon = M_HUD.CreateWidget<UI::Image>(RectangleShapeData(Vector2f(92.0f, 92.0f), "Life"), "PvIcon");
	_pvIcon->SetPosition(Vector2f(windowSize.x * 0.45, windowSize.y * 0.4));
	_pvIcon->SetZOrder(1);

	Label* _pvText = M_HUD.CreateWidget<Label>("Pv++", Screen, "Daydream", TTF);
	_pvText->SetPosition(Vector2f(windowSize.x * 0.46, windowSize.y * 0.52));
	_pvText->SetCharacterSize(15);
	_pvText->SetZOrder(2);


	UI::Image* _shootFrame = M_HUD.CreateWidget<UI::Image>(RectangleShapeData(Vector2f(192.0f, 192.0f), "Frame"), "ShootFrame");
	_shootFrame->SetPosition(Vector2f(windowSize.x * 0.61, windowSize.y * 0.34));
	_shootFrame->SetZOrder(0);

	UI::Image* _shootIcon = M_HUD.CreateWidget<UI::Image>(RectangleShapeData(Vector2f(92.0f, 92.0f), "Shoot"), "ShootIcon");
	_shootIcon->SetPosition(Vector2f(windowSize.x * 0.65, windowSize.y * 0.4));
	_shootIcon->SetZOrder(1);

	Label* _shootText = M_HUD.CreateWidget<Label>("Shoot++", Screen, "Daydream", TTF);
	_shootText->SetPosition(Vector2f(windowSize.x * 0.64, windowSize.y * 0.52));
	_shootText->SetCharacterSize(15);
	_shootText->SetZOrder(2);


	Label* _powerPickup = M_HUD.CreateWidget<Label>("Pickup Power Up", Screen, "Daydream", TTF);
	_powerPickup->SetPosition(Vector2f(windowSize.x * 0.35, windowSize.y * 0.7));
	_powerPickup->SetCharacterSize(25);
	_powerPickup->SetZOrder(2);


	canvas->AddWidget(_player);

	canvas->AddWidget(_speedFrame);
	canvas->AddWidget(_speedText);
	canvas->AddWidget(_speedIcon);

	canvas->AddWidget(_pvFrame);
	canvas->AddWidget(_pvIcon);
	canvas->AddWidget(_pvText);

	canvas->AddWidget(_shootFrame);
	canvas->AddWidget(_shootIcon);
	canvas->AddWidget(_shootText);

	canvas->AddWidget(_powerPickup);
}
