#include "ShapeWidget.h"
#include "Macro.h"



UI::ShapeWidget::ShapeWidget(const float _radius, const string& _path, 
	const TextureExtensionType& _textureType, const IntRect& _rect, bool _isRepeated, 
	bool _isSmooth, const size_t& _pointCount, const string& _name, const RenderType& _type)
	: Widget(_name, _type)
{
	shapeObject = new ShapeObject(_radius, _path, _textureType, _rect, _isRepeated, _isSmooth, _pointCount);
}

UI::ShapeWidget::ShapeWidget(const Vector2f& _size, const string& _path, 
	const TextureExtensionType& _textureType, const IntRect& _rect, bool _isRepeated, 
	bool _isSmooth, const string& _name, const RenderType& _type) : Widget(_name, _type)
{
	shapeObject = new ShapeObject(_size, _path, _textureType, _rect, _isRepeated, _isSmooth);
}

UI::ShapeWidget::ShapeWidget(const RectangleShapeData& _data, const string& _name, 
	const RenderType& _type) : Widget(_name, _type)
{
	shapeObject = new ShapeObject(_data);
	//SetOriginAtMiddle(GetDrawable());
}

UI::ShapeWidget::ShapeWidget(const vector<Vector2f> point, const string& _path, 
	const TextureExtensionType& _textureType, const IntRect& _rect, bool _isRepeated, 
	bool _isSmooth, const string& _name, const RenderType& _type) : Widget(_name, _type)
{
	shapeObject = new ShapeObject(point, _path, _textureType, _rect, _isRepeated, _isSmooth);
}

UI::ShapeWidget::ShapeWidget(const ShapeWidget& _other) : Widget(_other)
{
	shapeObject = _other.shapeObject;
}

UI::ShapeWidget::~ShapeWidget()
{
	delete shapeObject;
}