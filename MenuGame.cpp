#include "MenuGame.h"
#include "HUD.h"
#include "Level.h"
#include "CameraManager.h"
#include "GameManager.h"

#include "MeshActor.h"
#include "Label.h"
#include "Button.h"
#include "Image.h"
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
	const Vector2f& _windowSize = CAST(Vector2f, M_GAME.GetCurrent()->GetWindowSize());

	MeshActor* _background = Level::SpawnActor(MeshActor(RectangleShapeData(_windowSize, "Sky", PNG)));
	_background->SetFillColor(Color(255, 255, 255, 100));

	M_AUDIO.PlaySample<MusicSample>("MainMenu");

	canva = M_HUD.CreateWidget<Canvas>("Main Menu");
	InitMainMenu(canva);
	ApplyCanva(canva);
	M_HUD.SetCurrentWidget(canva);
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

void MenuGame::InitMainMenu(Canvas* _canva)
{
	const Vector2f& _windowSize = CAST(Vector2f, M_GAME.GetCurrent()->GetWindowSize());

	Label* _title = M_HUD.CreateWidget<Label>("ASTEROID", Screen, "Daydream", TTF);
	_title->SetPosition(Vector2f(_windowSize.x * 0.33, _windowSize.y * 0.2));
	_title->SetCharacterSize(75);
	_title->SetZOrder(1);

	_canva->AddWidget(_title);

	//////////////////////////
	///		Play
	//////////////////////////

	Label* _play = M_HUD.CreateWidget<Label>("Play", Screen, "Daydream", TTF);
	_play->SetPosition(Vector2f(_windowSize.x * 0.15, _windowSize.y * 0.8));
	_play->SetCharacterSize(25);
	_play->SetZOrder(2);

	UI::Image* _playImage = new UI::Image(Vector2f(100.0f, 30.0f), "PixelTransparent");
	const ButtonData& _playData = ButtonData([&]() {}, [&]() {}, [&]() 
	{ 
		if (Canvas* _canva = dynamic_cast<Canvas*>(M_HUD.GetCurrentWidget()))
		{
			_canva->RemoveWidgets();
			M_GAME.GetCurrent()->LaunchGame();
			//_canva = M_HUD.CreateWidget<Canvas>("Play Canva");
			/*InitStartMenu(_canva);
			_canva->UpdateWidgets();
			ApplyCanva(_canva);
			M_HUD.SetCurrentWidget(_canva);*/
		}
		else
		{
			LOG(Warning, "Dynamic Invalide");
		}
		
	}, [&]() {}, [&]() {});
	Button* _playButton = M_HUD.CreateWidget<Button>(_playImage, _playData, "PlayButton");
	_playButton->SetPosition(Vector2f(_windowSize.x * 0.15, _windowSize.y * 0.8));
	_playButton->SetZOrder(3);
	

	//////////////////////////
	///		LeaderBoard
	//////////////////////////

	Label* _leaderBoard = M_HUD.CreateWidget<Label>("LeaderBoard", Screen, "Daydream", TTF);
	_leaderBoard->SetPosition(Vector2f(_windowSize.x * 0.3, _windowSize.y * 0.8));
	_leaderBoard->SetCharacterSize(25);
	_leaderBoard->SetZOrder(2);

	UI::Image* _leaderBoardImage = new UI::Image(Vector2f(300.0f, 30.0f), "PixelTransparent");
	const ButtonData& _leaderBoardData = ButtonData([&]() {}, [&]() {}, [&]() 
	{ 
		if (Canvas* _canva = dynamic_cast<Canvas*>(M_HUD.GetCurrentWidget()))
		{
			_canva->RemoveWidgets();
			//_canva = M_HUD.CreateWidget<Canvas>("Play Canva");
			InitLeaderBoard(_canva);
			_canva->UpdateWidgets();
			ApplyCanva(_canva);
			M_HUD.SetCurrentWidget(_canva);
		}
		else
		{
			LOG(Warning, "Dynamic Invalide");
		}
	}, [&]() {}, [&]() {});
	Button* _leaderBoardButton = M_HUD.CreateWidget<Button>(_leaderBoardImage, _leaderBoardData, "LeaderBoardButton");
	_leaderBoardButton->SetPosition(Vector2f(_windowSize.x * 0.3, _windowSize.y * 0.8));
	_leaderBoardButton->SetZOrder(3);
	
	//////////////////////////
	///		Credits
	//////////////////////////

	Label* _credits = M_HUD.CreateWidget<Label>("Credits", Screen, "Daydream", TTF);
	_credits->SetPosition(Vector2f(_windowSize.x * 0.57, _windowSize.y * 0.8));
	_credits->SetCharacterSize(25);
	_credits->SetZOrder(2);

	UI::Image* _creditImage = new UI::Image(Vector2f(170.0f, 30.0f), "PixelTransparent");
	const ButtonData& _creditsData = ButtonData([&]() {}, [&]() {}, [&]() 
	{ 
		if (Canvas* _canva = dynamic_cast<Canvas*>(M_HUD.GetCurrentWidget()))
		{
			_canva->RemoveWidgets();
			//_canva = M_HUD.CreateWidget<Canvas>("Play Canva");
			InitCredits(_canva);
			_canva->UpdateWidgets();
			ApplyCanva(_canva);
			M_HUD.SetCurrentWidget(_canva);
		}
		else
		{
			LOG(Warning, "Dynamic Invalide");
		}
	}, [&]() {}, [&]() {});
	Button* _creditsButton = M_HUD.CreateWidget<Button>(_creditImage, _creditsData, "CreditsButton");
	_creditsButton->SetPosition(Vector2f(_windowSize.x * 0.57, _windowSize.y * 0.8));
	_creditsButton->SetZOrder(3);

	

	//////////////////////////
	///		Quit
	//////////////////////////

	Label* _quit = M_HUD.CreateWidget<Label>("Quit", Screen, "Daydream", TTF);
	_quit->SetPosition(Vector2f(_windowSize.x * 0.8, _windowSize.y * 0.8));
	_quit->SetCharacterSize(25);
	_quit->SetZOrder(2);

	UI::Image* _quitImage = new UI::Image(Vector2f(100.0f, 30.0f), "PixelTransparent");
	const ButtonData& _quitData = ButtonData([&]() {}, [&]() {}, [&]() 
	{ 
		M_GAME.GetCurrent()->IsOver();
	}, [&]() {}, [&]() {});
	Button* _quitButton = M_HUD.CreateWidget<Button>(_quitImage, _quitData, "QuitButton");
	_quitButton->SetPosition(Vector2f(_windowSize.x * 0.8, _windowSize.y * 0.8));
	_quitButton->SetZOrder(3);

	_canva->AddWidget(_playButton);
	_canva->AddWidget(_leaderBoardButton);
	_canva->AddWidget(_creditsButton);
	_canva->AddWidget(_quitButton);

	_canva->AddWidget(_play);
	_canva->AddWidget(_leaderBoard);
	_canva->AddWidget(_credits);
	_canva->AddWidget(_quit);

}

