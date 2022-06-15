/*
 * menus.c
 *
 *  Created on: 15 jun 2022
 *      Author: alan_
 */
#include "menus.h"

void menuPrincipal(void) {
	printf("\n Menu Principal"
		   "\n 1. Cargar censista"
		   "\n 2. Modificar censista"
		   "\n 3. Dar de baja censista"
		   "\n 4. Cargar zona"
		   "\n 5. Asignar zona a censar"
		   "\n 6. Carga de datos"
		   "\n 7. Mostrar censistas"
		   "\n 8. Mostrar zonas"
		   "\n 9. Informes"
		   "\n 10. Salir del programa\n");
}

void submenuModificar(void) {
	printf("\n Sub Menu Modificar"
		   "\n1. Modificar el nombre"
		   "\n2. Modificar el apellido"
		   "\n3. Modificar la fecha de nacimiento"
		   "\n4. Modificar la edad"
		   "\n5. Modificar el domicilio"
		   "\n6. Volver al menú principal\n");
}

void submenuModificarNacimiento(void) {
	printf("\n Sub Menu Nacimiento"
		   "\n1. Modificar el día de nacimiento"
		   "\n2. Modificar el mes de nacimiento"
		   "\n3. Modificar el año de nacimiento"
		   "\n4. Volver al submenú modificación de censista\n");
}

void submenuModificarDomicilio(void) {
	printf("\n Sub Menu Domicilio"
		   "\n1. Modificar la calle del domicilio"
		   "\n2. Modificar la altura del domicilio"
		   "\n3. Volver al submenú modificación de censista\n");
}

void submenuInformar(void) {
	printf("\n1. Cantidad de censistas activos con zona pendiente"
		   "\n2. Listado de censistas ordenados alfabéticamente por apellido y nombre"
		   "\n3. Localidad con más ausentes"
		   "\n4. Censista cuya zona fue la más censada"
		   "\n5. Promedio de censos"
		   "\n6. Volver al menú principal\n");
}

void submenuInformar2(void) {
	printf("\n1. Alberti"
		   "\n2. Balcarce"
		   "\n3. Campana"
		   "\n4. Dolores"
		   "\n5. Volver al submenú Informes\n");
}

void submenuInformar5(void) {
	printf("\n1. Por censista"
		   "\n2. Por zona"
		   "\n3. Volver al submenú Informes\n");
}
