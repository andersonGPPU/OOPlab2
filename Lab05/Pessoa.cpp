#include <iostream>
#include <fstream>
#include "Pessoa.h"

Pessoa::Pessoa() {
	std::cout << "Construtor padrão" << std::endl;
	nome_ = "Não foi implementado o nome";
	sobrenome_ = "Não foi implementado o sobrenome";
}
Pessoa::Pessoa(const char& nome, const char& sobrenome) {
	std::cout << "Construtor com argumentos" << std::endl;
	nome_ = &nome;
	sobrenome_ = &sobrenome;
}
void Pessoa::SetNome(const char& nome) {
	nome_ = &nome;
}
const char Pessoa::GetNome(void) {
	return *nome_;
}
void Pessoa::SetSobrenome(const char& sobrenome) {
	sobrenome_ = &sobrenome;
}
const char Pessoa::GetSobrenome(void) {
	return *sobrenome_;
}
void Pessoa::Exibir() {
	std::cout << "NOME: " << nome_ << std::endl;
}
void Pessoa::Formal() {
	std::cout << "SOBRENOME: " << sobrenome_ << std::endl;
}
void Pessoa::Gravar() {
	std::ofstream fout;
	fout.open("teste.txt", std::ios_base::app);
	if (fout.is_open()) { std::cout << "Arquivo para gravação aberto com sucesso!" << std::endl; }
	else { std::cout << "falha ao tentar criar o arquivo para gravação!" << std::endl; exit(1); }

	fout.write((char*)&nome_, sizeof(nome_));
	fout.write((char*)&sobrenome_, sizeof(sobrenome_));
	//fout << nome_ << " " << sobrenome_ << std::endl;
	fout.close();
}
void Pessoa::Ler() {
	std::ifstream fin;
	fin.open("teste.txt");
	if (fin.is_open()) { std::cout << "Arquivo aberto para leitura." << std::endl; }
	else { std::cout << "Erro ao tentar abrir o arquivo para leitura."; exit(1); }

	while (!fin.eof()) {
		fin.read((char*)&nome_, sizeof(nome_));
		fin.read((char*)&sobrenome_, sizeof(sobrenome_));
		std::cout << nome_ << " " << sobrenome_ << std::endl;
	}
	fin.close();
}