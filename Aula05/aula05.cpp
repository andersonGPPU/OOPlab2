#include "aula05.h"

iC::iC(int v) : value(v) {};

void iC::svalp(int s) {
	value = s;
}
int iC::rvalp() const {
	return value;
}