#include <iostream>
#include <windows.h>
#include <locale>
#include "Jogo.h"

int main() {
	setlocale(LC_ALL, "Portuguese_Brasil.1252"); system("chcp 1252 > nul");
	//SetConsoleCP(1252); SetConsoleOutputCP(1252);

	Jogo teste;
	Jogo teste2("Mega Driver");
	Jogo teste3{ "Nintendo 64 bits", 35.65f };
		
	teste.jogar(5);
	teste.atualizar(77.55f);
	teste.exibir();
	teste.gravar();
		
	teste2.jogar(3);
	teste2.atualizar(88.99f);
	teste2.exibir();
	teste2.gravar();
		
	teste3.jogar(4);
	teste3.atualizar(101.25f);
	teste3.exibir();
	teste3.gravar();

	teste3.ler();

	return 0;
}