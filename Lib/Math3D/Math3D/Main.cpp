#include "GMath.h"


int main()
{

	GVector3 p(1, 3,0), q(1, 1,0);

	GVector3 v = proj(p, q);
	GVector3 u = perp(p, q);

	GVector3 r = v + u;

	

    return 0;
}

