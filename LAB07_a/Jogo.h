#ifndef JOGO_H
#define JOGO_H
class Jogo {
private:
	const char* nome;
	double preco;
	unsigned int horas;
	double custo;

	void calcular();

public:
	Jogo();
	Jogo(const char* nome, double preco = 0.0f, unsigned int horas = 0);
	~Jogo();
	void atualizar(double custo);
	void jogar(unsigned int horas);

	void exibir_cst() const;
	void exibir();

	void arquivar();
	void ler_arquivo();

	const Jogo& comparar(const Jogo& jogo) const;
};
#endif
