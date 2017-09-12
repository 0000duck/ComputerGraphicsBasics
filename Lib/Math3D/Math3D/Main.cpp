#include "GMath.h"


int main()
{

	GVector3 q;
	GVector3 p(0.0f,0.0f,0.0f);
	GVector3 v(1.0f, 1.0f, 1.0f);
	GLine l(p, v);
	GVector3 p1(1.0f, .0f, .0f), p2(.0f, 1.0f, .0f), p3(.0f, .0f, 1.0f);
	intersect_line_triangle(q, l, p1, p2,p3,false);

	
	
    return 0;
}

