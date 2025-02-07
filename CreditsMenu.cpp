#include "CreditsMenu.h"
#include "ImageWidget.h"
#include "LabelWidget.h"
#include "ButtonWidget.h"
#include "HUD.h"
#include "LevelManager.h"

using namespace Camera;
using namespace UI;

CreditsMenu::CreditsMenu() : Menu("MainMenu Level")
{
	canva = nullptr;
}

CreditsMenu::CreditsMenu(const CreditsMenu& _other) : Menu("MainMenu Level")
{
	canva = _other.canva;
}

void CreditsMenu::InitLevel()
{
	Super::InitLevel();
	//TODO
   /*const Vector2f& _windowSize = CAST(Vector2f, M_LEVEL.GetCurrentLevel()->GetWindowSize());

   MeshActor* _background = M_LEVEL.GetCurrentLevel()->SpawnActor(MeshActor(RectangleShapeData(_windowSize, "Sky", PNG)));
   _background->SetFillColor(Color(255, 255, 255, 100));

   M_AUDIO.PlaySample<MusicSample>("MainMenu");

   canva = GetGameMode()->GetHUD()->SpawnWidget<Canvas>("Main Menu");
   InitMainMenu(canva);
   ApplyCanva(canva);
   GetGameMode()->GetHUD()->SetCurrentWidget(canva);*/
}

void CreditsMenu::InitCredits(CanvasWidget* _canva)
{
	const Vector2f& _windowSize = M_LEVEL.GetCurrentLevel()->GetWindowSize();

	LabelWidget* _credits = GetGameMode()->GetHUD()->SpawnWidget<LabelWidget>("Credits", Screen, "Daydream", TTF);
	_credits->SetPosition(Vector2f(_windowSize.x * 0.38, _windowSize.y * 0.1));
	_credits->SetCharacterSize(40);
	_credits->SetZOrder(3);

	//TODO Add People
	LabelWidget* _sacha = GetGameMode()->GetHUD()->SpawnWidget<LabelWidget>("Sacha - Lead", Screen, "Daydream", TTF);
	_sacha->SetPosition(Vector2f(_windowSize.x * 0.33, _windowSize.y * 0.3));
	_sacha->SetCharacterSize(20);
	_sacha->SetZOrder(3);

	LabelWidget* _alexandre = GetGameMode()->GetHUD()->SpawnWidget<LabelWidget>("Alexandre - Demarrage du Projet & Collisions", Screen, "Daydream", TTF);
	_alexandre->SetPosition(Vector2f(_windowSize.x * 0.33, _windowSize.y * 0.4));
	_alexandre->SetCharacterSize(20);
	_alexandre->SetZOrder(3);

	LabelWidget* _yoan = GetGameMode()->GetHUD()->SpawnWidget<LabelWidget>("Yoan - Shape & Convex", Screen, "Daydream", TTF);
	_yoan->SetPosition(Vector2f(_windowSize.x * 0.33, _windowSize.y * 0.5));
	_yoan->SetCharacterSize(20);
	_yoan->SetZOrder(3);

	LabelWidget* _sev = GetGameMode()->GetHUD()->SpawnWidget<LabelWidget>("Sev - Asteroides & Animations", Screen, "Daydream", TTF);
	_sev->SetPosition(Vector2f(_windowSize.x * 0.33, _windowSize.y * 0.6));
	_sev->SetCharacterSize(20);
	_sev->SetZOrder(3);

	LabelWidget* _romain = GetGameMode()->GetHUD()->SpawnWidget<LabelWidget>("Romain - UFOs", Screen, "Daydream", TTF);
	_romain->SetPosition(Vector2f(_windowSize.x * 0.33, _windowSize.y * 0.7));
	_romain->SetCharacterSize(20);
	_romain->SetZOrder(3);

	LabelWidget* _quentin = GetGameMode()->GetHUD()->SpawnWidget<LabelWidget>("Quentin - Menus", Screen, "Daydream", TTF);
	_quentin->SetPosition(Vector2f(_windowSize.x * 0.33, _windowSize.y * 0.8));
	_quentin->SetCharacterSize(20);
	_quentin->SetZOrder(3);

	LabelWidget* _back = GetGameMode()->GetHUD()->SpawnWidget<LabelWidget>("Back", Screen, "Daydream", TTF);
	_back->SetPosition(Vector2f(_windowSize.x * 0.05, _windowSize.y * 0.9));
	_back->SetCharacterSize(30);
	_back->SetZOrder(3);

	_canva->AddChild(_credits);
	_canva->AddChild(_sacha);
	_canva->AddChild(_alexandre);
	_canva->AddChild(_yoan);
	_canva->AddChild(_sev);
	_canva->AddChild(_romain);
	_canva->AddChild(_quentin);
	_canva->AddChild(_back);
}

void CreditsMenu::Reset()
{
	canva->BeginDestroy();
}
