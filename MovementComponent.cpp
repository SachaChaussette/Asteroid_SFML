#include "MovementComponent.h"
#include "Actor.h"

MovementComponent::MovementComponent(Actor* _owner) : Component(_owner)
{
	speed = 1.0f;
	friction = 0.95f;
	acceleration = Vector2f(1.0f,1.0f);
	rotateSpeed = 30.0f;
	direction = Vector2f(1.0f, 1.0f);
	target = nullptr;
}

MovementComponent::MovementComponent(Actor* _owner, const MovementComponent* _other) : Component(_owner)
{
	speed = _other->speed;
	friction = _other->friction;
	acceleration = _other->acceleration;
	rotateSpeed = _other->rotateSpeed;
	direction = _other->direction;
	target = _other->target;
}

void MovementComponent::Tick(const float _deltaTime)
{
	Super::Tick(_deltaTime);

	Move(_deltaTime);
	//owner->SetRotation(Angle(degrees(direction * 180.0f));
	//RotateAround(_deltaTime);
}


void MovementComponent::Move(const float _deltaTime)
{
	offset.x = acceleration.x * _deltaTime;
	offset.y = acceleration.y * _deltaTime;
	owner->Move(offset);
	//acceleration = Vector2f();
}

void MovementComponent::RotateAround(const float _deltaTime)
{
	if (!target) return;

	const Vector2f& _center = target->GetPosition();
	const Vector2f& _relativePos = owner->GetPosition() - _center;
	const float _radAngle = DegToRad(rotateSpeed * _deltaTime);

	const float _newPosX = _relativePos.x * cos(_radAngle) - _relativePos.y * sin(_radAngle);
	const float _newPosY = _relativePos.x * sin(_radAngle) + _relativePos.y * cos(_radAngle);
	const Vector2f& _newPosition = _center + Vector2f(_newPosX, _newPosY);

	owner->SetPosition(_newPosition);
}

void MovementComponent::Rotate(const float _degree)
{
	UpdateDirection(_degree);

	currentAngle += _degree;
	if (currentAngle > 360.0f)
	{
		currentAngle = 0.0f;
	}
	else if (currentAngle < 0.0f)
	{
		currentAngle = 360.0f;
	}
	owner->Rotate(Angle(degrees(_degree)));

}

void MovementComponent::UpdateDirection(const float _degree)
{
	float _cos = cos(DegToRad(_degree));
	float _sin = sin(DegToRad(_degree));

	direction.x = direction.x * _cos - direction.y * _sin;
	direction.y = direction.x * _sin + direction.y * _cos;
}

void MovementComponent::ComputeAcceleration()
{
	acceleration.x += 2.0f * cos(currentAngle);
	acceleration.y += 2.0f * sin(currentAngle);
	LOG(Warning, acceleration);
	LOG(Error, direction);
}
