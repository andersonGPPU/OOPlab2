/* CÓDIGO PARA ESTUDO e verificação do funcionamento de arrays e seus problemas de manipulação, principalmente por
não podermos inserir um ponto de parada '\0', embora tenha sido embutido no looping com intuito de comparar no 
momento da DEPURAÇÃO e seu efeito no resultado. */

#include <iostream>
//#include <windows.h>
#include <locale>
#include "StrplusStr.h"
//#include "StrplusStr.cpp" //linux

int main(int argc, char* argv[]) {
	//SetConsoleCP(1245); SetConsoleOutputCP(1252);
	setlocale(LC_ALL, "Portuguese_Brasil.1252"); system("chcp 1252 > nul");

	//setlocale(LC_ALL, "Portuguese_Brasil.1252"); //linux

	char c[] = "teste bem maior de dados.";
	char d[] = " Com mais informação!";

	const char* e = "Segundo teste.";
	const char* f = " Continua aqui.";

	StrplusStr tst;

	std::cout << tst.plus(c, d) << " - " << tst.tam(c) << " - " << tst.tam(d) << std::endl;
	std::cout << tst.tam(tst.plus(c, d)) << std::endl;

	std::cout << tst.plus(e, f) << " - " << tst.tam(e) << " - " << tst.tam(f) << std::endl;
	std::cout << tst.tam(tst.plus(e, f)) << std::endl;

	char nome1[50]{};
	char nome2[50]{};

	std::cout << "Digite o nome1: ";
	std::cin.getline(nome1, 50);

	std::cout << "Digite o nome2: ";
	std::cin.getline(nome2, 50);

	std::cout << " - " << tst.tam(nome1) << " - " << tst.tam(nome2) << std::endl;
	std::cout << tst.plus(nome1, nome2) << " - " << tst.tam(tst.plus(nome1, nome2)) << std::endl;

	return 0;
}
