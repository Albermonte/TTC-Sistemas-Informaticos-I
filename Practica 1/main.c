#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

int divis();
int pares();
int seg();

int main()
{
  int elegir;
  elegir=0;
  printf("Bienvenido\n\n");
  printf("Seleccione un programa de la lista:\n\n");
  printf("0. Ninguno, me tengo que ir\n");
  printf("1. Divisibles entre 7\n");
  printf("2. Numeros pares\n");
  printf("3. Segundos\n\n");
  printf("Introduzca numero:\t");
  scanf("%d", &elegir);
  if (elegir<0)
  {
    system("cls");
    printf("Introduce un numero mayor que 0\n\n");
    system("pause");
    system("cls");
    main();
  }
  else 
  {
    if (elegir==0)
    {
      return 0;
    }
    else
    {

    if (elegir==1)
    {
      system("cls");
      printf("Ejecutando programa 'Divisibles entre 7'\n\n");
      printf("Continuar?\n");
      system("pause");
      system("cls");
      divis();
    }
    else 
    {
      if (elegir==2)
      {
        system("cls");
        printf("Ejecutando programa 'Numeros pares'\n\n");
        printf("Continuar?\n");
        system("pause");
        system("cls");
        pares();
      }
      else
      {
        if (elegir==3)
        {
          system("cls");
          printf("Ejecutando programa 'Segundos'\n\n");
          printf("Continuar?\n");
          system("pause");
          system("cls");
          seg();
        }
        else
        {
          system("cls");
          printf("Introduce un numero entre el 1 y el 3\n");
          system("pause");
          system("cls");
          main();
        }
      }
    }
   }
  
  }

  return 0;
}