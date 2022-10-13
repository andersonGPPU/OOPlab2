//a solução se aplica apenas para o caso de se coincidir os parênteses '(' e ')'

#include <iostream>
#include <windows.h>
#include <locale>
#include "Sequencia.h"
//#include "Sequencia.cpp" //linux

int main(void) {
	//setlocale(LC_ALL, ""); //linux
	//SetConsoleCP(1252); SetConsoleOutputCP(1252); //windows
	setlocale(LC_ALL, "Portuguese_Brasil.1252"); system("chcp 1252 > nul"); //windows

	Sequencia teste;
	const char* exp_1 = { "((2+3)-5" };
	const char* exp_2 = { "(2+3)-5" };
	const char* exp_3 = { "((2+3)-(5*4))" }; //6-20 = -14
	const char* exp_4 = { "((7-11)*5+(6/5)*3)" };
	char exp_user[15]{};


	if (teste.Verificar(exp_1)) { std::cout << "\nOk" << std::endl; }
	else { std::cout << "\nErro em " << exp_1 << std::endl; }

	if (teste.Verificar(exp_3)) { std::cout << "\nOk" << std::endl; }
	else { std::cout << "\nErro em " << exp_3 << std::endl; }

	if (teste.Verificar(exp_4)) { std::cout << "\nOk" << std::endl; }
	else { std::cout << "\nErro em " << exp_4 << std::endl; }

	std::cout << "Digite uma expressão: ";
	std::cin.getline(exp_user, sizeof(exp_user));

	if (teste.Verificar(exp_user)) { std::cout << "\nOk" << std::endl; }
	else { std::cout << "\nErro em " << exp_user << std::endl; }

	return 0;
}
