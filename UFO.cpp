#include "UFO.h"
#include "GameManager.h"
#include "Player.h"
#include "Asteroid.h"
#include "Projectile.h"

UFO::UFO(const float _radius, const SizeType& _size, const string& _path, const TextureExtensionType& _textureType,
	const IntRect& _rect) : Entity(1, _size, 4, MeshActor(_radius, "UFO/" + _path, _textureType, _rect, false, false), "UFO")
{
	movement = CreateComponent<EnemyMovementComponent>();
	shoot = CreateComponent<ShootComponent>();
	convexShapePoints =
	{ 
		{170.0f, 70.0f},	{220.0f, 120.0f}, 
		{300.0f, 150.0f},	{330.0f, 180.0f}, 
		{300.0f, 210.0f},	{160.0f, 240.0f}, 
		{30.0f, 210.0f},	{0.0f, 180.0f},
		{30.0f, 150.0f},	{110.0f, 120.0f}, 
	};
}

UFO::UFO(const UFO& _other) : Entity(_other)
{
	movement = CreateComponent<EnemyMovementComponent>(_other.movement);
	shoot = CreateComponent<ShootComponent>(_other.shoot);
	size = _other.size;

}


void UFO::ComputeNewDirection()
{
	GetMovement()->SetDirection(Vector2f(
	GetRandomNumberInRange(0.01f, 1.0f),
	GetRandomNumberInRange(-1.0f, 1.0f)));
}

void UFO::Construct()
{
	Super::Construct();

	SetLayer(Layer::ASTEROID);

	const vector<pair<string, CollisionType>>& _responses
	{
		{"Player", CT_OVERLAP},
		{"Asteroid", CT_OVERLAP},
		{"UFO", CT_NONE},
		{"Projectile", CT_OVERLAP},
	};
	GetCollision()->AddResponses(_responses);

	// Scale
	const float _scaleFactor = 0.15f * CAST(float, size);
	SetScale({ _scaleFactor , _scaleFactor });
}

void UFO::Tick(const float _deltaTime)
{
	Super::Tick(_deltaTime);
}

void UFO::BeginPlay()
{
	Super::BeginPlay();
	new Timer<Seconds>([&]() { ComputeNewDirection(); }, seconds(3.0f), true, true);
	new Timer<Seconds>([&]() { shoot->Shoot(); }, seconds(5.0f), true, true);
}

void UFO::Deconstruct()
{
	Super::Deconstruct();
}


void UFO::OnCollision(const CollisionData& _data)
{
	Super::OnCollision(_data);

	if (_data.other->GetLayer() == Layer::PLAYER)
	{
		Player* _player = Cast<Player>(_data.other);
		_player->GetLife()->DecrementLife();
	}
	else if (_data.other->GetLayer() == Layer::ASTEROID)
	{
		Asteroid* _asteroid = Cast<Asteroid>(_data.other);
		_asteroid->GetLife()->DecrementLife();
	}
	else if (_data.other->GetLayer() == Layer::PROJECTILE)
	{
		Projectile* _projectile = Cast<Projectile>(_data.other);
		if (_projectile->GetFriendlyLayer() == Layer::UFO) return;
		_projectile->GetLife()->DecrementLife();
	}
}


