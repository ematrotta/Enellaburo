/*
 * Flyght.h
 *
 *  Created on: 10 may. 2022
 *      Author: Emanuel
 */

#ifndef FLYGHT_H_
#define FLYGHT_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"
#include "Outputs.h"
#include "LinkedList.h"
#define TAM_CODIGOVUELO 20
#define TAM_ESTADOVUELO 20
#define ATERRIZADO 1
#define DEMORADO 2
#define EN_HORARIO 3
#define EN_VUELO 4



typedef struct
{
	char flycode[TAM_CODIGOVUELO];
	int status;

}sFlyght;

sFlyght* Flyght_new();
sFlyght* Flyght_newParametros(char* codigoVuelo,char* estadoVuelo);


int Flyght_setCodigoVuelo(sFlyght* this,char* codigoVuelo);
int Flyght_getCodigoVuelo(sFlyght* this,char* codigoVuelo);

int Flyght_setEstadoVuelo(sFlyght* this,char* estadoVuelo);
int Flyght_getEstadoVuelo(sFlyght* this,int* estadoVuelo);

int Flyght_printOne(sFlyght* this);
int sFlyght_findFlyghtById(LinkedList* pArrayVuelos,char idFlyght[]);


#endif /* FLYGHT_H_ */
