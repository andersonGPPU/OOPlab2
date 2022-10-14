#include <iostream>
#include "matrix.h"

int main(int argc, char* argv[]) {
	Matrix m = Matrix(10,15);

	for (int i = 0; i < 10; i++)
		m.elemento(i,i,i);

	m.print_matriz();

	
	return 0;
}