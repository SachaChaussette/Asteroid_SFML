#include "Projectile.h"
#include "Player.h"
#include "UFO.h"
#include "Asteroid.h"
#include "Layer.h"

Projectile::Projectile(const CircleShapeData& _data, const vector<Vector2f>& _point,
	const SizeType& _size, const string& _name)
	: Entity(3, _size, 1, MeshActor(_data), MeshActor(_point, "Transparent"), _name)
{
	movement = CreateComponent<EnemyMovementComponent>();
	friendlyLayer = Layer::COUNT;
}

Projectile::Projectile(const RectangleShapeData& _data, const vector<Vector2f>& _point,
	const SizeType& _size, const string& _name)
	: Entity(3, _size, 1, MeshActor(_data), MeshActor(_size, "Transparent"), "Player")
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
	// TODO
	//SetLifeSpan(5.0f);
	Super::BeginPlay();
}


void Projectile::Construct()
{
	Super::Construct();
	movement->SetSpeed(250.0f);

	convexHitBox->AddComponent(new CollisionComponent(convexHitBox, "Projectile", IS_ALL, CT_OVERLAP));
	// TODO
	//convexHitBox->SetLayer(Layer::PROJECTILE);
	
	const vector<pair<string, CollisionType>>& _responses
	{
		{"Player", CT_NONE},
		{"Asteroid", CT_OVERLAP},
		{"UFO", CT_OVERLAP},
		{"Projectile", CT_NONE},
	};
	AddCollisionResponses(_responses);
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

void Projectile::CollisionEnter(const CollisionData& _data)
{
	Super::CollisionEnter(_data);
	// TODO
	/*if (Entity* _entity = Cast<Entity>(_data.other))
	{
		Layer::LayerType _layerType = _entity->GetConvexHitBox()->GetLayer();
		if (_layerType == Layer::PLAYER && friendlyLayer != Layer::PLAYER)
		{
			Player* _player = Cast<Player>(_entity);
			_player->GetLife()->DecrementLife();
		}
		if (_layerType == Layer::UFO && friendlyLayer != Layer::UFO)
		{
			UFO* _ufo = Cast<UFO>(_entity);
			_ufo->GetLife()->DecrementLife();
		}
		else if (_layerType == Layer::ASTEROID && friendlyLayer != Layer::ASTEROID)
		{
			Asteroid* _asteroid = Cast<Asteroid>(_entity);
			_asteroid->GetLife()->DecrementLife();
		}
	}*/
	

}

