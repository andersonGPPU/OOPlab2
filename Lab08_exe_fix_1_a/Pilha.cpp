#include "Pilha.h"
#include <iostream>
Pilha::Pilha(size_t tam) {
	std::cout << "Construtor" << std::endl;
	this->tam = tam;
	itens = new Item[tam];
	topo = 0;
}
Pilha::~Pilha() {
	delete[]itens;
}
bool Pilha::Vazia() const {
	return topo == 0;
}

bool Pilha::Empilhar(const Item& item) {
	if (topo < tam) {
		*(itens + topo++) = item;
		itens[1 + topo] = '\0';
		return true;
	}
	else return false;
}
bool Pilha::Desempilhar(Item& item) {
	if (topo > 0) {
		item = *(itens + --topo);
		return true;
	}
	else return false;
}

Item* Pilha::Escrever_Item() const {
	return itens;
}
