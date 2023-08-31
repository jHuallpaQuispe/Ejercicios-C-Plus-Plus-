/*   SE RECIBIRAN LOS NOMBRES DE LOS CANDIDATOS DE UNA ELECCION
     CON LA CANTIDAD DE VOTOS QUE OBTUVO EN CADA MESA.
     LOS NODOS CANDIDATO ESTARAN FORMADOS POR EL NOMBRE, LA CANTIDAD
     DE VOTOS ACUMULADOS Y EL PUNTERO AL SIGUIENTE.
     SE PIDE HACER UNA LISTA EN LA QUE NO SE REPITAN NODOS PARA EL MISMO CANDIDATO.
     SI ESTE NO ESTA EN LA LISTA, SE LO DA DE ALTA JUNTO CON SUS VOTOS.
     SI ESTE EXISTE, NO SE LO DEBE DAR DE ALTA Y SE DEBERAN ACTUALIZAR SUS VOTOS.
     DETERMINAR EL CANDIDATO GANADOR.
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>

using namespace std;

class CANDIDATO {
	public :
		char NOM[20] ;
		CANDIDATO * SIG ;	
		CANDIDATO(char *);
};


CANDIDATO::CANDIDATO(char * NOMBRE)
{
		strcpy(NOM,NOMBRE) ;		
}



class LISTA {
	private :
		CANDIDATO * INICIO ;
	public :
		LISTA();
		void CARGAR(char *,int);
		void MIRAR() ;
};


LISTA::LISTA()
{
		INICIO = NULL ;		
}



void LISTA::CARGAR(char * NOMBRE , int VOTOS)
{
		CANDIDATO * P ;
		P = new CANDIDATO(NOMBRE) ;
		P->SIG = INICIO ;
		INICIO = P ;	
}


void LISTA::MIRAR()
{
		CANDIDATO * P ;
					
		P = INICIO ;
		while ( P ) {
				cout << "\n\t\t CANDIDATO  :  " << P->NOM << "\n";
				P = P->SIG ;
		}
		getchar();
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
				
		/*   DETERMINAR EL CANDIDATO GANADOR  */
//		L.GANADOR() ;		
			
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
		
		
		
		
		
