#include <iostream>
#include <iomanip>
#include <fstream>
#include "Jogo.h"

void Jogo::calcular() {
	(_horas > 0) ? _custo = float(_preco) / _horas : _custo = _preco;
}

Jogo::Jogo() {
	std::cout << "\nConstruindo objeto Padrão." << std::endl;
	_nome = "nome está vazio"; _preco = _custo = 0.0f; _horas = 0;
}
Jogo::Jogo(const char* nome, float preco) {
	std::cout << "\nConstruindo objeto " << nome << " na área de memória " << &nome << std::endl;
	_nome = nome; _preco = preco; _horas = 0; _custo = _preco;
}
Jogo::~Jogo() {
	std::cout << "\nDestruindo objeto: " << _nome << std::endl;
}

void Jogo::SetNome(const char* nome) {
	_nome = nome;
}
const char* Jogo::GetNome() {
	return _nome;
}

void Jogo::atualizar(float custo) {
	_custo += custo;
}
void Jogo::jogar(int tempo) {
	_horas += tempo;
	calcular();
}
void Jogo::exibir() {
	std::cout.precision(2);
	std::cout << std::fixed;
	std::cout << "\nNOME: " << _nome << std::endl;
	std::cout << "PREÇO: " << _preco << std::endl;
	std::cout << "HORAS: " << _horas << std::endl;
	std::cout << "CUSTO: " << _custo << std::endl;
}
void Jogo::exibir_cst() const {
	std::cout.precision(2);
	std::cout << std::fixed;
	std::cout << "\nNOME: " << _nome << std::endl;
	std::cout << "PREÇO: " << _preco << std::endl;
	std::cout << "HORAS: " << _horas << std::endl;
	std::cout << "CUSTO: " << _custo << std::endl;
}
void Jogo::gravar_arquivo() {
	std::ofstream fout;
	fout.open("teste", std::ios_base::app | std::ios_base::binary);

	if (!fout.is_open()) { std::cout << "\nErro ao tentar gravar arquivo!" << std::endl; exit(1); }
	else {
		std::cout << "Iniciando a gravação do arquivo em disco..." << std::endl;

		fout.write((char*)&_nome, sizeof(_nome));
		fout.write((char*)&_preco, sizeof(_preco));
		fout.write((char*)&_horas, sizeof(_horas));
		fout.write((char*)&_custo, sizeof(_custo));

		std::cout << "\nGravação foi concluída." << std::endl;
		fout.close();
		std::cout << "Arquivo foi fechado, memória liberada!" << std::endl;
	}
}
void Jogo::ler_arquivo() {
	std::ifstream fin;
	fin.open("teste", std::ios_base::binary);

	if (!fin.is_open()) { std::cout << "\nNão foi possível encontrar o arquivo para leitura!" << std::endl; exit(1); }
	else {
		std::cout << "\niniciando a leitura do arquivo de dados..." << std::endl;
		float gasto = 0.0f; unsigned int tempo = 0;
		while (fin) {
			fin.read((char*)&_nome, sizeof(_nome));
			fin.read((char*)&_preco, sizeof(_preco));
			fin.read((char*)&_horas, sizeof(_horas));
			fin.read((char*)&_custo, sizeof(_custo));
			gasto += _preco;
			tempo += _horas;
			exibir();
			std::cout << "Gasto total: " << gasto << std::endl;
			std::cout << "Horas totais: " << tempo << std::endl;
		}
		std::cout << "\nLeitura do arquivo foi concluída!" << std::endl;
		fin.close();
		std::cout << "Arquivo foi fechado com memória liberada!" << std::endl;
	}
}
