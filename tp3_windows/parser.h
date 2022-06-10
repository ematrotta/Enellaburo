#include "ArrayPassenger_Flight.h"
#define TAM_BUFFER 100

int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger);
int parser_FlyghtsFromText(FILE* pFile , LinkedList* pArrayListFlyghts);
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);
