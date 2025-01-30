#include "MenuGame.h"
#include "HUD.h"
#include "Level.h"
#include "CameraManager.h"
#include "GameManager.h"

#include "MeshActor.h"
#include "Label.h"

using namespace Camera;

MenuGame::MenuGame() : Game()
{
	allCanvas =
	{
		M_HUD.CreateWidget<Canvas>("Main Menu"),
		M_HUD.CreateWidget<Canvas>("Start Menu"),
		M_HUD.CreateWidget<Canvas>("LeaderBoard Menu"),
		M_HUD.CreateWidget<Canvas>("Credits Menu"),
	};

	windowSize = Vector2f();
}

void MenuGame::Start()
{
	Super::Start();
	windowSize = CAST(Vector2f, M_GAME.GetCurrent()->GetWindowSize());

	MeshActor* _background = Level::SpawnActor(MeshActor(RectangleShapeData(windowSize, "Sky", PNG)));
	_background->SetFillColor(Color(255, 255, 255, 100));

	InitMainMenu();
	InitStartMenu();
	InitLeaderBoard();
	InitCredits();

	Canvas* _currentCanvas = allCanvas[3];
	_currentCanvas->UpdateWidgets();
	M_HUD.AddToViewport(_currentCanvas);
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

void MenuGame::InitMainMenu()
{
	Label* _title = M_HUD.CreateWidget<Label>("ASTEROID", Screen, "Daydream", TTF);
	_title->SetPosition(Vector2f(windowSize.x * 0.33, windowSize.y * 0.2));
	_title->SetCharacterSize(50);
	_title->SetZOrder(1);

	Label* _play = M_HUD.CreateWidget<Label>("Play", Screen, "Daydream", TTF);
	_play->SetPosition(Vector2f(windowSize.x * 0.2, windowSize.y * 0.8));
	_play->SetCharacterSize(25);
	_play->SetZOrder(2);

	Label* _leaderBoard = M_HUD.CreateWidget<Label>("LeaderBoard", Screen, "Daydream", TTF);
	_leaderBoard->SetPosition(Vector2f(windowSize.x * 0.3, windowSize.y * 0.8));
	_leaderBoard->SetCharacterSize(25);
	_leaderBoard->SetZOrder(2);

	Label* _credits = M_HUD.CreateWidget<Label>("Credits", Screen, "Daydream", TTF);
	_credits->SetPosition(Vector2f(windowSize.x * 0.55, windowSize.y * 0.8));
	_credits->SetCharacterSize(25);
	_credits->SetZOrder(2);

	Label* _quit = M_HUD.CreateWidget<Label>("Quit", Screen, "Daydream", TTF);
	_quit->SetPosition(Vector2f(windowSize.x * 0.7, windowSize.y * 0.8));
	_quit->SetCharacterSize(25);
	_quit->SetZOrder(2);


	allCanvas[0]->AddWidget(_title);
	allCanvas[0]->AddWidget(_play);
	allCanvas[0]->AddWidget(_leaderBoard);
	allCanvas[0]->AddWidget(_credits);
	allCanvas[0]->AddWidget(_quit);
}

void MenuGame::InitStartMenu()
{
	Label* _solo = M_HUD.CreateWidget<Label>("SOLO", Screen, "Daydream", TTF);
	_solo->SetPosition(Vector2f(windowSize.x * 0.2, windowSize.y * 0.25));
	_solo->SetCharacterSize(40);
	_solo->SetZOrder(3);

	Label* _coop = M_HUD.CreateWidget<Label>("COOP", Screen, "Daydream", TTF);
	_coop->SetPosition(Vector2f(windowSize.x * 0.2, windowSize.y * 0.5));
	_coop->SetCharacterSize(40);
	_coop->SetZOrder(3);

	Label* _controls = M_HUD.CreateWidget<Label>("Controls", Screen, "Daydream", TTF);
	_controls->SetPosition(Vector2f(windowSize.x * 0.6, windowSize.y * 0.15));
	_controls->SetCharacterSize(40);
	_controls->SetZOrder(3);

	Label* _up = M_HUD.CreateWidget<Label>("(Z) - Accelerate", Screen, "Daydream", TTF);
	_up->SetPosition(Vector2f(windowSize.x * 0.62, windowSize.y * 0.3));
	_up->SetCharacterSize(20);
	_up->SetZOrder(3);

	Label* _left = M_HUD.CreateWidget<Label>("(Q) - Rotate Left", Screen, "Daydream", TTF);
	_left->SetPosition(Vector2f(windowSize.x * 0.62, windowSize.y * 0.4));
	_left->SetCharacterSize(20);
	_left->SetZOrder(3);

	Label* _right = M_HUD.CreateWidget<Label>("(D) - Rotate Right", Screen, "Daydream", TTF);
	_right->SetPosition(Vector2f(windowSize.x * 0.62, windowSize.y * 0.5));
	_right->SetCharacterSize(20);
	_right->SetZOrder(3);

	Label* _shoot = M_HUD.CreateWidget<Label>("(S) - Shoot", Screen, "Daydream", TTF);
	_shoot->SetPosition(Vector2f(windowSize.x * 0.62, windowSize.y * 0.6));
	_shoot->SetCharacterSize(20);
	_shoot->SetZOrder(3);


	Label* _back = M_HUD.CreateWidget<Label>("Back", Screen, "Daydream", TTF);
	_back->SetPosition(Vector2f(windowSize.x * 0.05, windowSize.y * 0.9));
	_back->SetCharacterSize(30);
	_back->SetZOrder(3);

	allCanvas[1]->AddWidget(_solo);
	allCanvas[1]->AddWidget(_coop);
	allCanvas[1]->AddWidget(_controls);
	allCanvas[1]->AddWidget(_up);
	allCanvas[1]->AddWidget(_left);
	allCanvas[1]->AddWidget(_right);
	allCanvas[1]->AddWidget(_shoot);
	allCanvas[1]->AddWidget(_back);
}

void MenuGame::InitLeaderBoard()
{
	Label* _leaderBoard = M_HUD.CreateWidget<Label>("LeaderBoard", Screen, "Daydream", TTF);
	_leaderBoard->SetPosition(Vector2f(windowSize.x * 0.32, windowSize.y * 0.1));
	_leaderBoard->SetCharacterSize(40);
	_leaderBoard->SetZOrder(3);

	//TODO CHANGE
	Label* _score1 = M_HUD.CreateWidget<Label>("Jean Claude - 000146", Screen, "Daydream", TTF);
	_score1->SetPosition(Vector2f(windowSize.x * 0.35, windowSize.y * 0.3));
	_score1->SetCharacterSize(20);
	_score1->SetZOrder(3);

	Label* _score2 = M_HUD.CreateWidget<Label>("Marie - 000053", Screen, "Daydream", TTF);
	_score2->SetPosition(Vector2f(windowSize.x * 0.35, windowSize.y * 0.4));
	_score2->SetCharacterSize(20);
	_score2->SetZOrder(3);

	Label* _score3 = M_HUD.CreateWidget<Label>(" - 000000", Screen, "Daydream", TTF);
	_score3->SetPosition(Vector2f(windowSize.x * 0.35, windowSize.y * 0.5));
	_score3->SetCharacterSize(20);
	_score3->SetZOrder(3);

	Label* _score4 = M_HUD.CreateWidget<Label>(" - 000000", Screen, "Daydream", TTF);
	_score4->SetPosition(Vector2f(windowSize.x * 0.35, windowSize.y * 0.6));
	_score4->SetCharacterSize(20);
	_score4->SetZOrder(3);

	Label* _score5 = M_HUD.CreateWidget<Label>(" - 000000", Screen, "Daydream", TTF);
	_score5->SetPosition(Vector2f(windowSize.x * 0.35, windowSize.y * 0.7));
	_score5->SetCharacterSize(20);
	_score5->SetZOrder(3);

	Label* _score6 = M_HUD.CreateWidget<Label>(" - 000000", Screen, "Daydream", TTF);
	_score6->SetPosition(Vector2f(windowSize.x * 0.35, windowSize.y * 0.8));
	_score6->SetCharacterSize(20);
	_score6->SetZOrder(3);


	Label* _back = M_HUD.CreateWidget<Label>("Back", Screen, "Daydream", TTF);
	_back->SetPosition(Vector2f(windowSize.x * 0.05, windowSize.y * 0.9));
	_back->SetCharacterSize(30);
	_back->SetZOrder(3);

	allCanvas[2]->AddWidget(_leaderBoard);
	allCanvas[2]->AddWidget(_score1);
	allCanvas[2]->AddWidget(_score2);
	allCanvas[2]->AddWidget(_score3);
	allCanvas[2]->AddWidget(_score4);
	allCanvas[2]->AddWidget(_score5);
	allCanvas[2]->AddWidget(_score6);
	allCanvas[2]->AddWidget(_back);
}

void MenuGame::InitCredits()
{
	Label* _credits = M_HUD.CreateWidget<Label>("Credits", Screen, "Daydream", TTF);
	_credits->SetPosition(Vector2f(windowSize.x * 0.38, windowSize.y * 0.1));
	_credits->SetCharacterSize(40);
	_credits->SetZOrder(3);

	//TODO Add People
	Label* _sacha = M_HUD.CreateWidget<Label>("Sasha - Leader (le goat)", Screen, "Daydream", TTF);
	_sacha->SetPosition(Vector2f(windowSize.x * 0.33, windowSize.y * 0.3));
	_sacha->SetCharacterSize(20);
	_sacha->SetZOrder(3);

	Label* _etc = M_HUD.CreateWidget<Label>("...", Screen, "Daydream", TTF);
	_etc->SetPosition(Vector2f(windowSize.x * 0.48, windowSize.y * 0.4));
	_etc->SetCharacterSize(20);
	_etc->SetZOrder(3);


	Label* _back = M_HUD.CreateWidget<Label>("Back", Screen, "Daydream", TTF);
	_back->SetPosition(Vector2f(windowSize.x * 0.05, windowSize.y * 0.9));
	_back->SetCharacterSize(30);
	_back->SetZOrder(3);

	allCanvas[3]->AddWidget(_credits);
	allCanvas[3]->AddWidget(_sacha);
	allCanvas[3]->AddWidget(_etc);
	allCanvas[3]->AddWidget(_back);
}
