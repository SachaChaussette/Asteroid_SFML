#include "ShootComponent.h"
#include "Level.h"
#include "PlayerMovementComponent.h"

ShootComponent::ShootComponent(Actor* _owner) : Component(_owner)
{
	projectile = new Projectile(20.0f, "Shoot/laser", PNG, IntRect(Vector2i(), Vector2i(16, 16)));
}

ShootComponent::ShootComponent(Actor* _owner, const ShootComponent* _other) : Component(_owner)
{
	projectile = _other->projectile;
}

void ShootComponent::Shoot()
{
	projectile->SetFriendlyLayer(owner->GetLayer());

	// On prend un offset qui sera appliquer à la direction + centre de l'actor qui shoot
	const Vector2f& _offset = Vector2f(22.0f, 75.0f);

	float _currentAngle = 0.0f;
	if (PlayerMovementComponent* _movement  = owner->GetComponent<PlayerMovementComponent>())
	{
		_currentAngle = _movement->GetCurrentAngle();
	}
	else
	{
		_currentAngle = GetRandomNumberInRange(1.0f, 360.0f);
	}
	const float _rad = DegToRad(_currentAngle);
	const Vector2f& _direction = Vector2f(cos(_rad), sin(_rad));

	// Calcule la nouvelle pos
	const Vector2f& _newPos = owner->GetPosition() - _offset + _direction;

	// On spawn le projectile aux nouvelles coordonées et on lui donne la direction du tir
	Projectile* _projectile = Level::SpawnActor(Projectile(*projectile));
	_projectile->SetPosition(_newPos);
	_projectile->GetMovement()->SetDirection(_direction);
}
