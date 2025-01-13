#include "Game.h"

Game::Game()
{
	window = RenderWindow();
}

void Game::Start()
{
	window.create(VideoMode({ 200, 200 }), "SFML works!");
}

void Game::Update()
{
	while (window.isOpen())
	{
		while (const optional _event = window.pollEvent())
		{
			if (_event->is<Event::Closed>())
			{
				window.close();
			}
		}
		UpdateWindow();
	}
}

// TODO REMOVE DRAWABLE
void Game::UpdateWindow(Drawable* _DRAWABLE)
{
	window.clear();
	/*for (Actor* _actor : ActorManager::GetInstance().GetAllActors())
	{
		window.draw(*_actor->GetShape()->GetDrawable());
	}*/
	window.draw(*_DRAWABLE);
	window.display();
}

void Game::Stop()
{
}

void Game::Launch()
{
	Start();
	Update();
	Stop();
}
