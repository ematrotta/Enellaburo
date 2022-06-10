/*
 * ArrayPassenger_Flight.c
 *
 *  Created on: 10 may. 2022
 *      Author: Emanuel
 */

#include "ArrayPassenger_Flight.h"
//static int initId = 1000;
/*static int sPassenger_IdGenerator(void)
{
	return initId++;
}*/

/// @fn int int sPassenger_InputsDataPassenger(sPassenger *,sFlyght*,int, char*)
/// @brief Ingresar datos en un pasajero
///
/// @pre
/// @post
/// @param passenger puntero a estructura de un pasajero
/// @param listFlyghts Array Vuelos
/// @param lenflyghts Tamaño del array vuelos
/// @param mensajeError
/// @return -1 si el tipo es erroneo, -2 si el precio es erroneo, -3 Si no se encontraron vuelos con el flycode ingresado,
///-4 si no se cargó bien el codigo de vuelo, -5 Si el apellido es erroneo, -6 si el nombre es Erroneo
int Passenger_InputsDataPassenger(LinkedList* pArrayPassenger,LinkedList* pArrayVuelos,char mensajeError[])
{
	int retorno;
	int indiceVuelo;
	int tipoPasajero;
	char nombre[TAM_NOMBRE];
	char codigoVuelo[TAM_CODIGOVUELO];
	char apellido[TAM_APELLIDO];
	float precio;

	int estadoVueloInt;
	retorno = -1;


	if(pArrayPassenger != NULL && pArrayVuelos!= NULL && mensajeError != NULL)
	{


		Passenger* pasajero;
		sFlyght* Vuelo;
		pasajero = Passenger_new();
		if(pasajero != NULL)
		{

			//INGRESO MAL EL NOMBRE
			retorno = -2;

			if(!Utn_GetName(nombre, TAM_NOMBRE, "Ingrese el nombre", "No es un nombre. Reintente", 3))
			{
				Passenger_setNombre(pasajero, nombre);
				//INGRESO MAL EL APELLIDO
				retorno = -3;

				if(!Utn_GetName(apellido, TAM_APELLIDO, "Ingrese el Apellido", "No es un Apellido. Reintente", 3))
				{
					Passenger_setApellido(pasajero, apellido);

					//INGRESO MAL EL PRECIO
					retorno = -4;
					if(!Utn_GetNumeroFloat(&precio, "Ingrese el precio", "El precio debe ser entre 1 y 100000", 100000, 1, 3))
					{
						Passenger_setPrecio(pasajero, precio);
						//INGRESO CUALQUIER CARATER EN CODIGO DE VUELO
						retorno = -5;
						if(!Utn_GetStringAlfaNumericaPlus(codigoVuelo, "Ingrese el código de vuelo", "Ingrese solo letras y números", TAM_CODIGOVUELO, 3))
						{
							//EL VUELO NO SE ENCONTRÓ
							retorno = -6;
							indiceVuelo = sFlyght_findFlyghtById(pArrayVuelos,codigoVuelo);
							if(indiceVuelo>=0)
							{
								Passenger_setCodigoVuelo(pasajero,codigoVuelo);
								Vuelo = ll_get(pArrayVuelos, indiceVuelo);
								Flyght_getEstadoVuelo(Vuelo, &estadoVueloInt);

								switch(estadoVueloInt)
								{
								case ATERRIZADO:
									Passenger_setEstadoVuelo(pasajero, "Aterrizado");
									break;
								case DEMORADO:
									Passenger_setEstadoVuelo(pasajero, "Demorado");
									break;
								case EN_VUELO:
									Passenger_setEstadoVuelo(pasajero, "En Vuelo");
									break;
								case EN_HORARIO:
									Passenger_setEstadoVuelo(pasajero, "En Horario");
									break;
								}
								//SI SE INGRESA MAL EL TIPO DE PASAJERO
								retorno = -7;
								if(!Utn_GetNumeroInt(&tipoPasajero, "Ingrese el tipo de pasajero:\n1. EconomyClass\n"
										"2. ExecutiveClass\n3. FirstClass\nOPCIÓN", "La opción debe ser entre 1 y 3", 3, 1, 3))
								{
									switch(tipoPasajero)
									{
									case ECONOMYCLASS:
										retorno = Passenger_setTipoPasajero(pasajero, "EconomyClass");
										break;
									case EXECUTIVECLASS:
										retorno = Passenger_setTipoPasajero(pasajero, "ExecutiveClass");
										break;
									case FIRSTCLASS:
										retorno = Passenger_setTipoPasajero(pasajero, "FirstClass");
										break;
									}
									retorno = -8;
									if(!Passenger_setNewId(pasajero,"UltimoId.txt"))
									{
										ll_add(pArrayPassenger, pasajero);
										retorno = 0;
									}
								}

							}
						}
					}
				}
			}
		}

		if(retorno<0)
		{
			printf("\n%s\n",mensajeError);
			free(pasajero);
			pasajero = NULL;
		}


	}

	return retorno;
}


