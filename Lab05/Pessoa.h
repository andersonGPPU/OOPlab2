#ifndef PESSOA_H
#define PESSOA_H
class Pessoa
{
private:
	const char* nome_;
	const char* sobrenome_;
public:
	Pessoa();
	Pessoa(const char& nome, const char& sobrenome = ' ');

	void SetNome(const char& nome);
	void SetSobrenome(const char& sobrenome = ' ');
	const char GetNome(void);
	const char GetSobrenome(void);

	void Exibir(); //exibe apenas o nome
	void Formal(); //exibe nome e sobrenome
	void Gravar();
	void Ler();
};
#endif
