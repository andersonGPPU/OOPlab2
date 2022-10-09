#include "Pilha.h"
#include <iostream>
Pilha::Pilha() {
	//itens = new Item[1]{}; tam = 1;
	itens = nullptr; //ponteiro vazio
	tam = 0;
	topo = 0;
}
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
void Pilha::Expandir() {
if (topo == tam){
	std::cout << "Expandindo capacidade de " << tam;
	//cria novo espaço
	Item* vet = new Item[2 * tam + 1]; //se tam = 0, 2*0+1=1
	//copia elementos para novo espaço
	for (unsigned int i = 0; i < tam; ++i) vet[i] = itens[i];
	//libera espaço antigo
	delete[]itens;
	//atualiza atributos
	itens = vet; //ponteiro itens recebe endereço em vet, itens passa a apontar para o novo vetor com capacidade duplicada 
	tam = 2 * tam + 1;
	std::cout << " para " << tam << '\n';
	}
}
void Pilha::Empilhar(const Item& item) {
	std::cout << "Empilhando [" << item << "]\n";
	//se a pilha está cheia
		Expandir();
	itens[topo++] = item;
	std::cout << " [" << item << "] Empilhado\n";
}
void Pilha::Desempilhar(Item& item) {
	if (topo > 0) {
		item = *(itens + --topo);}
		/*return true;
	}
	else return false;*/
}
bool Pilha::Comparar(const Item* palavra, Item& item) {
	unsigned int cont = 0;
	for(unsigned i = 0; palavra[i]; i++) { Empilhar(palavra[i]); }
	
	for(unsigned i = 0; palavra[i]; i++) { Desempilhar(item); 
	if(palavra[i] != item) ++cont; }
		
	return cont == 0;
}
