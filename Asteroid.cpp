#include "Asteroid.h"
#include "GameManager.h"
#include "Level.h"


Asteroid::Asteroid(const float _radius, const SizeType& _size, const string& _path
	, const TextureExtensionType& _textureType, const IntRect& _rect)
	: Entity(1, _radius, 26, "Asteroid/" + _path, _textureType, _rect)
{
	movement = CreateComponent<EnemyMovementComponent>();
	size = _size;
	convexShapePoints =
	{ 
		{30.0f, 20.0f},		{80.0f, 0.0f}, 
		{220.0f, 20.0f},	{260.0f, 60.0f}, 
		{260.0f, 120.0f},	{230.0f, 180.0f}, 
		{80.0f, 190.0f},	{60.0f, 180.0f}, 
		{40.0f, 180.0f},	{0.0f, 100.0f}, 
	};

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

	// Scale
	const float _scaleFactor = 0.15f * CAST(float,size);
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
			Asteroid* _smallerAsteroid1 = Level::SpawnActor(Asteroid(SizeType(size - 1)));
			_smallerAsteroid1->ComputeNewDirection();
			_smallerAsteroid1->SetOriginAtMiddle();
			_smallerAsteroid1->SetPosition(GetPosition());
		}
	}
	Super::Deconstruct();
}
