#include "Asteroid.h"
#include "GameManager.h"
#include "Level.h"
#include "Player.h"
#include "UFO.h"
#include "Projectile.h"
#include "LevelManager.h"


Asteroid::Asteroid(const CircleShapeData& _data, const vector<Vector2f>& _point, 
	const SizeType& _size, const string& _name)
	: Entity(1, _size, 26, MeshActor(_data), MeshActor(_point, "Transparent"), _name)
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

	convexHitBox->AddComponent(new CollisionComponent(convexHitBox, "Asteroid", IS_ALL, CT_OVERLAP));
	// TODO
	//convexHitBox->SetLayer(Layer::ASTEROID);

	const vector<pair<string, CollisionType>>& _responses
	{
		{"Player", CT_OVERLAP},
		{"Asteroid", CT_NONE},
		{"UFO", CT_OVERLAP},
		{"Projectile", CT_OVERLAP},
	};
	AddCollisionResponses(_responses);


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
	if (size > SMALL)
	{
		for (size_t _i = 0; _i < 2; _i++)
		{
			const Vector2f& _windowSize = M_LEVEL.GetCurrentLevel()->GetWindowSize();

			const vector<Vector2f>& _convexShapePoints =
			{
				{3.0f,14.0f}, {10.0f,5.0f},
				{18.0f,5.0f}, {29.0f,11.0f},
				{29.0f,16.0f}, {26.0f,23.0f},
				{19.0f,28.0f}, {13.0f,28.0f},
				{3.0f,19.0f}, {3.0f,14.0f},
			};
			// TODO
			//Asteroid* _asteroid = Level::SpawnActor(Asteroid(20.0f, _convexShapePoints, GetMesh()->GetTexturePath(), SizeType(size - 1)));
			//_asteroid->ComputeNewDirection();
			//_asteroid->SetOriginAtMiddle();
			//_asteroid->SetPosition(GetPosition());
		}
	}
	Super::Deconstruct();
}

void Asteroid::CollisionEnter(const CollisionData& _data)
{
	Super::CollisionEnter(_data);
	if (Entity* _entity = Cast<Entity>(_data.other))
	{
		// TODO
		/*Layer::LayerType _layerType = _entity->GetConvexHitBox()->GetLayer();
		if (_layerType == Layer::UFO)
		{
			UFO* _ufo = Cast<UFO>(_entity);
			_ufo->GetLife()->DecrementLife();
		}
		else if (_layerType == Layer::PROJECTILE)
		{
			Projectile* _projectile = Cast<Projectile>(_entity);
			if (_projectile->GetFriendlyLayer() == Layer::ASTEROID) return;
			_projectile->GetLife()->DecrementLife();
		}
		else if (_layerType == Layer::PLAYER)
		{
			Player* _player = Cast<Player>(_entity);
			_player->GetLife()->DecrementLife();
		}*/
	}
}
