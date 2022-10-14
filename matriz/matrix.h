#ifndef MATRIX_H
#define MATRIX_H
class Matrix {
	unsigned int rows; //linhas
	unsigned int columns; //colunas
	double** a;

public:
	Matrix():
		rows{0},columns{0},a{nullptr}{}
	Matrix(unsigned int rows, unsigned int columns):
		rows{ rows }, columns{ columns }, a{ nullptr }{
		//alocar memória para armazenar os valores na matriz
		a = new double* [rows];
		for (unsigned int r = 0; r < rows; r++) {
			a[r] = new double[columns];
			for (unsigned int c = 0; c < columns; c++)
				a[r][c] = 0;
		}//fim do for
	}//fim do construtor Matrix

	~Matrix();

	void elemento(double a,unsigned int linha, unsigned int coluna) {
		this->a[linha][coluna] = a;
	}

	void print_matriz();
};
#endif