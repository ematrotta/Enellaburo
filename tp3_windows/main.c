#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{

	setbuf(stdout,NULL);
    int option = 0;
    char salida;
    int flagGuardado;
    int flagAlta;
    int flagModificacionlista;
    int retorno;
    retorno = -1;

    flagGuardado = 0;
    flagAlta = 0;
    flagModificacionlista = 0;
    LinkedList* listaPasajeros = ll_newLinkedList();
    LinkedList* listaVuelos = ll_newLinkedList();

    controller_loadFromTextFlyght("dataFlyghts.csv", listaVuelos);

    do
    {

        puts("\nMenu:\n");
        puts("1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).");
        puts("2. Cargar los datos de los pasajeros desde el archivo data.bin (modo binario).");
        puts("3. Alta de pasajero");
        puts("4. Modificar datos de pasajero");
        puts("5. Baja de pasajero");
        puts("6. Listar pasajeros");
        puts("7. Ordenar pasajeros");
        puts("8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto)");
        puts("9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).");
        puts("10. Salir");
        if(!Utn_GetNumeroInt(&option, "OPCIÓN", "Debe ser entre 1 y 10", 10, 1, 3))
        {
        	switch(option)
        	{
        	case 1:
        		if(!controller_loadFromText("data.csv", listaPasajeros))
        		{
        			flagAlta = 1;
        		}
        		break;
        	case 2:
        		//ARCHIVO BINARIO
        		if(!controller_loadFromText("data.csv", listaPasajeros))
        		{
        			flagAlta = 1;
        			flagModificacionlista = 1;
        		}
        		break;
        	case 3:
        		if(!controller_addPassenger(listaPasajeros, listaVuelos))
        		{
        			puts("\nALTA EXITOSA\n");
        			flagAlta = 1;
        			flagModificacionlista = 1;
        		}
        		break;
        	case 4:
        		if(flagAlta == 1)
        		{
        			controller_ListPassenger(listaPasajeros);
            		if(!controller_editPassenger(listaPasajeros, listaVuelos))
            		{
            			puts("\nMODIFIACIÓN EXITOSA\n");
            			flagModificacionlista = 1;
            		}
            		else
            		{
            			puts("\nNO SE PUDO MODIFICAR\n");
            		}
        		}
        		else
        		{
        			puts("\nPRIMERO DEBE REALIZAR UN ALTA AL MENOS");
        		}
        		break;
        	case 5:
        		if(flagAlta == 1)
        		{
            		controller_ListPassenger(listaPasajeros);
            		if(!controller_removePassenger(listaPasajeros))
            		{
            			puts("\nBAJA EXITOSA\n");
            			flagModificacionlista = 1;
            		}
            		else
            		{
            			puts("\nNO SE PUDO DAR DE BAJA");
            		}
        		}
        		else
        		{
        			puts("\nPRIMERO DEBE REALIZAR UN ALTA AL MENOS");
        		}

        		break;
        	case 6:
        		if(flagAlta == 1)
        		{
        			controller_ListPassenger(listaPasajeros);
        		}
        		else
        		{
        			puts("\nPRIMERO DEBE REALIZAR UN ALTA AL MENOS");
        		}
        		break;
        	case 7:
        		controller_sortPassenger(listaPasajeros);
        		break;
        	case 8:
        		if(flagModificacionlista == 1)
        		{
            		if(!controller_saveAsText("data.csv",listaPasajeros))
            		{

            		}
            		else
            		{
            			puts("\nERROR al guardar el nuevo archivo\n");
            		}
        		}
        		else
        		{
        			puts("\nNo hubo modificaciones\n");
        		}
        		flagGuardado = 1;

        		break;
        	case 9:
        		//GUARDADO EN BINARIO
        		/*if(flagModificacionlista == 1)
        		{
            		if(!controller_saveAsText("data.csv",listaPasajeros))
            		{

            		}
            		else
            		{
            			puts("\nERROR al guardar el nuevo archivo\n");
            		}
        		}
        		else
        		{
        			puts("\nNo hubo modificaciones\n");
        		}
        		flagGuardado = 1;*/

        		break;
        	case 10:
        		if(flagGuardado == 0)
        		{
        			puts("\nAntes de salir Debe seleccionar la opcion 8 o 9 para guardar el archivo\n");
        			option = 0;
        		}
        		else
        		{
            		if(!GetCharacter2Options(&salida, "Desea Salir? S/N", "ERROR. Ingrese S (si) / N (no)", 'S', 'N', 3))
            		{
            			if(salida == 's' || salida == 'S')
            			{
                			ll_deleteLinkedList(listaPasajeros);
                			ll_deleteLinkedList(listaVuelos);
            			}
            			else
            			{
            				option = 0;
            			}

            		}
        		}

        		break;
        	}

        	retorno = 0;
        }


    }while(option!= 10);
    return retorno;
}

