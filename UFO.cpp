#include "UFO.h"
#include "GameManager.h"

UFO::UFO(const SizeType& _size, const string& _path, const TextureExtensionType& _textureType, 
	const IntRect& _rect) : MeshActor(110.0f, _path, _textureType, _rect, false, false)
{
	animation = CreateComponent<AnimationComponent>();
	movement = CreateComponent<EnemyMovementComponent>();
	collision = CreateComponent<CollisionComponent>(CT_BLOCK);
	size = _size;
	convexShapePoints =
	{ 
		{170.0f, 70.0f},	{220.0f, 120.0f}, 
		{300.0f, 150.0f},	{330.0f, 180.0f}, 
		{300.0f, 210.0f},	{160.0f, 240.0f}, 
		{30.0f, 210.0f},	{0.0f, 180.0f},
		{30.0f, 150.0f},	{110.0f, 120.0f}, 
	};
	spriteCount = 4;
}

UFO::UFO(const UFO& _other) : MeshActor(_other)
{
	animation = CreateComponent<AnimationComponent>(_other.animation);
	movement = CreateComponent<EnemyMovementComponent>(_other.movement);
	collision = CreateComponent<CollisionComponent>(_other.collision);
	size = _other.size;
	spriteCount = _other.spriteCount;
}

void UFO::ComputeNewPositionIfNotInWindow()
{
	const Vector2f& _windowSize = CAST(Vector2f, M_GAME.GetCurrent()->GetWindowSize());
	const Vector2f& _UFOPosition = GetPosition();
	const Vector2f& _UFOScale = GetScale();
	const Vector2f& _UFOSize = Vector2f(_UFOScale.x, _UFOScale.y) / 2.0f; 

	if ((_UFOPosition.x + _UFOSize.x) < 0.0f)					// Gauche
	{
		SetPosition({ _windowSize.x + _UFOSize.x, _UFOPosition.y });
	}
	else if ((_UFOPosition.x - _UFOSize.x) > _windowSize.x)		// Droite
	{
		SetPosition({ 0.0f - _UFOSize.x, _UFOPosition.y });		
	}
	if ((_UFOPosition.y + _UFOSize.y) < 0.0f)					// Haut
	{
		SetPosition({ _UFOPosition.x , _windowSize.y + _UFOSize.y });
	}
	else if ((_UFOPosition.y - _UFOSize.y) > _windowSize.y)		// Bas
	{
		SetPosition({ _UFOPosition.x, 0.0f - _UFOSize.y });
	}
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

	// Scale
	const float _scaleFactor = 0.15f * CAST(float, size);
	SetScale({ _scaleFactor , _scaleFactor });

	// Animation / Sprite
	vector<SpriteData> _sprites;
	const Vector2i& _spriteSize = Vector2i(32, 32);

	for (u_int _index = 0; _index < spriteCount; _index++)
	{
		const Vector2i& _currentPos = Vector2i(0 , _spriteSize.y * (_index));
		_sprites.push_back(SpriteData(_currentPos, _spriteSize));
	}
	AnimationData _data = AnimationData(50.0f, _sprites, true, RD_COLUMN);
	Animation* _move = new Animation("Movement", GetMesh()->GetShape(), _data);

	animation->AddAnimation(_move);
	animation->SetCurrentAnimation("Movement");
	animation->StartAnimation();
}

void UFO::Tick(const float _deltaTime)
{
	Super::Tick(_deltaTime);
	ComputeNewPositionIfNotInWindow();
}

void UFO::BeginPlay()
{
	Super::BeginPlay();
	new Timer<Seconds>([&]() { ComputeNewDirection(); }, seconds(3.0f), true, true);
}

void UFO::Deconstruct()
{
	Super::Deconstruct();
}
