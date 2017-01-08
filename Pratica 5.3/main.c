#include "cabecera.h"
char Colores[10][10]={"blanco", "amarillo", "naranja", "rosa", "rojo", "verde", "azul", "morado", "marr�n", "negro"};
char TiposPrendas[8][10]={"camiseta", "camisa", "pantalon", "falda", "vestido", "zapatos", "jersey", "chaqueta"};

main()
{
   int op, n_tiendas=0;
   tCadena cadena;
  
   cadena.n_tiendas=0;
   cadena.p_tiendas=NULL;
 
   do
   {
      op=Menu();
	
	    if (op!=6)
	    {
	       switch (op)
	       {
			case 1: // crear array de tiendas
               if (CrearTiendas(&cadena)==-1)
                   ErrorMemoria(cadena, "las tiendas");
		           system("pause");
		        break;
		    case 2: //Inicializar las tiendas y crear arrays de prendas
			      if (IniTiendas(cadena.p_tiendas, cadena.n_tiendas)==-1)
					 ErrorMemoria(cadena, "las prendas");
		           system("pause");
		        break;
		/*         case 3:
		   	       //VisuTiendas(cadena.p_tiendas,cadena.n_tiendas);
			         VisuCadena(cadena);
			         system("pause");
		        break;
            case 4: //Abrir una tienda: crearla e inicializarla
		   	       if (AnyadirTienda(&cadena)==-1)
                  ErrorMemoria(cadena, "las tiendas");
               system("pause");
		           break;
     
           case 5: //Eliminar un tipo de prenda de las tiendas
		          EliminarPrendaDeTiendas(cadena);
			        system("pause");
		       break;
			   */
        } // fin del switch
     } // fin del if
      
   }while (op!=6);

   LiberaMemoria(cadena);
  
   MemoryManager_DumpMemoryLeaks();
   system("pause");
   return 0;
}

int Menu()
{
  int op;
  do
  {
	  system("cls");
	  printf("\n\n");
	  printf("\t1. Crear array de tiendas\n");
	  printf("\t2. Inicializar tiendas y prendas\n");
	  printf("\t3. Visualizar datos\n");
	  printf("\t4. Anyadir tienda\n");
	  printf("\t5. Eliminar un tipo de prenda de las tiendas\n");
	  printf("\t6. Salir\n");
	  printf("\n Selecciones la opcion deseada\n\n");
	  scanf("%d",&op);
  }while ((op<1) || (op>6));
  return op;
}

int CrearTiendas(tCadena *p_cadena)
{
	//Numero de tiendas
	int numero;
	do
	{
	system("cls");
	printf("Introduce el numero de tiendas:\t");
	scanf("%d",&numero);
	if(numero<=0) 
	{
		printf("Vuelve a introducir el numero.\n");
		system("pause");
	}
	system("cls"); // Limpiar pantalla
	}while(numero<=0);
	
	if((p_cadena->p_tiendas=(tTienda *)malloc(numero*sizeof(tTienda)))!=NULL)
	{
		printf("Introduce informacion sobre el contacto:\n");
		printf("Direccion:\t");
		scanf("%s",p_cadena->contacto.direccion);
		printf("Telefono:\t");
		scanf("%s",p_cadena->contacto.tfno);
		printf("Email:\t");
		scanf("%s",p_cadena->contacto.e_mail);
		return 0;
		
	}
	else 
	{
		return -1;
	}
}

void LiberaMemoria(tCadena cadena)
{
	free(cadena.p_tiendas->p_prendas);
	free(cadena.p_tiendas);
}

int IniTiendas(tTienda *p_tiendas, int n_tiendas)
{
	IniTienda(&p_tiendas);
	return 0;

}