#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cctype>
#include "Jogo.h"

const int MAX = 6;

int main(void) {
	setlocale(LC_ALL, "Portuguese_Brasil.1252"); system("chcp 1252 > nul");
	//SetConsoleCP(1252); SetConsoleOutputCP(1252);
	
	Jogo gears{ "Gears - A grande batalha", 90.0f, 25 };
	Jogo doom{ "Doom - a nova geração", 60.0f, 12 };
	Jogo halo{ "Halo - Microsoft", 80.0f, 40 };
	Jogo thor{ "Thor - o deus do trovão. Parte 5.", 50.55f, 8 };
	Jogo spider{ "O Espetacular Homem-Aranha", 115.65f, 4 };
	Jogo cpp{ "Programação em C++ com struct", 350.99f, 0 };

	Atualizar(&gears,100.75f);
	Jogar(&gears, 5);
	Exibir_cst(&gears);

	Atualizar(&doom, 123.50f);
	Jogar(&doom, 12);
	Exibir_cst(&doom);

	Atualizar(&halo, 60.95f);
	Jogar(&halo, 8);
	Exibir_cst(&halo);
	
	Calcular(&thor);  Calcular(&spider); Calcular(&cpp);
	Exibir_cst(&thor);
	Exibir_cst(&spider);
	Exibir_cst(&cpp);

	Arquivar(&gears); Arquivar(&doom); Arquivar(&halo);
	Arquivar(&thor); Arquivar(&spider); Arquivar(&cpp);

	std::cout << "\nFazer uma leitura do arquivo gravado?" << std::endl;
	char resp = 'N';
	std::cin.get(resp);
	if (toupper(resp) == 'S') {
		Jogo leitura;
		Ler_Arquivo(&leitura);
	}
			
	return 0;
}