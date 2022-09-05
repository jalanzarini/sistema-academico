#ifndef _PROFESSOR_H_
#define _PROFESSOR_H_

#include "Pessoa.h"
#include "Universidade.h"

class Professor : public Pessoa
{
public:
	Professor( int diaNa, int mesNa, int anoNa, char* nome );
	Professor();
	~Professor();
};
#endif
