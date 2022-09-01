#pragma once
#ifndef JOGO_H
#define JOGO_H

class Jogo {
private:
	const char *nome;
	float preco;
	int horas;
	float custo;

	void calcular() {
		(horas > 0) ? custo = (preco / horas) : custo = preco;
	}//if (horas > 0) custo = preco / horas;

public:
	Jogo();
	~Jogo();
	void adquirir(const char* titulo, float valor);
	void atualizar(float valor);
	void jogar(int tempo);
	void exibir();
	void gravar();
	void leitura();
	void nome_bits();
};
#endif
