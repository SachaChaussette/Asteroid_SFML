
#include "Asteroid.h"
#include "GameManager.h"
#include "Level.h"

Asteroid::Asteroid(const SizeType& _size, const string& _path
	, const TextureExtensionType& _textureType, const IntRect& _rect)
	: MeshActor(110.0f, _path,
		_textureType, _rect, false, false)
{
	animation = CreateComponent<AnimationComponent>();
	movement = CreateComponent<EnemyMovementComponent>();
	collision = CreateComponent<CollisionComponent>(CT_BLOCK);
	size = _size;
	convexShapePoints =
	{ 
		{30.0f, 20.0f},		{80.0f, 0.0f}, 
		{220.0f, 20.0f},	{260.0f, 60.0f}, 
		{260.0f, 120.0f},	{230.0f, 180.0f}, 
		{80.0f, 190.0f},	{60.0f, 180.0f}, 
		{40.0f, 180.0f},	{0.0f, 100.0f}, 
	};
	spriteCount = 26;
}

Asteroid::Asteroid(const Asteroid& _other) : MeshActor(_other)
{
	animation = CreateComponent<AnimationComponent>(_other.animation);
	movement = CreateComponent<EnemyMovementComponent>(_other.movement);
	collision = CreateComponent<CollisionComponent>(_other.collision);
	size = _other.size;
	spriteCount = _other.spriteCount;
}

void Asteroid::ComputeNewDirection()
{
	GetMovement()->SetDirection(Vector2f(
	GetRandomNumberInRange(0.01f, 1.0f),
	GetRandomNumberInRange(-1.0f, 1.0f)));
}

void Asteroid::Construct()
{
	Super::Construct();

	// Scale
	const float _scaleFactor = 0.15f * CAST(float,size);
	SetScale({ _scaleFactor , _scaleFactor });

	// Animation / Sprite
	vector<SpriteData> _spritesMove;
	const Vector2i& _moveSpriteSize = Vector2i( 32,32 );
	for (u_int _index = 0; _index < spriteCount; _index++)
	{
		const Vector2i& _currentPos = Vector2i(_moveSpriteSize.x * (_index % spriteCount/2), _moveSpriteSize.y * (_index / spriteCount/2));
		_spritesMove.push_back(SpriteData(_currentPos, _moveSpriteSize));
	}
	AnimationData _moveAnimationData = AnimationData(450.0f, _spritesMove);
	Animation* _move = new Animation("Movement", GetMesh()->GetShape(), _moveAnimationData);
	animation->AddAnimation(_move);
	animation->SetCurrentAnimation("Movement");
	animation->StartAnimation();
}

void Asteroid::Tick(const float _deltaTime)
{
	Super::Tick(_deltaTime);
	ComputeNewPositionIfNotInWindow();
}

void Asteroid::Deconstruct()
{

	Super::Deconstruct();
}

void Asteroid::Divide(set<Asteroid*>& _objects)
{
	if (size > SMALL)
	{
		for (size_t _i = 0; _i < 2; _i++)
		{
			Asteroid* _smallerAsteroid = Level::SpawnActor(Asteroid(SizeType(size - 1)));
			_smallerAsteroid->ComputeNewDirection();
			_smallerAsteroid->SetOriginAtMiddle();
			_smallerAsteroid->SetPosition(GetPosition());
			_objects.insert(_smallerAsteroid);
		}
	}
}
