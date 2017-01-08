#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#define MAX_CARAC 30

#include "MemoryManager.h" 

// Estructura de tipo tficha
typedef struct
{
char *nombre;
float nota;
}tficha;

// Declaración de funciones, siempre debajo de struct si se va a usar el tipo de este
tficha leeFicha();
void MuestraFicha(tficha ficha);
void crearArray();
void tiendas();
int menu();

int main()
{
	menu();
	switch (menu)
	{
	case 1: 
		crearArray();
		break;
	case 2: 
		tiendas();
		break;
	default:
		break;
	}
}

void crearArray()
{
  int numElementos,i;
  tficha *fichas; // Con * porque es un array dinámico

 do
  {
  printf("Introduce el numero de alumnos:\t");
  scanf("%d",&numElementos);
  if(numElementos<=0) // Si el número de alumnos es menor o igual a 0 dará error y se volverá a pedir el número
  {
    printf("Vuelve a introducir el numero.\n");
	system("pause");
  }
  system("cls"); // Limpiar pantalla
  }while(numElementos<=0); // Se ejecutará el "do" hasta que el número introducido sea mayor que 0, si se introduce uno mayor a 0 solo se ejecutará una vez

  fichas=(tficha *)malloc(numElementos*(sizeof(tficha))); // Array dinámico fichas
  
 for (i = 0; i < numElementos; i++)
  {
    fichas[i]=leeFicha(); // Dar valores a las fichas, una ficha por alumno
  }

 system("cls"); //Limpia pantalla

 for (i = 0; i < numElementos; i++)
 {
	printf("Alumno %d: \n",i+1);
	MuestraFicha(fichas[i]); // Imprime por pantalla la ficha de cada alumno
 }
 
 // Liberar memoria
 for(i=0;i<numElementos;i++)
 {
	free(fichas[i].nombre); // Libera memoria de nombre de la estructura
 }
 free(fichas); // Libera memoria de la estructura entera
 printf("\n\n"); // Saltos de linea para que quede bonito
 MemoryManager_DumpMemoryLeaks(); // Comprueba que la memoria ha sido liberada

 // Fin del programa
 system("pause");
}

tficha leeFicha() // Tipo tficha para poder devolver la estructura después
{
	char nombreTam[100]; // Crear array de 100 para averiguar longitud del nombre
	int tamNombre;      // Variable donde guardar longitud del nombre
	tficha ficha;       // Creación estructura tipo tficha con el nombre ficha (incluye nombre y nota)   // No necesita * porque ficha.nombre ya tiene un * (Mirar estructura tficha)

	// ######### Nombre #########
	printf("Introduce el nombre:\t");
	scanf("%s",nombreTam); // Escanea el nombre del alumno, tambien se podría haber usado fgets
	tamNombre=strlen(nombreTam); // Asigna longitud de nombreTam a tamNombre
	ficha.nombre=(char *)malloc(tamNombre*sizeof(char)+1); // Array con tamaño de tamNombre, necesario el +1 por el '\0'
	strcpy(ficha.nombre,nombreTam); // Copia el nombre introducido al nuevo array dinámico

	// ######### Nota #########
	printf("\nIntroduce la nota de %s:\t",ficha.nombre);
	scanf("%f",&ficha.nota); // Lee el numero introducido por el usuario de tipo float y lo guarda en la estructura
	printf("\n"); // Salto de linea para dejarlo más bonito
	return ficha; // Devuelve la estructura con tipo tficha	
}

void MuestraFicha(tficha ficha) // Tipo void porque no necesita devolver (return) nada
{
	printf("\n\t%s \n",ficha.nombre); // Imprime en pantalla el nombre correspondiente a cada alumno según el "for" usado en la función crearArray
	printf("\tNota: %f\n\n",ficha.nota); // Imprime la nota del alumno
}

void tiendas()
{


}

int menu()
{
	int op;
	printf("1. Alumnos\n2. Tiendas");
	scanf("%d",&op);
	return op;
}