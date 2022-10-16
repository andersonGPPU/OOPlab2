#include <iostream>
#include "matrix.h"

Matrix::Matrix(unsigned int rows, unsigned int columns):
		rows{ 0 }, columns{ 0 }, a{ nullptr }{
		//alocar memória para armazenar os valores na matriz
		alloc(rows, columns);
}//fim do construtor Matrix
Matrix::Matrix(const Matrix &m):
		Matrix(m.rows, m.columns){
		//fazendo a cópia dos elementos de m
		copy(m);
}//fim do construtor Matrix
Matrix::~Matrix() {//destrutor
	free();
}//fim do destrutor Matrix
void Matrix::alloc(unsigned int rows, unsigned int columns){
		free();
		this->rows = rows;
		this->columns = columns;
		//alocação de memória para armazenar os valores na matriz
		a = new double* [rows];
		for (unsigned int r = 0; r < rows; r++) {
			a[r] = new double[columns];
			for (unsigned int c = 0; c < columns; c++)
				a[r][c] = 0;
		}//fim do for
}
void Matrix::free(){ //libera memória
	if(a != nullptr){
		for (unsigned int r = 0; r < rows; r++)
			delete[] a[r];
		delete[]a;
		a = nullptr;
		rows = columns = 0;
	}
}
void Matrix::copy(const Matrix &m){
	for (unsigned int r = 0; r < rows; r++)
		for (unsigned int c = 0; c < columns; c++)
			a[r][c] = m.a[r][c];
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
	
	
