#include "cabecera.h"

extern char Colores[10][10];
extern char TiposPrendas[8][10];



void ErrorMemoria(tCadena cadena, char *pcadena)
{
  printf("Error al reservar la memoria de %s\n",pcadena);
  LiberaMemoria(cadena);
  MemoryManager_DumpMemoryLeaks();
  system("pause");
  exit(-1);
}

void VisuTienda(tTienda tienda)
{
	int i;
	printf("Código: %d\n",tienda.codigo);
	printf("Contacto:\n\n");
	printf("Direccion: %s\n",tienda.contacto.direccion);
	printf("Telefono: %s\n",tienda.contacto.tfno);
	printf("E_Mail: %s\n",tienda.contacto.e_mail);
	printf("Numero de prendas: %d\n",tienda.n_prendas);
	for (i = 0; i < tienda.n_prendas; i++)
	{
		printf("Prenda %d\n\n", i+1);
		VisuPrenda(tienda.p_prendas[i]);
	}
}

void VisuPrenda(tPrenda prenda)
{
	printf("Referencia: %s\n",prenda.ref);
	printf("Talla: %s\n",prenda.talla);
	printf("Color: NO TERMINADO\n");
	printf("Tipo: NO TERMINADO\n");
	printf("h_m: %c\n",prenda.h_m);
	printf("Numero unidades: %d\n",prenda.n_uds);
	printf("Precio: %f\n",prenda.precio);
}