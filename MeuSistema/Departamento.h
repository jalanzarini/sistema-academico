#ifndef _DEPARTAMENTO_H_
#define _DEPARTAMENTO_H_

class Universidade;
class Disciplina;

class Departamento
{
private:
	char nome[130];
	// Associa��o para uma Universidade.
	Universidade* pUniv;
	// Associa��es para as v�rias Disciplinas.
	Disciplina *pDisciplPrim;
	Disciplina *pDisciplAtual;

public:
	Departamento();
	~Departamento();

	void setNome(char* n);
	char* getNome();

	void setUniversidade(Universidade* pu);
	Universidade* getUniversidade();

	void setDisciplina(Disciplina* pd);
	void listeDisciplinas();
	void listeDisciplinas2();
};
#endif
