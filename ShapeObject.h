#pragma once
#include "TransformableObject.h"

enum TextureExtensionType
{
	PNG,
	JPG,
	GIF,
};

enum ShapeObjectType
{
	SOT_CIRCLE,
	SOT_RECTANGLE,
	SOT_CONVEX,

	SOT_COUNT,
};

struct CircleShapeData
{
	float radius;
	string path;
	IntRect rect;
	size_t pointCount;
	TextureExtensionType textureType;
	bool isRepeated;
	bool isSmooth;

	CircleShapeData(const float _radius, const string& _path, const TextureExtensionType& _textureType
		, const IntRect& _rect = IntRect(), bool _isRepeated = false, bool _isSmooth = true, const size_t& _pointCount = 30U)
	{
		radius = _radius;
		path = _path;
		rect = _rect;
		textureType = _textureType;
		pointCount = _pointCount;
		isRepeated = _isRepeated;
		isSmooth = _isSmooth;
	}

	CircleShapeData& operator = (CircleShapeData _other)
	{
		radius = _other.radius;
		path = _other.path;
		rect = _other.rect;
		textureType = _other.textureType;
		pointCount = _other.pointCount;
		isRepeated = _other.isRepeated;
		isSmooth = _other.isSmooth;

		return *this;
	}
};

struct RectangleShapeData
{
	Vector2f size;
	string path;
	IntRect rect;
	TextureExtensionType textureType;
	bool isRepeated;
	bool isSmooth;

	RectangleShapeData(const Vector2f& _size, const string& _path = "", const TextureExtensionType& _textureType = PNG, 
						const IntRect& _rect = IntRect(), bool _isRepeated = false, bool _isSmooth = true)
	{
		size = _size;
		path = _path;
		rect = _rect;
		textureType = _textureType;
		isRepeated = _isRepeated;
		isSmooth = _isSmooth;
	}
};

struct ConvexShapeData
{
	string path;
	IntRect rect;
	vector<Vector2f> point;
	TextureExtensionType textureType;
	bool isRepeated;
	bool isSmooth;
	ConvexShapeData(const vector<Vector2f> _point, const string& _path, const TextureExtensionType& _textureType
		, const IntRect& _rect = IntRect(), bool _isRepeated = false, bool _isSmooth = true)
	{
		path = _path;
		rect = _rect;
		point = _point;
		textureType = _textureType;
		isRepeated = _isRepeated;
		isSmooth = _isSmooth;
	}
};

union ObjectData
{
	CircleShapeData* circleData;
	RectangleShapeData* rectangleData;
	ConvexShapeData* convexData;

	ObjectData() {}
	~ObjectData() {}
};

struct ShapeObjectData
{
	ShapeObjectType type;
	ObjectData data;

	ShapeObjectData()
	{
		type = SOT_COUNT;
	}
	ShapeObjectData(const ShapeObjectType& _type, const CircleShapeData& _circleData)
	{
		type = _type;
		data.circleData = new CircleShapeData(_circleData);
	}
	ShapeObjectData(const ShapeObjectType& _type, const RectangleShapeData& _rectangleData)
	{
		type = _type;
		data.rectangleData = new RectangleShapeData(_rectangleData);
	}
	ShapeObjectData(const ShapeObjectType& _type, const ConvexShapeData& _convexData)
	{
		type = _type;
		data.convexData = new ConvexShapeData(_convexData);
	}
	~ShapeObjectData()
	{
		if (type == SOT_CIRCLE)
		{
			delete data.circleData;
		}

		else if (type == SOT_RECTANGLE)
		{
			delete data.rectangleData;
		}

		else
		{
			delete data.convexData;
		}
	}

	ShapeObjectData& operator = (const ShapeObjectData& _other)
	{
		type = _other.type;

		if (type == SOT_CIRCLE)
		{
			data.circleData = new CircleShapeData(*_other.data.circleData);
		}

		else if (type == SOT_RECTANGLE)
		{
			data.rectangleData = new RectangleShapeData(*_other.data.rectangleData);
		}

		else if (type == SOT_CONVEX)
		{
			data.convexData = new ConvexShapeData(*_other.data.convexData);
		}

		return *this;
	}
};

class ShapeObject : public TransformableObject
{
	Texture texture;
	Shape* shape;
	ShapeObjectData objectData;

public:
	FORCEINLINE Texture& GetTexture()
	{
		return texture;
	}
	FORCEINLINE virtual Shape* GetDrawable() const override
	{
		return shape;
	}
	FORCEINLINE virtual void SetOrigin(const Vector2f& _origin) override
	{
		shape->setOrigin(_origin);
	}
	FORCEINLINE virtual void SetPosition(const Vector2f& _position) override
	{
		shape->setPosition(_position);
	}
	FORCEINLINE virtual void SetRotation(const Angle& _rotation) override
	{
		shape->setRotation(_rotation);
	}
	FORCEINLINE virtual void SetScale(const Vector2f& _scale) override
	{
		shape->setScale(_scale);
	}
	FORCEINLINE virtual void SetTransform(const TransformData& _transformData) override
	{
		shape->setOrigin(_transformData.origin);
		shape->setPosition(_transformData.position);
		shape->setRotation(_transformData.rotation);
		shape->setScale(_transformData.scale);
	}
	FORCEINLINE virtual void Move(const Vector2f& _offset) override
	{
		shape->move(_offset);
	}
	FORCEINLINE virtual void Rotate(const Angle& _angle) override
	{
		shape->rotate(_angle);
	}
	FORCEINLINE virtual void Scale(const Vector2f& _factor) override
	{
		shape->scale(_factor);
	}

public:
	ShapeObject(const float _radius, const string& _path = "", const TextureExtensionType& _textureType = PNG,
		const IntRect& _rect = IntRect(), bool _isRepeated = false,
		bool _isSmooth = true, const size_t& _pointCount = 30U); // Circle
	ShapeObject(const Vector2f& _size, const string& _path = "", const TextureExtensionType& _textureType = PNG,
		const IntRect& _rect = IntRect(), bool _isRepeated = false, bool _isSmooth = true); // Rectangle
	ShapeObject(const vector<Vector2f> point, const string& _path = "", const TextureExtensionType& _textureType = PNG,
		const IntRect& _rect = IntRect(), bool _isRepeated = false, bool _isSmooth = true); // convex
	ShapeObject(const RectangleShapeData& _data); 
	ShapeObject(const ShapeObject& _other);
	~ShapeObject();

private:
	void InitCircle(const CircleShapeData& _data);
	void InitRectangle(const RectangleShapeData& _data);
	void InitConvex(const ConvexShapeData& _data);
};