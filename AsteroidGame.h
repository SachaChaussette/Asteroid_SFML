#pragma once
#include "Game.h"
#include "MeshActor.h"


class AsteroidGame : public Game
{
public:
	AsteroidGame();
	~AsteroidGame();

public:
	virtual void Start() override;
	virtual bool Update() override;
	virtual void Stop() override;

	void SpawnMeshActor();
};

