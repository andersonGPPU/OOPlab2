#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cctype>
#include "Jogo.h"

const int MAX = 6;

int main(void) {
	setlocale(LC_ALL, "Portuguese_Brasil.1252"); system("chcp 1252 > nul");
	//SetConsoleCP(1252); SetConsoleOutputCP(1252);

	//vetor de objetos inicializados
	Jogo colecao[MAX] =
	{
		Jogo("Gears - A grande batalha", 90.0f, 30),
		Jogo("Doom - a nova geração", 60.0f, 120),
		Jogo("Halo - Microsoft", 80.0f, 40),
		Jogo("Thor - o deus do trovão. Parte 5.", 50.55f, 60),
		Jogo("O Espetacular Homem-Aranha", 115.65f, 48),
		Jogo()
	};

	std::cout << "Coleção de Jogos:\n";
	for (short i = 0; i < MAX; colecao[i].exibir(), i++);

	//aponta para o primeiro elemento
	const Jogo* top = &colecao[0];

	//compara com todos os elementos
	for (short i = 1; i < MAX; top = &top->comparar(colecao[i]), i++);

	//top aponta para o mais jogado
	std::cout << "\nJogo mais usado:\n";
	top->exibir_cst();

	for (short i = 0; i < MAX; colecao[i].arquivar(), i++);
	std::cout << "\nFazer uma leitura do arquivo gravado?" << std::endl;
	char resp = 'N';
	std::cin.get(resp);
	if (toupper(resp) == 'S') {
		Jogo leitura;
		leitura.ler_arquivo();
		}
			
	return 0;
}
