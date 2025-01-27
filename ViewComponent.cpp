#include "ViewComponent.h"
#include "Actor.h"

ViewComponent::ViewComponent(Actor* _owner, const Vector2f& _center, const Vector2f& _size) : Component(_owner)
{
	view = View(_center, _size);
}

ViewComponent::ViewComponent(Actor* _owner, ViewComponent* _other) : Component(_owner)
{
	center = _other->center;
	size = _other->size;
}