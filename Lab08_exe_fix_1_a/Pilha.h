#ifndef PILHA_H
#define PILHA_H

typedef char Item; //using Item = char;

class Pilha {
private:
	size_t tam; //tamanho máximo
	Item *itens; //armazenamento de itens
	size_t topo; //índice do item no topo

public:
	Pilha(size_t tam); //construtor
	~Pilha();

	bool Vazia() const; //verifica se está vazia

	Item* Escrever_Item(); //permite ver cada caractere da pilha

	bool Empilhar(const Item&); //adiciona item na pilha
	bool Desempilhar(Item&); //remove item da pilha

};
#endif