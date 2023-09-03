#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std ;


class PROVEEDOR {	
	public:  
		char NOM[20]; 
		float PRECIO; 
		PROVEEDOR * SIG;
		PROVEEDOR(char *);
};
PROVEEDOR::PROVEEDOR(char * NOMBRE){
	strcpy(NOM,NOMBRE);
	PRECIO = 6+rand()%18;
	SIG = NULL;
}

class PRODUCTO {	
	public:  
		char DESCRIPCION [20];
		PRODUCTO * SIG; 
		PROVEEDOR * PRIMER_PROVEEDOR;
		PROVEEDOR * MEJOR_PROVEEDOR(  ); 
		PRODUCTO(char *);
};

PRODUCTO::PRODUCTO(char * NOMBRE){
	strcpy(DESCRIPCION,NOMBRE);
	SIG = NULL;
	PRIMER_PROVEEDOR = NULL;
}
class SUPERMERCADO { 
	private: 
		PRODUCTO * INICIO;
	public: 
		void MEJOR_PROVEEDOR(  );  
		void EDITAR_PRECIO(   char   *, char  * , float); 
		SUPERMERCADO();
		PRODUCTO * buscarProducto(char *);
		void MIRAR();
		
};

SUPERMERCADO::SUPERMERCADO(){
	INICIO = NULL;
	
	static char NOMDESCRIPCIONES[][20]={"Leche", "Pan", "Arroz", "Azucar", "Cafe",
    									"Harina","Aceite","Sal","Mantequilla","Yogur","FIN"};
																			
    static char NOMPROVEEDORES[][20]={	"Juan","Maria","Luis","Ana","Carlos",
    									"Pedro","Sofia","Fernando","Carmen",
    									"Andres","Paola","Javier","Alejandro","Gabriela",
    									"Roberto","Isabel","Valentina","Rafael","Natalia",
    									"Francisco","Patricia","Guillermo","Adriana",
    									"Carolina","Martin","Camila","Arturo","Beatriz",
    									"Gonzalo","Lucia","Hugo","Renata","Manuel",
    									"Diana","Oscar","Ines","Victor","Monica",
										"Pablo","Valeria","Federico","Elena","Hector",
    									"Marina","Raúl","Gabriela","Ramiro","Catalina",
    									"Ricardo","Mariana","Emilio","Carla","Santiago",
    									"Alicia","Matias","Laura","Maximiliano","Victoria",
    									"Sebastian","Daniela","Gustavo","Brenda","Andres",
    									"Constanza","Leandro","Camila","Martin","Agustina",
    									"Jorge","Lorena","Cecilia","Julian",
    									"Isabella","Eduardo","Luisa","Adrian","Melisa",
    									"Bruno","Pamela","Lucas","Natalia","Facundo","FIN"};									
	 
	int I = 0, J;
	
	
	PRODUCTO * nuevoProduc;
	
	while( strcmp("FIN",NOMDESCRIPCIONES[I]) ){
		
		nuevoProduc = new PRODUCTO(NOMDESCRIPCIONES[I]);
		nuevoProduc->SIG = INICIO;
		INICIO = nuevoProduc;
		I++;
	}
	
	PROVEEDOR * nuevoProvee;
	PRODUCTO * aux;
	
	I = 0;
	int X; //estatico
	while(strcmp("FIN",NOMDESCRIPCIONES[I])){ 
		
		int W = 0;	
		for(J = 0; J < 3; J++){
			X = W+rand()%79;
			nuevoProvee = new PROVEEDOR(NOMPROVEEDORES[X]);
			aux = buscarProducto(NOMDESCRIPCIONES[I]);
			nuevoProvee->SIG = aux->PRIMER_PROVEEDOR;
			aux->PRIMER_PROVEEDOR = nuevoProvee;
			W++;
		}
		I++;
	}
}

PRODUCTO * SUPERMERCADO::buscarProducto(char * Buscar){
	
	PRODUCTO * P;
	
	P = INICIO;
	
	while(P){
		
		if(!strcmpi(Buscar,P->DESCRIPCION))
			return P;
		P = P->SIG;
	}
	return NULL;

}

void SUPERMERCADO::MIRAR(){
	PRODUCTO * PRO;
	PROVEEDOR * PROVE, *MIN;
	
	PRO = INICIO;
	
	while(PRO){
		
		printf("\n\n\t\t\t%s",PRO->DESCRIPCION);
		PROVE = PRO->PRIMER_PROVEEDOR;
		while(PROVE){
			
			printf("\n\t\t\t\t%-20s\t\t %0.2f",PROVE->NOM, PROVE->PRECIO);
			
			PROVE = PROVE->SIG;
		}
		PRO = PRO->SIG;
	}	
}


int main(){
	SUPERMERCADO S;
	
	S.MIRAR();	
	printf("\n\n\n\n");
	return 0;
}