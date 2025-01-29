#include "InputManager.h"

void InputManager::CloseWindow(RenderWindow& _window)
{
    _window.close();
}

void InputManager::BindAction(function<void()> _callback, const Code& _code)
{
    inputsData.push_back(InputData(_callback, { _code }));
}

void InputManager::BindAction(function<void()> _callback, const vector<Code>& _codes)
{
    inputsData.push_back(InputData(_callback, _codes, _codes.empty()));
}

void InputManager::ConsumeInputs(RenderWindow& _window)
{
    while (const optional _event = _window.pollEvent())
    {
        if (_event->is<Event::Closed>())
        {
            CloseWindow(_window);
        }
        else if (const KeyPressed* _key = _event->getIf<KeyPressed>())
        {
            for (const InputData& _inputData : inputsData)
            {
                if (_inputData.TryToExecute(_key)) break;
            }
        }
        else if (const KeyReleased* _key = _event->getIf<KeyReleased>())
        {
            for (const InputData& _inputData : inputsData)
            {
                if (_inputData.TryToExecute(_key)) break;
            }
        }
    }
}