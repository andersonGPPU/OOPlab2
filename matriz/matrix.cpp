#include <iostream>
#include "matrix.h"
Matrix::~Matrix() {//libera memória
	for (unsigned int r = 0; r < rows; r++)
		delete[] a[r];
	delete[]a;
	a = nullptr;
}

void Matrix::print_matriz() {
	std::cout << "rows (linhas): " << rows << std::endl;
	std::cout << "columns (colunas): " << columns << std::endl;
	std::cout << "a (elemento): " << a << std::endl;
	for (unsigned int r = 0; r < rows; r++) {
		for (unsigned int c = 0; c < columns; c++)
			std::cout << a[r][c] << " ";
		if (columns > 0)
			std::cout << a[r][columns - 1];
		std::cout << std::endl;
	}
}