#include "ChronoMode.h"
#include "HUD.h"
#include "TimerManager.h"
#include "GameManager.h"

ChronoMode::ChronoMode(const u_int& _timerCount)
{
	timerCount = _timerCount;
	currentTime = timerCount;
	chrono = nullptr;
}

void ChronoMode::Start()
{
	Super::Start();

	chrono = M_HUD.CreateWidget<Label>(to_string(currentTime), Screen, "Score", TTF);
	chrono->SetPosition({ M_GAME.GetCurrent()->GetWindowSize().x / 2.0f, M_GAME.GetCurrent()->GetWindowSize().y / 2.0f });
	new Timer([&]() { --currentTime; }, seconds(1), true, true);
}

void ChronoMode::Update()
{
	Super::Update();

	chrono->SetString(to_string(currentTime));
}
