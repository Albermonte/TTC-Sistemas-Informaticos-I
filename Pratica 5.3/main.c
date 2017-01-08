#include "cabecera.h"
char Colores[10][10]={"blanco", "amarillo", "naranja", "rosa", "rojo", "verde", "azul", "morado", "marrón", "negro"};
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
	
	p_cadena->n_tiendas=numero; // Asigna el numero introducido antes a la estructura para usarlo después

	if((p_cadena->p_tiendas=(tTienda *)malloc(numero*sizeof(tTienda)))!=NULL) // Reserva memoria para el numero de tiendas
	{
		printf("Introduce informacion sobre el contacto:\n");
		printf("Direccion:\t");
		scanf("%s",p_cadena->contacto.direccion); // Dirección
		printf("Telefono:\t");
		scanf("%s",p_cadena->contacto.tfno);      // Telefono
		printf("Email:\t");
		scanf("%s",p_cadena->contacto.e_mail);    // E_Mail
		return 0; // Devuelve 0 si la reserva de memoria ha sido correcta; p_tiendas no es = a NULL
	}
	else 
	{
		return -1; // Devuelve -1 si la reserva ha sido incorrecta
	}
}

void LiberaMemoria(tCadena cadena)
{
	int i;
	for (i = 0; i < cadena.n_tiendas; i++)
	{
		free(cadena.p_tiendas[i].p_prendas); // Limpia memoria de p_tiendas asignada en `IniTienda()`
	}
	
	free(cadena.p_tiendas);					 // Limpia memoria de p_tiendas asignada en `CrearTiendas()`
}

int IniTiendas(tTienda *p_tiendas, int n_tiendas)
{
	int i;
	int error;
	for (i = 0; i < n_tiendas; i++)
	{
		error=IniTienda(&p_tiendas[i]);		// Inicializa una tienda y asigna el return a error para comprobar si ha habido errores de reserva de memoria
		if (error==-1)
		{
			return -1;
		}
	}

	IniPrendasUnaTienda(tPrenda *p_prendas, int n_prendas);

	return 0;
}