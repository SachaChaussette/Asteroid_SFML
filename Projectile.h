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
	Projectile(Level* _level, const CircleShapeData& _data, const ConvexShapeData& _hitBoxData,
		const SizeType& _size = SMALL, const string& _name = "Projectile");
	Projectile(Level* _level, const CircleShapeData & _data, const RectangleShapeData& _hitBoxData,
		const SizeType& _size = SMALL, const string& _name = "Projectile");
	Projectile(const Projectile& _other);

	virtual void Construct() override;
	virtual void Tick(const float _deltaTime) override;
	virtual void BeginPlay() override ;
	virtual void Deconstruct() override ;

	virtual void CollisionEnter(const CollisionData& _data) override;

};

