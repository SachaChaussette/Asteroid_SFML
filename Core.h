#pragma once

#include "CoreMinimal.h"

class Core
{
public:
	virtual void BeginPlay() = 0;
	virtual void Tick(const float _deltaTime) = 0;
	virtual void BeginDestoy() = 0;
};

