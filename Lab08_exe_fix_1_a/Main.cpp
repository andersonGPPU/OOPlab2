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
	size_t tamanho = strlen(texto);
	std::cout << "Tamanho do texto: " << tamanho << std::endl;

	Pilha pilha{ strlen(texto) };
	
	if (pilha.Vazia()) std::cout << "\nPilha está vazia!";
	else {
		std::cout << "\nPilha NÃO está vazia! > ";
		for (unsigned i = 0; i <= strlen(texto); i++)
			std::cout << pilha.Escrever_Item()[i];
	}

	//empilhar
	std::cout << "\nEMPILHANDO: ";
	for (size_t i = 0; i < strlen(texto); pilha.Empilhar(texto[i]), i++) {
		std::cout << texto[i] << '-';
	} std::cout << " EMPILHAMENTO CONCLUÍDO!" << std::endl;

	size_t cont = 0;
	while (pilha.Escrever_Item()[cont]) {
		std::cout << pilha.Escrever_Item()[cont++];
	}

	//desempilhar
	Item caractere; //char que será modificado por referência
	std::cout << "\nDESEMPILHANDO: ";
	while(pilha.Desempilhar(caractere)) {
		std::cout << caractere << '-';
	} std::cout << " CONCLUÍDO!" << std::endl;

	if (pilha.Vazia()) std::cout << "\nPilha está vazia!";
	else std::cout << "\nPilha NÃO está vazia! > ";


	return 0;
}