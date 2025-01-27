#include "Asteroid.h"

Asteroid::Asteroid(const vector<Vector2f> _point, const string& _path
	, const TextureExtensionType& _textureType, const IntRect& _rect)
	: MeshActor(_point, _path, _textureType, _rect, false, false)
{
}