void MenuGame::InitStartMenu(Canvas* _canva)
{
	const Vector2f& _windowSize = CAST(Vector2f, M_GAME.GetCurrent()->GetWindowSize());

	Label* _solo = M_HUD.CreateWidget<Label>("SOLO", Screen, "Daydream", TTF);
	_solo->SetPosition(Vector2f(_windowSize.x * 0.2, _windowSize.y * 0.25));
	_solo->SetCharacterSize(40);
	_solo->SetZOrder(3);

	Label* _coop = M_HUD.CreateWidget<Label>("COOP", Screen, "Daydream", TTF);
	_coop->SetPosition(Vector2f(_windowSize.x * 0.2, _windowSize.y * 0.5));
	_coop->SetCharacterSize(40);
	_coop->SetZOrder(3);

	Label* _controls = M_HUD.CreateWidget<Label>("Controls", Screen, "Daydream", TTF);
	_controls->SetPosition(Vector2f(_windowSize.x * 0.6, _windowSize.y * 0.15));
	_controls->SetCharacterSize(40);
	_controls->SetZOrder(3);

	Label* _up = M_HUD.CreateWidget<Label>("(Z) - Accelerate", Screen, "Daydream", TTF);
	_up->SetPosition(Vector2f(_windowSize.x * 0.62, _windowSize.y * 0.3));
	_up->SetCharacterSize(20);
	_up->SetZOrder(3);

	Label* _left = M_HUD.CreateWidget<Label>("(Q) - Rotate Left", Screen, "Daydream", TTF);
	_left->SetPosition(Vector2f(_windowSize.x * 0.62, _windowSize.y * 0.4));
	_left->SetCharacterSize(20);
	_left->SetZOrder(3);

	Label* _right = M_HUD.CreateWidget<Label>("(D) - Rotate Right", Screen, "Daydream", TTF);
	_right->SetPosition(Vector2f(_windowSize.x * 0.62, _windowSize.y * 0.5));
	_right->SetCharacterSize(20);
	_right->SetZOrder(3);

	Label* _shoot = M_HUD.CreateWidget<Label>("(S) - Shoot", Screen, "Daydream", TTF);
	_shoot->SetPosition(Vector2f(_windowSize.x * 0.62, _windowSize.y * 0.6));
	_shoot->SetCharacterSize(20);
	_shoot->SetZOrder(3);


	Label* _back = M_HUD.CreateWidget<Label>("Back", Screen, "Daydream", TTF);
	_back->SetPosition(Vector2f(_windowSize.x * 0.05, _windowSize.y * 0.9));
	_back->SetCharacterSize(30);
	_back->SetZOrder(3);

	//UI::Image* _backImage = new UI::Image(Vector2f(500.0f, 30.0f), "PixelTransparenta");
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

	//_canva->AddWidget(_backButton);

	_canva->AddWidget(_solo);
	_canva->AddWidget(_coop);
	_canva->AddWidget(_controls);
	_canva->AddWidget(_up);
	_canva->AddWidget(_left);
	_canva->AddWidget(_right);
	_canva->AddWidget(_shoot);
	_canva->AddWidget(_back);
}

