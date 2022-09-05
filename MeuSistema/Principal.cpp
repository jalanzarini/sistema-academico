#include "stdafx.h"
#include <time.h>

#include "Principal.h"
//#include "Windows.h"

Principal::Principal()
{
	struct tm *local;
	time_t segundos;
  	time(&segundos);
	local = localtime(&segundos);
    
    	diaAtual = local->tm_mday;
    	mesAtual = local->tm_mon + 1;
    	anoAtual = local->tm_year + 1900;
	
	Inicializa();
}

Principal::~Principal()
{	}

void Principal::Inicializa()
{
	InicializaAlunos();
	InicializaUnivesidades();
	InicializaDepartamentos();
	InicializaProfessores();
	InicializaDisciplinas();
	Executar();
}

void Principal::InicializaAlunos()
{
	AAA.setId(0);	AAA.setNome("Alan");
	BBB.setId(1);	BBB.setNome("Pedro");
	CCC.setId(2);	CCC.setNome("Henrique");
	DDD.setId(3);	DDD.setNome("Joãos");
	EEE.setId(4);	EEE.setNome("Gabriel");
	FFF.setId(5);	FFF.setNome("Murilo");
	GGG.setId(6);	GGG.setNome("Enzo");
}

void Principal::InicializaUnivesidades()
{
	// Registro do(s) nome(s) da(s) universidade(s)
	UTFPR.setNome     ( "UTFPR" );
	Princeton.setNome ( "Princeton" );
	Cambridge.setNome ( "Cambridge" );
}

void Principal::InicializaDepartamentos()
{
	// Registro do(s) nome(s) do(s) departamento(s)
	EletronicaUTFPR.setNome		( "Eletronica UTFPR" );
	MatematicaUTFPR.setNome		( "Matematica UTFPR" );
	FisicaUTFPR.setNome		( "Fisica UTFPR" );
	MatematicaPrinceton.setNome 	( "Matematica Princeton" );
	FisicaPrinceton.setNome		( "Fisica Pirnceton" );
	MatematicaCambridge.setNome 	( "Matematica Cambridge" );
	FisicaCambridge.setNome		( "Fisica Cambridge" );   

}

void Principal::InicializaProfessores()
{
	// Inicialização do(s) ojeto(s) da classe Professor
	Simao.Inicializa	( 3, 10, 1976, "Jean Simão" );
	Einstein.Inicializa 	( 14, 3, 1879, "Albert Einstein" );
	Newton.Inicializa	( 4, 1, 1643, "Isaac Newton" );
}

void Principal::InicializaDisciplinas()
{
	Computacao1_2006.setNome	( "Computacao I 2006" );
	Introd_Alg_2007.setNome		( "Introducao de Algoritmos de Programacao 2007" );
	Computacao2_2007.setNome	( "Computao II" );
	Metodos2_2007.setNome		( "Métodos II" );

	Computacao1_2006.setDepartamento  ( &EletronicaUTFPR );
	Introd_Alg_2007.setDepartamento	  ( &EletronicaUTFPR );
	Computacao2_2007.setDepartamento  ( &EletronicaUTFPR );
	Metodos2_2007.setDepartamento     ( &EletronicaUTFPR );

	Metodos2_2007.incluirAluno( &BBB );
	Metodos2_2007.incluirAluno( &AAA );
	Metodos2_2007.incluirAluno( &EEE );
	Metodos2_2007.incluirAluno( &CCC );
	Metodos2_2007.incluirAluno( &FFF );
	Metodos2_2007.incluirAluno( &DDD );
	Metodos2_2007.incluirAluno( &GGG );
    
	Computacao2_2007.incluirAluno( &AAA );
	Computacao2_2007.incluirAluno( &EEE );
 	Computacao2_2007.incluirAluno( &DDD );
}

void Principal::CalcIdadeProfs()
{
	// Cálculo da idade.
	Simao.Calc_Idade    ( diaAtual, mesAtual, anoAtual );
	Einstein.Calc_Idade ( diaAtual, mesAtual, anoAtual );
	Newton.Calc_Idade   ( diaAtual, mesAtual, anoAtual );
	cout << endl;
}

void Principal::ListeDiscDeptos()
{
	EletronicaUTFPR.listeDisciplinas();
	cout << endl;
	
	MatematicaUTFPR.listeDisciplinas();
	FisicaUTFPR.listeDisciplinas();
	cout << endl;
	
	MatematicaPrinceton.listeDisciplinas();
	FisicaPrinceton.listeDisciplinas();
	cout << endl;

	MatematicaCambridge.listeDisciplinas();
	FisicaCambridge.listeDisciplinas();
}

void Principal::ListeAlunosDisc()
{
	Metodos2_2007.listarAlunos();
	Computacao2_2007.listarAlunos();
}

void Principal::Executar()
{
	//CalcIdadeProfs();
	cout << "Lista de disciplinas por departamento:" << endl;
	
	ListeDiscDeptos();
	cout << "Pressione ENTER para continuar.." << endl;
	cin.get();

	ListeAlunosDisc();
	cout << "Pressione ENTER para continuar.." << endl;
	cin.get();
}

