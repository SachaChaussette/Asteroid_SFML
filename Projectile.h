#pragma once

#include "Entity.h"
#include "EnemyMovementComponent.h"
#include "AnimationComponent.h"
#include "SizeType.h"


class Projectile : public Entity
{
	EnemyMovementComponent* movement;
	Layer::LayerType friendlyLayer;
public:
	FORCEINLINE Layer::LayerType GetFriendlyLayer() const
	{
		return friendlyLayer;
	}
	FORCEINLINE void SetFriendlyLayer(const Layer::LayerType& _friendlyLayer)
	{
		friendlyLayer = _friendlyLayer;
	}
	FORCEINLINE EnemyMovementComponent* GetMovement() const
	{
		return movement;
	}
public:
	Projectile(const float _radius, const Vector2f& _size, const string& _path = "",
		const TextureExtensionType& _textureType = PNG, const IntRect& _rect = {});
	Projectile(const Projectile& _other);

	virtual void Construct() override;
	virtual void Tick(const float _deltaTime) override;
	virtual void BeginPlay() override ;
	virtual void Deconstruct() override ;

	void OnCollision(const CollisionData& _data);

};

