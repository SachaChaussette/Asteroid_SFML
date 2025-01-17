#pragma once

#include "Component.h"

enum CollisionType
{
	CT_NONE,
	CT_OVERLAP,
	CT_BLOCK,

	CT_COUNT,
};

enum LayerType
{
	LT_DYNAMIC,
	LT_STATIC,
	
	// ========== \\


};

class CollisionComponent : public Component
{
	LayerType layerType;
};

/*
* 
*	Actor => LayerMask
* 
*
*/

