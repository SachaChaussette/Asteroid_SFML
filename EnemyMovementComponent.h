#pragma once
#include "Component.h"

class EnemyMovementComponent : public Component
{ 
	float speed;
	float rotateSpeed;
	Vector2f direction;
	Actor* target;

public:
	FORCEINLINE void SetDirection(const Vector2f& _direction)
	{
		direction = _direction;
	}
	FORCEINLINE void SetRotateSpeed(const float _rotateSpeed)
	{
		rotateSpeed = _rotateSpeed;
	}

	FORCEINLINE void SetSpeed(const float _speed)
	{
		speed = _speed;
	}

	FORCEINLINE void SetTarget(Actor* _target)
	{
		target = _target;
	}
	
public:
	EnemyMovementComponent(Actor* _owner);
	EnemyMovementComponent(Actor* _owner, const EnemyMovementComponent* _other);

protected:
	virtual void Tick(const float _deltaTime) override;

private:
	void Move(const float _deltaTime);
	void RotateAround(const float _deltaTime);
};