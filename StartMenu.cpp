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

   canva = M_LEVEL.GetCurrentLevel()->SpawnWidget<Canvas>("Main Menu");
   InitMainMenu(canva);
   ApplyCanva(canva);
   M_LEVEL.GetCurrentLevel()->SetCurrentWidget(canva);*/
}

void StartMenu::InitStartMenu(CanvasWidget* _canva)
{
	const Vector2f& _windowSize = M_LEVEL.GetCurrentLevel()->GetWindowSize();

	LabelWidget* _solo = M_LEVEL.GetCurrentLevel()->SpawnWidget<LabelWidget>("SOLO", "Solo", Screen);
	_solo->SetFont("Daydream", TTF);
	_solo->SetPosition(Vector2f(_windowSize.x * 0.2, _windowSize.y * 0.25));
	_solo->SetCharacterSize(40);
	_solo->SetZOrder(3);

	LabelWidget* _coop = M_LEVEL.GetCurrentLevel()->SpawnWidget<LabelWidget>("COOP", "Coop", Screen);
	_coop->SetFont("Daydream", TTF);
	_coop->SetPosition(Vector2f(_windowSize.x * 0.2, _windowSize.y * 0.5));
	_coop->SetCharacterSize(40);
	_coop->SetZOrder(3);

	LabelWidget* _controls = M_LEVEL.GetCurrentLevel()->SpawnWidget<LabelWidget>("Controls", "Controls", Screen);
	_controls->SetFont("Daydream", TTF);
	_controls->SetPosition(Vector2f(_windowSize.x * 0.6, _windowSize.y * 0.15));
	_controls->SetCharacterSize(40);
	_controls->SetZOrder(3);

	LabelWidget* _up = M_LEVEL.GetCurrentLevel()->SpawnWidget<LabelWidget>("(Z) - Accelerate", "Accelerate", Screen);
	_up->SetFont("Daydream", TTF);
	_up->SetPosition(Vector2f(_windowSize.x * 0.62, _windowSize.y * 0.3));
	_up->SetCharacterSize(20);
	_up->SetZOrder(3);

	LabelWidget* _left = M_LEVEL.GetCurrentLevel()->SpawnWidget<LabelWidget>("(Q) - Rotate Left", "RotateL", Screen);
	_left->SetFont("Daydream", TTF);
	_left->SetPosition(Vector2f(_windowSize.x * 0.62, _windowSize.y * 0.4));
	_left->SetCharacterSize(20);
	_left->SetZOrder(3);

	LabelWidget* _right = M_LEVEL.GetCurrentLevel()->SpawnWidget<LabelWidget>("(D) - Rotate Right", "RotateR", Screen);
	_right->SetFont("Daydream", TTF);
	_right->SetPosition(Vector2f(_windowSize.x * 0.62, _windowSize.y * 0.5));
	_right->SetCharacterSize(20);
	_right->SetZOrder(3);

	LabelWidget* _shoot = M_LEVEL.GetCurrentLevel()->SpawnWidget<LabelWidget>("(S) - Shoot", "Shoot", Screen);
	_shoot->SetFont("Daydream", TTF);
	_shoot->SetPosition(Vector2f(_windowSize.x * 0.62, _windowSize.y * 0.6));
	_shoot->SetCharacterSize(20);
	_shoot->SetZOrder(3);


	LabelWidget* _back = M_LEVEL.GetCurrentLevel()->SpawnWidget<LabelWidget>("Back", "Back", Screen);
	_back->SetFont("Daydream", TTF);
	_back->SetPosition(Vector2f(_windowSize.x * 0.05, _windowSize.y * 0.9));
	_back->SetCharacterSize(30);
	_back->SetZOrder(3);

	//UI::ImageWidget* _backImage = new UI::ImageWidget(Vector2f(500.0f, 30.0f), "PixelTransparenta");
	//ButtonData _backData = ButtonData([&]() {}, [&]() {}, [&]()
	//	{
	//		if (Canvas* _canva = dynamic_cast<Canvas*>(M_LEVEL.GetCurrentLevel()->GetCurrentWidget()))
	//		{
	//			_canva->RemoveWidgets();
	//			//_canva = M_LEVEL.GetCurrentLevel()->SpawnWidget<Canvas>("Play Canva");
	//			InitMainMenu(_canva);
	//			_canva->UpdateWidgets();
	//			ApplyCanva(_canva);
	//			M_LEVEL.GetCurrentLevel()->SetCurrentWidget(_canva);
	//		}
	//		else
	//		{
	//			LOG(Warning, "Dynamic Invalide");
	//		}
	//	}, [&]() {}, [&]() {});
	//Button* _backButton = M_LEVEL.GetCurrentLevel()->SpawnWidget<Button>(_backImage, _backData, "CreditsButton");
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