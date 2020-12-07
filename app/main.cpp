#include <iostream>
#include "MyVector.h"
#include "MyMatrix.h"

int main()
{
	Vector<Vector<int>>A(5);

	Matrix<int> B(3);

	Matrix<int> b(3);
	Matrix<int> c(3);

	b[0][0] = 1;
	b[0][1] = 2;
	b[0][2] = 3;
	b[1][1] = 4;
	b[1][2] = 5;
	b[2][2] = 6;

	c[0][0] = 1;
	c[0][1] = 2;
	c[0][2] = 3;
	c[1][1] = 4;
	c[1][2] = 5;
	c[2][2] = 6;

	cout << b << c;
	cout << b * c;

	return 0;
}
