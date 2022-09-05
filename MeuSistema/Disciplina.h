#ifndef _DISCIPLINA_H_
#define _DISCIPLINA_H_

#include "Departamento.h"
#include "Aluno.h"
#include "ElAluno.h"

class Disciplina
{ 
private:
	int id;
	char nome[150];
	char area_conhecimento[150];
	int numero_alunos;
	int cont_alunos;
		
	// Associa cada disciplina a um departamento;
	Departamento* pDeptoAssociado;
	ElAluno* pAlunoPrim;
	ElAluno* pAlunoAtual;

public:
	Disciplina(int na = 45, char* ac = "");
	~Disciplina();
		
	// ponteiros para a lista duplamente encadeada;
	Disciplina* pProx;
	Disciplina* pAnte;

	void setId(int i);	
	int getId();
	void setNome(char* n);
	char* getNome();
	void setDepartamento(Departamento* pd);
	Departamento* getDepartamento();
	bool incluirAluno(Aluno * pa);
	bool excluirAluno(Aluno * pa);
	void listarAlunos();
	void listarAlunos2();
};
#endif
