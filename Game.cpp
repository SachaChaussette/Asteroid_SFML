#include "Game.h"
#include "ActorManager.h"
#include "CameraManager.h"
#include "TimerManager.h"
#include "InputManager.h"

using namespace Camera;

Game::Game()
{
	window = RenderWindow();
}


void Game::Start()
{
    const Vector2u& _size = { 1920, 1080 };
    window.create(VideoMode(_size), "SFML works!");
    const Vector2f& _center = Vector2f(CAST(Vector2f, window.getSize()) / 2.0f);
    // TODO
    //M_CAMERA.CreateCamera(_center, CAST(Vector2f, _size), "DefaultCamera");

    //M_ACTOR.BeginPlay();
};

bool Game::Update()
{
    TM_Seconds& _timer = M_TIMER;
    _timer.Update();
    

    M_INPUT.Update(window);

    const float _deltaTime = _timer.GetDeltaTime().asSeconds();
    // TODO
    //M_ACTOR.Tick(_deltaTime);

    return IsOver();
}

void Game::UpdateWindow()
{
    window.clear();
    // TODO
    //M_CAMERA.RenderAllCameras(window);
    window.display();
}

void Game::Stop()
{
    // TODO
    //M_ACTOR.BeginDestroy();
}