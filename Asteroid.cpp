#include "Asteroid.h"
#include "GameManager.h"

Asteroid::Asteroid(const SizeType& _size, const vector<Vector2f>& _point, const string& _path
	, const TextureExtensionType& _textureType, const IntRect& _rect)
	: MeshActor(_point, _path,
		_textureType, _rect, false, false)
{
	animation = CreateComponent<AnimationComponent>();
	movement = CreateComponent<MovementComponent>();
	size = _size;
}

Asteroid::Asteroid(const Asteroid& _other) : MeshActor(_other)
{
	animation = CreateComponent<AnimationComponent>(_other.animation);
	movement = CreateComponent<MovementComponent>(_other.movement);
	size = _other.size;
}

void Asteroid::ComputeNewPositionIfNotInWindow()
{
	const Vector2f& _windowSize = M_GAME.GetCurrent()->GetWindowSize();
	const Vector2f& _asteroidPosition= GetPosition();
	const Vector2f& _asteroidScale = GetScale();
	const Vector2f& _asteroidSize = Vector2f(200.0f * _asteroidScale.x, 200.0f * _asteroidScale.y) / 2.0f; //TODO tweak la valeur je pense car 200 / 200 c'ets au feeling
	if ((_asteroidPosition.x + _asteroidSize.x) < 0.0f )
	{
		SetPosition({ _windowSize.x + _asteroidSize.x, _asteroidPosition.y });
	}
	else if ((_asteroidPosition.x - _asteroidSize.x) > _windowSize.x)
	{
		SetPosition({0.0f - _asteroidSize.x, _asteroidPosition.y });
	}
	if ((_asteroidPosition.y + _asteroidSize.y) < 0.0f)
	{
		SetPosition({ _asteroidPosition.x , _windowSize.y + _asteroidSize.y});
	}
	else if ((_asteroidPosition.y - _asteroidSize.y) > _windowSize.y)
	{
		SetPosition({ _asteroidPosition.x, 0.0f - _asteroidSize.y });
	}
}

void Asteroid::Construct()
{
	Super::Construct();
	const float _scaleFactor = 0.15f * CAST(float,size);
	SetScale({ _scaleFactor , _scaleFactor });
	vector<SpriteData> _spritesMove;
	const Vector2i& _moveSriteSize = Vector2i( 32,32 );
	for (u_int _index = 0; _index < 26; _index++)
	{
		const Vector2i& _currentPos = Vector2i(_moveSriteSize.x * (_index % 13), _moveSriteSize.y * (_index / 13));
		_spritesMove.push_back(SpriteData(_currentPos, _moveSriteSize));
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
