
#include "stdafx.h"

#include "dot.h" 
bool operator ==(dot const & a, dot const & b)
{
	if ((a.x == b.x) && (a.y == b.y))
		return 1;
	else
		return 0;
}