int Passenger_sortPassengerByLastName(LinkedList* this, int order)
{
	int retorno;
	int flagSwap;
	int i;
	int cantidadPasajeros;
	char apellidoUno[TAM_APELLIDO];
	char apellidoDos[TAM_APELLIDO];

	flagSwap = 1;
	retorno = -1;
	Passenger* pAux1;
	Passenger* pAux2;
	Passenger* pAuxiliar;
	cantidadPasajeros = ll_len(this);
	if(this != NULL && cantidadPasajeros > 0 &&(order == 1 || order == -1))
	{
		if(order == 1 || order == -1)
		{
			//ORDENAMIENTO ASCENDENTE
			if(order == 1)
			{
				while(flagSwap == 1)
				{

					//RECORRO LAS ENTIDADES Y COMPARO POSICION POSTERIOR CON
					//POSICION ANTERIOR
					flagSwap = 0;
					for(i=1;i<cantidadPasajeros;i++)
					{
						pAux1 = ll_get(this, i);
						pAux2 = ll_get(this, i-1);
						Passenger_getApellido(pAux1, apellidoUno);
						Passenger_getApellido(pAux2, apellidoDos);

						//SI SUECEDE QUE ES MAYOR EL ANTERIOR
						if(strncmp(apellidoDos,apellidoUno,TAM_APELLIDO)<0)
						{
							//CAMBIO LOS VALORES EN LAS  POSICIONES
							pAuxiliar = pAux2;
							pAux2 = pAux1;
							pAux1 = pAuxiliar;
							flagSwap = 1;
							//ROMPO
							break;
						}
					}


				}

			}
			//ORDENAMIENTO DESCENDENTE
			else
			{

				while(flagSwap == 1)
				{
					//RECORRO LAS ENTIDADES Y COMPARO POSICION POSTERIOR CON
						//POSICION ANTERIOR
						flagSwap = 0;
						for(i=1;i<cantidadPasajeros;i++)
						{
							pAux1 = ll_get(this, i);
							pAux2 = ll_get(this, i-1);
							Passenger_getApellido(pAux1, apellidoUno);
							Passenger_getApellido(pAux2, apellidoDos);

							//SI SUECEDE QUE ES MAYOR EL ANTERIOR
							if(strncmp(apellidoDos,apellidoUno,TAM_APELLIDO)>0)
							{
								//CAMBIO LOS VALORES EN LAS  POSICIONES
								pAuxiliar = pAux2;
								pAux2 = pAux1;
								pAux1 = pAuxiliar;
								flagSwap = 1;
								//ROMPO
								break;
							}
						}

				}

			}
		}
			retorno = 0;
	}
	return retorno;
}
/*
/// @fn int sPassenger_addPassengerFlyghtStatus(sPassenger *,int,sFlyght*,int)
/// @brief Agregar a cada pasajero ACTIVO el estado de vuelo en base a su codigo de vuelo
///
/// @pre
/// @post
/// @param passenger listado de pasajeros
/// @param lenPassenger Tamaño del array pasajeros
/// @param listFlyghts Array Vuelos
/// @param lenflyghts Tamaño del array vuelos
/// @return -1 si no se ingresaron correctamente los parametros, 0 si salio todo bien
int sPassenger_addPassengerFlyghtStatus(sPassenger passenger[],int lenPassenger, sFlyght listFlyghts[],int lenflyghts)
{
	int retorno;
	int i;
	int j;

	retorno = -1;
	if(passenger != NULL && lenPassenger>0 && listFlyghts != NULL && lenflyghts>0)
	{
		//RECORREMOS EL ARRAY DE PASAJEROS
		for(j = 0;j<lenPassenger;j++)
		{
			//RECORREMOS TODOS LOS VUELOS
			for(i=0;i<lenflyghts;i++)
			{
				//SI EL PASAJERO NO ESTA DADO DE ALTA, NO SE LE ASIGNA EL ESTADO DE VUELO
				if(passenger[j].isEmpty != FALSE)
				{
					continue;
				}
				else
				{
					//SI ESTA DADO DE ALTA, SE RELACIONA SU CODIGO DE VUELO PREVIAMENTE INGRESADO
					//Y SE ASOCIA AL ESTADO DE VUELO
					if(strncmp(passenger[j].flycode,listFlyghts[i].flycode,FLYCODE)==0)
					{
						passenger[j].statusFlight = listFlyghts[i].status;
						retorno = 0;
						break;
					}

				}

			}


		}
	}

	return retorno;
}



/// @fn int sPassenger_Modification(sPassenger *,int,sFlyght*,int)
/// @brief Modifiar algun campo de la estructura
///
/// @pre
/// @post
/// @param passenger listado de pasajeros
/// @param lenPassenger Tamaño del array pasajeros
/// @param listFlyghts Array Vuelos
/// @param lenflyghts Tamaño del array vuelos
/// @return -1 si no se ingresaron correctamente los parametros, 0 si salio todo bien
int sPassenger_Modification(sPassenger * list,int len,int id,sFlyght listFlyght[],int lenFlyghts)
{
	int retorno;
	int indiceId;
	int opcionMenu;

	char auxiliarFlycode[FLYCODE];

	retorno = -1;
	if(listFlyght != NULL && lenFlyghts>0 && list != NULL && len>0)
	{
		indiceId = sPassenger_findPassengerById(list,len,id);
		if(indiceId<0)
		{
			retorno = -2;
		}
		else
		{
			//DESPLIEGO SUBMENU
			puts("\nQué dato desea modificar?\n\t1)Nombre\n\t2)Apellido"
					"\n\t3)Codigo de vuelo\n\t4)Tipo de pasajero\n\t5)Precio");
			//PIDO QUE INGRESE LA OPCION DEL SUBMENU
			if(Utn_GetNumeroInt(&opcionMenu, "Opcion", "Debe ser entre 1 y 5", 5, 1, 3) != 0)
			{
				retorno = -3;
			}
			else
			{
				switch(opcionMenu)
				{
					case 1:
						//MODIFICAE NOMBRE
						if(Utn_GetName(list[indiceId].name, NAME, "Ingrese el nuevo nombre", "El Max de caracteres 50 o no es un Nombre", 3) == 0)
						{
							retorno = 0;
						}
						break;
					case 2:
						//MODIFICAR APELLIDO
						if(Utn_GetName(list[indiceId].lastName, NAME, "Ingrese el nuevo Apellido", "El Max de caracteres 50 o no es un Apellido", 3) == 0)
						{
							retorno = 0;
						}
						break;
					case 3:
						//MODIFICAR CODIGO DE VUELO SOLO SI SE ENCUENTRA ENTRE LOS VUELOS DISPONIBLES
						if(Utn_GetString(auxiliarFlycode, "Ingrese el nuevo codigo de vuelo", "El codigo de vuelo supera el buffer",FLYCODE, 3) == 0 && sFlyght_findFlyghtById(listFlyght,lenFlyghts,auxiliarFlycode)>=0)
						{
							strncpy(list[indiceId].flycode,auxiliarFlycode,FLYCODE);
							retorno = 0;

						}
						break;
					case 4:
						//MODIFICAR TIPO DE PASAJERO
						if(Utn_GetNumeroInt(&list[indiceId].typePassenger, "Ingrese el nuevo tipo de pasajero", "ERROR. Debe ser entre 1 y 3", 3, 1, 3) == 0)
						{
							retorno = 0;
						}
						break;
					case 5:
						//MODIFICAR EL PRECIO
						if(Utn_GetNumeroFloat(&list[indiceId].price, "Ingrese el nuevo precio", "El precio debe ser entre", 100000, 0, 3) == 0)
						{
							retorno = 0;
						}
						break;
				}
				//VALIDO QUE EL RESULTADO DE LA MODIFICACION DEL CAMPO SEA CORRECTA
				if(retorno != 0)
				{
					//SI NO ES CORRECTA LA MODIFICACION
					retorno = -4;
				}

			}
		}
	}

	return retorno;
}

*/
