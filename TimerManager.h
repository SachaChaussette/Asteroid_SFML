#pragma once

#include "Game.h"

using Seconds = float;
using MilliSec = int32_t;
using MicroSec = int64_t;

template<class DurationType>
class Timer;

template<class DurationType = MilliSec>
class TimerManager : public Singleton<TimerManager<DurationType>>
{
	using T = Timer<DurationType>;
	friend Timer<DurationType>;

	// Objet qui contient toutes les données de temps
	Clock clock;
	// Temps en millisecondes depuis le début du programme
	DurationType time;
	// Stocke temporairement la précédente durée de la frame
	DurationType lastTime;
	// Met à jour le nbr de FPS
	DurationType lastFrameTime;
	// Temps en millisecondes depuis la dernière image rendue
	DurationType elapsedTime;
	// Vitesse à laquelle le temps s'écoule
	float timeScale;
	// Temps depuis la dernière image rendue avec le 'timeScale'
	DurationType deltaTime;
	// Nombre d'images qui ont été rendu depuis le début du programme
	l_long framesCount;
	// Maximum d'image à rendre par seconde
	u_short maxFrameRate;
	// Nombre d'image rendues par seconde
	DurationType fps;
	// Collection de tous les timers existants
	set<T*> allTimers;

	map<type_index, DurationType> durations;

private:
	FORCEINLINE DurationType GetDuration() const
	{
		return durations.at(typeid(DurationType));
	}
public:
	FORCEINLINE string GetCurrentRealTime() const
	{
		SYSTEMTIME _st;
		GetSystemTime(&_st);
		string _fullTime = "[" + to_string(_st.wDay + 1) + "/" + to_string(_st.wMonth) + "/" + to_string(_st.wYear) + "-";
		_fullTime += to_string(_st.wHour + 1) + ":" + to_string(_st.wMinute) + ":" + to_string(_st.wSecond) + "] ";
		return _fullTime;
	}
	FORCEINLINE void AddTimer(T* _timer)
	{
		allTimers.insert(_timer);
	}
	FORCEINLINE void RemoveTimer(T* _timer)
	{
		allTimers.erase(_timer);
		delete _timer;
	}
	FORCEINLINE void SetTimerScale(const DurationType& _timeScale)
	{
		timeScale = _timeScale;
	}
	FORCEINLINE DurationType ComputeFPS() const
	{
		return GetDuration() / (time - lastFrameTime);
	}
	FORCEINLINE DurationType GetTime(const Time& _time) const

	{
		map<type_index, function<DurationType()>> _durationCallback =
		{
			{ typeid(Seconds),	[&]() { return _time.asSeconds();		}},
			{ typeid(MilliSec), [&]() { return _time.asMilliseconds();	}},
			{ typeid(MicroSec), [&]() { return _time.asMicroseconds();	}},
		};

		return _durationCallback.at(typeid(DurationType))();
	};
	FORCEINLINE Time GetDeltaTime() const
	{
		return Time(seconds(deltaTime * GetDuration())) ;
	};

public:
	TimerManager()
	{
		clock = Clock(); 
		time = DurationType();
		lastTime = DurationType();
		lastFrameTime = DurationType();
		elapsedTime = DurationType();
		timeScale = 1.0f;
		deltaTime = DurationType();
		framesCount = 0;
		maxFrameRate = 60;
		fps = DurationType();
		allTimers = set<T*>();
		durations =
		{
			{ typeid(Seconds) , 1 },
			{ typeid(MilliSec) , 1000 },
			{ typeid(MicroSec) , 1000000 },
		};
	}
	~TimerManager()
	{
		for (Timer<DurationType>* _timer : allTimers)
		{
			delete _timer;
		}
	}

	
public:
	void Update()
	{
		lastTime = time;

		time = GetTime(clock.getElapsedTime());
		elapsedTime = time - lastTime;
		deltaTime = elapsedTime * timeScale;
		framesCount++;
		
		if (lastFrameTime == 0 || time - lastFrameTime >= maxFrameRate)
		{
			lastFrameTime = time;
			framesCount = 0;
			M_GAME.UpdateWindow();
		}
		using Iterator = set<T*>::iterator;
		for (Iterator _iterator = allTimers.begin(); _iterator != allTimers.end();)
		{
			T* _timer = *_iterator;
			_timer->Update(deltaTime);

			if (_timer->IsToDelete())
			{
				--_iterator;
				RemoveTimer(_timer);
				continue;
			}
			++_iterator;
		}
	}
	void Pause()
	{
		for (Timer* _timer : allTimers)
		{
			_timer->Pause();
		}
	}
	void Stop()
	{
		for (T* _timer : allTimers)
		{
			delete _timer;
		}
	}
};

using TM_Seconds = TimerManager<Seconds>;
using TM_Milli = TimerManager<MilliSec>;
using TM_Micro = TimerManager<MicroSec>;

template<class DurationType = Seconds>
class Timer
{
	bool isRunning;
	bool isLoop;
	bool isToDelete;
	double currentTime;
	double duration;
	function<void()> callback;

public:
	FORCEINLINE bool IsRunning() const
	{
		return isRunning;
	}
	FORCEINLINE bool IsLoop() const
	{
		return isLoop;
	}
	FORCEINLINE bool IsToDelete() const
	{
		return isToDelete;
	}
	
	FORCEINLINE double GetCurrentTime() const
	{
		return currentTime;
	}

public:
	Timer(const function<void()>& _callback, const Time& _time, const bool _startRunning = false,
		const bool _isLoop = false)
	{
		TM_Seconds& _manager = M_TIMER;

		isToDelete = false;
		isRunning = _startRunning;
		isLoop = _isLoop;
		currentTime = 0.0;
		duration = _manager.GetTime(_time);
		callback = _callback;

		TimerManager<DurationType>::GetInstance().AddTimer(this);
	}
public:
	void Update(const DurationType& _deltaTime)
	{
		if (!isRunning) return;

		currentTime += _deltaTime;
		if (currentTime >= duration)
		{
			if (callback)
			{
				callback();
			}

			if (!isLoop)
			{
				Stop();
			}

			Reset();
		}
	}
	void Start()
	{
		Reset();
		Resume();
	}
	void Stop()
	{
		isToDelete = true;
	}
	void Resume()
	{
		isRunning = true;
	}
	void Reset()
	{
		currentTime = 0.0;
	}
	void Pause()
	{
		isRunning = false;
	}
};

