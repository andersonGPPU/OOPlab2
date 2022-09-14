#include <iostream>
#include <iomanip>
#include <fstream>
#include "Jogo.h"

Jogo::Jogo() {
	nome = { "Sem nome definido pelo usuário." };
	preco = custo = 0.0f; horas = 0;
}
Jogo::Jogo(const char* titulo, float valor) {
	nome = titulo;
}
void Jogo::atualizar(float valor) {
	preco = valor;
	calcular();
}
void Jogo::jogar(int tempo) {
	horas = tempo;
}
void Jogo::exibir() {
	std::cout << std::setprecision(2) << std::fixed;
	std::cout << "Jogo: '" << nome << "' - preço: " << preco << std::endl;
	std::cout << "horas jogadas: " << horas << std::endl;
	std::cout << "custo: " << custo << std::endl << std::endl;
}
void Jogo::gravar() {
	std::ofstream fout;
	fout.open("teste.txt", std::ios_base::app);
	if (fout.is_open()) {
		std::cout << "Arquivo aberto para gravação. Jogo: " << nome << std::endl;
	}
	else {
		std::cout << "\nErro ao tentar gravar." << std::endl; exit(1);
	}
	fout.write((char*)&nome, sizeof(nome));
	fout.write((char*)&preco, sizeof(preco));
	fout.write((char*)&horas, sizeof(horas));
	fout.write((char*)&custo, sizeof(custo));
	fout.close();
	std::cout << "\nGravação do Jogo '" << nome << "' foi concluída!" << std::endl << std::endl;
}
void Jogo::ler() {
	std::ifstream fin;
	fin.open("teste.txt",std::ios_base::in);
	if(!fin) {std::cout << "\nErro ao tentar ler." << std::endl; exit(1);
	}
	while (fin) {
		std::cout << "\nLendo arquivo..." << std::endl;
		fin.read((char*)&nome, sizeof(nome));
		fin.read((char*)&preco, sizeof(preco));
		fin.read((char*)&horas, sizeof(horas));
		fin.read((char*)&custo, sizeof(custo));
		std::cout << "Jogo: " << nome << " - preço: " << preco << std::endl;
		std::cout << "horas jogadas: " << horas << std::endl;
		std::cout << "custo: " << custo << std::endl << std::endl;
	}
	fin.close();
	std::cout << "\Leitura foi concluída!" << std::endl;
}