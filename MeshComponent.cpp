#include "MeshComponent.h"

MeshComponent::MeshComponent(Actor* _owner, const float _radius, const size_t& _pointCount, 
						const string& _path, const IntRect& _rect) : Component(_owner)
{
	shape = new ShapeObject(_radius, _path, _rect, _pointCount);
}

MeshComponent::MeshComponent(Actor* _owner, const Vector2f _size, const string& _path,
							const IntRect& _rect) : Component(_owner)
{
	shape = new ShapeObject(_size, _path, _rect);
}

MeshComponent::~MeshComponent()
{
	delete shape;
}
