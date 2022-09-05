#include "stdafx.h"
#include "ElAluno.h"

ElAluno::ElAluno()
{
	pProx = pAnte = NULL;
}

ElAluno::~ElAluno()
{	}

void ElAluno::setAluno(Aluno *pa) 
{
	pAluno = pa;
}

Aluno* ElAluno::getAluno() 
{   
	return pAluno;
}
