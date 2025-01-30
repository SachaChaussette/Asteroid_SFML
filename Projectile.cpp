#include "Projectile.h"

Projectile::Projectile(const float _radius, const string& _path, 
	const TextureExtensionType& _textureType, const IntRect& _rect, bool _isRepeated, bool _isSmooth, 
	const string& _name) : MeshActor(_radius, _path, _textureType, _rect, _isRepeated, _isSmooth , 30U, _name)
{
	movement = CreateComponent<EnemyMovementComponent>();
}

Projectile::Projectile(const Projectile& _other) : MeshActor(_other)
{
	movement = CreateComponent<EnemyMovementComponent>(_other.movement);
}

void Projectile::BeginPlay()
{
	SetLifeSpan(5.0f);
	Super::BeginPlay();
}

void Projectile::ComputeNewPositionIfNotInWindow()
{
	const Vector2f& _windowSize = CAST(Vector2f, M_GAME.GetCurrent()->GetWindowSize());
	const Vector2f& _playerPosition = GetPosition();
	const Vector2f& _playerScale = GetScale();
	const Vector2f& _playerSize = Vector2f(_playerScale.x, _playerScale.y) / 2.0f;
	if ((_playerPosition.x + _playerSize.x) < 0.0f)
	{
		SetPosition({ _windowSize.x + _playerSize.x, _playerPosition.y });
	}
	else if ((_playerPosition.x - _playerSize.x) > _windowSize.x)
	{
		SetPosition({ 0.0f - _playerSize.x, _playerPosition.y });
	}
	if ((_playerPosition.y + _playerSize.y) < 0.0f)
	{
		SetPosition({ _playerPosition.x , _windowSize.y + _playerSize.y });
	}
	else if ((_playerPosition.y - _playerSize.y) > _windowSize.y)
	{
		SetPosition({ _playerPosition.x, 0.0f - _playerSize.y });
	}
}

void Projectile::Construct()
{
	Super::Construct();
	movement->SetSpeed(150.0f);

}

void Projectile::Tick(const float _deltaTime)
{
	Super::Tick(_deltaTime);
	ComputeNewPositionIfNotInWindow();
}

void Projectile::Deconstruct()
{
	Super::Deconstruct();
}