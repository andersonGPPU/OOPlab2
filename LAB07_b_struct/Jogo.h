#ifndef JOGO_H
#define JOGO_H
struct Jogo {
	const char* _nome;
	double _preco;
	unsigned int _horas;
	double _custo;
};
#endif

inline void Calcular(Jogo *este);
void Atualizar(Jogo* este, double custo);
void Jogar(Jogo* este, unsigned int horas);

void Exibir_cst(const Jogo* este);
void Exibir(Jogo* este);

void Arquivar(Jogo*este);
void Ler_Arquivo(Jogo*este);
