#include "iteradores.h"
#include <vector>
#include <string>
#include <algorithm>    // std::max
#include <cstdint>      // uint64_t
#include <iostream>

Vetores::Vetores() {
	this->_x = nullptr;
	v = {};
}
Vetores::Vetores(int *r, int tam) {
	/*_x = new int[tam];*/
	/*this->_x = r;*/ _x = r;

	_x = (int*)malloc(tam * sizeof(int));
	std::cout << "tamanho alocado: " << sizeof(int) * tam << "Bytes" << std::endl;

	std::vector<int> temp(r, r + tam);
	v = temp;
	std::cout << "tamanho alocado V: " << sizeof(v) << "Bytes" << std::endl;
}
Vetores::~Vetores() {
	//this->_x = nullptr;
	free(_x);
}
void Vetores::itvetor() {
	for (it = v.begin(); it != v.end(); it++) {
		std::cout << *it << ", ";
	} std::cout << std::endl;
}
void Vetores::ritvetor() {
	for (rit = v.rbegin(); rit != v.rend(); rit++) {
		std::cout << *rit << ", ";
	}std::cout << std::endl;
}