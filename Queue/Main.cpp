#include <iostream>
#include <windows.h>
//#include <locale>
#include "Queue.h"
//#include "Queue.cpp" //linux


int main(int argc, char* argv[]) {
	SetConsoleCP(1252); SetConsoleOutputCP(1252);
	//setlocale(LC_ALL, "Portuguese_Brasil.1252"); system("chcp 1252 > nul");
	//setlocale(LC_ALL, "portuguese"); //linux

	fila test;

	test.user();

	return 0;
}
