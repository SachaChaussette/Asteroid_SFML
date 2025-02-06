#pragma once

#include "Singleton.h"
#include "GameModel.h"

class GameModeManager : public Singleton<GameModeManager>
{
	set<GameModel*> allModes;
	GameModel* currentMode;

public:
	FORCEINLINE void SetCurrentMode(GameModel* _gameMode)
	{
		currentMode = _gameMode;
	}
	FORCEINLINE set<GameModel*> GetAllGameModes() const
	{
		return allModes;
	}
	FORCEINLINE void AddGameMode(GameModel* _gameMode)
	{
		if (allModes.contains(_gameMode)) LOG(Warning, "Un GameMode identique Existe D�j� !");
		allModes.insert(_gameMode);
	}
	FORCEINLINE void RemoveGameMode(GameModel* _gameMode)
	{
		if (!allModes.contains(_gameMode))
		{
			LOG(Error, "Le GameMode n'a pas �t� trouv� !");
			return;
		}
		allModes.erase(_gameMode);
	}
public:
	~GameModeManager();

public:
	virtual void Launch();
	virtual void Update();
	virtual void Stop();
};

