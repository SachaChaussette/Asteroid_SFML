#pragma once
#include "Component.h"

class MovementComponent : public Component
{ 
	float speed;
	float rotateSpeed;
	float currentAngle;
	float friction;
	Vector2f speedLimit;
	Vector2f direction;
	Vector2f acceleration;
	Actor* target;

public:

	FORCEINLINE void ApplyFriction()
	{
		acceleration *= friction;
	}

	FORCEINLINE void SetTarget(Actor* _target)
	{
		target = _target;
	}
	
public:
	MovementComponent(Actor* _owner);
	MovementComponent(Actor* _owner, const MovementComponent* _other);

public:
	void Rotate(const float _degree);
	void ComputeAcceleration();
protected:
	virtual void Tick(const float _deltaTime) override;

private:
	void UpdateDirection();
	void Move(const float _deltaTime);
	void RotateAround(const float _deltaTime);
};