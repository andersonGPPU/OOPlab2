#include <iostream>
//#include <string>
#include "Queue.h"

fila::fila() //CONSTRUTOR
{
	this->iniPtr = nullptr; this->fimPtr = nullptr; this->op = NULL;
	fout.open("teste.txt", std::ios_base::app);
	if (fout.is_open())
	{
		std::cout << "\nOk. Arquivo pode ser registrado em disco" << std::endl;
	}
	else
	{
		std::cout << "\nERRO! Arquivo n�o pode ser aberto!" << std::endl;
	}
}
fila::~fila() //DESTRUTOR
{
	this->op = NULL;
	while (this->iniPtr != NULL)
	{
		fnPtr temp = iniPtr; //temp recebe valor iniPtr
		iniPtr = (*iniPtr).Ptr; //valor de (*iniPtr) recebe valor do prx ponto
		delete temp;
		if (iniPtr == NULL) fimPtr = NULL;
	}
	if (iniPtr == NULL && fimPtr == NULL)
	{
		std::cout << "Destrutor: mem�ria liberada!" << std::endl;
		std::cout << cbytes(iniPtr) << " Bytes." << std::endl;
	}
	if (fout.is_open())
	{
		fout.close(); std::cout << "arquivo fechado!" << std::endl;
	}
}

//**fun��o usu�rio
void fila::user()
{
	this->op = '0';
	char uc = NULL; //uc = caractere do usu�rio
	while (this->op != '3')
	{
		switch (this->op)
		{
		case '0':
			tela();
			break;
		case '1': //enfileira o caractere 'uc'
			std::cout << "Digite um caractere: ";
			std::cin >> uc;
			enfila(&iniPtr, &fimPtr, uc);
			imp(iniPtr);
			std::cout << cbytes(iniPtr) << " Bytes." << std::endl;
			break;
		case '2':	//desenfileira o caractere removendo da fila
			if (!vazio(iniPtr)) //se n�o vazio
			{
				uc = remfila(&iniPtr, &fimPtr);
				std::cout << "'" << uc << "' retirado da fila." << std::endl;
				imp(iniPtr);
			}
			else
			{
				std::cout << "Fila vazia!" << std::endl;
			}
			std::cout << cbytes(iniPtr) << " Bytes." << std::endl;
			tela();
			break;
		default:
			std::cout << "Escolha inv�lida." << std::endl;
			std::cout << cbytes(iniPtr) << " Bytes." << std::endl;
			tela();
			break;
		} //switch(this->op) FIM
		std::cout << "\nN�MERO#: ";
		std::cin >> op;
	} //while(this->op != 3) FIM
	if (this->op == 3) { std::cout << "Fim do Programa." << std::endl; }
}
//**fun��o calcula bytes consumidos
size_t fila::cbytes(fnPtr iPtr) //ponteiro de Nodos
{
	size_t t = 0;
	while (iPtr != NULL)
	{
		++t;
		iPtr = iPtr->Ptr; //passa ao pr�ximo Nodo
	}
	delete iPtr;
	iPtr = NULL;
	return sizeof(Nodo) * t;
}
//**fun��o imprime
void fila::imp(fnPtr aPtr)
{
	if (aPtr == NULL)
	{
		std::cout << "\nFila vazia!" << std::endl;

	}
	else
	{
		std::cout << "\nA fila atual �:" << std::endl;
		while (aPtr != NULL)
		{
			std::cout << aPtr->ch << " --> ";
			fout << aPtr->ch; //escreve no arquivo TEXTO aberto com REPETI��ES
			aPtr = aPtr->Ptr; //recebe o pr�ximo ponteiro
		}
		std::cout << "/0" << std::endl;
		delete aPtr;
		aPtr = NULL;
	}
}
//**fun��o vazio: verifica se h� Nodo	
int fila::vazio(fnPtr iPtr)
{
	return iPtr == NULL;
}
//**fun��o enfileira(in�cioPtr, fimPtr, caractere)
void fila::enfila(fnPtr* iPtr, fnPtr* fPtr, char c)
{
	fnPtr pt = new fn; //Ptr de fila de Nodos = new fila de Nodos
	if (pt != NULL) //tem mem�ria dispon�vel?
	{
		pt->ch = c;
		pt->Ptr = NULL;

		//se vazio, insere nodo no in�cio
		if (vazio(*iPtr))
		{
			*iPtr = pt; //recebe no in�cio
		}
		else
		{
			(*fPtr)->Ptr = pt; //recebe no final
		}
		*fPtr = pt;
	}
	else
	{
		std::cout << c << " n�o foi inserido. Falta de mem�ria." << std::endl;
	}
}
//**fun��o remove da filaIN�CIO(in�cioPtr, fimPtr)
char fila::remfila(fnPtr* iPtr, fnPtr* fPtr)
{
	char in = (*iPtr)->ch; // 'in' recebe o valor do caractere do in�cio
	fnPtr tempPtr = *iPtr; // 'temp' recebe o valor iPtr (in�cio)
	*iPtr = (*iPtr)->Ptr; // iPtr (in�cio) recebe o pr�ximo ponto de Nodo
	//fila vazia?
	if (*iPtr == NULL) { *fPtr = NULL; }
	delete tempPtr; //delete o valor tempor�rio
	return in; //retorna o caractere 'in' removido do in�cio
}
//**fun��o tela: mostra as instru��es
void fila::tela(void)
{
	std::cout << std::endl;
	std::cout << "Digite sua escolha:" << std::endl;
	std::cout << "1 - para adicionar um item na fila:" << std::endl;
	std::cout << "2 - para remover um item do IN�CIO da fila" << std::endl;
	std::cout << "3 - sair." << std::endl;
	std::cout << "Digite uma op��o acima [1], [2] ou [3]:";
}
