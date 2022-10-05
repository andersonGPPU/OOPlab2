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
	
	if (pilha.Vazia()) std::cout << "\nPilha está vazia!";
	else {
		std::cout << "\nPilha NÃO está vazia! > ";
		for (unsigned i = 0; i <= strlen(texto); i++)
			std::cout << pilha.Escrever_Item()[i];
	}

	//usando o mesmo texto novamente para duplicar
	for (size_t i = 0; i <= strlen(texto); i++) {
		pilha.EmpilharPlus(texto[i]);
	}

	size_t cont = 0;
	while (pilha.Escrever_Item()[cont]) {
		std::cout << pilha.Escrever_Item()[cont++];
	}

	if (pilha.Vazia()) std::cout << "\nPilha está vazia!";
	else std::cout << "\nPilha NÃO está vazia! > ";

	pilha.ApagarPilha();
	cont = 0;
	while (pilha.Escrever_Item()[cont]) {
		std::cout << pilha.Escrever_Item()[cont++];
	}

	return 0;
}