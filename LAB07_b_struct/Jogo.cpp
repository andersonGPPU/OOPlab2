#include <iostream>
#include <iomanip>
#include <fstream>
#include "Jogo.h"

void Atualizar(Jogo* este, double preco) {
	este->_preco = preco;
	Calcular(este);
}
void Jogar(Jogo* este, unsigned int horas) {
	este->_horas += horas;
	Calcular(este);
}
void Exibir_cst(const Jogo* este) {
	std::cout.precision(2);
	std::cout << std::fixed;
	std::cout << "NOME: " << este->_nome << std::endl;
	std::cout << "PREÇO: " << este->_preco << std::endl;
	std::cout << "HORAS: " << este->_horas << std::endl;
	std::cout << "CUSTO: " << este->_custo << std::endl;
}
void Exibir(Jogo* este) {
	std::cout.precision(2);
	std::cout << std::fixed;
	std::cout << "\nNOME: " << este->_nome << std::endl;
	std::cout << "PREÇO: " << este->_preco << std::endl;
	std::cout << "HORAS: " << este->_horas << std::endl;
	std::cout << "CUSTO: " << este->_custo << std::endl;
}
void Arquivar(Jogo*este) {
	std::ofstream fout;
	fout.open("teste", std::ios_base::app|std::ios_base::binary);

	if(fout.is_open()){std::cout << "\nIniciando a gravação do arquivo em disco... " << este->_nome << std::endl;
	}
	else {
		std::cout << "\nErro ao tentar gravar arquivo!" << std::endl; exit(1);

	}

	fout.write((char*)&este->_nome, sizeof(este->_nome));
	fout.write((char*)&este->_preco, sizeof(este->_preco));
	fout.write((char*)&este->_horas, sizeof(este->_horas));
	fout.write((char*)&este->_custo, sizeof(este->_custo));
	fout.close(); std::cout << "Arquivo foi fechado, memória liberada!" << std::endl;
}
void Ler_Arquivo(Jogo*este) {
	std::ifstream fin;
	fin.open("teste");

	if (!fin.is_open()) { std::cout << "\nNão foi possível encontrar o arquivo para leitura!" << std::endl; exit(1); }
	else {
		
		std::cout << "\niniciando a leitura do arquivo de dados..." << std::endl;
		while (fin) {
		fin.read((char*)&este->_nome, sizeof(este->_nome));
		fin.read((char*)&este->_preco, sizeof(este->_preco));
		fin.read((char*)&este->_horas, sizeof(este->_horas));
		fin.read((char*)&este->_custo, sizeof(este->_custo));
		Exibir_cst(este);
		}
	}
	std::cout << "\nLeitura do arquivo foi concluída!" << std::endl;
	fin.close(); std::cout << "Arquivo foi fechado com memória liberada!" << std::endl;
}
//função inline
inline void Calcular(Jogo* este) {
	(este->_horas > 0) ? este->_custo = double(este->_preco) / este->_horas : este->_custo = este->_preco;
}