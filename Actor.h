#pragma once

#include "Component.h"
#include "Core.h"

class Actor : public Core
{
protected:
	set<Component*> components;

public:
	Actor();
	~Actor();
protected:
	void Register();

public:
	virtual void BeginPlay() override;
	virtual void Tick(const float _deltaTime) override;
	virtual void BeginDestoy() override;
	void AddComponent(Component* _component);
	void RemoveComponent(Component* _component);
	template<typename Type>
	Type* GetComponent()
	{
		for (Component* _component : components)
		{
			if (is_same_v<decltype(_component), Type>) return dynamic_cast<Type>(_component);
		}
		return nullptr;
		
	}
};

