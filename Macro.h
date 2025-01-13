#pragma once

#include "CoreMinimal.h"

#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)

static void Config()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
}