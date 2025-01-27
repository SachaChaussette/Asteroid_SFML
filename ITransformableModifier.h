#pragma once

#include "CoreMinimal.h"
#include "TransformData.h"

class ITransformableModifier
{
public:
	FORCEINLINE virtual void SetOrigin(const Vector2f& _origin) = 0;
	FORCEINLINE virtual void SetPosition(const Vector2f& _position) = 0;
	FORCEINLINE virtual void SetRotation(const Angle& _rotation) = 0;
	FORCEINLINE virtual void SetScale(const Vector2f& _scale) = 0;
	FORCEINLINE virtual void SetTransform(const TransformData& _transform)
	{
		SetOrigin(_transform.origin);
		SetPosition(_transform.position);
		SetRotation(_transform.rotation);
		SetScale(_transform.scale);
	}
	FORCEINLINE virtual void Move(const Vector2f& _offset) = 0;
	FORCEINLINE virtual void Scale(const Vector2f& _factor) = 0;
	FORCEINLINE virtual void Rotate(const Angle& _angle) = 0;

};
