/*
1"ALTAS: Se debe permitir ingresar un pasajero calculando autom�ticamente el n�mero de Id. El resto de los campos se le pedir� al usuario."
2 "MODIFICAR: Se ingresar� el N�mero de Id, permitiendo modificar: o Nombre o Apellido o Precio o Tipo de pasajero o C�digo de vuelo"
3 "BAJA: Se ingresar� el N�mero de Id y se eliminar� el empleado del sistema."
INFORMAR:1. Listado de los pasajeros ordenados alfab�ticamente por Apellido y Tipo de pasajero."
"2. Total y promedio de los precios de los pasajes, y cu�ntos pasajeros superan el precio promedio."
"3. Listado de los pasajeros por C�digo de vuelo y estados de vuelos �ACTIVO�"
"1-NOTA: Se deber� realizar el men� de opciones y las validaciones a trav�s de funciones.
 Tener en cuenta que no se podr� ingresar a los casos 2, 3 y 4; sin antes haber realizado la carga de alg�n pasajero"
"2-NOTA: Es deseable generar una segunda entidad y utilizarla en el programa."
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Passenger.h"

#define LENPASAJEROS 2000



int main(void) {
	char opcionMenu;
	int pasajero;

while(opcionMenu != 5){
	switch(opcionMenu){

	case 1:

		printf("ALTA");
		break;
	case 2:
		printf("MODIFICAR");
		break;
	case 3:
		printf("BAJA");
		break;
	case 4:
		printf("INFORMAR");
		break;

	case 5:
		printf("saliendo");
		break;

	default:
		printf("Error no ingresaste el numero de menu correcto");
		break;
	}

}

		return 0;
	}
