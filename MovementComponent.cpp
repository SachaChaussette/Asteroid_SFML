#include "MovementComponent.h"
#include "Actor.h"

MovementComponent::MovementComponent(Actor* _owner) : Component(_owner)
{
	speed = 100.0f;
	rotateSpeed = 30.0f;
	direction = Vector2f();
	target = nullptr;
}

MovementComponent::MovementComponent(Actor* _owner, const MovementComponent* _other) : Component(_owner)
{
	speed = _other->speed;
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
	const Vector2f& _offset = direction * speed * _deltaTime;
	owner->Move(_offset);
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

void MovementComponent::RotateDirection(const float _degree)
{
	Vector2f _result = Vector2f(_degree / 90.0f, _degree / 90.0f);
	direction.x += _result.x;
	direction.y += _result.y;
	owner->Rotate(Angle(degrees(_degree)));

	auto angle = atan2f(90 / 360.0f, 90 / 360.0f);

	if (direction.x > 1.0f || direction.x < -1.0f) direction.x *= -1;
	if (direction.y > 1.0f || direction.y < -1.0f) direction.y *= -1;

	LOG(Display, to_string(angle * 360.0f / pi));
	LOG(Warning, direction);
	//LOG(Error, _result);
}
