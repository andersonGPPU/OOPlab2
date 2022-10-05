#include <iostream>
#include <locale.h>
#include <windows.h>
#include <string>
#include "Pilha.h"
//#include "Pilha.cpp" //linux

int main(void) {
	//setlocale(LC_ALL, ""); //linux
	setlocale(LC_ALL, "Portuguese_Brasil.1252"); system("chcp 1252 > nul"); //windows
	//SetConsoleCP(1252); SetConsoleOutputCP(1252); //windows
	const char* texto{ "testando um nome aqui ainda bem maior do que antes! Mais palavras acrescentadas agora." };
	
	std::cout << "Tamanho do texto: " << strlen(texto) << std::endl;

	Pilha pilha{ texto , strlen(texto) + 1 };
	

	if (pilha.Cheia()) {
		std::cout << "\nAgora a pilha está cheia e será esvaziada!" << std::endl;

		Item i;
		while (pilha.Desempilhar(i)) {
			std::cout << i;
		}
	}

	if (pilha.Vazia()) std::cout << "\nPilha está vazia!";
	else std::cout << "\nPilha NÃO está vazia!";


	for (unsigned i = 0; i <= strlen(texto); pilha.Empilhar(texto[i], strlen(texto) + 1), i++);

	if (pilha.Vazia()) std::cout << "\nPilha está vazia!";
	else std::cout << "\nPilha NÃO está vazia!";

	if (pilha.Cheia()) {
		std::cout << "\nAgora a pilha está cheia e será esvaziada!" << std::endl;

		Item i;
		while (pilha.Desempilhar(i)) {
			std::cout << i;
		}
	}

	return 0;
}