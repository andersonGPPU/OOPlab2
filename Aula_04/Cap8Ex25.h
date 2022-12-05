#ifndef CAP8EX25_H
#define CAP8EX25_H

#include <string>
#include <fstream>

class Cadastro {
public:
	Cadastro(std::string);
	~Cadastro();

	void writeLinesToFile(std::string, std::string);
	void readLinesToFile();
	void clearFile();

private:
	std::string fileName;
	std::fstream filestr;

	void checkIsFileOpen();
};


#endif