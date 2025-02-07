#include "MenuGame.h"
#include "HUD.h"
#include "LevelManager.h"
#include "CameraManager.h"
#include "GameManager.h"

#include "MeshActor.h"
#include "LabelWidget.h"
#include "ButtonWidget.h"
#include "ImageWidget.h"
#include "AudioManager.h"

using namespace Camera;
using namespace UI;

MenuGame::MenuGame() : Game()
{
	canva = nullptr;
}

MenuGame::MenuGame(const MenuGame& _other)
{
	//canva = _other.canva;
}

void MenuGame::Start()
{
	Super::Start();
	// TODO
	/*const Vector2f& _windowSize = CAST(Vector2f, M_GAME.GetCurrent()->GetWindowSize());

	MeshActor* _background = Level::SpawnActor(MeshActor(RectangleShapeData(_windowSize, "Sky", PNG)));
	_background->SetFillColor(Color(255, 255, 255, 100));

	M_AUDIO.PlaySample<MusicSample>("MainMenu");

	canva = M_HUD.CreateWidget<Canvas>("Main Menu");
	InitMainMenu(canva);
	ApplyCanva(canva);
	M_HUD.SetCurrentWidget(canva);*/
}

bool MenuGame::Update()
{
	Super::Update();

	return false;
}

void MenuGame::Stop()
{
	Super::Stop();
}

