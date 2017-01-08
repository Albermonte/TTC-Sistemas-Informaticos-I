#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

double mediaAritmetica(double, double, double, double);
void intercambiar(double, double);
int cambiarBits(int, int, int);
long factorial(long);
int ponerACeroBit(int, int);
void operacionesLogicasBits();
int parImpar(int);
int desplazar(int, int);
int numeroBits(int);
int menu();

int main()
{
	double n1mediaAritmetica;
	double n2mediaAritmetica;
	double n3mediaAritmetica;
	double n4mediaAritmetica;
	double finalmediaAritmetica;
	double d1intercambiar;
	double d2intercambiar;
	int cambiarBitsfinal;
	int posicioncambiarBits;
	int invertircambiarBits;
	int numerocambiarBits;
	int numeroNBits;
	int numeroNBitsfinal;
	int factorialfinal;
	long numeroparafactorial;
	int nummodificado;
	int numdesplazar;
	int numerobit;
	int nPosBit;
	int valor;
	int desplazado;
	int numpar;
	int paroimpar;
	int opcion; // opción elegida del menú
	printf ("PRÁCTICA 2\n");
	printf ("==========\n");
	opcion = menu(); // llama/invoca a la función "menu"

  while (opcion != 10) // sentencia repetitiva
  {
    switch (opcion) // sentencia condicional
    {
    case 1:
      printf("Ejercicio 1: desplazar\n"); // llama a la función "printf"
      system("pause");
      system("cls");
      printf("Introduce el numero:\t");
      scanf("%d",&numdesplazar);
      printf("Introduce el valor del desplazamiento:\t");
      scanf("%d",&valor);
      desplazado=desplazar(numdesplazar, valor);// Llamar a la función "desplazar"
      printf("\nEl numero %d desplazado %d veces es: %d\n\n",numdesplazar, valor,desplazado);
      break;
    case 2:
      printf("Ejercicio 2: par o impar\n");
      system("pause");
	  system("cls");
      printf("Escribe el numero:\t");
      scanf("%d", &numpar);
      paroimpar=parImpar(numpar);
	  if (paroimpar !=0)
		  printf("El numero %d es impar\n\n",numpar);
	  else
		  printf("El numero %d es par\n\n",numpar);
      break;
    case 3:
      printf("Ejercicio 3: operaciones logicas y a nivel de bits\n");
      // Llamar a la función "operacionesLogicasBits"
	  operacionesLogicasBits();
      break;
    case 4:
      printf("Ejercicio 4: poner a cero un bit\n");
	  system("pause");
	  system("cls");
      // Llamar a la función "ponerACeroBit"
	  printf("Escribe el numero: \t");
	  scanf("%d", &numerobit);
	  printf("Escribe la posicion del bit a poner a cero: \t");
	  scanf("%D", &nPosBit);
	  nummodificado=ponerACeroBit(numerobit, nPosBit);
	  printf("El numero modificado es: %d\n", nummodificado);
      break;
    case 5:
      printf("Ejercicio 5: factorial\n");
      // Llamar a la función "factorial"
	  system("pause");
	  system("cls");
	  do
	  {
		printf("Escribe un numero entero positivo:\t");
		scanf("%ld", &numeroparafactorial);
		factorialfinal=factorial(numeroparafactorial);
		 if (factorialfinal==-1)
		  {
			  printf("No es posible calcular el factorial\n");
		  
		  }
		  else
		  {
			  printf("El factorial de %ld es: %ld\n\n",numeroparafactorial,factorialfinal);
		  }
	  }while (numeroparafactorial<0);
	  break;
    case 6:
      printf("Ejercicio 6: numero de bits\n");
      // Llamar a la función "numeroBits"
      system("pause");
      system("cls");
      numeroNBits = -1;
      do
      {
        printf("Introduzca un numero entero positivo:\t");
        scanf("%d",&numeroNBits);
        if (numeroNBits<0)
        {
          printf("\nDebe ser un numero entero positivo\n\n");
        
        }
        else
        {
        numeroNBitsfinal=numeroBits(numeroNBits);
        printf("El numero de bits para representar %d es: %d\n", numeroNBits, numeroNBitsfinal);
        }
      }while(numeroNBits < 0);
      break;
    case 7:
      printf("Ejercicio 7: cambiar bits\n");
      // Llamar a la función "cambiarBits"
	  system("pause");
	  system("cls");
	  do
	  {
	  printf("Introduzca un numero entero positivo: \t");
	  scanf("%d",&numerocambiarBits);
	  }while(numerocambiarBits<0);
	  printf("Introduzca la poscion del bit inicial a invertir: \t");
	  scanf("%d",&posicioncambiarBits);
	  printf("Introduzca el numero de bits a invertir: \t");
	  scanf("%d",&invertircambiarBits);
	  if (invertircambiarBits<0 || invertircambiarBits>posicioncambiarBits)
	  {
		  system("cls");
		  printf("Numero de bits no valido\n\n");
		  break;
	  }
	  
	  cambiarBitsfinal=cambiarBits(numerocambiarBits, posicioncambiarBits, invertircambiarBits);
	  printf("El numero modificado es: %d\n",cambiarBitsfinal);
      break;
    case 8:
      printf("Ejercicio 8: intercambiar\n");
      // Llamar a la función "intercambiar"
	  system("pause");
	  system("cls");
	  printf("Introduzca el valor de d1:\t");
	  scanf("%lf",&d1intercambiar);
	  printf("Introzca el valor de d2:\t");
	  scanf("%lf",&d2intercambiar);
	  intercambiar(d1intercambiar,d2intercambiar);
      break;
    case 9:
      printf("Ejercicio 9: media aritmetica\n");
      // Llamar a la función "mediaAritmetica"
	  system("pause");
	  system("cls");
	  printf("Introduce el numero 1:\t");
	  scanf("%lf",&n1mediaAritmetica);
	  printf("Introduce el numero 2:\t");
	  scanf("%lf",&n2mediaAritmetica);
	  printf("Introduce el numero 3:\t");
	  scanf("%lf",&n3mediaAritmetica);
	  printf("Introduce el numero 4:\t");
	  scanf("%lf",&n4mediaAritmetica);
	  finalmediaAritmetica=mediaAritmetica(n1mediaAritmetica,n2mediaAritmetica,n3mediaAritmetica,n4mediaAritmetica);
	  printf("Media: %lf\n",finalmediaAritmetica);
      break;
    default:
      printf ("ERROR: Opcion incorrecta.\n");
	  break;
    }
    system("pause");  //llamar a la función "system"
    opcion = menu(); // llamar a la función "menu"
  }
  system("cls");
  printf("Saliendo...\n\n");
  system("pause");
}
// DEFINICIONES DE FUNCIONES
int menu() // definición de la función "menu"
{
  int op;
  do // sentencia repetitiva
  {
    system("cls");
    printf ("\n"
      "\t01.- Ejercicio 1\n"
      "\t02.- Ejercicio 2\n"
      "\t03.- Ejercicio 3\n"
      "\t04.- Ejercicio 4\n"
      "\t05.- Ejercicio 5\n"
      "\t06.- Ejercicio 6\n"
      "\t07.- Ejercicio 7\n"
      "\t08.- Ejercicio 8\n"
      "\t09.- Ejercicio 9\n"
      "\t10.- Salir\n"
      "\n"
      "Elija una opcion: ");
    scanf ("%d", &op); // llamar a la función "scanf"
    if (op < 1 || op > 10) // sentencia condicional
    {
      // printf("Opción no válida\n");
      printf("Opcion no valida\n");
      //system("pause"); // detenerse hasta pulsar una tecla
    }
  }
  while (op < 1 || op > 10); // condición
  return op;
}


