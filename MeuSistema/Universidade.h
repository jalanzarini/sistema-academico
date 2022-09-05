#ifndef _UNIVERSIDADE_H_
#define _UNIVERSIDADE_H_

#include "Departamento.h"

class Universidade
{
private:
	char nome[130];
public:
	Universidade();
	~Universidade();

	void setNome(char* n);
	char* getNome();
};
#endif

