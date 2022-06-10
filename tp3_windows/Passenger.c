/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include "Passenger.h"

/// @fn Passenger Passenger_new*()
/// @brief Crea un puntero a estructura con memoria dinámica
///
/// @pre
/// @post
/// @return puntero a entidad
Passenger* Passenger_new()
{
	Passenger* p;
	p = (Passenger*)malloc(sizeof(Passenger));
	return p;
}


/// @fn Passenger Passenger_newParametros*(char*, char*, char*, char*, char*, char*, char*)
/// @brief Cargar un Puntero a estructura con datos
///
/// @pre
/// @post
/// @param id
/// @param nombre
/// @param apellido
/// @param precio
/// @param codigoVuelo
/// @param tipoPasajero
/// @param estadoVuelo
/// @return puntero a estructura
Passenger* Passenger_newParametros(char* id,char* nombre,char* apellido,char* precio, char* codigoVuelo,char* tipoPasajero,char* estadoVuelo)
{
	//id,name,lastname,price,flycode,typePassenger,statusFlight


	Passenger* pPasajero;
	if(id != NULL && nombre != NULL && apellido != NULL && precio != NULL && codigoVuelo != NULL && tipoPasajero != NULL && estadoVuelo != NULL)
	{

		pPasajero = Passenger_new();
		if(!Passenger_setId(pPasajero, atoi(id)) && !Passenger_setNombre(pPasajero, nombre) && !Passenger_setApellido(pPasajero, apellido) && !Passenger_setCodigoVuelo(pPasajero, codigoVuelo) &&
				!Passenger_setTipoPasajero(pPasajero, tipoPasajero) && !Passenger_setPrecio(pPasajero, atof(precio)) && !Passenger_setEstadoVuelo(pPasajero, estadoVuelo))
		{


		}
		else
		{
			free(pPasajero);
			pPasajero = NULL;
		}

	}


	return pPasajero;
}

/// @fn int Passenger_setId(Passenger*, int)
/// @brief Colocarle id a un Passenger
///
/// @pre
/// @post
/// @param this
/// @param id
/// @return -1 si alguno de los parámetros es NULL, 0 si salio todo bien
int Passenger_setId(Passenger* this,int id)
{
	int retorno;
	retorno = -1;


	if(this != NULL && id>0)
	{
		this->id = id;
		retorno = 0;
	}

	return retorno;
}
/// @fn int Passenger_getId(Passenger*, int*)
/// @brief Obtener un ID de una estructura Passenger
///
/// @pre
/// @post
/// @param this
/// @param id
/// @return -1 si alguno de los parámetros es NULL, 0 si salio todo bien
int Passenger_getId(Passenger* this,int* id)
{
	int retorno;
	retorno = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}


/// @fn int Passenger_setNombre(Passenger*, char*)
/// @brief Colocar el Nombre a un Passenger
///
/// @pre
/// @post
/// @param this
/// @param nombre
/// @return -1 si alguno de los parámetros es NULL, 0 si salio todo bien
int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno;
	retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strncpy(this->nombre,nombre,TAM_NOMBRE);
		retorno = 0;
	}

	return retorno;
}

/// @fn int Passenger_getNombre(Passenger*, char*)
/// @brief Obtener el Nombre de un Passenger
///
/// @pre
/// @post
/// @param this
/// @param nombre
/// @return -1 si alguno de los parámetros es NULL, 0 si salio todo bien
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno;
	retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strncpy(nombre,this->nombre,TAM_NOMBRE);
		retorno = 0;
	}

	return retorno;
}



/// @fn int Passenger_setApellido(Passenger*, char*)
/// @brief Colocar el apellido a un Passenger
///
/// @pre
/// @post
/// @param this
/// @param apellido
/// @return -1 si alguno de los parámetros es NULL, 0 si salio todo bien
int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno;
	retorno = -1;

	if(this != NULL && apellido != NULL)
	{
		strncpy(this->apellido,apellido,TAM_APELLIDO);
		retorno = 0;
	}

	return retorno;
}
/// @fn int Passenger_getApellido(Passenger*, char*)
/// @brief Obtener el apellido de un Passenger
///
/// @pre
/// @post
/// @param this
/// @param apellido
/// @return -1 si alguno de los parámetros es NULL, 0 si salio todo bien
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno;
	retorno = -1;

	if(this != NULL && apellido != NULL)
	{
		strncpy(apellido,this->apellido,TAM_APELLIDO);
		retorno = 0;
	}

	return retorno;
}

