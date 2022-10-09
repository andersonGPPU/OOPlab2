#ifndef PILHA_H
#define PILHA_H

typedef char Item; //using Item = char;

class Pilha {
private:
	size_t tam; //tamanho máximo
	Item *itens; //armazenamento de itens
	size_t topo; //índice do item no topo

	void Expandir(); //expande a capacidade da pilha

public:
	Pilha();
	Pilha(size_t tam); //construtor
	~Pilha();

	bool Vazia() const; //verifica se está vazia

	void Empilhar(const Item&); //adiciona item na pilha
	void Desempilhar(Item&); //remove item da pilha
	
	bool Comparar(const Item* palavra, Item& xis);

};
#endif
