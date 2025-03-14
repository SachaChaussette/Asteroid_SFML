#pragma once
#include "Component.h"
#include "VertexObject.h"

class Actor;

class VertexComponent : public Component
{
	VertexObject* vertex;

public:
	FORCEINLINE VertexObject* GetVertex() const
	{
		return vertex;
	}

	FORCEINLINE virtual Component* Clone(Actor* _owner) const override
	{
		return new VertexComponent(_owner, *this);
	}

public:
	VertexComponent(Actor* _owner, const u_int& _count, const PrimitiveType& _type = PrimitiveType::Points);
	VertexComponent(Actor* _owner, const VertexComponent& _other);
	~VertexComponent();

};