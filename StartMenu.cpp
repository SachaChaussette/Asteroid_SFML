#include "StartMenu.h"
#include "ImageWidget.h"
#include "LabelWidget.h"
#include "ButtonWidget.h"
#include "HUD.h"
#include "LevelManager.h"

using namespace Camera;
using namespace UI;

StartMenu::StartMenu() : Menu("MainMenu Level")
{
	canva = nullptr;
}

StartMenu::StartMenu(const StartMenu& _other) : Menu("MainMenu Level")
{
	canva = _other.canva;
}

void StartMenu::InitLevel()
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

void StartMenu::InitStartMenu(CanvasWidget* _canva)
{
	const Vector2f& _windowSize = M_LEVEL.GetCurrentLevel()->GetWindowSize();

	LabelWidget* _solo = GetGameMode()->GetHUD()->SpawnWidget<LabelWidget>("SOLO", Screen, "Daydream", TTF);
	_solo->SetPosition(Vector2f(_windowSize.x * 0.2, _windowSize.y * 0.25));
	_solo->SetCharacterSize(40);
	_solo->SetZOrder(3);

	LabelWidget* _coop = GetGameMode()->GetHUD()->SpawnWidget<LabelWidget>("COOP", Screen, "Daydream", TTF);
	_coop->SetPosition(Vector2f(_windowSize.x * 0.2, _windowSize.y * 0.5));
	_coop->SetCharacterSize(40);
	_coop->SetZOrder(3);

	LabelWidget* _controls = GetGameMode()->GetHUD()->SpawnWidget<LabelWidget>("Controls", Screen, "Daydream", TTF);
	_controls->SetPosition(Vector2f(_windowSize.x * 0.6, _windowSize.y * 0.15));
	_controls->SetCharacterSize(40);
	_controls->SetZOrder(3);

	LabelWidget* _up = GetGameMode()->GetHUD()->SpawnWidget<LabelWidget>("(Z) - Accelerate", Screen, "Daydream", TTF);
	_up->SetPosition(Vector2f(_windowSize.x * 0.62, _windowSize.y * 0.3));
	_up->SetCharacterSize(20);
	_up->SetZOrder(3);

	LabelWidget* _left = GetGameMode()->GetHUD()->SpawnWidget<LabelWidget>("(Q) - Rotate Left", Screen, "Daydream", TTF);
	_left->SetPosition(Vector2f(_windowSize.x * 0.62, _windowSize.y * 0.4));
	_left->SetCharacterSize(20);
	_left->SetZOrder(3);

	LabelWidget* _right = GetGameMode()->GetHUD()->SpawnWidget<LabelWidget>("(D) - Rotate Right", Screen, "Daydream", TTF);
	_right->SetPosition(Vector2f(_windowSize.x * 0.62, _windowSize.y * 0.5));
	_right->SetCharacterSize(20);
	_right->SetZOrder(3);

	LabelWidget* _shoot = GetGameMode()->GetHUD()->SpawnWidget<LabelWidget>("(S) - Shoot", Screen, "Daydream", TTF);
	_shoot->SetPosition(Vector2f(_windowSize.x * 0.62, _windowSize.y * 0.6));
	_shoot->SetCharacterSize(20);
	_shoot->SetZOrder(3);


	LabelWidget* _back = GetGameMode()->GetHUD()->SpawnWidget<LabelWidget>("Back", Screen, "Daydream", TTF);
	_back->SetPosition(Vector2f(_windowSize.x * 0.05, _windowSize.y * 0.9));
	_back->SetCharacterSize(30);
	_back->SetZOrder(3);

	//UI::ImageWidget* _backImage = new UI::ImageWidget(Vector2f(500.0f, 30.0f), "PixelTransparenta");
	//ButtonData _backData = ButtonData([&]() {}, [&]() {}, [&]()
	//	{
	//		if (Canvas* _canva = dynamic_cast<Canvas*>(GetGameMode()->GetHUD()->GetCurrentWidget()))
	//		{
	//			_canva->RemoveWidgets();
	//			//_canva = GetGameMode()->GetHUD()->SpawnWidget<Canvas>("Play Canva");
	//			InitMainMenu(_canva);
	//			_canva->UpdateWidgets();
	//			ApplyCanva(_canva);
	//			GetGameMode()->GetHUD()->SetCurrentWidget(_canva);
	//		}
	//		else
	//		{
	//			LOG(Warning, "Dynamic Invalide");
	//		}
	//	}, [&]() {}, [&]() {});
	//Button* _backButton = GetGameMode()->GetHUD()->SpawnWidget<Button>(_backImage, _backData, "CreditsButton");
	/*_backButton->SetPosition(Vector2f(_windowSize.x * 0.05, _windowSize.y * 0.9));
	_backButton->SetZOrder(3);*/

	//_canva->AddChild(_backButton);

	_canva->AddChild(_solo);
	_canva->AddChild(_coop);
	_canva->AddChild(_controls);
	_canva->AddChild(_up);
	_canva->AddChild(_left);
	_canva->AddChild(_right);
	_canva->AddChild(_shoot);
	_canva->AddChild(_back);
}