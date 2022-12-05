#include "Cap8Ex25.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdio> // remove()

Cadastro::Cadastro(std::string s) {
	fileName = s + ".txt";
}
Cadastro::~Cadastro() {

}

void Cadastro::checkIsFileOpen() {
	if (!filestr.is_open()) {
		std::cout << "Falha ao tentar abrir o arquivo " << fileName << std::endl;
		std::cout << "Saindo...";
		exit(1);
	}
}

void Cadastro::writeLinesToFile(std::string name, std::string age) {
	filestr.open(fileName.c_str(), std::ios_base::out | std::ios_base::app);
	checkIsFileOpen();
	filestr << std::left << std::setw(25) << name << ", " << std::setw(3) << age  << " anos." << std::endl;
	filestr.close();
}
void Cadastro::readLinesToFile() {
	std::string line{};
	filestr.open(fileName.c_str(), std::ios_base::in);
	checkIsFileOpen();
	std::cout << "Lendo o arquivo ..." << std::endl;
	while (!filestr.eof()) {
		std::getline(filestr, line);
		std::cout << line << std::endl;
	}
	filestr.close();
}
void Cadastro::clearFile() {
	if (!remove(fileName.c_str()))
		std::cout << "Arquivo removido..." << std::endl;
	else
		std::cout << "Não foi possível remover o arquivo..." << std::endl;
}