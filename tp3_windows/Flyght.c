/*
 * Flight.c
 *
 *  Created on: 10 may. 2022
 *      Author: Emanuel
 */
#include "Flyght.h"

/// @fn sFlyght Flyght_new*()
/// @brief Crea un puntero a estructura con memoria dinámica
///
/// @pre
/// @post
/// @return Puntero a estructura
sFlyght* Flyght_new()
{
	sFlyght* p;
	p = (sFlyght*)malloc(sizeof(sFlyght));
	return p;
}

/// @fn sFlyght Flyght_newParametros*(char*, char*)
/// @brief Cargar de datos un puntero a estructura con memoria dinámica
///
/// @pre
/// @post
/// @param codigoVuelo
/// @param estadoVuelo
/// @return Puntero con memoria dinámica
sFlyght* Flyght_newParametros(char* codigoVuelo,char* estadoVuelo)
{

	sFlyght* pVuelo;
	if(codigoVuelo != NULL && estadoVuelo != NULL)
	{

		pVuelo = Flyght_new();
		if(!Flyght_setCodigoVuelo(pVuelo, codigoVuelo) && !Flyght_setEstadoVuelo(pVuelo, estadoVuelo))
		{


		}
		else
		{
			pVuelo = NULL;
		}

	}


	return pVuelo;
}

/// @fn int Flyght_setCodigoVuelo(sFlyght*, char*)
/// @brief Cargar codigo de vuelo a estructura Vuelo
///
/// @pre
/// @post
/// @param this Puntero a Vuelo
/// @param codigoVuelo
/// @return -1 si alguno de los parámetros es NULL, 0 si salio todo bien
int Flyght_setCodigoVuelo(sFlyght* this,char* codigoVuelo)
{
	int retorno;
	retorno = -1;
	if(this != NULL && codigoVuelo != NULL)
	{
		strncpy(this->flycode,codigoVuelo,TAM_CODIGOVUELO);
		retorno = 0;
	}
	return retorno;
}

/// @fn int Flyght_getCodigoVuelo(sFlyght*, char*)
/// @brief Tomar el código de vuelo de un vuelo
///
/// @pre
/// @post
/// @param this
/// @param codigoVuelo
/// @return -1 si alguno de los parámetros es NULL, 0 si salio todo bien
int Flyght_getCodigoVuelo(sFlyght* this,char* codigoVuelo)
{
	int retorno;
	retorno = -1;
	if(this != NULL && codigoVuelo != NULL)
	{
		strncpy(codigoVuelo,this->flycode,TAM_CODIGOVUELO);
		retorno = 0;
	}
	return retorno;
}

/// @fn int Flyght_setEstadoVuelo(sFlyght*, char*)
/// @brief Cargar Estado de vuelo a estructura Vuelo
///
/// @pre
/// @post
/// @param this
/// @param estadoVuelo
/// @return -1 si alguno de los parámetros es NULL, 0 si salio todo bien
int Flyght_setEstadoVuelo(sFlyght* this,char* estadoVuelo)
{
	int retorno;
	retorno = -1;
	if(this != NULL && estadoVuelo != NULL)
	{
		if(!strncmp("Aterrizado",estadoVuelo,TAM_ESTADOVUELO))
		{
			this->status = ATERRIZADO;
		}
		else
		{
			if(!strncmp("Demorado",estadoVuelo,TAM_ESTADOVUELO))
			{
				this->status = DEMORADO;
			}
			else
			{
				if(!strncmp("En Horario",estadoVuelo,TAM_ESTADOVUELO))
				{
					this->status = EN_HORARIO;
				}
				else
				{
					if(!strncmp("En Vuelo",estadoVuelo,TAM_ESTADOVUELO))
					{
						this->status = EN_VUELO;
					}
					else
					{
						this->status = -1;
					}
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}

/// @fn int Flyght_getEstadoVuelo(sFlyght*, int*)
/// @brief Tomar el Estado de vuelo de un vuelo
///
/// @pre
/// @post
/// @param this
/// @param estadoVuelo
/// @return -1 si alguno de los parámetros es NULL, 0 si salio todo bien
int Flyght_getEstadoVuelo(sFlyght* this,int* estadoVuelo)
{
	int retorno;
	retorno = -1;

	if(this != NULL && estadoVuelo != NULL)
	{
		*estadoVuelo = this->status;
		retorno = 0;
	}

	return retorno;

}

/// @fn int Flyght_printOne(sFlyght*)
/// @brief Imprimir un vuelo
///
/// @pre
/// @post
/// @param this
/// @return -1 si el parámetro, o los buffers son NULL, -2 si no se pudieron tomar correctamente los datos del vuelo,
/// -3 el estado de vuelo es <0, 0 si salio todo bien
int Flyght_printOne(sFlyght* this)
{
	int retorno;
	retorno = -1;
	int auxEstadoVuelo;
	char bufferEstadoVuelo[TAM_ESTADOVUELO];
	char auxCodigoVuelo[TAM_CODIGOVUELO];

	if(this != NULL && bufferEstadoVuelo != NULL && auxCodigoVuelo != NULL)
	{

		retorno = -2;
		if(!Flyght_getCodigoVuelo(this, auxCodigoVuelo) && !Flyght_getEstadoVuelo(this, &auxEstadoVuelo))
		{
			retorno = -3;
			if(auxEstadoVuelo>0)
			{
				switch(auxEstadoVuelo)
				{
				case ATERRIZADO:
					strncpy(bufferEstadoVuelo,"Aterrizado",TAM_ESTADOVUELO);
					break;
				case DEMORADO:
					strncpy(bufferEstadoVuelo,"Demorado",TAM_ESTADOVUELO);
					break;
				case EN_HORARIO:
					strncpy(bufferEstadoVuelo,"En Horario",TAM_ESTADOVUELO);
					break;
				case EN_VUELO:
					strncpy(bufferEstadoVuelo,"En Vuelo",TAM_ESTADOVUELO);
					break;
				}
				printf("%15s | %15s\n",auxCodigoVuelo,bufferEstadoVuelo);
				retorno = 0;
			}

		}

	}
	return retorno;
}

/// @fn int sFlyght_findFlyghtById(LinkedList*, char[])
/// @brief Buscar indice de Vuelo en lista según codigo de vuelo
///
/// @pre
/// @post
/// @param pArrayVuelos
/// @param idFlyght
/// @return -1 si alguno de los parámetros es NULL, -2 si no encontró ningún vuelo,
/// 0 o <0 indicando el indice;
int sFlyght_findFlyghtById(LinkedList* pArrayVuelos,char idFlyght[])
{
	int retorno;
	int i;
	int retornocomp;
	int tamLista;
	char bufferFlycode[TAM_CODIGOVUELO];
	sFlyght* pAux;
	retorno = -1;

	if(pArrayVuelos != NULL && idFlyght != NULL)
	{
		retorno = -2;
		tamLista = ll_len(pArrayVuelos);
		for(i = 0;i<tamLista;i++)
		{
			pAux = ll_get(pArrayVuelos, i);
			Flyght_getCodigoVuelo(pAux, bufferFlycode);
			retornocomp = strncmp(bufferFlycode,idFlyght,TAM_CODIGOVUELO);
			if(retornocomp == 0)
			{
				retorno = i;
				break;
			}
		}

	}
	return retorno;
}
