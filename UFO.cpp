#include "UFO.h"
#include "Player.h"
#include "Asteroid.h"
#include "Projectile.h"

UFO::UFO(Level* _level, const CircleShapeData& _data, const ConvexShapeData& _hitBoxData,
	const SizeType& _size, const string& _name)
	: Entity(1, _size, 26, MeshActor(_level, _data), MeshActor(_level, _hitBoxData), _name)
{
	movement = CreateComponent<EnemyMovementComponent>();
	shoot = CreateComponent<ShootComponent>();
}

UFO::UFO(const UFO& _other) : Entity(_other)
{
	movement = CreateComponent<EnemyMovementComponent>(_other.movement);
	shoot = CreateComponent<ShootComponent>(_other.shoot);


}

UFO::~UFO()
{
	//M_TIMER.RemoveTimer(shootTimer);
	//M_TIMER.RemoveTimer(directionTimer);
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

	convexHitBox->AddComponent(new CollisionComponent(convexHitBox, "UFO", IS_ALL, CT_OVERLAP));
	convexHitBox->SetLayerType(Layer::UFO);

	const vector<pair<string, CollisionType>>& _responses
	{
		{"Player", CT_OVERLAP},
		{"Asteroid", CT_OVERLAP},
		{"UFO", CT_NONE},
		{"Projectile", CT_OVERLAP},
	};
	AddCollisionResponses(_responses);

	// Scale
	const float _scaleFactor = 1.65f * CAST(float, size);
	SetScale({ _scaleFactor , _scaleFactor });

	directionTimer = new Timer<Seconds>([&]() { ComputeNewDirection(); }, seconds(3.0f), true, true);
	shootTimer = new Timer<Seconds>([&]() { shoot->Shoot(); }, seconds(5.0f), true, true);
}

void UFO::Tick(const float _deltaTime)
{
	Super::Tick(_deltaTime);
}

void UFO::BeginPlay()
{
	Super::BeginPlay();
}

void UFO::Deconstruct()
{
	Super::Deconstruct();
	M_TIMER.RemoveTimer(directionTimer);
	M_TIMER.RemoveTimer(shootTimer);
}

void UFO::CollisionEnter(const CollisionData& _data)
{
	Super::CollisionEnter(_data);
	if (Entity* _entity = Cast<Entity>(_data.other))
	{
		Layer::LayerType _layerType = _entity->GetConvexHitBox()->GetLayerType();
		if (_layerType == Layer::ASTEROID)
		{
			Asteroid* _asteroid = Cast<Asteroid>(_entity);
			_asteroid->GetLife()->DecrementLife();
		}
		else if (_layerType == Layer::PROJECTILE)
		{
			Projectile* _projectile = Cast<Projectile>(_entity);
			if (_projectile->GetFriendlyLayer() == Layer::UFO) return;
			_projectile->GetLife()->DecrementLife();
		}
		else if (_layerType == Layer::PLAYER)
		{
			Player* _player = Cast<Player>(_entity);
			_player->GetLife()->DecrementLife();
		}
	}
}

