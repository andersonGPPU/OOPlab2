#include <iostream>
#include <clocale>

#include "aula05.h.h"
#include "Class2.h"


int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Portuguese_Brasil.1252"); system("chcp 1252 > null");

	P2 t(5);
	std::cout << t.rval() << std::endl;
	t.sval(15);
	std::cout << t.rval() << std::endl;
	


	return 0;
}