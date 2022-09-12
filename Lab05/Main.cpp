#include <iostream>
#include <windows.h>
#include <locale.h>
#include "Pessoa.h"

int main() {
	setlocale(LC_ALL, "Portuguese_Brasil.1252"); system("chcp 1252 > nul");
	//SetConsoleCP(1252); SetConsoleOutputCP(1252);

	Pessoa objeto_teste;
	char nome_usuario[50]{}, sobrenome_usuario[50]{};

	std::cout << "Digite o nome: " << std::endl;
	std::cin.getline(nome_usuario, 50);
	objeto_teste.SetNome(*nome_usuario);

	std::cout << "Digite o sobrenome: " << std::endl;
	std::cin.getline(sobrenome_usuario, 50);
	objeto_teste.SetSobrenome(*sobrenome_usuario);

	objeto_teste.Exibir();
	objeto_teste.Formal();
	objeto_teste.Gravar();
	objeto_teste.Ler();

	return 0;
}