#pragma once
#include "Component.h"

class PlayerMovementComponent : public Component
{ 
	float speed;
	float rotateSpeed;
	float currentAngle;
	float friction;
	float deltaTime;
	Vector2f maxVelocity;
	Vector2f direction;
	Vector2f acceleration;
	Vector2f velocity;
	Actor* target;

public:

	FORCEINLINE void ApplyFriction()
	{
		velocity *= friction;
	}

	FORCEINLINE void SetTarget(Actor* _target)
	{
		target = _target;
	}
	
public:
	PlayerMovementComponent(Actor* _owner);
	PlayerMovementComponent(Actor* _owner, const PlayerMovementComponent* _other);

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