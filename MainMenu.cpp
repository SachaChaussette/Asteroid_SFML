#include "MainMenu.h"
#include "ImageWidget.h"
#include "LabelWidget.h"
#include "ButtonWidget.h"
#include "HUD.h"
#include "LevelManager.h"

using namespace Camera;
using namespace UI;

MainMenu::MainMenu() : Menu("MainMenu Level")
{
	canva = nullptr;
}

MainMenu::MainMenu(const MainMenu& _other) : Menu("MainMenu Level")
{
	canva = _other.canva;
}

void MainMenu::InitLevel()
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

void MainMenu::InitMainMenu(CanvasWidget* _canva)
{
	const Vector2f& _windowSize = M_LEVEL.GetCurrentLevel()->GetWindowSize();

	LabelWidget* _title = GetGameMode()->GetHUD()->SpawnWidget<LabelWidget>("ASTEROID", Screen, "Daydream", TTF);
	_title->SetPosition(Vector2f(_windowSize.x * 0.33, _windowSize.y * 0.2));
	_title->SetCharacterSize(75);
	_title->SetZOrder(1);

	_canva->AddChild(_title);

	////////////////////////
	//		Play
	////////////////////////

	LabelWidget* _play = GetGameMode()->GetHUD()->SpawnWidget<LabelWidget>("Play", Screen, "Daydream", TTF);
	_play->SetPosition(Vector2f(_windowSize.x * 0.15, _windowSize.y * 0.8));
	_play->SetCharacterSize(25);
	_play->SetZOrder(2);

	UI::ImageWidget* _playImage = new UI::ImageWidget("PlayImg", RectangleShapeData({ 100.0f, 30.0f }, "PixelTransparent"));
	//const ButtonData& _playData = ButtonData([&]() {}, [&]() {}, [&]() 
	//{ 
	//	// TODO
	//	//if (Canvas* _canva = dynamic_cast<Canvas*>(GetGameMode()->GetHUD()->GetCurrentWidget()))
	//	//{
	//	//	_canva->Destroy();
	//	//	_canva->RemoveWidgets();
	//	//	M_LEVEL.GetCurrentLevel()->LaunchGame();
	//	//	//_canva = GetGameMode()->GetHUD()->SpawnWidget<Canvas>("Play Canva");
	//	//	/*InitStartMenu(_canva);
	//	//	_canva->UpdateWidgets();
	//	//	ApplyCanva(_canva);
	//	//	GetGameMode()->GetHUD()->SetCurrentWidget(_canva);*/
	//	//}
	//	//else
	//	//{
	//	//	LOG(Warning, "Dynamic Invalide");
	//	//}
	//	
	//}, [&]() {}, [&]() {});
	/*Button* _playButton = GetGameMode()->GetHUD()->SpawnWidget<Button>(_playImage, _playData, "PlayButton");
	_playButton->SetPosition(Vector2f(_windowSize.x * 0.15, _windowSize.y * 0.8));
	_playButton->SetZOrder(3);
	*/

	////////////////////////
	//		LeaderBoard
	////////////////////////

	LabelWidget* _leaderBoard = GetGameMode()->GetHUD()->SpawnWidget<LabelWidget>("LeaderBoard", Screen, "Daydream", TTF);
	_leaderBoard->SetPosition(Vector2f(_windowSize.x * 0.3, _windowSize.y * 0.8));
	_leaderBoard->SetCharacterSize(25);
	_leaderBoard->SetZOrder(2);

	UI::ImageWidget* _leaderBoardImage = new UI::ImageWidget("LeaderboardImg", RectangleShapeData({ 300.0f, 30.0f }, "PixelTransparent"));
	//const ButtonData& _leaderBoardData = ButtonData([&]() {}, [&]() {}, [&]() 
	//{ 
	//	// TODO
	//	//if (Canvas* _canva = dynamic_cast<Canvas*>(GetGameMode()->GetHUD()->GetCurrentWidget()))
	//	//{
	//	//	_canva->RemoveWidgets();
	//	//	//_canva = GetGameMode()->GetHUD()->SpawnWidget<Canvas>("Play Canva");
	//	//	InitLeaderBoard(_canva);
	//	//	_canva->UpdateWidgets();
	//	//	ApplyCanva(_canva);
	//	//	GetGameMode()->GetHUD()->SetCurrentWidget(_canva);
	//	//}
	//	//else
	//	//{
	//	//	LOG(Warning, "Dynamic Invalide");
	//	//}
	//}, [&]() {}, [&]() {});
	/*Button* _leaderBoardButton = GetGameMode()->GetHUD()->SpawnWidget<Button>(_leaderBoardImage, _leaderBoardData, "LeaderBoardButton");
	_leaderBoardButton->SetPosition(Vector2f(_windowSize.x * 0.3, _windowSize.y * 0.8));
	_leaderBoardButton->SetZOrder(3);*/
	
	////////////////////////
	//		Credits
	////////////////////////

	LabelWidget* _credits = GetGameMode()->GetHUD()->SpawnWidget<LabelWidget>("Credits", Screen, "Daydream", TTF);
	_credits->SetPosition(Vector2f(_windowSize.x * 0.57, _windowSize.y * 0.8));
	_credits->SetCharacterSize(25);
	_credits->SetZOrder(2);

	UI::ImageWidget* _creditImage = new UI::ImageWidget("CreditImg", RectangleShapeData({ 170.0f, 30.0f }, "PixelTransparent"));
	//const ButtonData& _creditsData = ButtonData([&]() {}, [&]() {}, [&]() 
	//{ 
	//	// TODO
	//	//if (Canvas* _canva = dynamic_cast<Canvas*>(GetGameMode()->GetHUD()->GetCurrentWidget()))
	//	//{
	//	//	_canva->RemoveWidgets();
	//	//	//_canva = GetGameMode()->GetHUD()->SpawnWidget<Canvas>("Play Canva");
	//	//	InitCredits(_canva);
	//	//	_canva->UpdateWidgets();
	//	//	ApplyCanva(_canva);
	//	//	GetGameMode()->GetHUD()->SetCurrentWidget(_canva);
	//	//}
	//	//else
	//	//{
	//	//	LOG(Warning, "Dynamic Invalide");
	//	//}
	//}, [&]() {}, [&]() {});
	/*Button* _creditsButton = GetGameMode()->GetHUD()->SpawnWidget<Button>(_creditImage, _creditsData, "CreditsButton");
	_creditsButton->SetPosition(Vector2f(_windowSize.x * 0.57, _windowSize.y * 0.8));
	_creditsButton->SetZOrder(3);*/

	

	////////////////////////
	//		Quit
	////////////////////////

	LabelWidget* _quit = GetGameMode()->GetHUD()->SpawnWidget<LabelWidget>("Quit", Screen, "Daydream", TTF);
	_quit->SetPosition(Vector2f(_windowSize.x * 0.8, _windowSize.y * 0.8));
	_quit->SetCharacterSize(25);
	_quit->SetZOrder(2);

	UI::ImageWidget* _quitImage = new UI::ImageWidget("QuitImg", RectangleShapeData({ 100.0f, 30.0f }, "PixelTransparent"));
	//const ButtonData& _quitData = ButtonData([&]() {}, [&]() {}, [&]() 
	//{ 
	//	//M_LEVEL.GetCurrentLevel()->IsOver();
	//}, [&]() {}, [&]() {});
	/*Button* _quitButton = GetGameMode()->GetHUD()->SpawnWidget<Button>(_quitImage, _quitData, "QuitButton");
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

