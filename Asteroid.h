#pragma once
#include "MeshActor.h"
#include "Entity.h"
#include "AnimationComponent.h"
#include "EnemyMovementComponent.h"
#include "SizeType.h"
#include "CollisionComponent.h"



class Asteroid : public Entity
{
	EnemyMovementComponent* movement;

public:
	FORCEINLINE EnemyMovementComponent* GetMovement() const
	{
		return movement;
	}
public:
	Asteroid(const vector<Vector2f>& _point, const string& _path = "", const SizeType& _size = BIG, const TextureExtensionType& _textureType = PNG,
		const IntRect& _rect = {}, bool _isRepeated = false, bool _isSmooth = false, const string& _name = "Asteroid");
	Asteroid(const Asteroid& _other);

public: 
	void ComputeNewDirection();
	virtual void Construct() override;
	virtual void Tick(const float _deltaTime) override;
	virtual void Deconstruct() override;
	virtual void OnCollision(const CollisionData& _data) override;
};

