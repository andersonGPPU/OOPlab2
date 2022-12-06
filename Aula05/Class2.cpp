#include "Class2.h"
#include "aula05.h"

P2::P2(int i) : ptr(new iC(i)){}
P2::~P2() { delete ptr; }

void P2::sval(int c) {
	(*ptr).svalp(c);
}
int P2::rval() const {
	return (*ptr).rvalp();
}