void MenuGame::InitMainMenu(CanvasWidget* _canva)
{
	const Vector2f& _windowSize = M_LEVEL.GetCurrentLevel()->GetWindowSize();

	LabelWidget* _title = M_HUD.CreateWidget<LabelWidget>("ASTEROID", Screen, "Daydream", TTF);
	_title->SetPosition(Vector2f(_windowSize.x * 0.33, _windowSize.y * 0.2));
	_title->SetCharacterSize(75);
	_title->SetZOrder(1);

	_canva->AddChild(_title);

	//////////////////////////
	///		Play
	//////////////////////////

	LabelWidget* _play = M_HUD.CreateWidget<LabelWidget>("Play", Screen, "Daydream", TTF);
	_play->SetPosition(Vector2f(_windowSize.x * 0.15, _windowSize.y * 0.8));
	_play->SetCharacterSize(25);
	_play->SetZOrder(2);

	UI::ImageWidget* _playImage = new UI::ImageWidget("PlayImg", RectangleShapeData({ 100.0f, 30.0f }, "PixelTransparent"));
	//const ButtonData& _playData = ButtonData([&]() {}, [&]() {}, [&]() 
	//{ 
	//	// TODO
	//	//if (Canvas* _canva = dynamic_cast<Canvas*>(M_HUD.GetCurrentWidget()))
	//	//{
	//	//	_canva->Destroy();
	//	//	_canva->RemoveWidgets();
	//	//	M_GAME.GetCurrent()->LaunchGame();
	//	//	//_canva = M_HUD.CreateWidget<Canvas>("Play Canva");
	//	//	/*InitStartMenu(_canva);
	//	//	_canva->UpdateWidgets();
	//	//	ApplyCanva(_canva);
	//	//	M_HUD.SetCurrentWidget(_canva);*/
	//	//}
	//	//else
	//	//{
	//	//	LOG(Warning, "Dynamic Invalide");
	//	//}
	//	
	//}, [&]() {}, [&]() {});
	/*Button* _playButton = M_HUD.CreateWidget<Button>(_playImage, _playData, "PlayButton");
	_playButton->SetPosition(Vector2f(_windowSize.x * 0.15, _windowSize.y * 0.8));
	_playButton->SetZOrder(3);
	*/

	//////////////////////////
	///		LeaderBoard
	//////////////////////////

	LabelWidget* _leaderBoard = M_HUD.CreateWidget<LabelWidget>("LeaderBoard", Screen, "Daydream", TTF);
	_leaderBoard->SetPosition(Vector2f(_windowSize.x * 0.3, _windowSize.y * 0.8));
	_leaderBoard->SetCharacterSize(25);
	_leaderBoard->SetZOrder(2);

	UI::ImageWidget* _leaderBoardImage = new UI::ImageWidget("LeaderboardImg", RectangleShapeData({ 300.0f, 30.0f }, "PixelTransparent"));
	//const ButtonData& _leaderBoardData = ButtonData([&]() {}, [&]() {}, [&]() 
	//{ 
	//	// TODO
	//	//if (Canvas* _canva = dynamic_cast<Canvas*>(M_HUD.GetCurrentWidget()))
	//	//{
	//	//	_canva->RemoveWidgets();
	//	//	//_canva = M_HUD.CreateWidget<Canvas>("Play Canva");
	//	//	InitLeaderBoard(_canva);
	//	//	_canva->UpdateWidgets();
	//	//	ApplyCanva(_canva);
	//	//	M_HUD.SetCurrentWidget(_canva);
	//	//}
	//	//else
	//	//{
	//	//	LOG(Warning, "Dynamic Invalide");
	//	//}
	//}, [&]() {}, [&]() {});
	/*Button* _leaderBoardButton = M_HUD.CreateWidget<Button>(_leaderBoardImage, _leaderBoardData, "LeaderBoardButton");
	_leaderBoardButton->SetPosition(Vector2f(_windowSize.x * 0.3, _windowSize.y * 0.8));
	_leaderBoardButton->SetZOrder(3);*/
	
	//////////////////////////
	///		Credits
	//////////////////////////

	LabelWidget* _credits = M_HUD.CreateWidget<LabelWidget>("Credits", Screen, "Daydream", TTF);
	_credits->SetPosition(Vector2f(_windowSize.x * 0.57, _windowSize.y * 0.8));
	_credits->SetCharacterSize(25);
	_credits->SetZOrder(2);

	UI::ImageWidget* _creditImage = new UI::ImageWidget("CreditImg", RectangleShapeData({ 170.0f, 30.0f }, "PixelTransparent"));
	//const ButtonData& _creditsData = ButtonData([&]() {}, [&]() {}, [&]() 
	//{ 
	//	// TODO
	//	//if (Canvas* _canva = dynamic_cast<Canvas*>(M_HUD.GetCurrentWidget()))
	//	//{
	//	//	_canva->RemoveWidgets();
	//	//	//_canva = M_HUD.CreateWidget<Canvas>("Play Canva");
	//	//	InitCredits(_canva);
	//	//	_canva->UpdateWidgets();
	//	//	ApplyCanva(_canva);
	//	//	M_HUD.SetCurrentWidget(_canva);
	//	//}
	//	//else
	//	//{
	//	//	LOG(Warning, "Dynamic Invalide");
	//	//}
	//}, [&]() {}, [&]() {});
	/*Button* _creditsButton = M_HUD.CreateWidget<Button>(_creditImage, _creditsData, "CreditsButton");
	_creditsButton->SetPosition(Vector2f(_windowSize.x * 0.57, _windowSize.y * 0.8));
	_creditsButton->SetZOrder(3);*/

	

	//////////////////////////
	///		Quit
	//////////////////////////

	LabelWidget* _quit = M_HUD.CreateWidget<LabelWidget>("Quit", Screen, "Daydream", TTF);
	_quit->SetPosition(Vector2f(_windowSize.x * 0.8, _windowSize.y * 0.8));
	_quit->SetCharacterSize(25);
	_quit->SetZOrder(2);

	UI::ImageWidget* _quitImage = new UI::ImageWidget("QuitImg", RectangleShapeData({ 100.0f, 30.0f }, "PixelTransparent"));
	//const ButtonData& _quitData = ButtonData([&]() {}, [&]() {}, [&]() 
	//{ 
	//	//M_GAME.GetCurrent()->IsOver();
	//}, [&]() {}, [&]() {});
	/*Button* _quitButton = M_HUD.CreateWidget<Button>(_quitImage, _quitData, "QuitButton");
	_quitButton->SetPosition(Vector2f(_windowSize.x * 0.8, _windowSize.y * 0.8));
	_quitButton->SetZOrder(3);*/

	/*_canva->AddChild(_playButton);
	_canva->AddChild(_leaderBoardButton);
	_canva->AddChild(_creditsButton);
	_canva->AddChild(_quitButton);*/

	/*_canva->AddChild(_play);
	_canva->AddChild(_leaderBoard);
	_canva->AddChild(_credits);
	_canva->AddChild(_quit);*/

}

