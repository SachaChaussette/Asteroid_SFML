#pragma once

#include "Singleton.h"

using KeyPressed = Event::KeyPressed;
using KeyReleased = Event::KeyReleased;
using MouseButtonPressed = Event::MouseButtonPressed;
using Code = Keyboard::Key;
using MouseCode  = Mouse::Button;

struct InputData
{
	vector<Code> codes;
	vector<MouseCode> mouseCodes;
	bool isAnyKey;
	function<void()> callback;
	function<void(Vector2i _pos)> buttonCallback;

	InputData() = default;
	InputData(const function<void()>& _callback, const vector<Code>& _codes = {},
			const bool _isAnyKey = false)
	{
		callback = _callback;
		codes = _codes;
		isAnyKey = _isAnyKey;
	}
	InputData(const function<void(Vector2i _pos)>& _buttonCallback, const vector<MouseCode>& _mouseCodes = {},
		const bool _isAnyKey = false)
	{
		buttonCallback = _buttonCallback;
		mouseCodes = _mouseCodes;
		isAnyKey = _isAnyKey;
	}

	template<typename Type = Event::KeyPressed>
	bool TryToExecute(const Type* _key) const
	{
		if (!isAnyKey && !ContainsKey(_key->code)) return false;
		callback();
		return true;
	}
	bool TryToExecute(const MouseButtonPressed* _key) const
	{
		if (!isAnyKey && !ContainsKey(_key->button)) return false;
		buttonCallback(_key->position);
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
	inline bool ContainsKey(const MouseCode& _currentCode) const
	{
		for (const MouseCode& _code : mouseCodes)
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
	void BindAction(const function<void(Vector2i _pos)>& _buttonCallback, const MouseCode& _code);
	void BindAction(const function<void()>& _callback, const Code& _code);
	void BindAction(const function<void(Vector2i _pos)>& _buttonCallback, const vector<MouseCode>& _code);
	void BindAction(const function<void()>& _callback, const vector<Code>& _code);
	void ConsumeInputs(RenderWindow& _window);
};

