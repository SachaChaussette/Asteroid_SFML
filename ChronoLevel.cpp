#include "ChronoLevel.h"
#include "HUD.h"
#include "TimerManager.h"
#include "LevelManager.h"
#include "Asteroid.h"
#include "UFO.h"

ChronoLevel::ChronoLevel(const int _timerCount) : Level("Chrono Level")
{
	timerCount = _timerCount;
	currentTime = timerCount;
	chrono = nullptr;
	canva = nullptr;
	life = nullptr;
}

void ChronoLevel::ComputeTime()
{
	if (currentTime <= 0) M_LEVEL.GetCurrentLevel()->Unload(); // GameOver

	const int _minutes = currentTime / 60;
	const int _seconds = currentTime % 60;
	const string& _finalText = to_string(_minutes) + ":" + to_string(_seconds);

	chrono->SetString(_finalText);
}

void ChronoLevel::UpdateLife()
{
	life->SetString("P1 : " + to_string(player->GetLife()->GetLifeCount()));
}

void ChronoLevel::ResetTime()
{
	currentTime = timerCount;
}


void ChronoLevel::GeneratePlayer()
{
	const Vector2f& _windowSize = M_LEVEL.GetCurrentLevel()->GetWindowSize();

	/*const vector<Vector2f>& _convexShapePoints =
	{
		{30.0f, 8.0f},
		{12.0f, 48.0f},
		{50.0f, 48.0f},
	};*/

	const CircleShapeData& _shapeData = CircleShapeData(30.0f, "Player/Ship_" + to_string(GetRandomNumberInRange(1, 5)));
	const RectangleShapeData& _hitBoxData = RectangleShapeData(Vector2f(60.0f, 60.0f), "Transparent");
	player = M_LEVEL.GetCurrentLevel()->SpawnActor<Player>(_shapeData, _hitBoxData);
	//player->SetOriginAtMiddle();
	player->SetPosition(Vector2f(_windowSize.x / 2, _windowSize.y / 2));
}

void ChronoLevel::GenerateAsteroid()
{
	const Vector2f& _windowSize = M_LEVEL.GetCurrentLevel()->GetWindowSize();

	const vector<Vector2f>& _convexShapePoints =
	{
		{3.0f,14.0f}, {10.0f,5.0f},
		{18.0f,5.0f}, {29.0f,11.0f},
		{29.0f,16.0f}, {26.0f,23.0f},
		{19.0f,28.0f}, {13.0f,28.0f},
		{3.0f,19.0f}, {3.0f,14.0f},
	};
	const string& _finalPath = "Asteroid/AsteroidSpriteSheet_" + to_string(GetRandomNumberInRange(1, 2));
	const CircleShapeData& _shapeData = CircleShapeData(20.0f, _finalPath);
	const ConvexShapeData& _hitBoxData = ConvexShapeData(_convexShapePoints, "Transparent");
	Asteroid* _asteroid = M_LEVEL.GetCurrentLevel()->SpawnActor<Asteroid>(_shapeData, _hitBoxData);
	_asteroid->SetOriginAtMiddle();
	_asteroid->SetPosition({ 0.0f, GetRandomNumberInRange(0.0f, _windowSize.y) });
	_asteroid->ComputeNewDirection();
}

void ChronoLevel::GenerateUFO()
{
	const Vector2f& _windowSize = M_LEVEL.GetCurrentLevel()->GetWindowSize();

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
	const CircleShapeData& _shapeData = CircleShapeData(20.0f, _finalPath);
	const ConvexShapeData& _hitBoxData = ConvexShapeData(_convexShapePoints, "Transparent"); 
	UFO* _ufo = M_LEVEL.GetCurrentLevel()->SpawnActor<UFO>(_shapeData, _hitBoxData);
	_ufo->SetOriginAtMiddle();
	_ufo->SetPosition({ 0.0f, GetRandomNumberInRange(0.0f, _windowSize.y) });
	_ufo->ComputeNewDirection();
}

void ChronoLevel::InitLevel()
{
	Super::InitLevel();

	const Vector2f& _windowSize = M_LEVEL.GetCurrentLevel()->GetWindowSize();

	//new Timer<Seconds>([&]() { GenerateAsteroid(); }, seconds(2.0f), true, true);
	//new Timer<Seconds>([&]() { GenerateUFO(); }, seconds(10.0f), true, true);

	GeneratePlayer();

	/*GenerateAsteroid();
	GenerateUFO();

	new Timer([&]() 
	{ 
		--currentTime; 
		ComputeTime();
		UpdateLife();
	}, seconds(1), true, true);

	chrono = M_HUD.CreateWidget<LabelWidget>(to_string(currentTime), "ChronoLabel", Screen);
	chrono->SetFont("Score", TTF);
	chrono->SetPosition({ _windowSize.x * 0.45f, _windowSize.y * 0.05f });
	chrono->SetCharacterSize(70);
	chrono->SetZOrder(3);

	life = M_HUD.CreateWidget<LabelWidget>("P1 : " + to_string(player->GetLife()->GetLifeCount()), "LifeLabel", Screen);
	life->SetFont("Score", TTF);
	life->SetPosition({ _windowSize.x * 0.05f, _windowSize.y * 0.005f });
	life->SetCharacterSize(50);
	life->SetZOrder(3);

	canva = M_HUD.CreateWidget<CanvasWidget>("ChronoCanva", Screen);
	canva->AddChild(chrono);
	canva->AddChild(life);

	M_HUD.AddToViewport(canva);*/
}
