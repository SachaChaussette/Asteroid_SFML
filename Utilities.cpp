#include "Utilities.h"

u_int GetUniqueId()
{
	static u_int _id = 0;
	return ++_id;
}
