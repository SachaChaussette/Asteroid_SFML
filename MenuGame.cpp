#include "MenuGame.h"
#include "HUD.h"
#include "Level.h"
#include "CameraManager.h"

#include "MeshActor.h"

using namespace Camera;
using namespace UI;

MenuGame::MenuGame() : Game()
{
}

void MenuGame::Start()
{
	Super::Start();

	MeshActor* _background = Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(window.getSize()), "Sky", PNG)));
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
