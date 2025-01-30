#include "PlayerMovementComponent.h"
#include "Actor.h"
#include "GameManager.h"
#include "TimerManager.h"

PlayerMovementComponent::PlayerMovementComponent(Actor* _owner) : Component(_owner)
{
	velocity = Vector2f();
	deltaTime = 0.0f;
	friction = 0.9f;
	currentAngle = 270.0f;
	maxVelocity = Vector2f(0.1f, 0.1f);
	acceleration = Vector2f();
	direction = Vector2f(1.0f, 1.0f);
}

PlayerMovementComponent::PlayerMovementComponent(Actor* _owner, const PlayerMovementComponent* _other) : Component(_owner)
{
	velocity = _other->velocity;
	deltaTime = _other->deltaTime;
	friction = _other->friction;
	currentAngle = _other->currentAngle;
	maxVelocity = _other->maxVelocity;
	acceleration = _other->acceleration;
	direction = _other->direction;
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

	if (velocity.x > maxVelocity.x) velocity.x = maxVelocity.x;
	else if (velocity.x < -maxVelocity.x) velocity.x = -maxVelocity.x;

	if (velocity.y > maxVelocity.y) velocity.y = maxVelocity.y;
	else if (velocity.y < -maxVelocity.y) velocity.y = -maxVelocity.y;

	owner->Move(velocity);
	//acceleration = Vector2f();
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
