#ifndef JOGO_H
#define JOGO_H
class Jogo
{
private:
	const char* _nome;
	float _preco;
	int _horas;
	float _custo;

	void calcular();

public:
	Jogo();
	Jogo(const char* nome, float preco = 0);
	~Jogo();

	void SetNome(const char* nome);
	const char* GetNome();

	void atualizar(float custo);
	void jogar(int tempo);
	void exibir();
	const void exibir_cst();
	void gravar_arquivo();
	void ler_arquivo();
}; 
#endif
