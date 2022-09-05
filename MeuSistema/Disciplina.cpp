#include "stdafx.h"

#include "Disciplina.h"

Disciplina::Disciplina(int na, char* ac)
{
	pDeptoAssociado		= NULL;
	pProx				= NULL;
    pAnte				= NULL;
	cont_alunos			= 0;
	numero_alunos		= na;
	pAlunoPrim			= NULL;
	pAlunoAtual			= NULL;
    
	strcpy(area_conhecimento, ac);
}

Disciplina::~Disciplina()
{
	ElAluno* aux = pAlunoPrim;
	while (NULL != aux)
	{		
		pAlunoPrim = pAlunoPrim->pProx;
		delete aux;
		aux = pAlunoPrim;
	}
}

void Disciplina::setId(int i)
{
	id = i;
}

int Disciplina::getId()
{
	return id;
}

void Disciplina::setNome(char* n)
{
	strcpy(nome, n);
}

char* Disciplina::getNome()
{
	return nome;
}

void Disciplina::setDepartamento(Departamento* pd)
{
	// Cada vez que um Departamento é associado a uma Disciplina,
	// esta Disciplina passa a fazer parte da lista de disciplina 
	// do Departamento, por meio do comando abaixo.
	pDeptoAssociado = pd;
	pd->setDisciplina( this );
}

Departamento* Disciplina::getDepartamento()
{
	return  pDeptoAssociado;
}

bool Disciplina::incluirAluno(Aluno * pa)
{
	if ((cont_alunos == numero_alunos) || NULL == pa)
		return false;

	ElAluno* nv = new ElAluno;
	nv->setAluno( pa );
	nv->pProx = NULL;

	if (NULL == pAlunoPrim)
	{
		pAlunoAtual = pAlunoPrim = nv;
	}
	else
	{
		//pAlunoAtual->pProx = nv;
		//nv->pAnte = pAlunoAtual;
		//pAlunoAtual = nv;

		// Uma maneira de inserir os elementos de maneira ordenada, considerando que em listas 
		// encadeadas é mais eficiente (computacionalmente) manter os elementos ordenados do que
		// ordená-los somente na hora de apresentá-los.
		ElAluno* aux = pAlunoPrim;
		while (NULL != aux)
		{
			// compara o nome a ser inserido com os nomes na lista;
			if( strcmp(pa->getNome(), aux->getAluno()->getNome()) < 0 )
			{
				nv->pProx = aux;
				nv->pAnte = aux->pAnte;
								
				if (aux == pAlunoPrim)
				{
					pAlunoPrim = nv;
				}
				else
				{
					aux->pAnte->pProx = nv;					
				}
				aux->pAnte = nv;
				break;
			}
			// caso tenha chegado ao final da lista, simplemente insere;
			if (aux == pAlunoAtual)
			{
				pAlunoAtual->pProx = nv;
				nv->pAnte = pAlunoAtual;
				pAlunoAtual = nv;
				break;
			}
			aux = aux->pProx;		
		}
	}

	cont_alunos ++;
	return true;
}

bool Disciplina::excluirAluno(Aluno * pa)
{
	ElAluno* aux = pAlunoPrim;
	while(NULL != aux)
	{
		if (aux->getAluno()->getId() == pa->getId())
		{			
			if (pAlunoPrim == pAlunoAtual)
			{
				pAlunoAtual = pAlunoPrim = NULL;			
			}
			else if (aux == pAlunoPrim)
			{
				pAlunoPrim = pAlunoPrim->pProx;
				pAlunoPrim->pAnte = NULL;
			} 
			else if (aux == pAlunoAtual)
			{
				pAlunoAtual = pAlunoAtual->pAnte;
				pAlunoAtual->pProx = NULL;
			}
			else
			{
				aux->pAnte->pProx = aux->pProx;
				aux->pProx->pAnte = aux->pAnte;
			}
			delete aux;

			cont_alunos --;
			return true;
		}
		aux = aux->pProx;
	}
	return false;
}

void Disciplina::listarAlunos()
{
	if (NULL != pAlunoPrim)
	{
		cout << "Lista de alunos de: " << nome << endl;

		ElAluno* aux = pAlunoPrim;	
		while(NULL != aux)
		{
			cout << aux->getAluno()->getNome() << endl;
			aux = aux->pProx;
		}
	}
}

void Disciplina::listarAlunos2()
{
	if (NULL != pAlunoPrim)
	{
		cout << "Lista de alunos de: " << nome << endl;

		ElAluno* aux = pAlunoAtual;
		while(NULL != aux)
		{
			cout << aux->getAluno()->getNome() << endl;
			aux = aux->pAnte;
		}
	}
}