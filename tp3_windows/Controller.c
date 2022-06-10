#include "Controller.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{

	int retorno;
	retorno = -1;
	if(path != NULL && pArrayListPassenger != NULL)
	{

		FILE* pArchivo = fopen(path,"r");
		if(pArchivo!= NULL)
		{
			parser_PassengerFromText(pArchivo, pArrayListPassenger);
		}
		fclose(pArchivo);

		retorno = 0;
	}
    return retorno;
}

/** \brief Carga los datos de los vuelos desde el archivo dataFlyghts.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListFlyght LinkedList*
 * \return int
 *
 */
int controller_loadFromTextFlyght(char* path , LinkedList* pArrayListFlyght)
{


	int retorno;
	retorno = -1;
	if(path != NULL && pArrayListFlyght != NULL)
	{


		FILE* pArchivo = fopen(path,"r");
		if(pArchivo!= NULL)
		{
			parser_FlyghtsFromText(pArchivo, pArrayListFlyght);
		}
		fclose(pArchivo);

		retorno = 0;
	}
    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger,LinkedList* pArrayVuelos)
{
	int retorno;
	retorno = -1;

	if(pArrayListPassenger != NULL && pArrayVuelos != NULL)
	{
		retorno = -2;
		if(!Passenger_InputsDataPassenger(pArrayListPassenger,pArrayVuelos,"No se pudo cargar correctamente"))
		{
			retorno = 0;
		}

	}

	return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger,LinkedList* pVuelos)
{
	int retorno;
	int i;
	int option;
	int idPasajero;
	int tamLista;
	int auxId;
	int indexPasajero;
	int indiceVuelo;
	int tipoPasajero;
	char nombre[TAM_NOMBRE];
	char apellido[TAM_APELLIDO];
	float precio;
	char codigoVuelo[TAM_CODIGOVUELO];
	int estadoVueloInt;
	Passenger* auxPassenger;
	sFlyght* Vuelo;
	retorno = -1;
	if(pArrayListPassenger != NULL && pVuelos != NULL)
	{

		retorno = -2;
		if(!Utn_GetNumeroInt(&auxId, "Qué Id desea modificar?", "Error. Debe ser entre 1 y 10000", 10000, 1, 3))
		{
			retorno = -3;
			tamLista = ll_len(pArrayListPassenger);
			for(i = 0;i<tamLista;i++)
			{

				auxPassenger = ll_get(pArrayListPassenger, i);
				Passenger_getId(auxPassenger, &idPasajero);
				if(idPasajero == auxId)
				{
					indexPasajero = i;
					break;
				}
			}
			//SI ENCUENTRA EL ID
			retorno = -5;
			if(indexPasajero>=0)
			{
				if(!Utn_GetNumeroInt(&option, "Qué dato desea modificar?\n1. Nombre\n2. Apellido"
						"\n3. Precio\n4. Tipo de Pasajero\n5. Codigo de vuelo\nOPCIÓN", "ERROR. debe ser entre 1 y ", 5, 1, 3))
				{
					retorno = -6;
					switch(option)
					{
					case 1:
						//NOMBRE
						if(!Utn_GetName(nombre, TAM_NOMBRE, "Ingrese el nuevo nombre", "No es un nombre. Reintente", 3))
						{
							Passenger_setNombre(auxPassenger, nombre);
							retorno = 0;
						}
						break;
					case 2:
						//APELLIDO
						if(!Utn_GetName(apellido, TAM_APELLIDO, "Ingrese el nuevo Apellido", "No es un Apellido. Reintente", 3))
						{
							Passenger_setApellido(auxPassenger, apellido);
							retorno = 0;
						}
						break;
					case 3:
						//PRECIO
						if(!Utn_GetNumeroFloat(&precio, "Ingrese el nuevo precio", "El precio debe ser entre 1 y 100000", 100000, 1, 3))
						{
							Passenger_setPrecio(auxPassenger, precio);
							retorno = 0;
						}
						break;
					case 4:
						//TIPO PASAJERO
						if(!Utn_GetNumeroInt(&tipoPasajero, "Ingrese el tipo de pasajero:\n1. EconomyClass\n"
								"2. ExecutiveClass\n3. FirstClass\nOPCIÓN", "La opción debe ser entre 1 y 3", 3, 1, 3))
						{
							switch(tipoPasajero)
							{
							case ECONOMYCLASS:
								retorno = Passenger_setTipoPasajero(auxPassenger, "EconomyClass");
								break;
							case EXECUTIVECLASS:
								retorno = Passenger_setTipoPasajero(auxPassenger, "ExecutiveClass");
								break;
							case FIRSTCLASS:
								retorno = Passenger_setTipoPasajero(auxPassenger, "FirstClass");
								break;
							}
							retorno = 0;
						}
						break;
					case 5:
						//AL MODIFICAR EL CODIGO DE VUELO YA SE MODIFICA EL ESTADO DEL MISMO
						if(!Utn_GetStringAlfaNumericaPlus(codigoVuelo, "Ingrese el nuevo código de vuelo", "Ingrese solo letras y números", TAM_CODIGOVUELO, 3))
						{
							//SI NO SE ENONTRÓ EL CODIGO DE VUELO
							retorno = -7;
							indiceVuelo = sFlyght_findFlyghtById(pVuelos,codigoVuelo);
							if(indiceVuelo>=0)
							{
								Vuelo = ll_get(pVuelos, indiceVuelo);
								Passenger_setCodigoVuelo(auxPassenger,codigoVuelo);
								Flyght_getEstadoVuelo(Vuelo, &estadoVueloInt);

								switch(estadoVueloInt)
								{
								case ATERRIZADO:
									Passenger_setEstadoVuelo(auxPassenger, "Aterrizado");
									break;
								case DEMORADO:
									Passenger_setEstadoVuelo(auxPassenger, "Demorado");
									break;
								case EN_VUELO:
									Passenger_setEstadoVuelo(auxPassenger, "En Vuelo");
									break;
								case EN_HORARIO:
									Passenger_setEstadoVuelo(auxPassenger, "En Horario");
									break;
								}
								retorno = 0;
							}
						}
						break;
					}

				}
			}

		}

	}

    return retorno;

}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int -1 si los parametros ingresados son NULL,-2 si ingresó el usuario mal el ID,
 * -3 si no se encontró usuario con el id, 0 si salio todo bien
 *
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int retorno;
	int i;
	char confirm;
	int idPasajero;
	int tamLista;
	int auxId;
	Passenger* auxPassenger;
	retorno = -1;
	if(pArrayListPassenger != NULL)
	{
		retorno = -2;
		if(!Utn_GetNumeroInt(&auxId, "Qué Id desea dar de baja?", "Error. Debe ser entre 1 y 10000", 10000, 1, 3))
		{
			retorno = -3;
			tamLista = ll_len(pArrayListPassenger);
			for(i = 0;i<tamLista;i++)
			{

				auxPassenger = ll_get(pArrayListPassenger, i);
				Passenger_getId(auxPassenger, &idPasajero);
				if(idPasajero == auxId)
				{
					if(!GetCharacter2Options(&confirm, "Se perderan todos los datos. Esta seguro de la baja? S/N", "Ingrese S(si) o N(no)", 'S', 'N', 3))
					{
						if(confirm == 's' || confirm == 'S')
						{
							ll_remove(pArrayListPassenger, i);
							retorno = 0;
						}
					}

					break;
				}
			}
		}

	}

    return retorno;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno;
	int i;
	int cantidadPasajeros;

	retorno = -1;
	Passenger* pAux;

	cantidadPasajeros = ll_len(pArrayListPassenger);

	if(pArrayListPassenger != NULL)
	{
		printf("%10s | %15s | %15s | %10s | %15s | %15s | %15s\n","ID","NOMBRE","APELLIDO","PRECIO","CODIGO VUELO","TIPO PASAJERO","ESTADO VUELO");
		for(i = 0; i<cantidadPasajeros;i++)
		{
			pAux = ll_get(pArrayListPassenger,i);
			if(pAux != NULL)
			{
				Passenger_printOne(pAux);
			}

		}
		retorno = 0;

	}
    return retorno;
}

