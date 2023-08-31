#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

class Sueldo{
    public:
        char nombre[20];
        int sueldo;
        Sueldo * sig;
        Sueldo (char *);
};

Sueldo::Sueldo(char * nom)
{
    strcpy(nombre, nom);
    sueldo = 5000+rand()%2000;
    sig = NULL;
}

class Jugador{
    public:
        char nombre[20];
        Jugador * sig;
        Jugador (char *);
};

Jugador::Jugador(char * nom)
{
    strcpy(nombre, nom);
    sig = NULL;
}

class Equipo{
    public:
        char nombre[20];
        Equipo * sig;
        Jugador * primerJugador;
        Equipo(char *);
};

Equipo::Equipo(char * nom)
{
    strcpy(nombre, nom);
    sig = NULL;
    primerJugador = NULL;
}


class Campeonato{
    private:
        Equipo * inicio_equipos;
        Sueldo * inicio_sueldos;
    public:
        Campeonato ();
        Equipo * buscarEquipo(char *);
        void mirar();
        ~Campeonato();
        Equipo * retornarEquipo();
        Sueldo * retornarSueldo();
        
        int buscarSueldo(char *);
};

Campeonato::Campeonato()
{
    inicio_equipos=NULL;
    inicio_sueldos=NULL;

    static char lista_jugadores[][20] = {"MARADONA","RONALDO","MESSI",
						  "PELE","MESSI","LABRUNA",
						  "ORTEGA","RIQUELME","ROMA","CARRIZO",
						  "LORENZO","BOBBY MOORE","RONALDINHO","ARMANI",
						  "TARANTINI","RATTIN","ROSSI","ONEGA",
						  "ARTIME","VARACKA","GALLARDO","TEVEZ",
						  "MORETE","ERICO","LABRUNA","MORENO",
						  "PEDERNERA","LOUSTEAU","CAVENAGHI","NAVARRO",
						  "PAVONI","VERON","MESSI","RONALDO",
						  "PERFUMO","MATOSAS","PELE",
						  "CUBILLA","SANTORO","MALBERNAT","BECKENBAUER",
						  "EUSEBIO","PASTORIZA","JAIRZINHO","ROJAS",
						  "MADURGA","PIANETTI","ANDRADA","MARIN",
						  "ROMERO","ALONSO","FRANCESCOLI","DOMINGUEZ",
						  "MAYADA","MORA","MASCHERANO","KRANEVITER",
						  "SOLARI","MATURANA","BOBY MOORE",
						  "HIGUITA","BASILE","FRANCESCOLI",
						  "SARNARI","BILARDO","BATISTUTA","VALENTIM",
						  "CRISTIANO","ZAMORANO","SALAS","ARDILES",
						  "KEMPES","ZANABRIA","OLGUIN","PALACIOS",
						  "MESSI","VERON","FIN"};
    static char lista_equipos[][20] = {"BARCELONA","RIVER","BOCA","JUVENTUS",
						  		 "MILAN","REAL MADRID","DYNAMO",
								 "BOTAFOGO","COLO COLO","SAN LORENZO",
								 "RACING","INDEPENDIENTE", "FIN"};

    int I=0,J;

    Equipo * nuevoEquipo;

    while (strcmp("FIN",lista_equipos[I]))
    {
        nuevoEquipo = new Equipo(lista_equipos[I]);
        nuevoEquipo->sig = inicio_equipos;
        inicio_equipos = nuevoEquipo;
        I++;
    }

    Jugador * nuevoJugador;
    Sueldo * nuevoSueldo;
    Equipo * aux;

    I = 0;

    while (strcmp("FIN",lista_jugadores[I]))
    {
        nuevoJugador = new Jugador(lista_jugadores[I]);
        nuevoSueldo = new Sueldo(lista_jugadores[I]);

        nuevoSueldo->sig = inicio_sueldos;
        inicio_sueldos = nuevoSueldo;
        J = rand()%11;
        aux = buscarEquipo(lista_equipos[J]);
        nuevoJugador->sig = aux->primerJugador;
        aux->primerJugador = nuevoJugador;

        I++;
    }

}

Equipo * Campeonato::buscarEquipo(char * equi)
{
    Equipo * e;
    e = inicio_equipos;

    while(e)
    {
        if(!strcmp(e->nombre, equi))
            return e;
        e=e->sig;
    }
    return NULL;
}

Equipo * Campeonato::retornarEquipo(){
	return inicio_equipos;
	
}
Sueldo * Campeonato::retornarSueldo(){
	
	return inicio_sueldos;
}

int Campeonato::buscarSueldo (char * buscar){
	
	Sueldo * sueldo = inicio_sueldos;
	while(sueldo){
		
		if(!strcmp(sueldo->nombre,buscar))
			return sueldo->sueldo;
		sueldo = sueldo->sig;
	}
	return 0;
}
Campeonato::~Campeonato()
{
	//Liberar la lista simple de sueldos
	Sueldo * sueldoAEliminar;
	while(inicio_sueldos){
		
		sueldoAEliminar = inicio_sueldos;
		inicio_sueldos = sueldoAEliminar->sig;
		delete sueldoAEliminar;
	}
	
	//Liberar la Guirnalda 
	Equipo * equipoEliminar;
	Jugador * jugadorEliminar;
	while(inicio_equipos)
	{
		equipoEliminar = inicio_equipos;
		while(equipoEliminar->primerJugador){
			jugadorEliminar = equipoEliminar->primerJugador;
			equipoEliminar->primerJugador = jugadorEliminar->sig;
			delete jugadorEliminar;
		}
		
		equipoEliminar = inicio_equipos;
		inicio_equipos = equipoEliminar->sig;
		delete equipoEliminar;
		
	}
	
}

void Campeonato::mirar()
{
    Jugador * j;
    Equipo * e;
    Sueldo * s;

    s=inicio_sueldos;
    printf("\n\n\t\tSUELDOS:");
    while(s)
    {
        printf("\n\t\t\t%s  %d", s->nombre, s->sueldo);
        s=s->sig;
    }

    e = inicio_equipos;
    printf("\n\n\t\tEQUIPOS:");
    while(e)
    {
        printf("\n\n\t\t\t%s", e->nombre);
        j = e->primerJugador;
        while(j)
        {
           printf("\n\t\t\t\t%s", j->nombre);
           j=j->sig;
        }
        e=e->sig;
    }
}

void MILLONARIO( Campeonato & );

int main() {
    Campeonato c;

    c.mirar();

    MILLONARIO( c ); //muestre en pantalla cual es el equipo que más gasta mensualmente en sueldos de jugadores y cuál es ese monto
    delete (&c);
    
    c.mirar();

    printf("\n\n");

}


void MILLONARIO(Campeonato & Cam){
	
	Equipo * equi;
	Jugador * juga;
	
	int acu , MAX = 0;
	char NOMMAX[20];
	equi = Cam.retornarEquipo();
	while(equi){
		
		acu = 0;
		juga = equi->primerJugador;
		while(juga){
			acu += Cam.buscarSueldo(juga->nombre);	
			juga = juga->sig;
		}
		printf("\n\n\n\t\t----> %s",equi->nombre);
		printf("\n\n\t\tY GASTA -> %d",acu);
		if(acu > MAX){
			MAX = acu;
			strcpy(NOMMAX,equi->nombre);
		}
		
		equi = equi->sig;
	}
	
	printf("\n\n\n\t\tEL EQUIPO QUE MAS GASTA EN SUELDO DE JUGADORES ES----> %s",NOMMAX);
	printf("\n\n\t\tY GASTA -> %d",MAX);
	
}