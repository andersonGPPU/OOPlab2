#include "Jogo.h"
#include <iostream>
#include <locale>
#include <windows.h>

int main(void) {
	setlocale(LC_ALL, "Portuguese_Brasi.1252"); system("chcp 1252 > nul");
	//SetConsoleCP(1252); SetConsoleOutputCP(1252);
	char gera_nome[50]{"testando um nome"};

	std::cout << "inicializa: \n";
	{
		Jogo sackboy = Jogo("Sack Boy", 150.0f);
		sackboy.atualizar(5.55f);
		sackboy.jogar(5);
		sackboy.jogar(6);
		sackboy.gravar_arquivo();
	
	}
	std::cout << "\nCria e Atribui: \n";
	{
		Jogo horizon;
		horizon = Jogo("Game Horizon", 199.0f);
		horizon.atualizar(7.65f);
		horizon.jogar(3);
		horizon.gravar_arquivo();
	}
	std::cout << "\nDigitação do usuário..." << std::endl;
	{
		std::cout << "indique o nome do jogo: ";
		std::cin.getline(gera_nome, 50);
		Jogo usuario(gera_nome,75.50f);
		usuario.atualizar(2.50f);
		usuario.jogar(2);
		usuario.gravar_arquivo();
	}
	{
		Jogo thundercats{ "Thunder Cats Aventura!", 250.0f }, spiderman{ "O Espetacular Homem-Aranha 3", 550.0f }, tempestade{ "Jumanji Tempestade no Deserto IV", 128.66f };
	}

	Jogo dados;

	dados.ler_arquivo();

	return 0;
}