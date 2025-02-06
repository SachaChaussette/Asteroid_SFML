#include "EnemyMovementComponent.h"
#include "Actor.h"

EnemyMovementComponent::EnemyMovementComponent(Actor* _owner) : Component(_owner)
{
	speed = 100.0f;
	rotateSpeed = 30.0f;
	direction = Vector2f(1.0f, 0.0f);
}

EnemyMovementComponent::EnemyMovementComponent(Actor* _owner, const EnemyMovementComponent* _other) : Component(_owner)
{
	speed = _other->speed;
	rotateSpeed = _other->rotateSpeed;
	direction = _other->direction;
}


void EnemyMovementComponent::Tick(const float _deltaTime)
{
	Super::Tick(_deltaTime);

	Move(_deltaTime);
	//RotateAround(_deltaTime);
}


void EnemyMovementComponent::Move(const float _deltaTime)
{
	const Vector2f& _offset = direction * speed * _deltaTime;
	owner->Move(_offset);
}
