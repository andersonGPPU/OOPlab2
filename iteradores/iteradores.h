#ifndef ITERADORES_H
#define ITERADORES_H
#include <vector>
#include <string>

class Vetores {
private:
	int *_x;

	std::vector<int> v{};
	std::vector<int>::iterator it;
	std::vector<int>::reverse_iterator rit;
public:
	Vetores();
	Vetores(int *, int);
	~Vetores();

	int qtd(int[]);

	void itvetor();
	void ritvetor();

};

#endif
