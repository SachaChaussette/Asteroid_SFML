#pragma once

#include "Actor.h"
#include "MeshComponent.h"

class MeshActor : public Actor
{
	MeshComponent* mesh;
	u_int renderMeshToken;
public:
	FORCEINLINE MeshComponent* GetMesh() const
	{
		return mesh;
	}
public:
	MeshActor(const float _radius, const size_t& _pointCount = 30, const string& _path = "", const IntRect& _rect = IntRect());
	MeshActor(const Vector2f _size, const string& _path = "", const IntRect& _rect = IntRect());

private:
	void RenderMesh(RenderWindow& _window);
};
