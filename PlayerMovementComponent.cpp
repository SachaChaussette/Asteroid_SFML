#include "PlayerMovementComponent.h"
#include "Actor.h"
#include "GameManager.h"
#include "TimerManager.h"

PlayerMovementComponent::PlayerMovementComponent(Actor* _owner) : Component(_owner)
{
	velocity = Vector2f();
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

PlayerMovementComponent::PlayerMovementComponent(Actor* _owner, const PlayerMovementComponent* _other) : Component(_owner)
{
	velocity = _other->velocity;
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

void PlayerMovementComponent::Tick(const float _deltaTime)
{
	Super::Tick(_deltaTime);

	Move(_deltaTime);
	//owner->SetRotation(Angle(degrees(direction * 180.0f));
	//RotateAround(_deltaTime);
}

void PlayerMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	//new Timer([&]() { LOG(Warning, velocity); }, seconds(0.5f), true, true);
}


void PlayerMovementComponent::Move(const float _deltaTime)
{
	deltaTime = _deltaTime;

	if (velocity.x > speedLimit.x) velocity.x = speedLimit.x;
	else if (velocity.x < -speedLimit.x) velocity.x = -speedLimit.x;

	if (velocity.y > speedLimit.y) velocity.y = speedLimit.y;
	else if (velocity.y < -speedLimit.y) velocity.y = -speedLimit.y;

	owner->Move(velocity);
	//acceleration = Vector2f();
}

void PlayerMovementComponent::RotateAround(const float _deltaTime)
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

void PlayerMovementComponent::Rotate(const float _degree)
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

void PlayerMovementComponent::UpdateDirection()
{
	const float _rad = DegToRad(currentAngle);
	direction.x = cos(_rad);
	direction.y = sin(_rad);
}

void PlayerMovementComponent::ComputeAcceleration()
{
	UpdateDirection();

	acceleration.x += 0.5f;
	acceleration.y += 0.5f;

	// Calcul l'offset et le cap pour ne pas aller au dela de la vitesse max
	velocity.x += direction.x * acceleration.x * deltaTime;
	velocity.y += direction.y * acceleration.y * deltaTime;
}
