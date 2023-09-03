/*se recibiran los nombres de los candidatos de una eleccion con la cantidad de votos que obtuvo en cada mesa.
los nodos candidato estaran formados por el nombre, la cantidad de votos acumulados y el puntero al sig.
SE PIDE HACER UNA LISTA EN LA QUE NO SE REPITAN NODOS PARA EL MISMO CANDIDATO.
SI EXISTE ESTE CANDIDATO, SE LE ACTUALIZARAN LOS VOTOS.
DETERMINAR EL GANADOR*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

class CANDIDATO {
	public:
    	char NOM[20];
    	int VOTOS;
    	CANDIDATO * SIG ;
    	CANDIDATO (char *, int );
    	CANDIDATO (char * );

};

CANDIDATO ::CANDIDATO( char * NOMBRE, int VOTOS1)
{
    strcpy (NOM, NOMBRE);
    VOTOS = VOTOS1;


}
CANDIDATO ::CANDIDATO( char * NOMBRE)
{
    strcpy (NOM, NOMBRE);


}

class LISTA{
	private :
		CANDIDATO * INICIO;
	public :
		LISTA();
		~LISTA();
		void CARGAR(char *);
		void MIRAR();
		CANDIDATO * BUSCAR(char * );
		void DEPURA();
		void MATAR(CANDIDATO *);
		
};

LISTA::LISTA()
{
	INICIO = NULL;
}

LISTA::~LISTA(){
	CANDIDATO * P, *Q;
	P = INICIO;
	
	while(P){
		
		Q = Q->SIG;
		delete P;
		P = Q-> SIG;
	}
}

CANDIDATO * LISTA::BUSCAR(char * NOMBRE)
{
	CANDIDATO * P;

	P = INICIO;

	while(P)
	{
		if( ! strcmp (P->NOM, NOMBRE) )
		{
			return P;
		}
		P = P->SIG;
	}
	return NULL;
}

void LISTA::CARGAR(char * NOMBRE)
{

	CANDIDATO * P;
	P = new CANDIDATO(NOMBRE);
	P->SIG = INICIO;
	INICIO = P;

}

void LISTA::MIRAR()
{
	CANDIDATO * P ;
	int K = 1;

	P = INICIO ;

	while( P )
	{

		cout << "\n\n\t CANDIDATO : " << K++ << P->NOM;

		P = P->SIG ;
	}
	getchar();

}
void LISTA::MATAR(CANDIDATO *PANT){
	CANDIDATO *P;
	P = INICIO;
	if(PANT == INICIO){
		/*ESTA VACIA*/
		INICIO = PANT->SIG;
		delete PANT;
		return;
		
	}
	/*RECORRIDO*/
	while(P->SIG != PANT)
		P = P->SIG;
	
	P->SIG = PANT->SIG;
	delete PANT; 
}
void LISTA::DEPURA(){
	
	CANDIDATO * P, *Q, * AUX;
	P = INICIO;
	
	while(P){
		Q = INICIO;
		while(Q){
		
			if(!strcmp(P->NOM,Q->NOM)){
				AUX = Q->SIG;
				// 
				while(AUX){
					if(!strcmp(Q->NOM,AUX->NOM))
						MATAR(AUX);
						
					AUX = AUX->SIG;
				}
			
			}
			
			Q = Q->SIG;
		
	    }
		P=P->SIG;
	}
}
char * GENERANOM();

int main (){

    int I , CANTIDAD ;
    LISTA L ;

    CANTIDAD = 30;

    for (I = 0; I < CANTIDAD ; I++)
    {
    	//L.CARGAR( GENERANOM(), 200+rand()%300 ) ;
    	L.CARGAR( GENERANOM()) ;
	}

	L.MIRAR() ;
	L.DEPURA();
	
	L.MIRAR();

	return 0;
}

char * GENERANOM()
{

	static char NOM[][20] = {"CARLOS","MELISA","CARLA","BENITO",
							"KURT","ARCHY","MARSHALL","NATHY",
							"GARCIA","GARMENDIA","BERTOLINI","JAIME",
							"VARELA","LAURIA","DORIO","ZAPATA",
							"OSORNO","GALINDEZ","ZAPATA","LAUTARO",
							"HERMAN","JORDAN","PEPE","NAPOLITANO",
							"LOLA","PACO","ANDRES","LUNA",
							"INES","MARTINA","IBARRA","MINERVA",
							"ANDRES","BENEDETO","SORIA","DINASTIA",
							"RODRIGO","SANTIAGO","MARCOS","JEREMIAS",} ;

	return NOM[rand()%40];

}
