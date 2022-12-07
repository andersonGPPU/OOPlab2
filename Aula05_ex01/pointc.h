#ifndef POINTC_H
#define POINTC_H

#include <string>
#include <fstream>

class Dot {
public:
	void sCoord(float,float);
	void eCoord();

private:
	float _x, _y;
};
#endif