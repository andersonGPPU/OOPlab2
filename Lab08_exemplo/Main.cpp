#include <iostream>
#include <locale.h>
#include <windows.h>
#include "Pilha.h"
//#include "Pilha.cpp" //linux

int main(void) {
	//setlocale(LC_ALL, ""); //linux
	setlocale(LC_ALL, "Portuguese_Brasil.1252"); system("chcp 1252 > nul"); //windows
	//SetConsoleCP(1252); SetConsoleOutputCP(1252); //windows

	Pilha pilha;

	char texto[50]{};

	std::cout << "Texto a ser empilhado: ";
	std::cin.getline(texto,sizeof(texto));
	std::cout << "\nTamanho: " << sizeof(texto) << '\t';

	for (unsigned i = 0; i < sizeof(texto); pilha.Empilhar(*(texto + i)), i++);
	for (unsigned i = 0; i < sizeof(texto); std::cout << texto[i], i++);

	if (pilha.Cheia()) {
		std::cout << "\nAgora a pilha está cheia e será esvaziada!" << std::endl;

		Item i;
		while (pilha.Desempilhar(i)) {
			std::cout << i << std::endl;
		}
	}

	if (pilha.Vazia()) std::cout << "\nPilha está vazia!";
	else std::cout << "\nPilha NÃO está vazia!";

	return 0;
}