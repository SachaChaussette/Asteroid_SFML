#include "UFO.h"
#include "GameManager.h"
#include "Player.h"
#include "Asteroid.h"
#include "Projectile.h"

UFO::UFO(const float _radius, const vector<Vector2f>& _point, const string& _path, const TextureExtensionType& _textureType,
	const IntRect& _rect, bool _isRepeated, bool _isSmooth, const string& _name) : 
	Entity(1, MEDIUM, 4, MeshActor(_radius, "UFO/" + _path, _textureType, _rect, _isRepeated, _isSmooth), MeshActor(_point, ""), "UFO")
{
	movement = CreateComponent<EnemyMovementComponent>();
	shoot = CreateComponent<ShootComponent>();
}

UFO::UFO(const UFO& _other) : Entity(_other)
{
	movement = CreateComponent<EnemyMovementComponent>(_other.movement);
	shoot = CreateComponent<ShootComponent>(_other.shoot);
	size = _other.size;

}

UFO::~UFO()
{
	M_TIMER.RemoveTimer(shootTimer);
	M_TIMER.RemoveTimer(directionTimer);
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

	convexHitBox->AddComponent(new CollisionComponent(this, "UFO", IS_ALL, CT_OVERLAP));
	convexHitBox->SetLayer(Layer::UFO);

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
}

void UFO::OnCollision(const CollisionData& _data)
{
	Super::OnCollision(_data);
	if (Entity* _entity = Cast<Entity>(_data.other))
	{
		Layer::LayerType _layerType = _entity->GetConvexHitBox()->GetLayer();
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

