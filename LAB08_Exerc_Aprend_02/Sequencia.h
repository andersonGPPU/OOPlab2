#ifndef SEQUENCIA_H
#define SEQUENCIA_H
class Sequencia {
private:
	char* dado;
	unsigned int limite; //limitador
	unsigned int tamanho; //tamanho do vetor
	double resultado;
	
	void Expandir_Dado();
public:
	Sequencia();
	~Sequencia();
	
	void Empilhar(const char& info_ref);
	void Desempilhar(char& volta);
	bool Verificar(const char* exp_ptr);
};
#endif
