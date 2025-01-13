#pragma once

#include "Singleton.h"

class Game : public Singleton<Game>
{
	RenderWindow window;

public:
	Game();
	~Game();

private:
	void Start();
	void Update();
	void Stop();

public:
	void UpdateWindow(Drawable* _DRAWABLE = nullptr);
	void Launch();
};

