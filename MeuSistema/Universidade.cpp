#include "stdafx.h"
#include "Universidade.h"

Universidade::Universidade()
{	}

Universidade::~Universidade()
{	}

char* Universidade::getNome()
{
	return nome;
}

void Universidade::setNome(char* n)
{
	strcpy(nome, n);
}
