#include <iostream>
#include <clocale>
#include <iomanip>
#include <string>
#include "Cap8Ex25.h"


int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Portuguese_Brasil.1252"); system("chcp 1252 > null");

	std::string file{};
	char op{};
	bool exe = true;

	std::cout << "Entre com o nome do arquivo: ";
	std::getline(std::cin, file);

	Cadastro cd(file);

	while (exe) {
		std::cout << "Entre com a operação desejada: " << std::endl;
		std::cout << "[1] - inserir dado." << std::endl;
		std::cout << "[2] - mostrar dados." << std::endl;
		std::cout << "[3] - limpar dados." << std::endl;
		std::cout << "[4] - terminar o programa." << std::endl;

		std::cin.get(op);
		std::cin.ignore();
		std::cout << "Operação selecionada " << op << std::endl;

		switch (op) {
		case '1': {
			std::string name{}, age{};
			std::cout << "Entre com o nome: ";
			std::getline(std::cin, name);
			std::cin.ignore();
			std::cout << "Entre com a idade: ";
			std::getline(std::cin, age);
			std::cin.ignore();
			std::cout << "Cadastro a ser inserido:\n" <<
				std::left << std::setw(25) << name << " " << std::setw(3) << age << std::endl;

			cd.writeLinesToFile(name, age);
		}
				break;
		case '2': {
			cd.readLinesToFile();
		}
				break;
		case '3': {
			cd.clearFile();
		}
				break;
		case '4': {
			exe = false;
			std::cout << "Saindo do programa..." << std::endl;
		}
				break;
		default: { 
			std::cout << "\n==============================================\n";
			std::cout << "||Operação não encontrada, tente novamente! ||\n"; 
			std::cout << "==============================================\n\n"; }
			   break;
		}
	}

	return 0;
}