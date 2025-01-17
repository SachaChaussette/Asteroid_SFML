#include "ShapeObject.h"
#include "TextureManager.h"


ShapeObject::ShapeObject(const float _radius, const string& _path, const IntRect& _rect, 
						const size_t& _pointCount)
{
	shape = new CircleShape(_radius, _pointCount);
	M_TEXTURE.Load(this, _path, _rect);
}

ShapeObject::ShapeObject(const Vector2f _size, const string& _path, const IntRect& _rect)
{
	shape = new RectangleShape(_size);
	M_TEXTURE.Load(this, _path, _rect);
}

ShapeObject::~ShapeObject()
{
	delete shape;
}

