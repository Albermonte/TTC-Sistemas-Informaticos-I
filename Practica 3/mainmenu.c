#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>
#define MAX 10 
#define SALIR 7 
 
int Menu(); 
int introducir_array(int[]);
void visualizar_array(int Array[], int n_eltos);
void ordenar_insercion (int A[], int num);
int busqueda_binaria(int x, int valores[], int num);
int introducir_valor(int, int [], int, int); 
 
int main()
{
	int Array[MAX], n_eltos=0, i=0, y;
	int  op=0, x, pos, resu;
	while ((op=Menu()) != SALIR)
	{  
		switch(op)
		{ 
			 case 1:    
				 n_eltos = introducir_array(Array);
				 printf("La matriz contiene %d elementos\n", n_eltos);
				 printf ("\n\n");
				 system("pause");
				 break;
			 case 2:
				 visualizar_array(Array, n_eltos);
				 system("pause");
				 break;
			 case 3:
				 ordenar_insercion(Array, n_eltos);
				  system("pause");
				 break;
			 case 4:
				 printf("Introducir el valor a buscar:\n");
				 scanf("%d",&x);
				 pos = busqueda_binaria(x, Array,n_eltos);
				 if (pos == -1)
					 printf("Fracaso!");
				 else
				 printf("El valor encontrado es %d \n",pos);
				 system("pause");
                 break;
			 case 5: 
				 printf ("Ejercicio 5: Añadir un valor de un elemento\n ");
				 printf ("Introduzca el valor que desea añadir:\n");
				 scanf ("%d", &x);
				 resu = introducir_valor(x, Array, n_eltos, pos);
				 if (resu == -1)
					printf ("El array esta lleno\n");
				else
				{
                printf ("El valor se a anyadido con exito\n");
                n_eltos++;
				}
				system ("pause");
				break;
			 case 6:
				printf ("Ejercicio 6: Modificar un elemento del array\n");
				printf ("Introduzca el elemento a buscar en el array:\n");
				scanf ("%d", &x);
				pos = busqueda_binaria (x, Array, n_eltos);
				if ( pos == -1)
					{
                    printf ("Fracaso!!!!");
                    break;
					}
			    else
					{
					printf ("Introduzca un nuevo valor: \n");
					scanf ("%d", &y);
					resu = introducir_valor(y, Array, n_eltos, pos);
					printf("El valor se ha modificado con exito\n");
					}	
				system ("pause");
				break;
			 case 7:
				printf ("Saliendo del programa.........\n\n");



		}
	 }
} 
int Menu()
{ 
	int op;
	system("cls");
	do
	{
		system("cls");
		printf("\n");
		printf("\t1. Introducir array\n");
		printf("\t2. Visualizar array\n");
		printf("\t3. Ordenar array\n");
		printf("\t4. Buscar un elemento en el array\n");
		printf("\t5. Anyadir un elemento al array\n");
		printf("\t6. Modificar un elemento del array\n");
		printf("\t7. Salir\n");
		printf("\n Seleccione la opcion deseada\n\n");
		scanf("%d",&op);
	}
	while (op < 1 || op > SALIR);
	return op;
} 
int introducir_array(int Array[])
{
	int i, num;
	printf ("Introduzca el numero de elementos del array: ");
	scanf ("%d", &num);

	for(i=0;i<num;i++)
	{
		printf("Introduzca el elemento del array %d:",i);
		scanf("%d", &Array[i]);
    }
return i;
}
void visualizar_array (int Array[], int n_eltos)
{
	int k;
	for(k=0;k<n_eltos;k++)
		printf("El valor de los elementos del array son %d \n", Array[k]);
}
void ordenar_insercion (int A[], int num)
{
	int xd;
	int k, j;
	for(k=1;k<num;k++)
	{
		xd= A [k];
		j=k-1;
		while(A [j]>xd &&(j>=0))
		{
			
			A[j+1]= A[j];
			j--;
			
		}
		A[j+1]=xd;
	}
	for(k=0;k<num;k++)
		printf("El elemento del array %d ordenado es: %d\n", k, A[k]);
}
int busqueda_binaria(int x, int valores[], int num)
{
	int bajo=0, alto=num-1, central, encontrado=0;
	while(!encontrado && bajo<=alto)
	{
		central=(alto+bajo)/2;
			if(x==valores[central])
				encontrado=1;
			else
				if(x<valores [central])
				alto=central-1;
				else
					bajo=central+1;
	}
	if(encontrado)
		return central;
	else 
		return -1;	
}
int introducir_valor (int numint, int A[], int n_eltos, int pos)
{
    if (pos < 0)
    {
    if (n_eltos < MAX)
    {
        A[n_eltos] = numint;
        n_eltos++;
        return A[n_eltos];
    }
    else return -1;
    }
    else 
        A[pos] = numint;
    return A[pos];
}



