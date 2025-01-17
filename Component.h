#pragma once

#include "Core.h"

class Component : public Core
{
protected:
	class Actor* owner;

public:
	FORCEINLINE Actor* GetActor() const
	{
		return owner;
	}
public:
	Component(Actor* _owner);
	~Component();
public:
	virtual void BeginPlay() override {};
	virtual void Tick(const float _deltaTime) override {};
	virtual void BeginDestoy() override {};
};

