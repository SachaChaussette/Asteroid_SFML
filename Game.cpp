#include "Game.h"
#include "ActorManager.h"
#include "TimerManager.h"
#include "SoundManager.h"
#include "MenuManager.h"
#include "MainMenu.h"
#include "MeshActor.h"

// TODO REMOVE
bool TEST(const int _index)
{
    cout << "Index" << _index << endl;
    return _index % 2 == 0;
}

Game::Game()
{
    window = RenderWindow();
}

Game::~Game()
{

}

void Game::Launch()
{
    Start();
    Update();
}
void Game::Start()
{
    window.create(VideoMode({ 800, 600 }), "SFML works!");

    new Timer([]() 
    { 
        /*static int _index = 0;
        if (TEST(++_index))
        {
            LOG(Display, "coucou");
        }*/
    }, Time(seconds(1.0f)), true, false);

   /* MeshActor * _mesh1 = new MeshActor(50.0f, 30, "images.jpg");
    MeshActor * _mesh2 = new MeshActor(20.0f, 30, "images.jpg");
    _mesh2->GetMesh()->GetShape()->Move({ 50.0f, 0.0f });

    FloatRect _boundingBox1 = _mesh1->GetMesh()->GetShape()->GetDrawable()->getGlobalBounds();
    FloatRect _boundingBox2 = _mesh2->GetMesh()->GetShape()->GetDrawable()->getGlobalBounds();

    if (const optional<FloatRect>& _intersection = _boundingBox1.findIntersection(_boundingBox2))
    {
        LOG(Display, to_string(_intersection.value().getCenter().x) + " / " + to_string(_intersection.value().getCenter().y));
    }*/

    M_MENU.RegisterMenu(MT_MAIN, new MainMenu());

    SoundSample* _sample = M_SOUND.PlaySound("yipeeee", WAV);
}

void Game::Update()
{
    while (window.isOpen())
    {
        TM_Seconds& _timer = M_TIMER;
        _timer.Update();
        while (const std::optional _event = window.pollEvent())
        {
            if (_event->is<Event::Closed>())
            {
                Stop();
            }
        }   
        const float _deltaTime = _timer.GetDeltaTime().asSeconds();
        //LOG(Warning, "DeltaTime => " + to_string(_deltaTime));
        
        M_ACTOR.Tick(_deltaTime);

        UpdateWindow();
    }
}

void Game::UpdateWindow()
{
    window.clear();
    for (const pair<u_int, OnRenderWindow>& _renderPair : onRenderWindow)
    {
        _renderPair.second(window);
    }
    window.display();
}

void Game::Stop()
{
    window.close();
}

