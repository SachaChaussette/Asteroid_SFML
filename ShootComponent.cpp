#include "ShootComponent.h"
#include "LevelManager.h"
#include "PlayerMovementComponent.h"

ShootComponent::ShootComponent(Actor* _owner) : Component(_owner)
{

}

ShootComponent::ShootComponent(Actor* _owner, const ShootComponent* _other) : Component(_owner)
{
}

void ShootComponent::Shoot()
{
	// On prend un offset qui sera appliquer à la direction + centre de l'actor qui shoot
	const Vector2f& _offset = Vector2f(22.0f, 34.0f);

	if (Entity* _entity = Cast<Entity>(owner))
	{
		float _currentAngle = 0.0f;
		if (PlayerMovementComponent* _movement = _entity->GetComponent<PlayerMovementComponent>())
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
		const Vector2f& _newPos = _entity->GetPosition() - _offset + _direction;

		// On spawn le projectile aux nouvelles coordonées et on lui donne la direction du tir
		
		const RectangleShapeData& _hitBoxData = RectangleShapeData(Vector2f(10.0f, 20.0f), "projectile");
		const CircleShapeData& _shapeData = CircleShapeData(10.0f, "Transparent");
		Projectile* _projectile = M_LEVEL.GetCurrentLevel()->SpawnActor<Projectile>(_shapeData, _hitBoxData);

		_projectile->SetFriendlyLayer(_entity->GetConvexHitBox()->GetLayerType());

		_projectile->SetPosition(_newPos);
		_projectile->GetMovement()->SetDirection(_direction);
	}
	
}