void MenuGame::InitLeaderBoard(Canvas* _canva)
{
	const Vector2f& _windowSize = CAST(Vector2f, M_GAME.GetCurrent()->GetWindowSize());

	Label* _leaderBoard = M_HUD.CreateWidget<Label>("LeaderBoard", Screen, "Daydream", TTF);
	_leaderBoard->SetPosition(Vector2f(_windowSize.x * 0.32, _windowSize.y * 0.1));
	_leaderBoard->SetCharacterSize(40);
	_leaderBoard->SetZOrder(3);

	//TODO CHANGE
	Label* _score1 = M_HUD.CreateWidget<Label>("Jean Claude - 000146", Screen, "Daydream", TTF);
	_score1->SetPosition(Vector2f(_windowSize.x * 0.35, _windowSize.y * 0.3));
	_score1->SetCharacterSize(20);
	_score1->SetZOrder(3);

	Label* _score2 = M_HUD.CreateWidget<Label>("Marie - 000053", Screen, "Daydream", TTF);
	_score2->SetPosition(Vector2f(_windowSize.x * 0.35, _windowSize.y * 0.4));
	_score2->SetCharacterSize(20);
	_score2->SetZOrder(3);

	Label* _score3 = M_HUD.CreateWidget<Label>(" - 000000", Screen, "Daydream", TTF);
	_score3->SetPosition(Vector2f(_windowSize.x * 0.35, _windowSize.y * 0.5));
	_score3->SetCharacterSize(20);
	_score3->SetZOrder(3);

	Label* _score4 = M_HUD.CreateWidget<Label>(" - 000000", Screen, "Daydream", TTF);
	_score4->SetPosition(Vector2f(_windowSize.x * 0.35, _windowSize.y * 0.6));
	_score4->SetCharacterSize(20);
	_score4->SetZOrder(3);

	Label* _score5 = M_HUD.CreateWidget<Label>(" - 000000", Screen, "Daydream", TTF);
	_score5->SetPosition(Vector2f(_windowSize.x * 0.35, _windowSize.y * 0.7));
	_score5->SetCharacterSize(20);
	_score5->SetZOrder(3);

	Label* _score6 = M_HUD.CreateWidget<Label>(" - 000000", Screen, "Daydream", TTF);
	_score6->SetPosition(Vector2f(_windowSize.x * 0.35, _windowSize.y * 0.8));
	_score6->SetCharacterSize(20);
	_score6->SetZOrder(3);


	Label* _back = M_HUD.CreateWidget<Label>("Back", Screen, "Daydream", TTF);
	_back->SetPosition(Vector2f(_windowSize.x * 0.05, _windowSize.y * 0.9));
	_back->SetCharacterSize(30);
	_back->SetZOrder(3);

	_canva->AddWidget(_leaderBoard);
	_canva->AddWidget(_score1);
	_canva->AddWidget(_score2);
	_canva->AddWidget(_score3);
	_canva->AddWidget(_score4);
	_canva->AddWidget(_score5);
	_canva->AddWidget(_score6);
	_canva->AddWidget(_back);
}

