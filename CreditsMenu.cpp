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

   canva = M_LEVEL.GetCurrentLevel()->SpawnWidget<Canvas>("Main Menu");
   InitMainMenu(canva);
   ApplyCanva(canva);
   M_LEVEL.GetCurrentLevel()->SetCurrentWidget(canva);*/
}

void CreditsMenu::InitCredits(CanvasWidget* _canva)
{
	const Vector2f& _windowSize = M_LEVEL.GetCurrentLevel()->GetWindowSize();

	LabelWidget* _credits = M_LEVEL.GetCurrentLevel()->SpawnWidget<LabelWidget>("Credits", "Credits", Screen);
	_credits->SetFont("Daydream", TTF);
	_credits->SetPosition(Vector2f(_windowSize.x * 0.38, _windowSize.y * 0.1));
	_credits->SetCharacterSize(40);
	_credits->SetZOrder(3);

	//TODO Add People
	LabelWidget* _sacha = M_LEVEL.GetCurrentLevel()->SpawnWidget<LabelWidget>("Sacha - Lead", "Sacha", Screen);
	_sacha->SetFont("Daydream", TTF);
	_sacha->SetPosition(Vector2f(_windowSize.x * 0.33, _windowSize.y * 0.3));
	_sacha->SetCharacterSize(20);
	_sacha->SetZOrder(3);

	LabelWidget* _alexandre = M_LEVEL.GetCurrentLevel()->SpawnWidget<LabelWidget>("Alexandre - Demarrage du Projet & Collisions", "Alexandre", Screen);
	_alexandre->SetFont("Daydream", TTF);
	_alexandre->SetPosition(Vector2f(_windowSize.x * 0.33, _windowSize.y * 0.4));
	_alexandre->SetCharacterSize(20);
	_alexandre->SetZOrder(3);

	LabelWidget* _yoan = M_LEVEL.GetCurrentLevel()->SpawnWidget<LabelWidget>("Yoan - Shape & Convex", "Yoan", Screen);
	_yoan->SetFont("Daydream", TTF);
	_yoan->SetPosition(Vector2f(_windowSize.x * 0.33, _windowSize.y * 0.5));
	_yoan->SetCharacterSize(20);
	_yoan->SetZOrder(3);

	LabelWidget* _sev = M_LEVEL.GetCurrentLevel()->SpawnWidget<LabelWidget>("Sev - Asteroides & Animations", "Sev", Screen);
	_sev->SetFont("Daydream", TTF);
	_sev->SetPosition(Vector2f(_windowSize.x * 0.33, _windowSize.y * 0.6));
	_sev->SetCharacterSize(20);
	_sev->SetZOrder(3);

	LabelWidget* _romain = M_LEVEL.GetCurrentLevel()->SpawnWidget<LabelWidget>("Romain - UFOs", "Romain", Screen);
	_romain->SetFont("Daydream", TTF);
	_romain->SetPosition(Vector2f(_windowSize.x * 0.33, _windowSize.y * 0.7));
	_romain->SetCharacterSize(20);
	_romain->SetZOrder(3);

	LabelWidget* _quentin = M_LEVEL.GetCurrentLevel()->SpawnWidget<LabelWidget>("Quentin - Menus", "Quentin", Screen);
	_quentin->SetFont("Daydream", TTF);
	_quentin->SetPosition(Vector2f(_windowSize.x * 0.33, _windowSize.y * 0.8));
	_quentin->SetCharacterSize(20);
	_quentin->SetZOrder(3);

	LabelWidget* _back = M_LEVEL.GetCurrentLevel()->SpawnWidget<LabelWidget>("Back", "Back", Screen);
	_back->SetFont("Daydream", TTF);
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
