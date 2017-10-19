
#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Pendiente por realizar
#include <conio.h>
#include <cstdio>
#include <sys\timeb.h> 
#define reservar_memoria_cola (NodoCola *)malloc(sizeof(NodoCola))
#define reservar_memoria_pila (NodoPila *)malloc(sizeof(NodoPila))

struct NodoPila{
	int dato;
	NodoPila * siguiente;
};

struct NodoCola{
	int dato;
	NodoCola * siguiente;
};

//**** DECLARACIONES DE LA PILA ****
void menuPila (NodoPila *&);
void menu_generarDatosPila(NodoPila *&);
void unMillonPila(NodoPila *&);
void dosMillonesPila(NodoPila *&);
void cincoMillonesPila(NodoPila *&);
void diezMillonesPila(NodoPila *&);
void veinteMillonesPila(NodoPila *&);
void insertarElementoPila(int, NodoPila *&);
void editarElementoPila(NodoPila *&, int);
void eliminarElementoPila(NodoPila *&);
void eliminarPila(NodoPila *&);
void listarElementosPila(NodoPila *);
void busarElementosPila(NodoPila *, int);
bool pilaVacia(NodoPila *);
int pedirDatosPila();
void insertarDatosPila(NodoPila *&, int );
void vaciarPila(NodoPila *&);

//**** DECLARACIONES DE LA COLA ****
void menuCola(NodoCola *&, NodoCola *&);
void generarDatosCola(NodoCola *&, NodoCola *&);
void insertarDatosCola(int, NodoCola *&, NodoCola *&);
void ordenarDatosCola(NodoCola *);
void imprimirDatosCola(NodoCola *);

int main(int argc, char *argv[]) {
	
	int opcion;
	NodoCola *inicioCola = NULL;
	NodoCola *finCola = NULL;
	NodoPila *inicioPila = NULL;
	srand(time(NULL));
	
	while(opcion!=0)
	{
		printf("******** M E N U ********\n");
		printf("*                       *\n");
		printf("*  1.Registro en Pila:  *\n");
		printf("*  2.Registro en Cola:  *\n");
		printf("*  0.Salir              *\n"); 
		printf("*                       *\n");
		printf("*************************\n");
		printf("\n Seleccione Opcion: ");
		scanf("%d",&opcion);
		
		
		switch(opcion)
		{
			case 1: 
			{
				
				system("CLS");
				
				menuPila(inicioPila);
				
				break;
			}          
			case 2: 
			{
				system("CLS");
				
				menuCola(inicioCola, finCola);
				
				break;
			}        
			
			default:
			{
				system("CLS");
				
				break;
			}          
		}
		
	}
	
	return 0;
}

//**** MENU PILA ****
void menuPila(NodoPila *&inicio){
	
	system("CLS");
	
	NodoPila * pila = NULL;
	int opcion, dato;
	
	do{
		printf("******** MENU PILAS ********\n");
		printf("*                          *\n");
		printf("*  1. Generar datos (pend) *\n");
		printf("*  2. Insertar Elementos   *\n");
		printf("*  3. Listar Elementos     *\n");
		printf("*  4. Eliminar Elementos   *\n");
		printf("*  5. Buscar Elementos     *\n");
		printf("*  6. Editar Elementos     *\n");
		printf("*  7. Eliminar Pila        *\n");
		printf("*  8. Salvar datos (pend)  *\n");
		printf("*  9. Ordenar datos (pend) *\n");
		printf("*  0. Regresar             *\n");
		printf("*                          *\n");
		printf("****************************\n");
		printf("\n Ingrese una opcion: ");
		scanf("%d", &opcion);
		
		switch(opcion){
		
			case 1:
			{	
				
				menu_generarDatosPila(inicio);
				break;
			}
			
			case 2: 
			{	
				
				dato = 0;
				
				while(dato != -1){
					dato = pedirDatosPila();
					
					if(dato != -1){
						insertarElementoPila(dato, pila);
					}
				}
				break;
			}
			
			case 3: 
			{	
				
				listarElementosPila(pila);
				break;
			}
			
			case 4: 
			{	
				system("CLS");
				eliminarElementoPila(pila);
				break;
			}	
			case 5: 
			{	
				
				dato = pedirDatosPila();
				busarElementosPila(pila, dato);
				break;
			}
			
			case 6: 
			{	
				
				listarElementosPila(pila);
				dato = pedirDatosPila();
				editarElementoPila(pila, dato);
				break;
			}
			
			case 7: 
			{	
				
				eliminarPila(pila);
				break;
			}
			
			case 8: 
			{	
				system("CLS");
				//salvarDato();
				break;
			}
			
			case 9: 
			{	
				system("CLS");
				//ordenarDato();
				break;
			}
			
			default:
			{	
				system("CLS");
				
				break;
			}
		}
	}while(opcion != 0);
}

