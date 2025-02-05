#pragma once
#include "Component.h"
#include "ShapeObject.h"

class Actor;

class MeshComponent : public Component
{
	ShapeObject* shape;
	string texturePath;
	//TODO store TexturePath 

public:
	FORCEINLINE ShapeObject* GetShape() const
	{
		return shape;
	}
	FORCEINLINE string GetTexturePath() const
	{
		return texturePath;
	}
	FORCEINLINE void SetShape(ShapeObject* _shape)
	{
		shape = _shape;
	}

public:
	MeshComponent(Actor* _owner, const float _radius, const string& _path = "",
		const TextureExtensionType& _textureType = PNG, const IntRect& _rect = {},
		bool _isRepeated = false, bool _isSmooth = true, const size_t& _pointCount = 30U);
	MeshComponent(Actor* _owner, const Vector2f& _size, const string& _path = "",
		const TextureExtensionType& _textureType = PNG, const IntRect& _rect = {},
		bool _isRepeated = false, bool _isSmooth = true);

	MeshComponent(Actor* _owner, const RectangleShapeData& _data); // Rectangle v2

	MeshComponent(Actor* _owner, const vector<Vector2f> point, const string& _path = "",
		const TextureExtensionType& _textureType = PNG, const IntRect& _rect = {},
		bool _isRepeated = false, bool _isSmooth = true);

	MeshComponent(Actor* _owner, const MeshComponent* _other);
	~MeshComponent();
};