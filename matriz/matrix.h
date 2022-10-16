#ifndef MATRIX_H
#define MATRIX_H

#include <cassert>

class Matrix {
private:
	unsigned int rows; //linhas
	unsigned int columns; //colunas
	double** a;
	
	void copy(const Matrix &m);
	void free();

public:
	Matrix():
		rows{0},columns{0},a{nullptr}{}
	Matrix(const Matrix &m);
	Matrix(unsigned int rows, unsigned int columns);
	~Matrix();
	
	void alloc(unsigned int, unsigned int);

	void elemento(double a,unsigned int linha, unsigned int coluna) {
		this->a[linha][coluna] = a;
	}
	
	void print_matriz();
	
	//funções de operadores

	Matrix &operator= (const Matrix &m){
	//alocar memória coerente com o tamanho de linhas e colunas de m
	alloc(m.rows, m.columns);
	//copiar elementos de m
	copy(m);
	return *this;
	}
	
	Matrix &operator+= (const Matrix &m){
	assert(rows == m.rows && columns == m.columns);
	for(unsigned int r = 0; r < rows; r++)
		for(unsigned int c = 0; c < columns; c++)
			a[r][c] += m.a[r][c];
	return *this;
	}
	
	Matrix operator+ (const Matrix &m){
	assert(rows == m.rows && columns == m.columns);
	return Matrix(*this) += m;
	}
	
	Matrix &operator-= (const Matrix &m){
	assert(rows == m.rows && columns == m.columns);
	for(unsigned int r = 0; r < rows; r++)
		for(unsigned int c = 0; c < columns; c++)
			a[r][c] -= m.a[r][c];
	return *this;
	}
	
	Matrix operator- (const Matrix &m){
	assert(rows == m.rows && columns == m.columns);
	return Matrix(*this) -= m;
	}
};
#endif
