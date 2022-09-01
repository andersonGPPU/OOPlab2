#include <iostream>
#include <iomanip>
#include <locale.h>
#include <windows.h>
#include "Jogo.h"

int main(void) {
	setlocale(LC_ALL, "Portuguese_Brasil.1252"); system("chcp 1252 > nul");
	//SetConsoleCP(1252); SetConsoleOutputCP(1252);

	Jogo produto;

	produto.adquirir("Mega Saga Gamer 64 bits", 33.55f); //precisa do 'f' para compilar como float
	produto.atualizar(30.01f);
	produto.jogar(5);
	produto.exibir();
	produto.gravar();
	std::cout << std::endl;
	produto.leitura();
	produto.nome_bits();

	char mygame[50]{};

	int i = 0;
	std::cout << "Digite o nome do jogo: ";
	std::cin.getline(mygame, 50);//para vetor de caracteres //para string é getline(std::cin,str) (recebe com cin, guardacom str:string)
	while (mygame[i]) {
		switch (mygame[i]) {
		case '/': case '*': case '+': case '=': case '&': case '(': case')':case'§':case'@':case'#':case'%':case'$':
			std::cout << "\nNão são aceitos caracteres como: '+', '*', '@' ..." << std::endl;
			std::cout << "Foi digitado o caractere '" << mygame[i] << "' não aceito!" << std::endl;
			std::cout << "Digite o nome do jogo: ";
			std::cin.getline(mygame, 50);
			i = 0;
			break;
		default: ++i;
		}
	}

	produto.adquirir(mygame, 160.0f);		
	produto.jogar(2);
	produto.exibir();
	produto.atualizar(55.01f);
	produto.gravar();
	std::cout << std::endl;
	produto.leitura();
	produto.nome_bits();

	return 0;
}