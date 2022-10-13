#include "Sequencia.h"
#include <iostream>

Sequencia::Sequencia() {
	dado = new char[tamanho]{};
	limite = tamanho = 0; resultado = 0.0f;
}
Sequencia::~Sequencia() {
	delete[]dado;
}
void Sequencia::Expandir_Dado() {
		char* vet = new char[2 * tamanho + 1]; //vetor auxiliar
		for (unsigned int i = 0; i < tamanho; vet[i] = dado[i], i++);
		tamanho = 2 * tamanho + 1; //dobra o tamanho
		delete[]dado; //libera memória de 'dado'
		dado = vet; //'dado' aponta para endereço de vet[]
}
void Sequencia::Empilhar(const char& info_ref) {
	if(limite == tamanho) Expandir_Dado();
	dado[limite++] = info_ref;
}
void Sequencia::Desempilhar(char& volta_ch) {
	if (limite > 0)
		volta_ch = dado[--limite];
}
bool Sequencia::Verificar(const char* exp_ptr) {
	for (unsigned int i = 0; exp_ptr[i]; Empilhar(exp_ptr[i]), i++);
	
	unsigned int t_cont = 0;
	std::cout << "Emp " << " Desemp" << std::endl;
	char ch_des{}; unsigned int j = 0;
	for (unsigned int i = limite; i > 0; i--) {
		Desempilhar(ch_des);
		if (ch_des == '(' && dado[j] == '(') ++t_cont;
		if (ch_des == ')' && dado[j] == ')') ++t_cont;
		if (ch_des == '(' && dado[j] != ')') ++t_cont;
		if (ch_des == ')' && dado[j] != '(') ++t_cont;

		std::cout << "[" << dado[j++] << "]" << " - [" << ch_des << "] " << std::endl;
	}
	return 0 == t_cont;
}