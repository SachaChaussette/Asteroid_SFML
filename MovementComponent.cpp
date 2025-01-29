#include "MovementComponent.h"
#include "Actor.h"
#include "GameManager.h"
#include "TimerManager.h"

MovementComponent::MovementComponent(Actor* _owner) : Component(_owner)
{
	_offset = Vector2f();
	speed = 1.0f;
	deltaTime = 0.0f;
	friction = 0.9f;
	currentAngle = 270.0f;
	rotateSpeed = 30.0f;
	speedLimit = Vector2f(0.05f, 0.05f);
	acceleration = Vector2f();
	direction = Vector2f(1.0f, 1.0f);
	target = nullptr;
}

MovementComponent::MovementComponent(Actor* _owner, const MovementComponent* _other) : Component(_owner)
{
	_offset = _other->_offset;
	deltaTime = _other->deltaTime;
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

void MovementComponent::BeginPlay()
{
	Super::BeginPlay();

	//new Timer([&]() { LOG(Warning, _offset); }, seconds(0.5f), true, true);
}


void MovementComponent::Move(const float _deltaTime)
{
	deltaTime = _deltaTime;

	if (_offset.x > speedLimit.x) _offset.x = speedLimit.x;
	else if (_offset.x < -speedLimit.x) _offset.x = -speedLimit.x;

	if (_offset.y > speedLimit.y) _offset.y = speedLimit.y;
	else if (_offset.y < -speedLimit.y) _offset.y = -speedLimit.y;

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
	UpdateDirection();

	acceleration.x += 0.5f;
	acceleration.y += 0.5f;

	// Calcul l'offset et le cap pour ne pas aller au dela de la vitesse max
	_offset.x += direction.x * acceleration.x * deltaTime;
	_offset.y += direction.y * acceleration.y * deltaTime;
}
