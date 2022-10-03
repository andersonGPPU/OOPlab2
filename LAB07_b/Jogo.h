#ifndef JOGO_H
#define JOGO_H
class Jogo {
private:
	const char* nome;
	double preco;
	unsigned int horas;
	double custo;

	//void Calcular();
public:
	Jogo();
	Jogo(const char* nome, double preco = 0.0f, unsigned int horas = 0);
	~Jogo();
	void Atualizar(double custo);
	void Jogar(unsigned int horas);

	double Custo() const;
	unsigned int Horas() const;

	void Exibir_cst() const;
	void Exibir();

	void Arquivar();
	void Ler_Arquivo();

	const Jogo& Comparar(const Jogo& jogo) const;

	const Jogo& Comparar_Ptr(const Jogo& jogo, 
		const Jogo& (func)(const Jogo&, const Jogo&)) const;
};
#endif
//Métodos inline
inline void Jogo::Calcular() {
	if (horas > 0) custo = double(preco) / horas;
}
inline double Jogo::Custo() const {
	return custo;
}
inline unsigned int Jogo::Horas() const {
	return horas;
}
//funções auxiliares
const Jogo& MaisJogado(const Jogo&, const Jogo&);
const Jogo& MenorCusto(const Jogo&, const Jogo&);
