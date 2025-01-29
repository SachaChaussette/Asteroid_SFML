#pragma once
#include "Component.h"

class MovementComponent : public Component
{ 
	float speed;
	float rotateSpeed;
	float currentAngle;
	float friction;
	float deltaTime;
	Vector2f speedLimit;
	Vector2f direction;
	Vector2f acceleration;
	Vector2f _offset;
	Actor* target;

public:

	FORCEINLINE void ApplyFriction()
	{
		_offset *= friction;
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
	virtual void BeginPlay() override;

private:
	void UpdateDirection();
	void Move(const float _deltaTime);
	void RotateAround(const float _deltaTime);
};