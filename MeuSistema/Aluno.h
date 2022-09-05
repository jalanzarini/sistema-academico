#ifndef _ALUNO_H_
#define _ALUNO_H_

#include "Departamento.h"
#include "Pessoa.h"

class Aluno : public Pessoa
{ 
private:
	int				id;
	int				RA;
	Departamento*	DeptoAssociado;

public:

	Aluno(int diaNa, int mesNa, int anoNa, char* nome = "");
	Aluno(int i);
	Aluno();
	~Aluno();

	void setRA(int ra);
	int getRA();
	void setDepartamento (Departamento* d);
	Departamento* getDepartamento();
	void setId(int i);
	int getId();
};
#endif
