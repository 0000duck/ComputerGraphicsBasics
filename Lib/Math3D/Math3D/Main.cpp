#include "GMath.h"


int main()
{

	float m[] = {
		3.0f, 2.0f,-3.0f,-13.0f,
		4.0f,-3.0f, 6.0f, 7.0f,
		1.0f, 0.0f,-1.0f,-5.0f };
	GMatrix M(3, 4, m);

	cout << RowEchelonForm(M) << endl << endl;

	cout << ReducedRowEchelon(M) << endl;

	
	
    return 0;
}

