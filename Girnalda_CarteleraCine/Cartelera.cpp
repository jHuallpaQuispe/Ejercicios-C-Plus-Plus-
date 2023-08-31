
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std ;

class PELICULA {
	public:
		char NOM[20];
		char DIRECTOR[20];
		float VALORACION;
		PELICULA * SIG;
		PELICULA(char *,char *);
};

PELICULA::PELICULA(char * NOMP, char * NOMDIREC){
	
	strcpy(NOM,NOMP);
	strcpy(DIRECTOR,NOMDIREC);
	VALORACION = 5 + rand()%6;
	SIG = NULL;
}
class GENERO{
	public:
		char NOM [20];
		GENERO * SIG;
		PELICULA * PRIMER_PELICULA;
		float PROMEDIO_VALORACION(  );
		GENERO(char *);
};
GENERO::GENERO(char * NOMBRE){
	strcpy(NOM,NOMBRE);
	SIG = NULL;
	PRIMER_PELICULA = NULL;
}


class CARTELERA {
	private:
		GENERO * INICIO;
	public:
		void MEJOR_GENERO( );
		void MOSTRAR_PELICULA_DE(   char   * );
		CARTELERA();
		GENERO * buscarGenero(char *);
		void MIRAR();
};

CARTELERA:: CARTELERA(){	
	
	INICIO = NULL;
	static char NOMGENEROS[][20] = {"Terror","Accion","Aventura","Comedia","Dibujos","Anime","FIN"};
	
	static char NOMDIREC[][20] = {"MAKISON","JORGE","IRESNE",
						"IRESNE","ANA","PAOLA",
						"ELENA","PALOMINO","PAKISTON",
						"MICHAEL","MICHAEL","BRAYAN",
						"TOMAS","PALOMINO","MARIO CERVANTES",
						"IROSHIMA","HOMERO","PALOMINO","FIN"};
	static char NOMPELI[][20] = {"IT","LA LLORONA","EL ARO",
						"RAPIDOS Y FURIOSOS","ANACONDA","GRIT",
						"AL ESPACIO","YUMANYI","DINOSAURIOS",
						"LOS 3 CHIFLADOS","PAUL","TED",
						"TOM Y JERRY","PATO DONAL","MARIO BROS",
						"ONE PIECE","NARUTO","KIMETSU NO YAIBA","FIN"};
						
	int I = 0, J ;
	
	GENERO * generoNuevo;
	
	while(strcmp("FIN",NOMGENEROS[I]))
	{
		generoNuevo = new GENERO(NOMGENEROS[I]);
		generoNuevo->SIG = INICIO;
		INICIO = generoNuevo;
		I++;
	}
	
	PELICULA * nuevoPeli;
	GENERO * aux;
	
	I = 0;
	/*PARA HACERLO AL AZAR CADA PELICULA*/
/*	while(strcmp("FIN",NOMPELI[I]))
	{
		nuevoPeli = new PELICULA(NOMPELI[I],NOMDIREC[I]);
		//J = rand()%5; // esto es al azar agregar a un jugador a un equipo
		//aux = buscarGenero(NOMGENEROS[J]);
		nuevoPeli->SIG = aux->PRIMER_PELICULA;
		aux->PRIMER_PELICULA = nuevoPeli;
		I++;
	}*/
	
	/*PARA HACERLO EN ORDEN PERO EN FORMA DE PILA*/
	int X = 0; //ESTATICO
	while (strcmp("FIN",NOMGENEROS[I])){
		
		for(J = 0; J < 3; J++){
			nuevoPeli = new PELICULA(NOMPELI[X],NOMDIREC[X]);
			aux = buscarGenero(NOMGENEROS[I]);
			nuevoPeli->SIG = aux->PRIMER_PELICULA;
			aux->PRIMER_PELICULA = nuevoPeli;
			X++;
		}
		I++;
	}
						
}

GENERO * CARTELERA::buscarGenero(char * gen){
	GENERO * G;
	G = INICIO;
	while(G){
		
		if( !strcmpi(G->NOM, gen) )
			return G;
			
		G = G->SIG;
	}
	return NULL;
}


void CARTELERA::MIRAR(){
	
	GENERO * G;
	PELICULA * P;
	G = INICIO;
	cout <<"\n\n\n\t\tGENEROS:";
	while(G){
		
		printf("\n\n\t\t\t%s", G->NOM);
		
		P = G->PRIMER_PELICULA;
		while(P){
			
			printf("\n\t\t\t\t%-20s\t\t\t%-10s\t\t %f",P->NOM, P->DIRECTOR, P->VALORACION);
			P = P->SIG;
		}
		G = G->SIG;
	}
}

int main(){
	CARTELERA C;
	C.MIRAR();
	
	printf("\n\n\n");
	return 0;
}
