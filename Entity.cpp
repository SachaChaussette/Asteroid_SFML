#include "Entity.h"
#include "GameManager.h"

Entity::Entity(const u_int& _lifeCount, const SizeType& _size, const u_int& _spriteCount, const MeshActor& _mesh,
	const string& _name) : MeshActor(_mesh)
{
	animation = CreateComponent<AnimationComponent>();
	life = CreateComponent<LifeComponent>(_lifeCount);
	collision = CreateComponent<CollisionComponent>(_name, IS_ALL, CT_OVERLAP);

	size = _size;
	spriteCount = _spriteCount;
}

Entity::Entity(const Entity& _other) : MeshActor(_other)
{
	animation = CreateComponent<AnimationComponent>(_other.animation);
	life = CreateComponent<LifeComponent>(_other.life);
	collision = CreateComponent<CollisionComponent>(*_other.collision);
	spriteCount = _other.spriteCount;
	size = _other.size;
}

void Entity::Tick(const float _deltaTime)
{
	Super::Tick(_deltaTime);
	ComputeNewPositionIfNotInWindow();
}

void Entity::ComputeNewPositionIfNotInWindow()
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

void Entity::Construct()
{
	Super::Construct();
	

	// Animation / Sprite
	const Vector2i& _spriteSize = Vector2i(32, 32);
	vector<SpriteData> _sprites;

	for (u_int _index = 0; _index < spriteCount; _index++)
	{
		const Vector2i& _currentPos = Vector2i(_spriteSize.x * (_index), 0);
		_sprites.push_back(SpriteData(_currentPos, _spriteSize));
	}
	AnimationData _data = AnimationData(100.0f, _sprites, true, true, RD_ROW);
	Animation* _move = new Animation("Movement", GetMesh()->GetShape(), _data);

	animation->AddAnimation(_move);
	animation->SetCurrentAnimation("Movement");
	animation->StartAnimation();
}
