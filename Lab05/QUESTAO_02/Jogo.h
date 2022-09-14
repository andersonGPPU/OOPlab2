#ifndef JOGO_H
#define JOGO_H

class Jogo {
private:
	const char* nome;
	float preco;
	int horas;
	float custo;

	void calcular() {
		(horas > 0) ? float(custo = float(preco) / horas) : custo = 0.0;
	}

public:
	Jogo();
	Jogo(const char* titulo, float valor = 1.0f);
	void atualizar(float valor);
	void jogar(int tempo);
	void exibir();
	void gravar();
	void ler();
};
#endif