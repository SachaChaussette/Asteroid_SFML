#include "Projectile.h"
#include "Player.h"
#include "UFO.h"
#include "Asteroid.h"

Projectile::Projectile(const Vector2f& _size, const string& _path
	, const TextureExtensionType& _textureType, const IntRect& _rect)
	: Entity(1, SMALL, 4, MeshActor(_size, "Shoot/" + _path, _textureType, _rect), "Projectile")
{
	movement = CreateComponent<EnemyMovementComponent>();
	friendlyLayer = Layer::COUNT;
}

Projectile::Projectile(const Projectile& _other) : Entity(_other)
{
	movement = CreateComponent<EnemyMovementComponent>(_other.movement);
	friendlyLayer = _other.friendlyLayer;
}

void Projectile::BeginPlay()
{
	SetLifeSpan(5.0f);
	Super::BeginPlay();
}


void Projectile::Construct()
{
	Super::Construct();
	movement->SetSpeed(150.0f);

	SetLayer(Layer::PROJECTILE);
	
	const vector<pair<string, CollisionType>>& _responses
	{
		// TODO CHANGE PLAYER
		{"Player", CT_NONE},
		{"Asteroid", CT_OVERLAP},
		{"UFO", CT_OVERLAP},
		{"Projectile", CT_NONE},
	};
	collision->AddResponses(_responses);

	// Scale
	const float _scaleFactor = 1.65f * CAST(float, size);
	SetScale({ _scaleFactor , _scaleFactor });

}

void Projectile::Tick(const float _deltaTime)
{
	Super::Tick(_deltaTime);
}

void Projectile::Deconstruct()
{
	Super::Deconstruct();
}

void Projectile::OnCollision(const CollisionData& _data)
{
	Super::OnCollision(_data);

	if (_data.other->GetLayer() == Layer::PLAYER && friendlyLayer != Layer::PLAYER)
	{
		Player* _player = Cast<Player>(_data.other);
		_player->GetLife()->DecrementLife();
	}
	if (_data.other->GetLayer() == Layer::UFO && friendlyLayer != Layer::UFO)
	{
		UFO* _ufo = Cast<UFO>(_data.other);
		_ufo->GetLife()->DecrementLife();
	}
	else if (_data.other->GetLayer() == Layer::ASTEROID && friendlyLayer != Layer::ASTEROID)
	{
		Asteroid* _asteroid = Cast<Asteroid>(_data.other);
		_asteroid->GetLife()->DecrementLife();
	}

}

