#include "ChronoMode.h"
#include "HUD.h"
#include "TimerManager.h"
#include "GameManager.h"
#include "LevelManager.h"

ChronoMode::ChronoMode(const int _timerCount) : GameModel("ChronoMode")
{
	timerCount = _timerCount;
	currentTime = timerCount;
	chrono = nullptr;
	canva = nullptr;
	life = nullptr;
}

void ChronoMode::ComputeTime()
{
	if (currentTime <= 0) Stop();

	const int _minutes = currentTime / 60;
	const int _seconds = currentTime % 60;
	const string& _finalText = to_string(_minutes) + ":" + to_string(_seconds);

	chrono->SetString(_finalText);
}

void ChronoMode::UpdateLife()
{
	life->SetString("P1 : " + to_string(player->GetLife()->GetLifeCount()));
}

void ChronoMode::ResetTime()
{
	currentTime = timerCount;
}

void ChronoMode::Start()
{
	Super::Start();

	const Vector2f& _windowSize = M_LEVEL.GetCurrentLevel()->GetWindowSize();


	//new Timer<Seconds>([&]() { GenerateAsteroid(); }, seconds(2.0f), true, true);
	//new Timer<Seconds>([&]() { GenerateUFO(); }, seconds(10.0f), true, true);

	GeneratePlayer();

	GenerateAsteroid();
	GenerateUFO();

	new Timer([&]() { --currentTime; }, seconds(1), true, true);

	chrono = M_HUD.CreateWidget<Label>(to_string(currentTime), Screen, "Score", TTF);
	chrono->SetPosition({ _windowSize.x * 0.45f, _windowSize.y * 0.05f });
	chrono->SetCharacterSize(70);
	chrono->SetZOrder(3);

	life = M_HUD.CreateWidget<Label>("P1 : " + to_string(player->GetLife()->GetLifeCount()), Screen, "Score", TTF);
	life->SetPosition({ _windowSize.x * 0.05f, _windowSize.y * 0.005f });
	life->SetCharacterSize(50);
	life->SetZOrder(3);

	canva = M_HUD.CreateWidget<Canvas>("ChronoCanva");
	canva->AddWidget(chrono);
	canva->AddWidget(life);

	M_HUD.AddToViewport(canva);
}

void ChronoMode::Update()
{
	Super::Update();
	ComputeTime();
	UpdateLife();
}

void ChronoMode::Stop()
{
	Super::Stop();
	LOG(Display, "STOP");
}
