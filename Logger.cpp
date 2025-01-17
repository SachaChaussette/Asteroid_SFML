#include "Logger.h"
#include "TimerManager.h"

string VerbosityData::GetFullText(const bool _useColor) const
{
    const string& _reset = _useColor ? RESET : "";
	string _fullText;

    if (useTime)
    {
		_fullText += TimerManager<Seconds>::GetInstance().GetCurrentRealTime();
	}

	_fullText += GetPrefix(_useColor) + (_useColor ? color.GradientString(text) : text);
    if (USE_DEBUG || useDebug)
    {
        _fullText += debug;
    }

    _fullText += _reset;

    return _fullText;
}

string Logger::logsPath = "Logs/Log.txt";

Logger::Logger()
{

}

void Logger::WriteInConsole(const string& _text)
{
	cout << _text << endl;
}

void Logger::WriteInLogs(const string& _text)
{
	ofstream _stream = ofstream(logsPath, ios_base::app | ios_base::binary);
	_stream << _text << "\n";
}

void Logger::Reset()
{
	ofstream(logsPath, ios_base::trunc | ios_base::binary);
}

void Logger::PrintLog(const VerbosityType& _type, const string& _text, const string& _debug)
{
	if (WRITE_IN_LOG(_type))
	{
		const VerbosityData& _verbosity = VerbosityData(_type, _text, _debug);
		WriteInLogs(_verbosity.GetFullText(false));

		if (WRITE_IN_CONSOLE(_type))
		{
			WriteInConsole(_verbosity.GetFullText(true));
		}
	}
	if (_type == Fatal)
	{
		assert(false);
	}
}
