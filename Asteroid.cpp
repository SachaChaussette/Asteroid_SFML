#include "Asteroid.h"

Asteroid::Asteroid(const vector<Vector2f> _point, const SizeType& _size, const string& _path
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

void Asteroid::Construct()
{
	Super::Construct();
	const float _scaleFactor = 0.25f * CAST(float,size);
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

void Asteroid::Deconstruct()
{
	Super::Deconstruct();


}
