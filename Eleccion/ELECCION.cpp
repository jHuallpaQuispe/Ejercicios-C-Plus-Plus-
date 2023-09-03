
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>

using namespace std;

class CANDIDATO {
	public :
		char NOM[20] ;
		int VOTOS;
		CANDIDATO * SIG ;	
		CANDIDATO(char *, int);
};


CANDIDATO::CANDIDATO(char * NOMBRE, int VOTOS1)
{
		strcpy(NOM,NOMBRE) ;
		VOTOS = VOTOS1;		
}



class LISTA {
	private :
		CANDIDATO * INICIO ;
	public :
		LISTA();
		void MIRAR() ;
		void CARGAR(char *,int);
		void GANADOR();
		CANDIDATO * BUSCAR(char *);
		void PONER_PRINCIPIO(CANDIDATO *);
};


LISTA::LISTA()
{
		INICIO = NULL ;		
}

void LISTA::MIRAR()
{
		CANDIDATO * P ;
					
		P = INICIO ;
		while ( P ) {
				printf("\n\t\t CANDIDATO  :  %s			%-15d", P->NOM,P->VOTOS);
				P = P->SIG ;
		}
	//	getchar();
}
void LISTA::GANADOR(){
	int cont;
	int contMax = 0;
	char Ganador[20];
	CANDIDATO * P;
	P = INICIO;
	
	while(P){
		if(P->VOTOS > contMax){
			strcpy(Ganador, P->NOM);
			contMax= P->VOTOS;
		}
		P = P->SIG;
	}
	
	cout << "\n\n\t	EL GANADOR ES " << Ganador;
	
}
void LISTA::PONER_PRINCIPIO(CANDIDATO * P){
	
	P->SIG = INICIO;
	INICIO = P;
	
}
CANDIDATO * LISTA::BUSCAR(char * S){
	CANDIDATO * P;
	
	P = INICIO;
	while(P){
		if(!strcmp(S,P->NOM))
			return P;
		P = P->SIG;
	}
	return NULL;
}

void LISTA::CARGAR(char * S, int VOTOS){
	CANDIDATO * P;
	P = BUSCAR(S);
	if(P){
		//ACUMULAMOS
		P->VOTOS += VOTOS;
		return;
	}
	P = new CANDIDATO(S, VOTOS);
	PONER_PRINCIPIO(P);
}

char * GENERANOM() ;

int main()
{
		int I , CANTIDAD ;
		LISTA L ;
				
		CANTIDAD = 500 + rand()%300	;	
		for ( I = 0 ; I < CANTIDAD ; I++ )
				L.CARGAR( GENERANOM() , 200+rand()%300 ) ;
				
		L.MIRAR() ;	
		
		L.GANADOR();
				
		return 0 ;
}



char * GENERANOM()
{
		static char NOM[][20] = {"GOMEZ","FERNANDEZ","LONCO","BERMUDEZ",
						  "INSAURRALDE","DIMARIA","DIBLASIO","BELAUSTEGUI",
						  "GARCIA","GARMENDIA","BERTOLINI","JAIME",
						  "VARELA","LAURIA","DINASTASIO","DORIO",
						  "OSORNO","ALBERTENGO","SORIA","BENEDETTO",
						  "AMENDOLA","LAUTARO","GALINDEZ","ZAPATA",
						  "HERMAN","JORDAN","NAPOLITANO","PEPE",
						  "LOLA","PACO","ANDRES","HERMENEGILDO",
						  "CAROLINA","CATALINA","MINERVA","VASQUEZ",
						  "CONSTANTINOPLA","IBARRA","LUNA","ZOLORZANO"};
		return NOM[rand()%40];
}
		
		
		
		
		
