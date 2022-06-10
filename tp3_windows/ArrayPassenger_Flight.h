/*
 * ArrayPassenger_Flight.h
 *
 *  Created on: 10 may. 2022
 *      Author: Emanuel
 */

#ifndef ARRAYPASSENGER_FLIGHT_H_
#define ARRAYPASSENGER_FLIGHT_H_
#include "Passenger.h"
#include "Flyght.h"
#define TAM_CODIGOVUELO 20
#define TAM_ESTADOVUELO 20
#define TAM_TIPOPASAJERO 20
#define TAM_APELLIDO 50
#define TAM_NOMBRE 50
#define TAM_BUFFER 100

int Passenger_InputsDataPassenger(LinkedList* pArrayPassenger,LinkedList* pArrayVuelos,char mensajeError[]);
int Passenger_sortPassengerByLastName(LinkedList* this, int order);
//Passenger* Passenger_InputsDataPassenger(LinkedList* pArrayPassenger,LinkedList* pArrayVuelos,char mensajeError[]);
/*int sPassenger_addPassengerFlyghtStatus(sPassenger passenger[],int lenPassenger, sFlyght listFlyghts[],int lenflyghts);
int sPassenger_Modification(sPassenger * list,int len,int id,sFlyght listFlyght[],int lenFlyghts);*/




#endif /* ARRAYPASSENGER_FLIGHT_H_ */
