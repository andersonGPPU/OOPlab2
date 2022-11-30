#include <iostream>
#include <clocale>
#include "iteradores.h"

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "");

	int xis[] = { 4, 3, -8, 13, 7, 15 };

	Vetores teste(xis, sizeof(xis) / sizeof(int));

	teste.itvetor();
	teste.ritvetor();

	return 0;
}