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
	const char* texto{ "testando um nome!" };

	Item tch{};

	std::cout << "Tamanho do texto: " <<  strlen(texto) << std::endl;
	
	Pilha pilha;

	for(unsigned int i = 0; texto[i]; i++)
		pilha.Empilhar(texto[i]);

	std::cout << "\nDesempilhando ";
	for (unsigned int i = 0; i < strlen(texto); i++) {
		pilha.Desempilhar(tch);
		std::cout << "[" << tch << "] ";
	} std::cout << std::endl;

	pilha.Empilhar('S');
	pilha.Empilhar('F');
	pilha.Empilhar('P');
	pilha.Empilhar('W');
	pilha.Empilhar('b');

	std::cout << "\nDesempilhando ";
	pilha.Desempilhar(tch); std::cout << "[" << tch << "] ";
	pilha.Desempilhar(tch); std::cout << "[" << tch << "] ";
	pilha.Desempilhar(tch); std::cout << "[" << tch << "] ";
	pilha.Desempilhar(tch); std::cout << "[" << tch << "] ";
	pilha.Desempilhar(tch); std::cout << "[" << tch << "] ";

	return 0;
}