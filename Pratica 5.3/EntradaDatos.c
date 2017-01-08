#include "cabecera.h"

void LeeCadena(char cadena[], char *p_mensaje, int max)
{
	 char *p;
	 int n;
   printf("Introduzca %s\n",p_mensaje);
   fflush(stdin);
	 p = fgets(cadena, max, stdin);
	 if (p != NULL)
	 {
		  n = strlen(cadena);
		  if (n>0 && cadena[n - 1] == '\n')
			   cadena[n - 1] = '\0';
	 }
}

int IniTienda(tTienda *pTienda)
{
	system("cls");
	printf("Introduce codigo de la tienda:\t");
	scanf("%d",&pTienda->codigo);
	printf("Introduce informacion sobre contacto\n\n");
	printf("Direccion:\t");
	scanf("%s",pTienda->contacto.direccion);
	printf("Telefono:\t");
	scanf("%s",pTienda->contacto.tfno);
	printf("Mail:\t");
	scanf("%s",pTienda->contacto.e_mail);
	printf("Introduce numero de prendas:\t");
	scanf("%d",&pTienda->n_prendas);
	if((pTienda->p_prendas=(tPrenda  *)malloc(pTienda->n_prendas*sizeof(tPrenda)))!=NULL)
	{
			return 0;
	}
	else
	{
			return -1;
	}	
}

void IniPrendasUnaTienda(tPrenda *p_prendas, int n_prendas)
{
	int i;
	for (i=0; i < n_prendas; i++)
	{
		system("cls");
		printf("Prenda %d:\n\n",i+1);
		IniPrenda(p_prendas[i]);
	}
}

tPrenda IniPrenda(tPrenda prenda)
{
	printf("Introduzca referencia:\t");
	scanf("%s",prenda.ref);
	printf("Introduzca talla:\t");
	scanf("%s",prenda.talla);
	printf("Introduzca color (blanco, amarillo, naranja, rosa, rojo, verde, azul, morado, marrón, negro):\t");
	scanf("%s",&prenda.color);
	printf("Introduce tipo prenda (camiseta, camisa, pantalon, falda, vestido, zapatos, jersey, chaqueta):\t");
	scanf("%s",&prenda.tipo);
	fflush(stdin);
	printf("Introduce h_m:\t");
	scanf("%c",&prenda.h_m);
	printf("Introduce numero de unidades:\t");
	scanf("%d",&prenda.n_uds);
	printf("Introduce precio:\t");
	scanf("%f",&prenda.precio);
}