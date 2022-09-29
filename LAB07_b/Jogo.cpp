#include <iostream>
#include <iomanip>
#include <fstream>
#include "Jogo.h"

Jogo::Jogo() {
	nome = "nome n�o digitado"; horas = 0; preco = custo = 0.0f;
}
Jogo::Jogo(const char* nome, double preco, unsigned int horas) {
	this->nome = nome;
	this->preco = preco;
	this->horas = horas;
	custo = preco;
	Calcular();
}
Jogo::~Jogo() {
}
void Jogo::Atualizar(double preco) {
	this->preco = preco;
	Calcular();
}
void Jogo::Jogar(unsigned int horas) {
	this->horas += horas;
	Calcular();
}
void Jogo::Exibir_cst() const {
	std::cout.precision(2);
	std::cout << std::fixed;
	std::cout << "\nNOME: " << this->nome << std::endl;
	std::cout << "PRE�O: " << this->preco << std::endl;
	std::cout << "HORAS: " << this->horas << std::endl;
	std::cout << "CUSTO: " << this->custo << std::endl;
}
void Jogo::Exibir() {
	std::cout.precision(2);
	std::cout << std::fixed;
	std::cout << "\nNOME: " << nome << std::endl;
	std::cout << "PRE�O: " << preco << std::endl;
	std::cout << "HORAS: " << horas << std::endl;
	std::cout << "CUSTO: " << custo << std::endl;
}
const Jogo& Jogo::Comparar(const Jogo& jogo) const {
	return MaisJogado(*this, jogo);
}
const Jogo& Jogo::Comparar_Ptr(const Jogo& jogo,
	const Jogo& (func)(const Jogo&, const Jogo&)) const {
	return func(*this, jogo);
}
void Jogo::Arquivar() {
	std::ofstream fout;
	fout.open("teste", std::ios_base::app | std::ios_base::binary);

	if(fout.is_open()){std::cout << "Iniciando a grava��o do arquivo em disco... " << nome << std::endl;
	}
	else {
		std::cout << "\nErro ao tentar gravar arquivo!" << std::endl; exit(1);

	}

	fout.write((char*)&nome, sizeof(nome));
	fout.write((char*)&preco, sizeof(preco));
	fout.write((char*)&horas, sizeof(horas));
	fout.write((char*)&custo, sizeof(custo));
	fout.close(); std::cout << "Arquivo foi fechado, mem�ria liberada!" << std::endl;
}
void Jogo::Ler_Arquivo() {
	std::ifstream fin;
	fin.open("teste", std::ios_base::app);

	if (!fin.is_open()) { std::cout << "\nN�o foi poss�vel encontrar o arquivo para leitura!" << std::endl; exit(1); }
	else {
		
		std::cout << "\niniciando a leitura do arquivo de dados..." << std::endl;
		while (fin) {
		fin.read((char*)&nome, sizeof(nome));
		fin.read((char*)&preco, sizeof(preco));
		fin.read((char*)&horas, sizeof(horas));
		fin.read((char*)&custo, sizeof(custo));
		Exibir();
		}
	}
	std::cout << "\nLeitura do arquivo foi conclu�da!" << std::endl;
	fin.close(); std::cout << "Arquivo foi fechado com mem�ria liberada!" << std::endl;
}
//fun��es auxiliares
const Jogo& MaisJogado(const Jogo& a, const Jogo& b) {
	if (a.Horas() > b.Horas()) return a;
	else return b;
}
const Jogo& MenorCusto(const Jogo& a, const Jogo& b) {
	if (a.Custo() < b.Custo()) return a;
	else return b;
}