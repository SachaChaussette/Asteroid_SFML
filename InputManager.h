#pragma once

#include "Singleton.h"

using KeyPressed = Event::KeyPressed;
using KeyReleased = Event::KeyReleased;
using MouseButtonPressed = Event::MouseButtonPressed;
using Code = Keyboard::Key;

struct InputData
{
	vector<Code> codes;
	bool isAnyKey;
	function<void()> callback;

	InputData() = default;
	InputData(const function<void()>& _callback, const vector<Code>& _codes = {}, 
			const bool _isAnyKey = false)
	{
		callback = _callback;
		codes = _codes;
		isAnyKey = _isAnyKey;
	}

	template<typename Type = Event::KeyPressed>
	bool TryToExecute(const Type* _key) const
	{
		if (!isAnyKey && !ContainsKey(_key->code)) return false;
		callback();
		return true;
	}
private:
	inline bool ContainsKey(const Code& _currentCode) const
	{
		for (const Code& _code : codes)
		{
			if (_currentCode == _code) return true;
		}
		return false;
	}
};

class InputManager : public Singleton<InputManager>
{
	vector<InputData> inputsData;
public:

private:
	void CloseWindow(RenderWindow& _window);
public:
	void BindAction(function<void()> _callback, const Code& _code);
	void BindAction(function<void()> _callback, const vector<Code>& _code);
	void ConsumeInputs(RenderWindow& _window);
};

