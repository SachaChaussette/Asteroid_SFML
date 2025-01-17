#pragma once

#include "Macro.h"

class CustomException : public exception
{
	using Exception = char const*;

public:
	CustomException(const Exception _error) : exception(_error)
	{

	}
public:
	NO_DISCARD virtual Exception what() const override
	{
		const string& _customMsg = (DEBUG_INFO + " Exception = > " +
									static_cast<string>(Super::what())).c_str();
		return _customMsg.c_str();
	}
private:
	NO_DISCARD Exception What() const
	{
		return what();
	}

};

