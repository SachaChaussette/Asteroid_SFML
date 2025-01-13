#pragma once

#include "CoreMinimal.h"

template <class Class>
class Singleton
{
public:
	FORCEINLINE static Class& GetInstance()
	{
		static Class _instance;
		return _instance;
	}
};