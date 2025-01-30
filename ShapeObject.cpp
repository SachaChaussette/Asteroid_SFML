#include "ShapeObject.h"
#include "TextureManager.h"

ShapeObject::ShapeObject(const float _radius, const string& _path, const TextureExtensionType& _textureType, 
	const IntRect& _rect, bool _isRepeated, bool _isSmooth, const size_t& _pointCount)
{
	objectData = ShapeObjectData(SOT_CIRCLE, CircleShapeData(_radius, _path, _textureType, _rect, _isRepeated, _isSmooth, _pointCount));
	InitCircle(*objectData.data.circleData);
}

ShapeObject::ShapeObject(const Vector2f& _size, const string& _path, const TextureExtensionType& _textureType,
	const IntRect& _rect, bool _isRepeated, bool _isSmooth)
{
	objectData = ShapeObjectData(SOT_RECTANGLE, RectangleShapeData(_size, _path, _textureType, _rect, _isRepeated, _isSmooth));
	InitRectangle(*objectData.data.rectangleData);
}

ShapeObject::ShapeObject(const RectangleShapeData& _data)
{
	objectData = ShapeObjectData(SOT_RECTANGLE, _data);
	InitRectangle(*objectData.data.rectangleData);
}

ShapeObject::ShapeObject(const vector<Vector2f> point, const string& _path, const TextureExtensionType& _textureType,
	const IntRect& _rect, bool _isRepeated, bool _isSmooth)
{
	objectData = ShapeObjectData(SOT_CONVEX, ConvexShapeData(point, _path, _textureType, _rect, _isRepeated, _isSmooth));
	InitConvex(*objectData.data.convexData);
}


ShapeObject::ShapeObject(const ShapeObject& _other)
{
	objectData = _other.objectData;

	if (objectData.type == SOT_CIRCLE)
	{
		InitCircle(*objectData.data.circleData);
	}

	else if (objectData.type == SOT_RECTANGLE)
	{
		InitRectangle(*objectData.data.rectangleData);
	}

	else if (objectData.type == SOT_CONVEX)
	{
		InitConvex(*objectData.data.convexData);
	}
}

ShapeObject::~ShapeObject()
{
	delete shape;
}


void ShapeObject::InitCircle(const CircleShapeData& _data)
{
	shape = new CircleShape(_data.radius, _data.pointCount);
	M_TEXTURE.Load(this, _data.path, _data.rect, _data.textureType, _data.isRepeated, _data.isSmooth);
}

void ShapeObject::InitRectangle(const RectangleShapeData& _data)
{
	shape = new RectangleShape(_data.size);
	M_TEXTURE.Load(this, _data.path, _data.rect, _data.textureType, _data.isRepeated, _data.isSmooth);
}

void ShapeObject::InitConvex(const ConvexShapeData& _data)
{
	u_int _index = 0;
	ConvexShape* _convex = new ConvexShape(_data.point.size());
	for (Vector2f _point : _data.point)
	{
		_convex->setPoint(_index++, _point);
	}
	shape = _convex;
	_convex = nullptr;
	delete _convex;
	M_TEXTURE.Load(this, _data.path, _data.rect, _data.textureType, _data.isRepeated, _data.isSmooth);
}