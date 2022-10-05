#include "Pilha.h"
#include <iostream>
Pilha::Pilha() {
	itens[0] = '\0'; tam = topo = 0;
}
Pilha::Pilha(const Item* ch, size_t tam) {
	std::cout << "Construtor" << std::endl;
	std::cout << ch << std::endl;
	topo = tam; this->tam = tam;
	
	for (size_t i = 0; i < tam; itens[i] = ch[i], ++i);
	std::cout << std::endl;
	std::cout << itens;
}
Pilha::~Pilha() {
}
bool Pilha::Vazia() const {
	return topo == 0;
}

void Pilha::EmpilharPlus(const Item& item) {
	if (topo > 0) {
		++tam;
		*(itens + ++topo) = item;
		itens[topo + 1] = '\0';
	}
}
bool Pilha::Desempilhar(Item& item) {
	if (topo > 0) {
		item = *(itens + --topo);
		return true;
	}
	else return false;
}

Item* Pilha::Escrever_Item() {
	return this->itens;
}

void Pilha::ApagarPilha() {
	size_t i = 0;
	while (itens[i]) {
		itens[i++] = 'x';
	}
}