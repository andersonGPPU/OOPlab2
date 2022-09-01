#include "Jogo.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <bitset>


Jogo::Jogo() {
	std::cout << "Construtor" << std::endl;
	nome = " "; preco = custo = 0.0; horas = 0;
}
Jogo::~Jogo() {
	std::cout << "Destrutor" << std::endl;
}

void Jogo::adquirir(const char* titulo, float valor) {
	preco = valor; nome = titulo;
}
void Jogo::atualizar(float valor) {
	preco = valor;
}
void Jogo::jogar(int tempo) {
	horas = tempo;
	calcular();
}
void Jogo::exibir() {
	std::cout << "nome: " << nome << '\t' << std::setprecision(2) << std::fixed << "R$: " << preco << '\t' << "R$/horas: " << custo << '\t' << "horas: " << horas << std::endl;
}
void Jogo::nome_bits() {
	int i = 0;
	while (nome[i]) {
		std::bitset<8>mybit(nome[i]); //converte cada caractere em bits do tipo 'x' bits para bitset<x>
		std::cout << mybit << '\t' //representação em bits do caractere nome[i]
				  << nome[i] << '\t'
				  << (int)(mybit.to_ulong()) << '\t' //representação como inteiro de nome[i]
			      << (char)(mybit.to_ulong()) << '\t' 
			      << int(nome[i]) << std::endl; //converte caractere nome[i] em inteiro
		++i;
	}
}
void Jogo::gravar() {
	std::ofstream fout;
	Jogo objeto;
	
	fout.open(nome, std::ios_base::app | std::ios_base::binary);
	if (!fout.is_open()) { std::cout << "Erro ao tentar gravar!" << std::endl; exit(1); }
	else { std::cout << "\nIniciando a gravação do arquivo <" << nome << ">" << std::endl; }
	
	fout << preco << '\t' << horas << '\t' << custo << '\n';

	fout.close(); std::cout << "Arquivo <" << nome << "> foi fechado após gravação!" << std::endl;
}
void Jogo::leitura() {
	std::ifstream fin;

	Jogo ler_objeto;

	fin.open(nome);
	if (!fin.is_open()) { std::cout << "Erro ao tentar abrir o arquivo para leitura." << std::endl; exit(1); }
	else { std::cout << "\nAberto o arquivo <" << nome << "> para leitura." << std::endl; }
	
	while (!fin.eof()) {
		fin >> ler_objeto.preco >> ler_objeto.horas >> ler_objeto.custo;
		std::cout << "Preço R$: " << ler_objeto.preco << "\tHoras: " << ler_objeto.horas << "\tCusto (R$/horas): " << ler_objeto.custo << std::endl;
	}

	fin.close(); std::cout << "Arquivo <" << nome << "> foi fechado após leitura!" << std::endl;
}
