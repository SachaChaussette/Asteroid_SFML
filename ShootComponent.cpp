#include "ShootComponent.h"
#include "Level.h"
#include "PlayerMovementComponent.h"

ShootComponent::ShootComponent(Actor* _owner) : Component(_owner)
{
	owner = _owner;
}

ShootComponent::ShootComponent(Actor* _owner, const ShootComponent* _other) : Component(_owner)
{
	owner = _owner;
}

void ShootComponent::Shoot()
{
	// On prend un offset qui sera appliquer � la direction + centre de l'actor qui shoot
	const Vector2f& _offset = Vector2f(0.0f, 40.0f);

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
	const Vector2f& _newPos = owner->GetChildrenAtIndex(0)->GetPosition();
	
	// On spawn le projectile aux nouvelles coordon�es et on lui donne la direction du tir
	Projectile* _projectile = Level::SpawnActor(Projectile(10.0f, Vector2f(20.0f, 10.0f), "projectile"));
	_projectile->SetOriginAtMiddle();
	_projectile->Rotate(degrees(90));
	_projectile->Rotate(owner->GetChildrenAtIndex(0)->GetRotation());
	_projectile->SetFriendlyLayer(owner->GetChildrenAtIndex(0)->GetLayer());

	_projectile->SetPosition(_newPos);
	_projectile->GetMovement()->SetDirection(_direction);
}
