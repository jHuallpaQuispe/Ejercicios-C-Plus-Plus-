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

/*que retorna el puntero al nodo del proveedor que comercializa el producto con el precio más bajo.*/
PROVEEDOR * PRODUCTO::MEJOR_PROVEEDOR(){
	
	PROVEEDOR * MIN, * P;
	P = PRIMER_PROVEEDOR;
	MIN = P;
	while(P){
		
		if(P->PRECIO < MIN->PRECIO){
			MIN = P;
		}
		P= P->SIG;
	}
	return MIN;
	
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
		MIN = PRO->MEJOR_PROVEEDOR();
		printf("\n\n\t\t\tEL MENOR PRECIO ES DE %s",MIN->NOM);
		PRO = PRO->SIG;
	}	
}

/*que muestra en pantalla el proveedor que más productos comercializa al mejor precio.*/
void SUPERMERCADO::MEJOR_PROVEEDOR(  ){
	
	PRODUCTO * PRO ,* PRO2;
	PROVEEDOR * PROVE, * PROVE2;
	int cont, contMax = 0;
	char nomMax[20];
	
	
	PRO = INICIO;
	while(PRO){
		
		cont = 0;
		PRO2 = INICIO;
		PROVE = PRO->MEJOR_PROVEEDOR(); // guardamos al mejor precio
		while(PRO2){
			/*BUSCAMOS EN LA LISTA SI SE REPITE EL MISMO PROVEEDOR*/
			PROVE2 = PRO2->MEJOR_PROVEEDOR();
			
			if(!strcmpi(PROVE->NOM,PROVE2->NOM))
				cont++;
			
			PRO2 = PRO2->SIG;		
		}
		
		/*COMPARAMOS SI ES EL MAXIMO*/
		if(cont > contMax){
			contMax = cont;
			strcpy(nomMax,PROVE->NOM);
		}
		PRO = PRO->SIG;
	}
	
	printf("\n\n\n\t\tEL MEJOR PROVEEDOR EN VENDER A MENOR PRECIO ES---->	%s",nomMax);
	
}

/*que recibe el nombre de un producto, el nombre de un proveedor y el nuevo precio del producto comercializado para editarlo*/
void SUPERMERCADO::EDITAR_PRECIO( char * Producto, char * Proveedor, float nuevoPrecio ){
	
	
	PRODUCTO * PRO;
	PROVEEDOR * PROVEE;
	PRO = INICIO;
	
	while(PRO){	
		if(!strcmpi(PRO->DESCRIPCION,Producto)){
			/*ENCONTRAMOS EL PRODUCTO*/
			PROVEE = PRO->PRIMER_PROVEEDOR;
			while(PROVEE){
				
				if(!strcmpi(PROVEE->NOM,Proveedor)){
					/*ENCONTRAMOS AL PROVEEDOR*/
					PROVEE->PRECIO = nuevoPrecio;
				}
				
				PROVEE = PROVEE->SIG;
			}
		}
		PRO = PRO->SIG;
	}
}
int main(){
	SUPERMERCADO S;
	
	S.MIRAR();	
	S.MEJOR_PROVEEDOR();
	
	S.EDITAR_PRECIO("YOGUR","VALERIA",7.0);
	S.MIRAR();
	printf("\n\n\n\n");
	return 0;
}