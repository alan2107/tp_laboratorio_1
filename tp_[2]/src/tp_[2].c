/*
1"ALTAS: Se debe permitir ingresar un pasajero calculando automáticamente el número de Id. El resto de los campos se le pedirá al usuario."
2 "MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido o Precio o Tipo de pasajero o Código de vuelo"
3 "BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema."
INFORMAR:1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero."
"2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio."
"3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’"
"1-NOTA: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
 Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la carga de algún pasajero"
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
