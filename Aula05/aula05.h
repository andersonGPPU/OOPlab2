#ifndef AULA05_H
#define AULA05_H

#include <string>
#include <fstream>

class iC {
public:
	iC(int);

	void svalp(int);
	int rvalp() const;

private:
	int value;
};


#endif