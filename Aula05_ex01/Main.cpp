#include <iostream>
#include <clocale>
#include <iomanip>
#include <string>
#include "pointc.h"
#include "rtg.h"


int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Portuguese_Brasil.1252"); system("chcp 1252 > null");

	Rt r;
	char op{};

	std::cout <<"Mudar o valor padrão de comprimento e largura? (S/N) " << std::endl;
	std::cin >> op;
	op = toupper(op);
	if (op != 'S') {
		r.s_Lgth();
		r.s_Wdth();
		r.s_Pont();
		r.g_Coord();
	} else std::cout << "FIM" << std::endl;
	
	return 0;
}