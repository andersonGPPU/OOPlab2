#ifndef PILHA_H
#define PILHA_H

typedef char Item; //using Item = char;

class Pilha {
private:
	size_t tam;
	Item *itens = new Item[tam]; //armazenamento de itens
	size_t topo; //�ndice do item no topo

public:
	Pilha(const Item* ch, size_t tam); //construtor
	~Pilha();

	bool Vazia() const; //verifica se est� vazia
	bool Cheia() const; //verifica se est� cheia

	bool Empilhar(const Item& item, size_t); //adiciona item na pilha
	bool Desempilhar(Item& item); //remove item da pilha

};
#endif