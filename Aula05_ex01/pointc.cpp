#include "pointc.h"
#include <iostream>
#include <iomanip>

void Dot::sCoord(float a, float b) {
	_x = a; _y = b;
}
void Dot::eCoord() {
	std::cout << "(" << _x << ", " << _y << ")" << std::endl;
}