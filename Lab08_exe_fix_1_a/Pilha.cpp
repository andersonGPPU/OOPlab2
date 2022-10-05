#include "Pilha.h"
#include <iostream>
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
bool Pilha::Cheia() const {
	return topo == tam;
}
bool Pilha::Empilhar(const Item& item, size_t tam) {
	if (topo < tam) {
		*(itens + topo++) = item;
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