#include <iostream>
#include "StrplusStr.h"

StrplusStr::StrplusStr() {
	_ab = NULL; _resp = NULL; //endereço nulo
}
StrplusStr::~StrplusStr() {
	delete _ab; _ab = NULL; _resp = NULL;
}

size_t StrplusStr::tam(const char* ptr) const {
	size_t i = 0; //valor do ponteiro *ptr; incrementa endereço ptr++
	for (; *ptr != '\0'; ptr++, ++i);
	return i;
}

char* StrplusStr::plus(char* aPtr, char* bPtr) {
	size_t t = tam(aPtr) + tam(bPtr);
	this->_ab = new char[t + 1]; // +1 para '\0'

	while (*aPtr != '\0') {
		*_ab = *aPtr; //valor 'ab' rebece valor 'aPtr'
		_ab++; aPtr++; //avança os endereços
	}

	while (*bPtr != '\0') {
		*_ab = *bPtr;
		_ab++; bPtr++;
	} //ao final 'ab' ficou muito avançado
	*_ab = '\0'; //último valor recebe nulo
	for (size_t i = 0; i < t; _ab--, ++i); //retorna posição de 'ab'
	this->_resp = _ab;
	return _resp;
}
char* StrplusStr::plus(const char* aPtr, const char* bPtr) {
	size_t t = tam(aPtr) + tam(bPtr);
	this->_ab = new char[t + 1]; // +1 para '\0'

	while (*aPtr != '\0') {
		*_ab = *aPtr;
		_ab++; aPtr++;
	}

	while (*bPtr != '\0') {
		*_ab = *bPtr;
		_ab++; bPtr++;
	}
	*_ab = '\0'; //último valor recebe nulo
	for (size_t i = 0; i < t; _ab--, ++i); //retorna posição de 'ab'
	this->_resp = _ab;
	return _resp;
}
