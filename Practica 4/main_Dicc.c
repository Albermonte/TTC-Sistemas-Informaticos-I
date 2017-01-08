#include "diccionario.h"

int menu();

int main ()
{
    tPalabra Diccionario[MAX_PAL];
    int num=0;
    int opcion;

    printf ("PROGRAMA DICCIONARIO\n");
    printf ("====================\n");
    do
    {
    opcion=menu();
    switch (opcion)
    {
    case 1:
      anyadir_palabra (Diccionario,& num);
      break;
    case 2:
      traducir_palabra (Diccionario, num);
      break;
    case 3:
      mostrar_diccionario(Diccionario, num);
      break;
    case 4:
      system("pause");
      return 0;
    default:
      return 0;
      break;
    }
    }while (opcion!=4);

	return 0;
}

int menu()
{
  int op;
  int c;
  do
  {
    system("cls");
    printf ("\n"
                "\t1.- Anyadir palabra\n"
                "\t2.- Traducir palabra\n"
                "\t3.- Mostrar diccionario\n"
                "\t4.- Salir\n"
                "\n"
                "Elija una opcion: ");

     scanf ("%d", &op);
  }while ((op<1)||(op>4));
 
  while ( (c = getchar()) != '\n' && c != EOF ) { }

  return op;
}

void LeeCadena(char cadena[], int max)
{
	char *p;
	int n;

	p = fgets(cadena, max, stdin);
	if (p != NULL)
	{
		n = strlen(cadena);
		if (n>0 && cadena[n - 1] == '\n')
			cadena[n - 1] = '\0';
	}
}

int anyadir_palabra (tPalabra Diccionario[],int *num)
{
  int i;
  i=*num;
  printf("Introduzca palabra nueva:\t");
  fgets(Diccionario[i].espanyol,MAX_PAL,stdin);
  Diccionario[i].espanyol[strlen(Diccionario[i].espanyol)-1]='\0';
  printf("Introduzca traduccion:\t");
  fgets(Diccionario[i].ingles,MAX_PAL,stdin);
  Diccionario[i].ingles[strlen(Diccionario[i].ingles)-1]='\0';

  *num=*num+1;
  return 0;
}

void traducir_palabra (tPalabra Diccionario[], int num)
{
	int comparar, i;
	char palabra[MAX_CAD];
	printf("Introduzca la palabra a traducir:\t");
	fgets(palabra,MAX_CAD,stdin);
	palabra[strlen(palabra)-1]='\0';

	for (i = 0; i < MAX_PAL; i++)
	{
		comparar=strcmp(palabra,Diccionario[i].espanyol);
		if (comparar==0)
		{
			printf("Introduzca traduccion:\t");
			fgets(Diccionario[i].ingles,MAX_PAL,stdin);
			Diccionario[i].ingles[strlen(Diccionario[i].ingles)-1]='\0';
		}
	}
 printf("Yeeeah");
}

void mostrar_diccionario (tPalabra Diccionario[], int num)
{
	int i, max;
	max=num; //Imprimir tantas palabras como se hayan añadido antes
	system("cls");
	printf("\t Espanyol \t Ingles \t\n");
	for (i = 0; i < max; i++)
	{
		printf("\t %s \t\t %s \t\n",Diccionario[i].espanyol,Diccionario[i].ingles);
		
	}
	system("pause");
}