void MenuGame::InitStartMenu(CanvasWidget* _canva)
{
	const Vector2f& _windowSize = M_LEVEL.GetCurrentLevel()->GetWindowSize();

	LabelWidget* _solo = M_HUD.CreateWidget<LabelWidget>("SOLO", Screen, "Daydream", TTF);
	_solo->SetPosition(Vector2f(_windowSize.x * 0.2, _windowSize.y * 0.25));
	_solo->SetCharacterSize(40);
	_solo->SetZOrder(3);

	LabelWidget* _coop = M_HUD.CreateWidget<LabelWidget>("COOP", Screen, "Daydream", TTF);
	_coop->SetPosition(Vector2f(_windowSize.x * 0.2, _windowSize.y * 0.5));
	_coop->SetCharacterSize(40);
	_coop->SetZOrder(3);

	LabelWidget* _controls = M_HUD.CreateWidget<LabelWidget>("Controls", Screen, "Daydream", TTF);
	_controls->SetPosition(Vector2f(_windowSize.x * 0.6, _windowSize.y * 0.15));
	_controls->SetCharacterSize(40);
	_controls->SetZOrder(3);

	LabelWidget* _up = M_HUD.CreateWidget<LabelWidget>("(Z) - Accelerate", Screen, "Daydream", TTF);
	_up->SetPosition(Vector2f(_windowSize.x * 0.62, _windowSize.y * 0.3));
	_up->SetCharacterSize(20);
	_up->SetZOrder(3);

	LabelWidget* _left = M_HUD.CreateWidget<LabelWidget>("(Q) - Rotate Left", Screen, "Daydream", TTF);
	_left->SetPosition(Vector2f(_windowSize.x * 0.62, _windowSize.y * 0.4));
	_left->SetCharacterSize(20);
	_left->SetZOrder(3);

	LabelWidget* _right = M_HUD.CreateWidget<LabelWidget>("(D) - Rotate Right", Screen, "Daydream", TTF);
	_right->SetPosition(Vector2f(_windowSize.x * 0.62, _windowSize.y * 0.5));
	_right->SetCharacterSize(20);
	_right->SetZOrder(3);

	LabelWidget* _shoot = M_HUD.CreateWidget<LabelWidget>("(S) - Shoot", Screen, "Daydream", TTF);
	_shoot->SetPosition(Vector2f(_windowSize.x * 0.62, _windowSize.y * 0.6));
	_shoot->SetCharacterSize(20);
	_shoot->SetZOrder(3);


	LabelWidget* _back = M_HUD.CreateWidget<LabelWidget>("Back", Screen, "Daydream", TTF);
	_back->SetPosition(Vector2f(_windowSize.x * 0.05, _windowSize.y * 0.9));
	_back->SetCharacterSize(30);
	_back->SetZOrder(3);

	//UI::ImageWidget* _backImage = new UI::ImageWidget(Vector2f(500.0f, 30.0f), "PixelTransparenta");
	//ButtonData _backData = ButtonData([&]() {}, [&]() {}, [&]()
	//	{
	//		if (Canvas* _canva = dynamic_cast<Canvas*>(M_HUD.GetCurrentWidget()))
	//		{
	//			_canva->RemoveWidgets();
	//			//_canva = M_HUD.CreateWidget<Canvas>("Play Canva");
	//			InitMainMenu(_canva);
	//			_canva->UpdateWidgets();
	//			ApplyCanva(_canva);
	//			M_HUD.SetCurrentWidget(_canva);
	//		}
	//		else
	//		{
	//			LOG(Warning, "Dynamic Invalide");
	//		}
	//	}, [&]() {}, [&]() {});
	//Button* _backButton = M_HUD.CreateWidget<Button>(_backImage, _backData, "CreditsButton");
	//_backButton->SetPosition(Vector2f(_windowSize.x * 0.05, _windowSize.y * 0.9));
	//_backButton->SetZOrder(3);

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

void MenuGame::InitLeaderBoard(CanvasWidget* _canva)
{
	const Vector2f& _windowSize = M_LEVEL.GetCurrentLevel()->GetWindowSize();

	LabelWidget* _leaderBoard = M_HUD.CreateWidget<LabelWidget>("LeaderBoard", Screen, "Daydream", TTF);
	_leaderBoard->SetPosition(Vector2f(_windowSize.x * 0.32, _windowSize.y * 0.1));
	_leaderBoard->SetCharacterSize(40);
	_leaderBoard->SetZOrder(3);

	//TODO CHANGE
	LabelWidget* _score1 = M_HUD.CreateWidget<LabelWidget>("Jean Claude - 000146", Screen, "Daydream", TTF);
	_score1->SetPosition(Vector2f(_windowSize.x * 0.35, _windowSize.y * 0.3));
	_score1->SetCharacterSize(20);
	_score1->SetZOrder(3);

	LabelWidget* _score2 = M_HUD.CreateWidget<LabelWidget>("Marie - 000053", Screen, "Daydream", TTF);
	_score2->SetPosition(Vector2f(_windowSize.x * 0.35, _windowSize.y * 0.4));
	_score2->SetCharacterSize(20);
	_score2->SetZOrder(3);

	LabelWidget* _score3 = M_HUD.CreateWidget<LabelWidget>(" - 000000", Screen, "Daydream", TTF);
	_score3->SetPosition(Vector2f(_windowSize.x * 0.35, _windowSize.y * 0.5));
	_score3->SetCharacterSize(20);
	_score3->SetZOrder(3);

	LabelWidget* _score4 = M_HUD.CreateWidget<LabelWidget>(" - 000000", Screen, "Daydream", TTF);
	_score4->SetPosition(Vector2f(_windowSize.x * 0.35, _windowSize.y * 0.6));
	_score4->SetCharacterSize(20);
	_score4->SetZOrder(3);

	LabelWidget* _score5 = M_HUD.CreateWidget<LabelWidget>(" - 000000", Screen, "Daydream", TTF);
	_score5->SetPosition(Vector2f(_windowSize.x * 0.35, _windowSize.y * 0.7));
	_score5->SetCharacterSize(20);
	_score5->SetZOrder(3);

	LabelWidget* _score6 = M_HUD.CreateWidget<LabelWidget>(" - 000000", Screen, "Daydream", TTF);
	_score6->SetPosition(Vector2f(_windowSize.x * 0.35, _windowSize.y * 0.8));
	_score6->SetCharacterSize(20);
	_score6->SetZOrder(3);


	LabelWidget* _back = M_HUD.CreateWidget<LabelWidget>("Back", Screen, "Daydream", TTF);
	_back->SetPosition(Vector2f(_windowSize.x * 0.05, _windowSize.y * 0.9));
	_back->SetCharacterSize(30);
	_back->SetZOrder(3);

	_canva->AddChild(_leaderBoard);
	_canva->AddChild(_score1);
	_canva->AddChild(_score2);
	_canva->AddChild(_score3);
	_canva->AddChild(_score4);
	_canva->AddChild(_score5);
	_canva->AddChild(_score6);
	_canva->AddChild(_back);
}

void MenuGame::InitCredits(CanvasWidget* _canva)
{
	const Vector2f& _windowSize = M_LEVEL.GetCurrentLevel()->GetWindowSize();

	LabelWidget* _credits = M_HUD.CreateWidget<LabelWidget>("Credits", Screen, "Daydream", TTF);
	_credits->SetPosition(Vector2f(_windowSize.x * 0.38, _windowSize.y * 0.1));
	_credits->SetCharacterSize(40);
	_credits->SetZOrder(3);

	//TODO Add People
	LabelWidget* _sacha = M_HUD.CreateWidget<LabelWidget>("Sacha - Lead", Screen, "Daydream", TTF);
	_sacha->SetPosition(Vector2f(_windowSize.x * 0.33, _windowSize.y * 0.3));
	_sacha->SetCharacterSize(20);
	_sacha->SetZOrder(3);

	LabelWidget* _alexandre = M_HUD.CreateWidget<LabelWidget>("Alexandre - Demarrage du Projet & Collisions", Screen, "Daydream", TTF);
	_alexandre->SetPosition(Vector2f(_windowSize.x * 0.33, _windowSize.y * 0.4));
	_alexandre->SetCharacterSize(20);
	_alexandre->SetZOrder(3);

	LabelWidget* _yoan = M_HUD.CreateWidget<LabelWidget>("Yoan - Shape & Convex", Screen, "Daydream", TTF);
	_yoan->SetPosition(Vector2f(_windowSize.x * 0.33, _windowSize.y * 0.5));
	_yoan->SetCharacterSize(20);
	_yoan->SetZOrder(3);

	LabelWidget* _sev = M_HUD.CreateWidget<LabelWidget>("Sev - Asteroides & Animations", Screen, "Daydream", TTF);
	_sev->SetPosition(Vector2f(_windowSize.x * 0.33, _windowSize.y * 0.6));
	_sev->SetCharacterSize(20);
	_sev->SetZOrder(3);

	LabelWidget* _romain = M_HUD.CreateWidget<LabelWidget>("Romain - UFOs", Screen, "Daydream", TTF);
	_romain->SetPosition(Vector2f(_windowSize.x * 0.33, _windowSize.y * 0.7));
	_romain->SetCharacterSize(20);
	_romain->SetZOrder(3);

	LabelWidget* _quentin = M_HUD.CreateWidget<LabelWidget>("Quentin - Menus", Screen, "Daydream", TTF);
	_quentin->SetPosition(Vector2f(_windowSize.x * 0.33, _windowSize.y * 0.8));
	_quentin->SetCharacterSize(20);
	_quentin->SetZOrder(3);

	LabelWidget* _back = M_HUD.CreateWidget<LabelWidget>("Back", Screen, "Daydream", TTF);
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

void MenuGame::Reset()
{
	canva->BeginDestroy();
}

void MenuGame::ApplyCanva(CanvasWidget* _canva)
{
	M_HUD.AddToViewport(_canva);
}
