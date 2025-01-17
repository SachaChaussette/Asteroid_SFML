#pragma once

#include "Macro.h"
#include "CustomException.h"
#include "Color.h"

#ifdef DEBUG
#define USE_DEBUG 1
#else
#define USE_DEBUG 0
#endif // DEBUG

#define LOG(_verbosity, _msg) Logger::PrintLog(_verbosity, _msg, DEBUG_INFO);

#define WRITE_IN_LOG(_verbosity)        _verbosity >= Log
#define WRITE_IN_CONSOLE(_verbosity)    _verbosity > Log

enum VerbosityType
{
    VeryVerbose,
    Verbose,
    Log,
    Display,
    Warning,
    Error,
    Fatal,

    VT_COUNT,
};

class VerbosityData
{
    Gradient color;
    string prefix;
    string text;
    string debug;
    bool useDebug;
    bool useTime;

private:
    FORCEINLINE string GetPrefix(const bool _useColor) const
    {
        string _prefix = prefix;
        if (_useColor)
        {
            _prefix = "[" + string(RESET) + color.GradientString(prefix) + string(RESET) + "]";
        }
        else
        {
            _prefix += " :";
        }
        return _prefix;
    }
public:
    FORCEINLINE string GetFullText(const bool _useColor = true) const;
   
    

public:
    VerbosityData(const VerbosityType& _type, const string& _text, const string _debug,
                  const bool _useDebug = false, const bool _useTime = false)
    {
        ComputePrefix(_type);
        ComputeColor(_type);
        ComputeUseDebug(_type);
        ComputeUseTime(_type);
        text = _text;
        debug = _debug;
    }

private:
    void ComputePrefix(const VerbosityType& _type)
    {
        if (_type == VT_COUNT)
        {
            throw CustomException("Exception => invalid VerbosityType !");
        }

        const vector<string>& _verbosityTexts =
        {
            "VeryVerbose",
            "Verbose",
            "Log",
            "Display",
            "Warning",
            "Error",
            "Fatal",
        };

        prefix = _verbosityTexts[_type];
    }
    void ComputeColor(const VerbosityType& _type)
    {
        if (_type == VT_COUNT)
        {
            throw CustomException("Exception => Invalid VerbosityType !");
        }

        const vector<Gradient>& _verbosityColors =
        {
            Gradient(ColorData(27, 27, 33), ColorData(37, 37, 51)),            //VERY VERBOSE
            Gradient(ColorData(55, 55, 61), ColorData(69, 69, 93)),            //VERBOSE
            Gradient(ColorData(100, 100, 119), ColorData(143, 143, 194)),    //LOG
            Gradient(ColorData(221, 221, 246), ColorData(122, 122, 236)),    //DISPLAY
            Gradient(ColorData(255, 231, 0), ColorData(255, 76, 17)),        //WARNING
            Gradient(ColorData(193, 6, 11), ColorData(249, 56, 67)),        //ERROR
            Gradient(ColorData(255, 0, 95), ColorData(118, 37, 184)),        //FATAL
        };

        color = _verbosityColors[_type];
    }
    void ComputeUseDebug(const VerbosityType& _type)
    {
        useDebug = set<VerbosityType>({ Warning, Error, Fatal }).contains(_type);
    }
    void ComputeUseTime(const VerbosityType& _type)
    {
        useTime = set<VerbosityType>({ Warning, Error, Log, Fatal }).contains(_type);
    }
};

class Logger
{
    static string logsPath;
    
public:
    Logger();

private:
    static void WriteInConsole(const string& _text);
    static void WriteInLogs(const string& _text);

public:
    static void Reset();
    static void PrintLog(const VerbosityType& _type, const string& _text, const string& _debug);
};
