#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

int pares ()
{
  int maximo, numero, rresto;
  printf ("Este programa imprime los numeros pares por debajo del número introducido.\n");
  printf ("Introduzca el numero: ");
  scanf ("%d", &maximo);
  if (maximo <= 0)
  {
    printf ("El numero debe ser positivo\n");
  }
  else
  {
    for (numero=1; numero <= maximo; numero++)
    {
    rresto = numero % 2;
    if (rresto == 0)
    printf ("%d es un numero par\n", numero);
    }
  }
  printf("Adios\n");
  system ("pause");
  system("cls");
  main();
 }