#pragma once

#include "MeshActor.h"
#include "SizeType.h"
#include "AnimationComponent.h"
#include "LifeComponent.h"

class Entity : public MeshActor
{
protected:
	AnimationComponent* animation;
	LifeComponent* life;
	u_int spriteCount;
	SizeType size;
protected:
	
public:
	Entity(const u_int& _lifeCount, const float _radius, const u_int& _spriteCount, const string& _path = "",
		const TextureExtensionType& _textureType = PNG, const IntRect& _rect = {}, bool _isRepeated = false, bool _isSmooth = true,
		const string& _name = "Entity");
	Entity(const u_int& _lifeCount, const Vector2f& _size, const u_int& _spriteCount, const string& _path = "", const TextureExtensionType& _textureType = PNG,
		const IntRect& _rect = {}, bool _isRepeated = false, bool _isSmooth = false,
		const string& _name = "Entity");
	Entity(const Entity& _other);
protected:
	virtual void Tick(const float _deltaTime) override;
	void ComputeNewPositionIfNotInWindow();
	virtual void Construct() override;
};

