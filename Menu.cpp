#include "Menu.h"
#include "ImageWidget.h"
#include "LabelWidget.h"
#include "ButtonWidget.h"
#include "HUD.h"
#include "LevelManager.h"

using namespace Camera;
using namespace UI;

Menu::Menu(const string& _name) : Level(_name)
{
	name = _name;
	canva = nullptr;
}

Menu::Menu(const Menu& _other) : Level("MainMenu Level")
{
	name = _other.name;
	canva = _other.canva;
}

void Menu::InitLevel()
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

void Menu::Reset()
{
	canva->BeginDestroy();
}

void Menu::ApplyCanva(CanvasWidget* _canva)
{
	//M_LEVEL.GetCurrentLevel()->AddToViewport(_canva);
}