void MenuGame::InitCredits(Canvas* _canva)
{
	const Vector2f& _windowSize = CAST(Vector2f, M_GAME.GetCurrent()->GetWindowSize());

	Label* _credits = M_HUD.CreateWidget<Label>("Credits", Screen, "Daydream", TTF);
	_credits->SetPosition(Vector2f(_windowSize.x * 0.38, _windowSize.y * 0.1));
	_credits->SetCharacterSize(40);
	_credits->SetZOrder(3);

	//TODO Add People
	Label* _sacha = M_HUD.CreateWidget<Label>("Sacha - Lead", Screen, "Daydream", TTF);
	_sacha->SetPosition(Vector2f(_windowSize.x * 0.33, _windowSize.y * 0.3));
	_sacha->SetCharacterSize(20);
	_sacha->SetZOrder(3);

	Label* _alexandre = M_HUD.CreateWidget<Label>("Alexandre - Demarrage du Projet & Collisions", Screen, "Daydream", TTF);
	_alexandre->SetPosition(Vector2f(_windowSize.x * 0.33, _windowSize.y * 0.4));
	_alexandre->SetCharacterSize(20);
	_alexandre->SetZOrder(3);

	Label* _yoan = M_HUD.CreateWidget<Label>("Yoan - Shape & Convex", Screen, "Daydream", TTF);
	_yoan->SetPosition(Vector2f(_windowSize.x * 0.33, _windowSize.y * 0.5));
	_yoan->SetCharacterSize(20);
	_yoan->SetZOrder(3);

	Label* _sev = M_HUD.CreateWidget<Label>("Sev - Asteroides & Animations", Screen, "Daydream", TTF);
	_sev->SetPosition(Vector2f(_windowSize.x * 0.33, _windowSize.y * 0.6));
	_sev->SetCharacterSize(20);
	_sev->SetZOrder(3);

	Label* _romain = M_HUD.CreateWidget<Label>("Romain - UFOs", Screen, "Daydream", TTF);
	_romain->SetPosition(Vector2f(_windowSize.x * 0.33, _windowSize.y * 0.7));
	_romain->SetCharacterSize(20);
	_romain->SetZOrder(3);

	Label* _quentin = M_HUD.CreateWidget<Label>("Quentin - Menus", Screen, "Daydream", TTF);
	_quentin->SetPosition(Vector2f(_windowSize.x * 0.33, _windowSize.y * 0.8));
	_quentin->SetCharacterSize(20);
	_quentin->SetZOrder(3);

	Label* _back = M_HUD.CreateWidget<Label>("Back", Screen, "Daydream", TTF);
	_back->SetPosition(Vector2f(_windowSize.x * 0.05, _windowSize.y * 0.9));
	_back->SetCharacterSize(30);
	_back->SetZOrder(3);

	_canva->AddWidget(_credits);
	_canva->AddWidget(_sacha);
	_canva->AddWidget(_alexandre);
	_canva->AddWidget(_yoan);
	_canva->AddWidget(_sev);
	_canva->AddWidget(_romain);
	_canva->AddWidget(_quentin);
	_canva->AddWidget(_back);
}

void MenuGame::Reset()
{
	canva->BeginDestroy();
}

void MenuGame::ApplyCanva(Canvas* _canva)
{
	M_HUD.AddToViewport(_canva);
}
