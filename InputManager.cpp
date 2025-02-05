#include "InputManager.h"

void InputManager::CloseWindow(RenderWindow& _window)
{
    _window.close();
}

//void InputManager::BindAction(const function<void(Vector2i _pos)>& _buttonCallback, const MouseCode& _buttonCodes)
//{
//    inputsData.push_back(InputData(_buttonCallback, { _buttonCodes }));
//}

void InputManager::BindAction(const function<void()>& _callback, const Code& _code)
{
    inputsData.push_back(InputData(_callback, { _code }));
}

void InputManager::BindAction(const function<void(Vector2i _pos)>& _buttonCallback, const vector<MouseCode>& _buttonCodes)
{
    inputsData.push_back(InputData(_buttonCallback, _buttonCodes, _buttonCodes.empty()));
}
void InputManager::BindAction(const function<void()>& _callback, const vector<Code>& _codes)
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

        else if (const MouseButtonPressed* _key = _event->getIf<MouseButtonPressed>())
        {
            for (const InputData& _inputData : inputsData)
            {
                _inputData.TryToExecute(_key);
            }
        }
    }
}