/** \brief Listar Vuelos
 *
 * \param path char*
 * \param pArrayListFlyght LinkedList*
 * \return int
 *
 */
int controller_ListFyght(LinkedList* pArrayListFlyght)
{
	int retorno;
	int i;
	int cantidadVuelos;

	retorno = -1;
	sFlyght* pAux;

	cantidadVuelos = ll_len(pArrayListFlyght);

	if(pArrayListFlyght != NULL)
	{
		printf("%15s | %15s\n","CODIGO VUELO","ESTADO VUELO");
		for(i = 0; i<cantidadVuelos;i++)
		{
			pAux = ll_get(pArrayListFlyght,i);
			if(pAux != NULL)
			{
				Flyght_printOne(pAux);
			}

		}
		retorno = 0;

	}
    return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno;
	retorno = -1;
	if(pArrayListPassenger != NULL)
	{
		if(!Passenger_sortPassengerByLastName(pArrayListPassenger, 1))
		{
			puts("Todo ok");
		}
	}
    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
    int retorno;
	int id;
	char nombre[TAM_NOMBRE];
	char apellido[TAM_APELLIDO];
	char codigoVuelo[TAM_CODIGOVUELO];
	char tipoPasajero[TAM_TIPOPASAJERO];
	float precio;
	char estadoVuelo[TAM_ESTADOVUELO];
	int cantidadPasajeros;
	int i;

    retorno = -1;
    Passenger* pAux;
    cantidadPasajeros = ll_len(pArrayListPassenger);
    if(path != NULL && pArrayListPassenger != NULL)
    {
    	retorno = -2;
    	FILE* pArchivo = fopen(path,"w");
    	if(pArchivo != NULL)
    	{
    		if(nombre != NULL && apellido != NULL && codigoVuelo != NULL && tipoPasajero != NULL && estadoVuelo != NULL)
    		{
    			retorno = -3;
    			for(i = 0;i<cantidadPasajeros;i++)
    			{
    				pAux = ll_get(pArrayListPassenger, i);
        			if(!Passenger_getId(pAux, &id) && !Passenger_getNombre(pAux, nombre) &&
        					!Passenger_getApellido(pAux, apellido) && !Passenger_getCodigoVuelo(pAux, codigoVuelo) &&
        					!Passenger_getTipoPasajero(pAux, tipoPasajero) && !Passenger_getPrecio(pAux, &precio) &&
        					!Passenger_getEstadoVuelo(pAux, estadoVuelo))
        			{

    					//id,name,lastname,price,flycode,typePassenger,statusFlight
    					fprintf(pArchivo,"%d,%s,%s,%.2f,%s,%s,%s",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);
    					retorno = 0;

        			}
    			}

    		}

    	}
    	fclose(pArchivo);
    }

    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