/// @fn int Passenger_setCodigoVuelo(Passenger*, char*)
/// @brief Colocar codigo de Vuelo a un Passenger
///
/// @pre
/// @post
/// @param this
/// @param codigoVuelo
/// @return -1 si alguno de los parámetros es NULL, 0 si salio todo bien
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno;
	retorno = -1;

	if(this != NULL && codigoVuelo != NULL)
	{
		strncpy(this->codigoVuelo,codigoVuelo,TAM_CODIGOVUELO);
		retorno = 0;
	}

	return retorno;
}
/// @fn int Passenger_getCodigoVuelo(Passenger*, char*)
/// @brief Obtener el codigo de vuelo de un Passenger
///
/// @pre
/// @post
/// @param this
/// @param codigoVuelo
/// @return -1 si alguno de los parámetros es NULL, 0 si salio todo bien
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno;
	retorno = -1;

	if(this != NULL && codigoVuelo != NULL)
	{
		strncpy(codigoVuelo,this->codigoVuelo,TAM_CODIGOVUELO);
		retorno = 0;
	}

	return retorno;
}

/// @fn int Passenger_setTipoPasajero(Passenger*, char*)
/// @brief Colocar el tipo de Pasajero a un Passenger
///
/// @pre
/// @post
/// @param this
/// @param tipoPasajero
/// @return -1 si alguno de los parámetros es NULL, 0 si salio todo bien
int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int retorno;
	retorno = -1;

	if(this != NULL && tipoPasajero != NULL)
	{
		strncpy(this->tipoPasajero,tipoPasajero,TAM_TIPOPASAJERO);
		retorno = 0;
	}

	return retorno;
}

/// @fn int Passenger_getTipoPasajero(Passenger*, char*)
/// @brief Obtener un tipo de Pasajero de Passenger
///
/// @pre
/// @post
/// @param this
/// @param tipoPasajero
/// @return -1 si alguno de los parámetros es NULL, 0 si salio todo bien
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int retorno;
	retorno = -1;

	if(this != NULL && tipoPasajero != NULL)
	{
		strncpy(tipoPasajero,this->tipoPasajero,TAM_TIPOPASAJERO);
		retorno = 0;
	}

	return retorno;
}

/// @fn int Passenger_setPrecio(Passenger*, float)
/// @brief Colocar el precio de vuelo de un Passenger
///
/// @pre
/// @post
/// @param this
/// @param precio
/// @return -1 si alguno de los parámetros es NULL o el precio es menor a 0, 0 si salio todo bien
int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno;
	retorno = -1;

	if(this != NULL && precio>0)
	{
		this->precio = precio;
		retorno = 0;
	}

	return retorno;
}

/// @fn int Passenger_getPrecio(Passenger*, float*)
/// @brief Obtener el precio de un vuelo
///
/// @pre
/// @post
/// @param this
/// @param precio
/// @return -1 si alguno de los parámetros es NULL, 0 si salio todo bien
int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno;
	retorno = -1;

	if(this != NULL)
	{
		*precio = this->precio;
		retorno = 0;
	}

	return retorno;
}

/// @fn int Passenger_setEstadoVuelo(Passenger*, char*)
/// @brief Colocar el estado de vuelo a un Passenger
///
/// @pre
/// @post
/// @param this
/// @param estadoVuelo
/// @return -1 si alguno de los parámetros es NULL, 0 si salio todo bien
int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int retorno;
	retorno = -1;

	if(this != NULL && estadoVuelo != NULL)
	{
		strncpy(this->estadoVuelo,estadoVuelo,TAM_ESTADOVUELO);
		retorno = 0;
	}

	return retorno;
}
/// @fn int Passenger_getEstadoVuelo(Passenger*, char*)
/// @brief Obtener el estado de vuelo de un Passenger
///
/// @pre
/// @post
/// @param this
/// @param estadoVuelo
/// @return -1 si alguno de los parámetros es NULL, 0 si salio todo bien
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int retorno;
	retorno = -1;

	if(this != NULL && estadoVuelo != NULL)
	{
		strncpy(estadoVuelo,this->estadoVuelo,TAM_ESTADOVUELO);
		retorno = 0;
	}

	return retorno;
}


