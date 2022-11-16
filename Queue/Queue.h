#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <fstream>

class fila {
private:
	std::ofstream fout;

	struct Nodo { //ponteiro 'Ptr' indica o endereço do próximo Nodo
		char ch;
		Nodo* Ptr; //ponto do próximo Nodo (recusivo por ponteiro)
	};

	typedef Nodo fn; //fn->fila de Nodos
	typedef fn* fnPtr; //fnPtr -> ponto de fila de Nodos

	char op; //guarda a opção do usuário

	fnPtr iniPtr; //Nodo de inícioPtr
	fnPtr fimPtr; //Nodo de fimPtr

public:
	fila();
	~fila();
	void user(); //prog principal
	void imp(fnPtr aPtr); //aPtr ponto atual
	int vazio(fnPtr iPtr);
	void enfila(fnPtr* iPtr, fnPtr* fPtr, char c); //enfileira
	char remfila(fnPtr* iPtr, fnPtr* fPtr); //remove de fila no início ao fim
	//char dfilafim(fnPtr *iPtr, fnPtr *fPtr); //remove de fila no fim ao início
	size_t cbytes(fnPtr iPtr);
	void tela(void); //tela com instruções

};



#endif
