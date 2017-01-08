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
	scanf("%d",pTienda->codigo);
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