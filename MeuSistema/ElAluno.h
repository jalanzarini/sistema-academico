#ifndef _ELALUNO_H_
#define _ELANULO_H_

#include "Aluno.h"

class ElAluno
{
private:
	Aluno* pAluno;

public:
	ElAluno *pAnte;
	ElAluno *pProx;

	ElAluno();
	~ElAluno();
	
	void setAluno(Aluno *pa);
	Aluno* getAluno();	
};

#endif