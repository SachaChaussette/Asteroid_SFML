#include "MovementComponent.h"
#include "Actor.h"

MovementComponent::MovementComponent(Actor* _owner) : Component(_owner)
{
	speed = 1.0f;
	friction = 0.95f;
	currentAngle = 270.0f;
	rotateSpeed = 30.0f;
	speedLimit = Vector2f(200.0f, 200.0f);
	acceleration = Vector2f(1.0f, 1.0f);
	direction = Vector2f(1.0f, 1.0f);
	target = nullptr;
}

MovementComponent::MovementComponent(Actor* _owner, const MovementComponent* _other) : Component(_owner)
{
	speed = _other->speed;
	friction = _other->friction;
	currentAngle = _other->currentAngle;
	rotateSpeed = _other->rotateSpeed;
	speedLimit = _other->speedLimit;
	acceleration = _other->acceleration;
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
	Vector2f _offset;

	// Calcul l'offset et le cap pour ne pas aller au dela de la vitesse max
	_offset.x = acceleration.x < speedLimit.x ? direction.x * acceleration.x * _deltaTime : direction.x * speedLimit.x * _deltaTime;
	_offset.y = acceleration.y < speedLimit.x ? direction.y * acceleration.y * _deltaTime : direction.y * speedLimit.y * _deltaTime;
	
	owner->Move(_offset);
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
	UpdateDirection();

	currentAngle += _degree;
	if (currentAngle > 360.0f)
	{
		currentAngle -= 360.0f;
	}
	else if (currentAngle < 0.0f)
	{
		currentAngle = 360.0f;
	}

	owner->Rotate(Angle(degrees(_degree)));
}

void MovementComponent::UpdateDirection()
{
	const float _rad = DegToRad(currentAngle);
	direction.x = cos(_rad);
	direction.y = sin(_rad);
}

void MovementComponent::ComputeAcceleration()
{
	acceleration.x *= 1.1f;
	acceleration.y *= 1.1f;
}
