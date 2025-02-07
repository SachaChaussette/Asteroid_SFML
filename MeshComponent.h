#pragma once
#include "Component.h"
#include "ShapeObject.h"

class Actor;

class MeshComponent : public Component
{
	ShapeObject* shape;
	string path;

public:
	FORCEINLINE ShapeObject* GetShape() const
	{
		return shape;
	}
	FORCEINLINE void SetShape(ShapeObject* _shape)
	{
		shape = _shape;
	}
	FORCEINLINE string GetPath() const
	{
		return path;
	}
public:
	MeshComponent(Actor* _owner, const CircleShapeData& _data);
	MeshComponent(Actor* _owner, const RectangleShapeData& _data);
	MeshComponent(Actor* _owner, const ConvexShapeData& _data);
	MeshComponent(Actor* _owner, const MeshComponent& _other);
	~MeshComponent();
};