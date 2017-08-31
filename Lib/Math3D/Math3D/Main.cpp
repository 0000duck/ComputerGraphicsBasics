#include "GMath.h"


int main()
{

	GVector3 p(1, 3, 0), q(1, 1, 0), r(0, 1, 0);

	float m[] = { 2,1,3,0,1,-1,1,3,-1 };// , 10, 11, 12, 13, 14, 15, 16

	GMatrix M(3, 3, m);

	cout << M << endl;

	GMatrix M1 = RowEchelonForm(M);

	cout << M1 << endl;

	GMatrix M2 = ReducedRowEchelon(M);

	cout << M2 << endl;

	
	
    return 0;
}

