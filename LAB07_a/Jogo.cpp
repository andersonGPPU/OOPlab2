#include <iostream>
#include <iomanip>
#include <fstream>
#include "Jogo.h"

Jogo::Jogo() {
	nome = "nome não digitado"; horas = 0; preco = custo = 0.0f;
}
Jogo::Jogo(const char* nome, double preco, unsigned int horas) {
	this->nome = nome;
	this->preco = preco;
	this->horas = horas;
	custo = preco;
	calcular();
}
Jogo::~Jogo() {
}
void Jogo::atualizar(double preco) {
	this->preco = preco;
	calcular();
}
void Jogo::jogar(unsigned int horas) {
	this->horas += horas;
	calcular();
}
void Jogo::exibir_cst() const {
	std::cout.precision(2);
	std::cout << std::fixed;
	std::cout << "\nNOME: " << nome << std::endl;
	std::cout << "PREÇO: " << preco << std::endl;
	std::cout << "HORAS: " << horas << std::endl;
	std::cout << "CUSTO: " << custo << std::endl;
}
void Jogo::exibir() {
	std::cout.precision(2);
	std::cout << std::fixed;
	std::cout << "\nNOME: " << nome << std::endl;
	std::cout << "PREÇO: " << preco << std::endl;
	std::cout << "HORAS: " << horas << std::endl;
	std::cout << "CUSTO: " << custo << std::endl;
}
const Jogo& Jogo::comparar(const Jogo& jogo) const {
	if (jogo.horas > horas)
		return jogo;
	else return *this;
}
void Jogo::arquivar() {
	std::ofstream fout;
	fout.open("teste", std::ios_base::app | std::ios_base::binary);

	if(fout.is_open()){std::cout << "Iniciando a gravação do arquivo em disco... " << nome << std::endl;
	}
	else {
		std::cout << "\nErro ao tentar gravar arquivo!" << std::endl; exit(1);

	}

	fout.write((char*)&nome, sizeof(nome));
	fout.write((char*)&preco, sizeof(preco));
	fout.write((char*)&horas, sizeof(horas));
	fout.write((char*)&custo, sizeof(custo));
	fout.close(); std::cout << "Arquivo foi fechado, memória liberada!" << std::endl;
}
void Jogo::ler_arquivo() {
	std::ifstream fin;
	fin.open("teste", std::ios_base::app);

	if (!fin.is_open()) { std::cout << "\nNão foi possível encontrar o arquivo para leitura!" << std::endl; exit(1); }
	else {
		
		std::cout << "\niniciando a leitura do arquivo de dados..." << std::endl;
		while (fin) {
		fin.read((char*)&nome, sizeof(nome));
		fin.read((char*)&preco, sizeof(preco));
		fin.read((char*)&horas, sizeof(horas));
		fin.read((char*)&custo, sizeof(custo));
		exibir();
		}
	}
	std::cout << "\nLeitura do arquivo foi concluída!" << std::endl;
	fin.close(); std::cout << "Arquivo foi fechado com memória liberada!" << std::endl;
}