/// @fn int Passenger_printOne(Passenger*)
/// @brief Imprimir un Passenger
///
/// @pre
/// @post
/// @param this
/// @return -1 si los parámetros o los buffersauxiliares son NULL, -2 si alguna de las fuciones de obtener datos falla,
/// 0 si salio todo bien
int Passenger_printOne(Passenger* this)
{
	int retorno;
	retorno = -1;
	int auxId;
	char auxNombre[TAM_NOMBRE];
	char auxApellido[TAM_APELLIDO];
	float auxPrecio;
	char auxTipoPasajero[TAM_TIPOPASAJERO];
	char auxEstadoVuelo[TAM_ESTADOVUELO];
	char auxCodigoVuelo[TAM_CODIGOVUELO];

	if(this != NULL && auxNombre!= NULL && auxApellido != NULL && auxTipoPasajero != NULL && auxEstadoVuelo != NULL &&
			auxCodigoVuelo != NULL)
	{
		//id,name,lastname,price,flycode,typePassenger,statusFlight
		retorno = -2;
		if(!Passenger_getId(this, &auxId) && !Passenger_getNombre(this, auxNombre) && !Passenger_getApellido(this, auxApellido) && !Passenger_getPrecio(this, &auxPrecio) &&
				!Passenger_getCodigoVuelo(this, auxCodigoVuelo) && !Passenger_getTipoPasajero(this, auxTipoPasajero) && !Passenger_getEstadoVuelo(this, auxEstadoVuelo))
		{
			printf("%10d | %15s | %15s | %10.2f | %15s | %15s | %15s\n",auxId,auxNombre,auxApellido,auxPrecio,auxTipoPasajero,auxEstadoVuelo,auxCodigoVuelo);
			retorno = 0;
		}


		retorno = 0;
	}
	return retorno;
}

int Passenger_setNewId(Passenger* this , char* path)
{
	int retorno;
	char bufferAuxId[TAM_BUFFER];
	int ultimoid;
	retorno = -1;


	if(this != NULL && path != NULL)
	{
		retorno = -2;
		FILE* pArchivoUltimoId = fopen(path,"r");
		if(pArchivoUltimoId != NULL)
		{
			fscanf(pArchivoUltimoId,"%[^,],",bufferAuxId);
		}
		fclose(pArchivoUltimoId);

		if(!EsNumerica(bufferAuxId))
		{
			ultimoid = atoi(bufferAuxId)+1;
			Passenger_setId(this, ultimoid);
			FILE* pArchivoUltimoId = fopen(path,"w");
			retorno = -3;
			if(pArchivoUltimoId != NULL)
			{
				fprintf(pArchivoUltimoId,"%d,",ultimoid);
				retorno = 0;
			}
			fclose(pArchivoUltimoId);
		}
	}

	return retorno;
}

int Passenger_writeOnetxt(Passenger* this, char* path)
{
	int retorno;
	int id;
	char nombre[TAM_NOMBRE];
	char apellido[TAM_APELLIDO];
	char codigoVuelo[TAM_CODIGOVUELO];
	char tipoPasajero[TAM_TIPOPASAJERO];
	float precio;
	char estadoVuelo[TAM_ESTADOVUELO];

	retorno = -1;
	if(this != NULL && path != NULL)
	{
		retorno = -2;
		if(nombre != NULL && apellido != NULL && codigoVuelo != NULL && tipoPasajero != NULL && estadoVuelo != NULL)
		{
			retorno = -3;
			if(!Passenger_getId(this, &id) && !Passenger_getNombre(this, nombre) &&
					!Passenger_getApellido(this, apellido) && !Passenger_getCodigoVuelo(this, codigoVuelo) &&
					!Passenger_getTipoPasajero(this, tipoPasajero) && !Passenger_getPrecio(this, &precio) &&
					!Passenger_getEstadoVuelo(this, estadoVuelo))
			{
				retorno = -4;
				FILE* pArchivo = fopen(path,"a");
				if(pArchivo != NULL)
				{
					//id,name,lastname,price,flycode,typePassenger,statusFlight
					fprintf(pArchivo,"%d,%s,%s,%.2f,%s,%s,%s",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);
					retorno = 0;
				}
				fclose(pArchivo);

			}

		}

	}


	return retorno;
}



