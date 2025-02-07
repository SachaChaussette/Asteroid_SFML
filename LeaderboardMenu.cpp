#include "LeaderboardMenu.h"
#include "ImageWidget.h"
#include "LabelWidget.h"
#include "ButtonWidget.h"
#include "HUD.h"
#include "LevelManager.h"

using namespace Camera;
using namespace UI;

LeaderboardMenu::LeaderboardMenu() : Menu("MainMenu Level")
{
	canva = nullptr;
}

LeaderboardMenu::LeaderboardMenu(const LeaderboardMenu& _other) : Menu("MainMenu Level")
{
	canva = _other.canva;
}

void LeaderboardMenu::InitLevel()
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

void LeaderboardMenu::InitLeaderBoard(CanvasWidget* _canva)
{
	const Vector2f& _windowSize = M_LEVEL.GetCurrentLevel()->GetWindowSize();

	LabelWidget* _leaderBoard = M_LEVEL.GetCurrentLevel()->SpawnWidget<LabelWidget>("LeaderBoard", "Leaderboard", Screen);
	_leaderBoard->SetFont("Daydream", TTF);
	_leaderBoard->SetPosition(Vector2f(_windowSize.x * 0.32, _windowSize.y * 0.1));
	_leaderBoard->SetCharacterSize(40);
	_leaderBoard->SetZOrder(3);

	// TODO CHANGE
	LabelWidget* _score1 = M_LEVEL.GetCurrentLevel()->SpawnWidget<LabelWidget>("Jean Claude - 000146", "Score1", Screen);
	_leaderBoard->SetFont("Daydream", TTF);
	_score1->SetPosition(Vector2f(_windowSize.x * 0.35, _windowSize.y * 0.3));
	_score1->SetCharacterSize(20);
	_score1->SetZOrder(3);

	LabelWidget* _score2 = M_LEVEL.GetCurrentLevel()->SpawnWidget<LabelWidget>("Marie - 000053", "Score2", Screen);
	_score2->SetFont("Daydream", TTF);
	_score2->SetPosition(Vector2f(_windowSize.x * 0.35, _windowSize.y * 0.4));
	_score2->SetCharacterSize(20);
	_score2->SetZOrder(3);

	LabelWidget* _score3 = M_LEVEL.GetCurrentLevel()->SpawnWidget<LabelWidget>(" - 000000", "Score3", Screen);
	_score3->SetFont("Daydream", TTF);
	_score3->SetPosition(Vector2f(_windowSize.x * 0.35, _windowSize.y * 0.5));
	_score3->SetCharacterSize(20);
	_score3->SetZOrder(3);

	LabelWidget* _score4 = M_LEVEL.GetCurrentLevel()->SpawnWidget<LabelWidget>(" - 000000", "Score4", Screen);
	_score4->SetFont("Daydream", TTF);
	_score4->SetPosition(Vector2f(_windowSize.x * 0.35, _windowSize.y * 0.6));
	_score4->SetCharacterSize(20);
	_score4->SetZOrder(3);

	LabelWidget* _score5 = M_LEVEL.GetCurrentLevel()->SpawnWidget<LabelWidget>(" - 000000", "Score5", Screen);
	_score5->SetFont("Daydream", TTF);
	_score5->SetPosition(Vector2f(_windowSize.x * 0.35, _windowSize.y * 0.7));
	_score5->SetCharacterSize(20);
	_score5->SetZOrder(3);

	LabelWidget* _score6 = M_LEVEL.GetCurrentLevel()->SpawnWidget<LabelWidget>(" - 000000", "Score6", Screen);
	_score6->SetFont("Daydream", TTF);
	_score6->SetPosition(Vector2f(_windowSize.x * 0.35, _windowSize.y * 0.8));
	_score6->SetCharacterSize(20);
	_score6->SetZOrder(3);


	LabelWidget* _back = M_LEVEL.GetCurrentLevel()->SpawnWidget<LabelWidget>("Back", "Back", Screen);
	_back->SetFont("Daydream", TTF);
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

void LeaderboardMenu::Reset()
{
	canva->BeginDestroy();
}
