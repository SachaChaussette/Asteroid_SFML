#include "Image.h"

UI::Image::Image(const float _radius, const string& _path, 
	const TextureExtensionType& _textureType, const IntRect& _rect, bool _isRepeated, 
	bool _isSmooth, const size_t& _pointCount, const string& _name, const RenderType& _type)
	: Widget(_name, _type)
{
	shape = new ShapeObject(_radius, _path, _textureType, _rect, _isRepeated, _isSmooth, _pointCount);
	sizeToContent = false;
	initialSize = Vector2f(_radius / 2, _radius / 2);
	gradient = VertexArray(PrimitiveType::TriangleStrip, 4);
}

UI::Image::Image(const Vector2f& _size, const string& _path,
	const TextureExtensionType& _textureType, const IntRect& _rect, bool _isRepeated,
	bool _isSmooth, const string& _name, const RenderType& _type) : Widget(_name, _type)
{
	shape = new ShapeObject(_size, _path, _textureType, _rect, _isRepeated, _isSmooth);
	sizeToContent = false;
	initialSize = _size;
	gradient = VertexArray(PrimitiveType::TriangleStrip, 4);
}

UI::Image::Image(const RectangleShapeData& _data, const string& _name, const RenderType& _type)
		: Widget(_name, _type)
{
	shape = new ShapeObject(_data);
	sizeToContent = false;
	initialSize = _data.size;
	gradient = VertexArray(PrimitiveType::TriangleStrip, 4);
}

UI::Image::Image(const vector<Vector2f> point, const string& _path, 
	const TextureExtensionType& _textureType, const IntRect& _rect, bool _isRepeated, 
	bool _isSmooth, const string& _name, const RenderType& _type) : Widget(_name, _type)
{
	shape = new ShapeObject(point, _path, _textureType, _rect, _isRepeated, _isSmooth);
	sizeToContent = false;
	initialSize = Vector2f();
	gradient = VertexArray(PrimitiveType::TriangleStrip, 4);
}

UI::Image::Image(const Image& _other) : Widget(_other)
{
	shape = _other.shape;
	sizeToContent = _other.sizeToContent;
	initialSize = _other.initialSize;
	gradient = _other.gradient;
}

void UI::Image::UpdateSize()
{
	if (sizeToContent)
	{
		SetScale(CAST(Vector2f, shape->GetTexture().getSize()));
	}
	else
	{
		SetPosition(initialSize);
	}
}

void UI::Image::UpdateGradient()
{
	gradient[0].position = GetPosition();
	gradient[0].color = colorGradient.topLeft;

	gradient[1].position = { GetPosition().x, GetScale().y };
	gradient[1].color = colorGradient.topRight;

	gradient[2].position = GetScale();
	gradient[2].color = colorGradient.bottomLeft;

	gradient[3].position = { GetScale().x, GetPosition().y };
	gradient[3].color = colorGradient.bottomRight;
}

void UI::Image::Render(RenderWindow& _window)
{
	if (visibility == Hidden) return;
	_window.draw(*shape->GetDrawable());
	_window.draw(gradient);
}

void UI::Image::SetSizeToContent(const bool _status)
{
	sizeToContent = _status;
	UpdateSize();
}

void UI::Image::SetGradient(const Gradient& _gradient)
{
	colorGradient = _gradient;
	UpdateGradient();
}
