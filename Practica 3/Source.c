#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX9 9
#define MAX100 100
#define numerosIntroducir2
#define MAX 10
#define SALIR 7

int potencia(int,int);
int factorial(int);
int euros(int);
int algoritmo(int);
int busqueda(int);
int menu();
int introducir_array(int Array[]);
void visualizar_array(int Array[], int n_eltos);
void ordenar_insercion (int A[], int num);
int busqueda_binaria(int x, int valores[], int num);
int introducir_valor(int, int [], int);

int main()
{
	int Array[MAX], n_eltos=0, x, pos, resu, resultadoMenu;
	//int resultadoBusqueda;
	//int numerosIntroducir, resultadoAlgoritmo;
	int numeroEuros, resultadoEuros;
	int numeroFactorial, resultadoFactorial;
	int basePotencia, exponentePotencia,resultadoPotencia;
	int opcion;
  
  
  do
  {
  printf("0. Salir\n1. Potenica\n2. Factorial\n3. Euros\n4. Ordenar mediante algoritmo de insercion\n5. Busqueda binaria\n6. Menu \n");
  printf("Selecciona ejercicio:\t");
  scanf("%d",&opcion);
  switch (opcion)
  {
  
  case 1:
    system("cls");
    printf("Introduzca la base: \t");
    scanf("%d",&basePotencia);
    printf("Introduzca el exponente: \t");
    scanf("%d",&exponentePotencia);
    resultadoPotencia=potencia(basePotencia,exponentePotencia);
    printf("El resultado es:\t %d\n",resultadoPotencia);
    system("pause");
   break;
  case 2:
    do
    {
      system("cls");
      printf("Introduce numero:\t");
      scanf("%d",&numeroFactorial);
      if (numeroFactorial<0)
      {
        printf("Introduce un numero mayor que 0\n");
        system("pause");
      }
    }while(numeroFactorial<0);
    resultadoFactorial=factorial(numeroFactorial);
    printf("El resultado es:\t %d\n",resultadoFactorial);
    system("pause");
    break;
  case 3:
    system("cls");
	do
	{
    printf("Introduce los euros:\t");
    scanf("%d",&numeroEuros);
	if (numeroEuros<=0)
	{
		printf ("ERROR: La cantidad debe ser mayor que cero. \n");
		system("pause");
		system("cls");
	}
	}while(numeroEuros<=0);
    resultadoEuros=euros(numeroEuros);
    break;
  case 4:
	  /*
	  system("cls");
	  printf("Introduce cuantos numeros quiere introducir: \t");
	  scanf("%d",&numerosIntroducir);
	  resultadoAlgoritmo=algoritmo(numerosIntroducir);
	  printf("%d",resultadoAlgoritmo);
	  
	  */
	  break;
  case 5:
	  /*
	  system("cls");
	  printf("Introduce cuantos numeros quiere introducir: \t");
	  scanf("%d",&numerosIntroducir);
	  resultadoBusqueda=algoritmo(numerosIntroducir);
	  printf("%d",resultadoBusqueda);
	  */

	  break;
  case 6:
	  system("cls");
	  do
	  {
	  resultadoMenu=menu(Array);
	  switch (resultadoMenu)
	  {
	  case 1:
		  n_eltos = introducir_array(Array);
		  break;

	  case 2:
		  visualizar_array(Array, n_eltos);
		  system("pause");
		  break;

	  case 3:
		  ordenar_insercion(Array, n_eltos);
		  break;

	  case 4:
		  printf("Introduce el valor a buscar:\t");
		  scanf("%d",&x);
		  pos = busqueda_binaria(x, Array, n_eltos);
		  if (pos == -1)
		  {
			  printf("Fracaso\n");
		  }
		  else
		  {
			  printf("La posicion del valor buscado es:\t %d",pos);
		  }
		  system("pause");
		  break;

	  case 5:
		  printf("Introduce el valor a añadir:\t");
		  scanf("%d",&x);
		  resu=introducir_valor(x, Array, n_eltos);
		  if (resu==-1)
		  {
			  printf("El array ya esta lleno");
		  }
		  else
		  {
			  printf("El valor se ha añadido con exito");
			  n_eltos++;
		  }
		  system("pause");
		  break;

	  case 6:
		  printf("Introduce numero a buscar en el array:\t");
		  scanf("%d",&x);
		  resu=busqueda_binaria(x, Array, n_eltos);
		  if (resu==1)
		  {
			  printf("No se encuentra el elemento\n");
			  system("pause");
		  }
		  else
		  {
			  printf("Introduce el nuevo valor:\t");
			  scanf("%d",&x);
			  introducir_valor(x, Array, n_eltos);
		  }
		  break;

	  case 7:
		  printf("\nSaliendo...\n\n");
		  system("pause");
		  break;

	  default:

		  break;
	  }
	  }while(resultadoMenu!=SALIR);
	  break;
    default:
		if (opcion !=0)
		{
			system("cls");
			printf("Numero no conocido\n\n");
		}
    break;
  }
  }while(opcion!=0);
  printf("Saliendo...\n");
  system("pause");
 

  return 0;
}

int potencia (int base, int exponente)
{
  int resultado = 0;
  resultado = base;
  if (exponente == 0)
  resultado = 1;
  else
  while (exponente > 1)
  {
    resultado*=base;
    exponente--;
  }
return resultado;
}

int factorial(int numero)
{
  int resultado;
  if (numero==0)
  {
    resultado=1;
  }
  else
  {
    resultado=numero;
  }
  while(numero>1)
  {
    numero --;
    resultado=resultado*numero;
  }
  return resultado;
}

int euros(int cantidad)
{

  int valor[MAX9] = { 500, 200, 100, 50, 20, 10, 5, 2, 1 };
  int i, cociente, resto;
  for(i=0;cantidad>0;i++)
  {
    cociente=cantidad/valor[i];
    resto=cantidad%valor[i];
    cantidad=resto;
    if(resto>=0)
    {
      printf("%d billetes/monedas de %d euros\n\n",cociente, valor[i]);
    }
  }

  return 0;
}

/*
int algoritmo(int numerosIntroducir)
{
	int numeros[numerosIntroducir2];
	int i;
	int contador=1;
	printf("Escribe los numeros a ordenar:\n");
	for(i=0;contador<numerosIntroducir;i++)
	{
		printf("Numero %d:\t",i);
		scanf("%d",&numeros[i]);

		contador++;
	}
	for(i=0;i<numerosIntroducir;i++)
	{
		printf("Numeros introducidos: %d,  ",numeros[i]);
	}
	
	return 0;
}


int busqueda(int )
{

	return 0;
} */

int menu(int menuArray)
{
	int opcion;
	do
	{
	system("cls");
	printf("1. Introducir Array\n2. Visualizar Array\n3. Ordenar Array\n4. Buscar un elemento en el Array\n5. Agregar un elementro al array\n6. Modificar un elemento del array\n7. Salir\n \n");
	printf("Selecciona ejercicio:\t");
	scanf("%d",&opcion);
	
	if (opcion<1 || opcion>SALIR)
	{
		printf("\nERROR: Numero no conocido\n\n");
		system("pause");
	}
	}while (opcion<1 || opcion>SALIR);

	system("cls");
	return opcion;
}

int introducir_array(int Array[])
{

}

void visualizar_array(int Array[], int n_eltos)
{

}

void ordenar_insercion (int A[], int num)
{

}

int busqueda_binaria(int x, int valores[], int num)
{

}

int introducir_valor(int, int [], int)
{

}