//**** FUNCIONES PILA ****
void menu_generarDatosPila(NodoPila *&inicio){
	
	system("CLS");
	
	//NodoPila *inicio = NULL;

	int opcion;
	
	
	while(opcion!=0)
	{
		printf("******** GENERAR DATOS ********\n");
		printf("*                             *\n");
		printf("*   1.Un millon de datos      *\n");
		printf("*   2.Dos millones de datos   *\n");
		printf("*   3.Cinco millones de datos *\n"); 
		printf("*   4.Diez millones de datos  *\n"); 
		printf("*   0.Regresar                *\n"); 
		printf("*                             *\n");
		printf("*******************************\n");
		printf("\n Seleccione Opcion: ");
		scanf("%d",&opcion);
		
		
		switch(opcion)
		{
			case 1: 
			{
				
				system("CLS");
				
				unMillonPila(inicio);
				
				break;
			}          
			case 2: 
			{
				system("CLS");
				
				dosMillonesPila(inicio);
				
				break;
			}
			
			case 3: 
			{
				system("CLS");
				
				cincoMillonesPila(inicio);
				
				break;
			}
			case 4: 
			{
				system("CLS");
				
				diezMillonesPila(inicio);
				
				break;
			}
			
			case 5: 
			{
				system("CLS");
				
				veinteMillonesPila(inicio);
				
				break;
			}
			
			default:
			{
				system("CLS");
				
				break;
			}          
		}
	}
}

/*void unMillon(Nodo *&inicio, Nodo *&fin){
	
	int cantDatos = 1000000;
	
	generarDatps(inicio, fin, cantDatos);
}*/

void unMillonPila(NodoPila *&inicio){
	
	int cantDatos = 1000000, i, aleatorio;
	
	srand(time(NULL));
	
	for(i = 1; i <= cantDatos; i++){
		aleatorio = (rand() % (1999999 + 1)- 1000000);
		insertarDatosPila(inicio,aleatorio);
	}
}

void dosMillonesPila(NodoPila *&inicio){
	
	int cantDatos = 2000000, i, aleatorio;
	
	srand(time(NULL));
	
	for(i = 1; i <= cantDatos; i++){
		aleatorio = (rand() % (1999999 + 1)- 1000000);
		insertarDatosPila(inicio,aleatorio);
	}
}

void cincoMillonesPila(NodoPila *&inicio){
	
	int cantDatos = 5000000, i, aleatorio;
	
	srand(time(NULL));
	
	for(i = 1; i <= cantDatos; i++){
		aleatorio = (rand() % (1999999 + 1)- 1000000);
		insertarDatosPila(inicio,aleatorio);
	}
}

void diezMillonesPila(NodoPila *&inicio){
	
	int cantDatos = 10000000, i, aleatorio;
	
	srand(time(NULL));
	
	for(i = 1; i <= cantDatos; i++){
		aleatorio = (rand() % (1999999 + 1)- 1000000);
		insertarDatosPila(inicio,aleatorio);
	}
}

void veinteMillonesPila(NodoPila *&inicio){
	
	int cantDatos = 20000000, i, aleatorio;

	srand(time(NULL));
	
	for(i = 1; i <= cantDatos; i++){
		aleatorio = (rand() % (1999999 + 1)- 1000000);
		insertarDatosPila(inicio,aleatorio);
	}
}
void insertarElementoPila(int n, NodoPila *&pilita){
	
	NodoPila * nuevo_nodo = reservar_memoria_pila;
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = pilita;
	pilita = nuevo_nodo;
	
	printf("Dato %d insertado correctamente\n", n);
}

void editarElementoPila(NodoPila *&pilita, int dato){
		
	NodoPila *aux = pilita;
	int contador = 0, nuevo_dato;
	
	if(pilaVacia(pilita)){
		
		printf("Pila vacia\n");
		
	}else{
		while(aux != NULL){
			if(aux->dato == dato){
				
				nuevo_dato = pedirDatosPila();
				contador += 1;
				aux->dato = nuevo_dato;
				break;
			}
			aux = aux->siguiente;
		}
		
		if(contador == 0){
			
			printf(":( lo siento no encontre el dato\n");
			
		}else{
			
			printf("iuuuuuju el dato fue editado\n");
			listarElementosPila(pilita);
		}
	}
}

void eliminarElementoPila(NodoPila *&pilita){
	
	NodoPila *aux = pilita;
	
	if(pilaVacia(pilita)){
		
		printf("Pila vacia\n");
		
	}else{
		
		pilita = aux->siguiente;
		free(aux);
	}
}

void eliminarPila(NodoPila *&pilita){
	
	if(pilaVacia(pilita)){
		
		printf("Pila vacia\n");
		
	}else{
		while(pilita != NULL){
			
			NodoPila *aux = pilita;
			pilita = aux->siguiente;
			free(aux);
		}
	}
}

