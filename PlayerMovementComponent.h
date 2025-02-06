#pragma once
#include "Component.h"

class PlayerMovementComponent : public Component
{ 
	float currentAngle;
	float friction;
	float deltaTime;

	Vector2f maxVelocity;
	Vector2f acceleration;
	Vector2f velocity;
	Vector2f direction;

public:

	FORCEINLINE void ApplyFriction()
	{
		velocity *= friction;
	}
	FORCEINLINE float GetCurrentAngle() const
	{
		return currentAngle;
	}
public:
	PlayerMovementComponent(Actor* _owner);
	PlayerMovementComponent(Actor* _owner, const PlayerMovementComponent* _other);

public:
	FORCEINLINE Vector2f GetDirection()
	{
		return direction;
	}
	void Rotate(const float _degree);
	void ComputeAcceleration();
protected:
	virtual void Tick(const float _deltaTime) override;
	virtual void BeginPlay() override;

private:
	void UpdateDirection();
	void Move(const float _deltaTime);

};