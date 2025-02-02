#include "CollisionComponent.h"
#include "Player.h"
#include "Asteroid.h"
#include "UFO.h"


CollisionComponent::CollisionComponent(Actor* _owner, const CollisionType& _type) : Component(_owner)
{
	playerCollisionType = _type;
}
CollisionComponent::CollisionComponent(Actor* _owner, const CollisionComponent* _other) : Component(_owner)
{
	playerCollisionType = _other->playerCollisionType;
}


void CollisionComponent::Tick(const float _deltaTime)
{
	Super::Tick(_deltaTime);
}

void CollisionComponent::CheckCollide(const Shape* _playerShape, set<MeshActor*>& _objects, const bool _isUFO)
{
	const FloatRect& _playerRect = _playerShape->getGlobalBounds();

	MeshActor* _toDelete;

	if (_isUFO)
	{
		set<MeshActor*> _ufos;
		for (MeshActor* _object : _objects)
		{
			if (CAST(UFO*, _object)->collision->playerCollisionType == CT_NONE) return;

			Shape* _objectShape = _object->GetMesh()->GetShape()->GetDrawable();
			const FloatRect& _objectRect = _objectShape->getGlobalBounds();

			if (const optional<FloatRect> _intersection = _playerRect.findIntersection(_objectRect))
			{
				// Collision Ufo
			}
		}
		if (_ufos.size() > 0)
		{
			_objects = _ufos;
		}
	}
	else
	{
		set<MeshActor*> _asteroids;
		for (MeshActor* _object : _objects)
		{
			if (CAST(Asteroid*, _object)->collision->playerCollisionType == CT_NONE) return;

			Shape* _objectShape = _object->GetMesh()->GetShape()->GetDrawable();
			const FloatRect& _objectRect = _objectShape->getGlobalBounds();

			if (const optional<FloatRect> _intersection = _playerRect.findIntersection(_objectRect))
			{
				// Collision Astéroid
				set<Asteroid*> _newObjects;
				for (MeshActor* _aste : _objects)
				{
					_newObjects.insert(CAST(Asteroid*, _aste));
				}

				CAST(Asteroid*, _object)->Divide(_newObjects);


				for (Asteroid* _obj : _newObjects)
				{
					_asteroids.insert(CAST(MeshActor*, _obj));
				}


				_object->SetToDelete();
				_toDelete = _object;
			}
		}
		if (_asteroids.size() > 0)
		{
			_objects = _asteroids;
		}
	}
	
	_objects.erase(_toDelete);
}