void listarElementosPila(NodoPila *pilita){
	
	NodoPila *aux = pilita;
	
	if(pilita == NULL){
		
		printf("La pila esta vacia\n");
		
	}else{
		while(aux != NULL){
			
			printf("%d ", aux->dato);
			aux = aux->siguiente;
		}
		printf("\n");
	}
}

void busarElementosPila(NodoPila *pilita, int dato){
	
	NodoPila *aux = pilita;
	int contador = 0;
	
	if(pilaVacia(pilita)){
		
		printf("Pila vacia\n");
		
	}else{
		while(aux != NULL){
			if(aux->dato == dato){
				
				contador += 1;
				break;
			}
			aux = aux->siguiente;
		}
		if(contador == 0){
			
			printf(":( lo siento no encontre el dato\n");
			
		}else{
			
			printf("iuuuuuju el dato fue encontrado\n");
		}
	}
}

bool pilaVacia(NodoPila *pilita){
	
	return (pilita == NULL) ? true:false;
}

int pedirDatosPila(){
	
	int dato;
	
	printf("Ingrese un dato\n");
	scanf("%d", &dato);
	return dato;
}

void insertarDatosPila(NodoPila *&pilita, int n){
	
	NodoPila * nuevo_nodo = reservar_memoria_pila;
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = pilita;
	pilita = nuevo_nodo;
	
}

void vaciarPila(NodoPila *&inicio){
	
	while(inicio != NULL){
		
		NodoPila *aux = inicio;
		inicio = aux->siguiente;
		free(aux);
	}
	
}

//**** MENU COLA ****
void menuCola(NodoCola *&inicio, NodoCola *&fin){
	
	//NodoCola *inicio = NULL;
	//NodoCola *fin = NULL;
	int opcion;
	
	do{
		printf("********* MENU COLA *********\n");
		printf("*                           *\n");
		printf("*    1. Generar Datos       *\n");
		printf("*    2. Cargar Datos(pend)  *\n");
		printf("*    3. Imprimir Datos      *\n");
		printf("*    4. Eliminar(pend)      *\n");
		printf("*    5. Buscar (pend)       *\n");
		printf("*    6. Editar(pend)        *\n");
		printf("*    7. Eliminar cola(pend) *\n");
		printf("*    8. Salvar Datos(pend)  *\n");
		printf("*    9. Ordenar Datos       *\n");
		printf("*    0. Regresar            *\n");
		printf("*                           *\n");
		printf("*****************************\n");
		printf("\n Ingrese una opcion: ");
		scanf("%d", &opcion);
		
		switch(opcion){

			case 1:
			{
				generarDatosCola(inicio, fin);
				break;
			}
			
			case 2:
			{
				//cargarDatos();
				break;
			}
			
			case 3:
			{
				//imprimirDatosCola(inicio);
				break;
			}
			
			case 4:
			{
				//eliminar();
				break;
			}
			
			case 5:
			{
				//buscar();
				break;
			}
				
			case 6:
			{
				//editar();
				break;
			}
				
			case 7:
			{
				//eliminarCola();
				break;
			}
				
			case 8:
			{
				//salvarDatos();
				break;
			}
				
			case 9:
			{
				//ordenarDatos(inicio);
				break;
			}
		
			default:
			{	
				system("CLS");
				
				break;
			}
		}
	}while(opcion != 0);
}

//**** FUNCIONES COLA ****
void generarDatosCola(NodoCola *&inicio, NodoCola *&fin){
	
	int cantDatos = 1000000, i, aleatorio;
	
	srand(time(NULL));
	
	for(i = 1; i <= cantDatos; i++){
		aleatorio = (rand() % (1999999 + 1)- 1000000);
		insertarDatosCola(aleatorio, inicio, fin);
	}
}

void insertarDatosCola(int n, NodoCola *&inicio, NodoCola *&fin){
	
	NodoCola * nuevo_nodo = reservar_memoria_cola;
	nuevo_nodo -> dato = n;
	nuevo_nodo -> siguiente = NULL;
	
	if(inicio == NULL){
		inicio = nuevo_nodo;
	}else{
		fin -> siguiente = nuevo_nodo;
	}
	
	fin = nuevo_nodo;
}

/*Este ordenar datos tiene la forma burbuja*/
void ordenarDatosCola(NodoCola *inicio){
	int aux;
	
	NodoCola * x = inicio;
	NodoCola * y = NULL;
	
	if(inicio == NULL){
		printf("Me la gane suave\n");
	}else{
		while(x != NULL){
			y = x -> siguiente;
			while(y != NULL){
				if(x -> dato > y -> dato){
					aux = x -> dato;
					x -> dato = y -> dato;
					y -> dato = aux;
				}
				y = y -> siguiente;
			}
			x = x -> siguiente;
		}
	}
}

void imprimirDatosCola(NodoCola *&inicio){
	
	NodoCola * aux = inicio;
	
	if(inicio == NULL){
		printf("Esta vacio\n");
	}else{
		while(aux != NULL){
			printf("%d ", aux -> dato);
			aux = aux -> siguiente;
		}
	}
}
