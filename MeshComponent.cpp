#include "MeshComponent.h"

MeshComponent::MeshComponent(Actor* _owner, const float _radius,
	const string& _path, const TextureExtensionType& _textureType, const IntRect& _rect,
	bool _isRepeated, bool _isSmooth, const size_t& _pointCount) : Component(_owner)
{
	shape = new ShapeObject(_radius, _path, _textureType, _rect, _isRepeated, _isSmooth, _pointCount);
}

MeshComponent::MeshComponent(Actor* _owner, const Vector2f& _size, const string& _path,
	const TextureExtensionType& _textureType, const IntRect& _rect, 
	bool _isRepeated, bool _isSmooth) : Component(_owner)
{
	shape = new ShapeObject(_size, _path, _textureType, _rect, _isRepeated, _isSmooth);
}

MeshComponent::MeshComponent(Actor* _owner, const RectangleShapeData& _data) : Component(_owner)
{
	shape = new ShapeObject(_data);
}

MeshComponent::MeshComponent(Actor* _owner, const vector<Vector2f> point, const string& _path, 
	const TextureExtensionType& _textureType, const IntRect& _rect,
	bool _isRepeated, bool _isSmooth) : Component(_owner)
{
	shape = new ShapeObject(point, _path, _textureType, _rect, _isRepeated, _isSmooth);
}

MeshComponent::MeshComponent(Actor* _owner, const MeshComponent* _other) : Component(_owner) 
{
	shape = new ShapeObject(*_other->shape);
}


MeshComponent::~MeshComponent()
{
	delete shape;
}