int desplazar(int numdesplazar, int valor)
{
  int nDesplazado;
  nDesplazado=0;
  nDesplazado=numdesplazar>>valor;
  return nDesplazado;
}


int parImpar(int numpar)
{
  int resultadoparimpar;
  resultadoparimpar=numpar%2;
  return resultadoparimpar;
}

void operacionesLogicasBits()
{
int a = 8,b = 0, c = 15, d = 93, e, r1, r2, r3, r4, r5, r6;
r1 = a && b || c && !d;					// 0
r2 = !a || b && c || d;					// 1
r3 = a < b || !c > d;					// 0
r4 = a + b > d -c;						// 0
r5 = a && b && !c || !(a && b) && c;	// 1
a = 0x12; b = 0x56; c = 0x9a ; d = 0x0f ; e = 0360;
r1 = a & b | c;							// 154
r2 = c & 0177;							// 26
r3 = ~a | b ^ c;						// -19
r4 = e & c;								// 144
r5 = r4 & ~077;							// 128
r6 = (a & d) << 4 | (a & e) >> 4;		// 33
}

int ponerACeroBit(int numerobit, int nPosBit)
{
int resultado,mascara;
mascara = 1 << nPosBit;
resultado= numerobit-mascara;
return resultado;
}

long factorial(long numfactorial)
{
long factorial = 1, contador = 0;
if (numfactorial < 0 || numfactorial > 16) return -1;
while (numfactorial>1)
{
	factorial=factorial*numfactorial;
	numfactorial--;
	contador++;
}
return factorial;
}

int numeroBits(int numeroNBits)
{
 int dosElevadoN = 2, nbits = 1; // 2^1 = 2
 while (dosElevadoN <= numeroNBits)
 {
   dosElevadoN=dosElevadoN*2;
   nbits ++;
 }
 return nbits;
}

int cambiarBits(int numerocambiarBits, int posicioncambiarBits, int invertircambiarBits)
{
	int varnumerocambiarBits;
	int var2numerocambiarBits;
	int mascara;
	varnumerocambiarBits=numerocambiarBits;
	//varnumerocambiarBits>>posicioncambiarBits;
	//varnumerocambiarBits<<3;
	mascara=varnumerocambiarBits<<posicioncambiarBits;
	varnumerocambiarBits=~mascara;
	var2numerocambiarBits=var2numerocambiarBits & varnumerocambiarBits;
	return var2numerocambiarBits;

	//Idea: variable a=10001010, mover a la drcha tantos bits como invertircambiarsBits (ej: invertircambiarBits=3; a>>3; a=00010001 , hacer suma (AND, OR, etc)
	//https://es.wikipedia.org/wiki/Operador_a_nivel_de_bits#Copiando_bits (posicioncmabiarBits)
}

void intercambiar(double d1intercambiar, double d2intercambiar)
{
	double varintercambiar;
	varintercambiar=d1intercambiar;
	d1intercambiar=d2intercambiar;
	d2intercambiar=varintercambiar;
	printf("Valores intercambiados: d1 = %lf, d2 = %lf\n\n",d1intercambiar,d2intercambiar);
}

double mediaAritmetica(double n1mediaAritmetica,double n2mediaAritmetica,double n3mediaAritmetica,double n4mediaAritmetica)
{
	double sumamediaAritmetica;
	double divisionmediaAritmetica;
	sumamediaAritmetica=n1mediaAritmetica+n2mediaAritmetica+n3mediaAritmetica+n4mediaAritmetica;
	divisionmediaAritmetica=sumamediaAritmetica/4;
	return divisionmediaAritmetica;
}