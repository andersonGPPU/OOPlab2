#ifndef PILHA_H
#define PILHA_H

typedef char Item; //using Item = char;

class Pilha {
private:
	size_t tam;
	Item *itens = new Item[tam]; //armazenamento de itens
	size_t topo; //índice do item no topo

public:
	Pilha();
	Pilha(const Item* ch, size_t tam); //construtor
	~Pilha();

	bool Vazia() const; //verifica se está vazia

	Item* Escrever_Item();

	void EmpilharPlus(const Item& item); //adiciona item na pilha CHEIA
	bool Desempilhar(Item& item); //remove item da pilha

	void ApagarPilha();
};
#endif