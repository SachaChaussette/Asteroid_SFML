#include "ChronoMode.h"
#include "HUD.h"
#include "TimerManager.h"
#include "GameManager.h"
#include "Particle.h"
#include "Level.h"

ChronoMode::ChronoMode(const int _timerCount) : GameMode("ChronoMode")
{
	timerCount = _timerCount;
	currentTime = timerCount;
	chrono = nullptr;
}

void ChronoMode::ComputeTime()
{
	if (currentTime <= 0) Stop();

	const int _minutes = currentTime / 60;
	const int _seconds = currentTime % 60;
	const string& _finalText = to_string(_minutes) + ":" + to_string(_seconds);

	chrono->SetString(_finalText);
}

void ChronoMode::ResetTime()
{
	currentTime = timerCount;
}

void ChronoMode::Start()
{
	Super::Start();

	const Vector2f& _windowSize = CAST(Vector2f, M_GAME.GetCurrent()->GetWindowSize());

	//new Timer<Seconds>([&]() { GenerateAsteroid(); }, seconds(2.0f), true, true);
	//new Timer<Seconds>([&]() { GenerateUFO(); }, seconds(10.0f), true, true);

	GeneratePlayer();

	GenerateAsteroid();
	GenerateUFO();

	
	chrono = M_HUD.CreateWidget<Label>(to_string(currentTime), Screen, "Score", TTF);
	M_HUD.AddToViewport(chrono);
	chrono->SetPosition({ _windowSize.x * 0.45f, _windowSize.y * 0.05f });
	chrono->SetCharacterSize(70);
	chrono->SetZOrder(3);

	new Timer([&]() { --currentTime; }, seconds(1), true, true);


}

void ChronoMode::Update()
{
	Super::Update();
	ComputeTime();
}

void ChronoMode::Stop()
{
	Super::Stop();
	LOG(Display, "STOP");
}
