#include "ShootComponent.h"
#include "Actor.h"
#include "Level.h"

ShootComponent::ShootComponent(Actor* _owner) : Component(_owner)
{
}

void ShootComponent::Shoot()
{
	// On prend un offset qui sera appliquer à la direction + centre de l'actor qui shoot
	const float _offset = 2.0f;

	// Calcule la nouvelle pos
	Vector2f _newPos = (owner->GetPosition() / 2.0f + currentDirection) * _offset;

	// On spawn le projectile aux nouvelles coordonées et on lui donne la direction du tir
	//Level::SpawnActor<Projectile>(_newPos, currentDirection);
}
