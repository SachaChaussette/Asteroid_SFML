#include "CircleActor.h"

CircleActor::CircleActor(const float _radius, const string& _path, const TextureExtensionType& _textureType, const IntRect& _rect,
	bool _isRepeated, bool _isSmooth)
	: MeshActor(_radius, _path, _textureType, _rect, _isRepeated, _isSmooth, 30U)
{
	
}