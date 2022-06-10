#include "parser.h"


int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);
int controller_loadFromTextFlyght(char* path , LinkedList* pArrayListFlyght);
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);
int controller_addPassenger(LinkedList* pArrayListPassenger,LinkedList* pArrayVuelos);
int controller_editPassenger(LinkedList* pArrayListPassenger,LinkedList* pVuelos);
int controller_removePassenger(LinkedList* pArrayListPassenger);
int controller_ListPassenger(LinkedList* pArrayListPassenger);
int controller_ListFyght(LinkedList* pArrayListFlyght);
int controller_sortPassenger(LinkedList* pArrayListPassenger);
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);


