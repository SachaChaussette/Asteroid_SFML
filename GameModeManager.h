#pragma once

#include "Singleton.h"
#include "GameMode.h"

class GameModeManager : public Singleton<GameModeManager>
{
	set<GameMode*> allModes;
	GameMode* currentMode;

public:
	FORCEINLINE void SetCurrentMode(GameMode* _gameMode)
	{
		currentMode = _gameMode;
	}
	FORCEINLINE set<GameMode*> GetAllGameModes() const
	{
		return allModes;
	}
	FORCEINLINE void AddGameMode(GameMode* _gameMode)
	{
		if (allModes.contains(_gameMode)) LOG(Warning, "Un GameMode identique Existe D�j� !");
		allModes.insert(_gameMode);
	}
	FORCEINLINE void RemoveGameMode(GameMode* _gameMode)
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

