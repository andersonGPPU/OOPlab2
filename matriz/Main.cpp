#include <iostream>
#include <math.h>
#include <locale>
#include "matrix.h"
#include "matrix.cpp"

int main(int argc, char* argv[]) {
	setlocale(LC_ALL,"");//linux
	
	Matrix m1 = Matrix(10,10);

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		m1.elemento(i * 3 - 2 * j + 5,i,j);
		
	m1.print_matriz();
	
	Matrix m2 = Matrix(10,10);

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		m2.elemento(j * 2 - i * 3 + 7,i,j);
		
	m2.print_matriz();
	
	Matrix ms = Matrix(10,10);
	ms = m1 + m2;
	ms.print_matriz();
	ms = m1 - m2;
	ms.print_matriz();
	
	
	std::cout << "potência de 2 elevado a 3: " << pow(2,3) << std::endl; //2 elevado a 3 = 8

	
	return 0;
}
