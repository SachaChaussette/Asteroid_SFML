#include "Asteroid.h"
#include "GameManager.h"
#include "Level.h"
#include "Player.h"
#include "UFO.h"
#include "Projectile.h"


Asteroid::Asteroid(const vector<Vector2f>& _point, const string& _path, const SizeType& _size, const TextureExtensionType& _textureType,
	const IntRect& _rect, bool _isRepeated, bool _isSmooth, const string& _name)
	: Entity(1, _size, 26, MeshActor(_point, "Asteroid/" + _path, _textureType, _rect), "Asteroid")
{
	movement = CreateComponent<EnemyMovementComponent>();
}
Asteroid::Asteroid(const Asteroid& _other) : Entity(_other)
{
	movement = CreateComponent<EnemyMovementComponent>(_other.movement);
}



void Asteroid::ComputeNewDirection()
{
	movement->SetDirection(Vector2f(
	GetRandomNumberInRange(0.01f, 1.0f),
	GetRandomNumberInRange(-1.0f, 1.0f)));
}

void Asteroid::Construct()
{
	Super::Construct();

	SetLayer(Layer::ASTEROID);

	const vector<pair<string, CollisionType>>& _responses
	{
		{"Player", CT_OVERLAP},
		{"Asteroid", CT_NONE},
		{"UFO", CT_OVERLAP},
		{"Projectile", CT_OVERLAP},
	};
	GetCollision()->AddResponses(_responses);

	// Scale
	const float _scaleFactor = 1.65f * CAST(float,size);
	SetScale({ _scaleFactor , _scaleFactor });
}

void Asteroid::Tick(const float _deltaTime)
{
	Super::Tick(_deltaTime);

}

void Asteroid::Deconstruct()
{
	Super::Deconstruct();
}

void Asteroid::OnCollision(const CollisionData& _data)
{
	Super::OnCollision(_data);

	if (_data.other->GetLayer() == Layer::PLAYER)
	{
		Player* _player = Cast<Player>(_data.other);
		_player->GetLife()->DecrementLife();
	}
	else if (_data.other->GetLayer() == Layer::UFO)
	{
		UFO* _ufo = Cast<UFO>(_data.other);
		_ufo->GetLife()->DecrementLife();
	}
	else if (_data.other->GetLayer() == Layer::PROJECTILE)
	{
		Projectile* _projectile = Cast<Projectile>(_data.other);
		if (_projectile->GetFriendlyLayer() == Layer::ASTEROID) return;
		_projectile->GetLife()->DecrementLife();
	}

}
