#ifndef PILHA_H
#define PILHA_H

typedef char Item; //using Item = char;

class Pilha {
private:
	enum { MAX = 50 }; //limite de itens
	Item itens[MAX]; //armazenamento de itens
	unsigned int topo; //�ndice do item no topo

public:
	Pilha(); //construtor

	bool Vazia() const; //verifica se est� vazia
	bool Cheia() const; //verifica se est� cheia

	bool Empilhar(const Item& item); //adiciona item na pilha
	bool Desempilhar(Item& item); //remove item da pilha

};
#endif
