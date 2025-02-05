#pragma once
#include "Widget.h"
#include "ShapeObject.h"

namespace UI
{
	struct Gradient
	{
		Color topLeft;
		Color topRight;
		Color bottomLeft;
		Color bottomRight;

		Gradient(const Color& _topLeft = Color(), const Color& _topRight = Color(),
			const Color& _bottomLeft = Color(), const Color& _bottomRight = Color())
		{
			topLeft = _topLeft;
			topRight = _topRight;
			bottomLeft = _bottomLeft;
			bottomRight = _bottomRight;
		}
	};

	class Image : public Widget
	{
		ShapeObject* shape;

		bool sizeToContent;
		Vector2f initialSize;
		VertexArray gradient;
		Gradient colorGradient;

	public:
		FORCEINLINE Vector2f GetInitialSize() const
		{
			return initialSize;
		}
		FORCEINLINE ShapeObject* GetShape() const
		{
			return shape;
		}
		FORCEINLINE virtual void SetPosition(const Vector2f& _position) override
		{
			Super::SetPosition(_position);
			shape->SetPosition(_position);
		}
		FORCEINLINE virtual void SetRotation(const Angle& _rotation) override
		{
			Super::SetRotation(_rotation);
			shape->SetRotation(_rotation);
		}
		FORCEINLINE virtual void SetScale(const Vector2f& _scale) override
		{
			Super::SetScale(_scale);
			shape->SetScale(_scale);
		}
		FORCEINLINE virtual void SetOrigin(const Vector2f& _origin) override
		{
			Super::SetOrigin(_origin);
			shape->SetOrigin(_origin);
		}
		FORCEINLINE virtual void Move(const Vector2f& _offset) override
		{
			Super::Move(_offset);
			shape->Move(_offset);
		}
		FORCEINLINE virtual void Rotate(const Angle& _angle) override
		{
			Super::Rotate(_angle);
			shape->Rotate(_angle);
		}
		FORCEINLINE virtual void Scale(const Vector2f& _factor) override
		{
			Super::Scale(_factor);
			shape->Scale(_factor);
		}
		FORCEINLINE virtual void SetFillColor(const Color& _color)
		{
			shape->GetDrawable()->setFillColor(_color);
		}
		FORCEINLINE Vector2f GetSize() const
		{
			return shape->GetDrawable()->getScale();
		}
		FORCEINLINE Vector2f GetPosition() const
		{
			return shape->GetDrawable()->getPosition();
		}


	public:
		Image(const float _radius, const string& _path = "", const TextureExtensionType& _textureType = PNG,
			const IntRect& _rect = IntRect(), bool _isRepeated = false,
			bool _isSmooth = true, const size_t& _pointCount = 30U, const string& _name = "Image", const RenderType& _type = Screen);
		Image(const Vector2f& _size, const string& _path = "", const TextureExtensionType& _textureType = PNG,
			const IntRect& _rect = IntRect(), bool _isRepeated = false, bool _isSmooth = true, const string& _name = "Image", const RenderType& _type = Screen); // Rectangle
		Image(const RectangleShapeData& _data, const string& _name = "Image", const RenderType& _type = Screen);
		Image(const vector<Vector2f> point, const string& _path = "", const TextureExtensionType& _textureType = PNG,
			const IntRect& _rect = IntRect(), bool _isRepeated = false, bool _isSmooth = true, const string& _name = "Image", const RenderType& _type = Screen);
		Image(const Image& _other);
	private:
		void UpdateSize();
		void UpdateGradient();

	public:
		virtual void Render(RenderWindow& _window) override;
		void SetSizeToContent(const bool _status);
		void SetGradient(const Gradient& _gradient);
	};
}

