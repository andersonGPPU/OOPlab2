#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cctype>
#include "Jogo.h"
//#include "Jogo.cpp" //linux

const int MAX = 6;

int main(void) {
	//setlocale(LC_ALL,""); //linux
	setlocale(LC_ALL, "Portuguese_Brasil.1252"); system("chcp 1252 > nul"); //windows
	//SetConsoleCP(1252); SetConsoleOutputCP(1252); //windows

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
	for (short i = 0; i < MAX; colecao[i].Exibir(), i++);

	//aponta para o primeiro elemento
	const Jogo* top = &colecao[0];

	//compara com todos os elementos
	for (short i = 1; i < MAX; top = &top->Comparar(colecao[i]), i++);

	//top aponta para o mais jogado
	std::cout << "\nJogo mais usado:\n";
	top->Exibir_cst();

	for (short i = 0; i < MAX; colecao[i].Arquivar(), i++);
	std::cout << "\nFazer uma leitura do arquivo gravado?" << std::endl;
	char resp = 'N';
	std::cin.get(resp);
	if (toupper(resp) == 'S') {
		Jogo leitura;
		leitura.Ler_Arquivo();
		}

	//segunda parte
	Jogo gears{ "Efeito Colateral - Grande Filme!", 200.0f,100 };
	Jogo doom{ "Game Doom - Explosão Fatal", 120.0f,80 };

	const Jogo& topPlay = gears.Comparar_Ptr(doom, MaisJogado);
	const Jogo& topValue = gears.Comparar_Ptr(doom, MenorCusto);
	std::cout << std::endl;
	std::cout << "Jogo mais utilizado:";
	topPlay.Exibir_cst();

	std::cout << "\nJogo com menor custo:";
	topValue.Exibir_cst();
			
	return 0;
}
