/*Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerolíneas Argentinas para ofrecerlos a sus clientes.
 Se deberá ingresar por cada vuelo los km totales y el precio total del mismo.  El objetivo de la aplicación es mostrar las diferentes opciones de pagos
 a sus clientes.
 Para ello el programa iniciará y contará con un menú de opciones:
 1. Ingresar Kilómetros: ( km=x)

 2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)
 - Precio vuelo Aerolíneas:
 - Precio vuelo Latam:

 3. Calcular todos los costos:
 a) Tarjeta de débito (descuento 10%)
 b) Tarjeta de crédito (interés 25%)
 c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
 d) Mostrar precio por km (precio unitario)
 e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)
 4. Informar Resultados
 “Latam:
 a) Precio con tarjeta de débito: r
 b) Precio con tarjeta de crédito: r
 c) Precio pagando con bitcoin : r
 d) Precio unitario: r
 Aerolíneas:
 a) Precio con tarjeta de débito: r
 b) Precio con tarjeta de crédito: r
 c) Precio pagando con bitcoin : r
 d) Precio unitario: r
 La diferencia de precio es : r “
 5. Carga forzada de datos
 6. Salir
 */

#include <stdio.h>
#include <stdlib.h>
#include "utnEntrada.h"

int main(void) {
	setbuf(stdout, NULL);
	int opcionMenu,kilometros, validacionDeRetorno,kilometrosForzados;
	float tarjetaDeDebito, tarjetaDeCredito, bitcoin,precioDeAerolineas, precioDeLatam, diferenciaDePrecios;
	char y , z;

	kilometros = 0;
	kilometrosForzados = 10000;
	precioDeAerolineas= 10000;
	precioDeLatam = 15000;
	bitcoin = 4606954.55;


	do {
		validacionDeRetorno = utn_GetInt(&opcionMenu,
				"MENU DE VUELO\n\n1-Ingrese Kilometros\n2-Ingrese precio de vuelo\n3-calcular costo\n4-Informar Resultado\n5-carga forzada de datos\n",
				"Error, ingrese correctamente una opcion valida", 3, 1, 2);
		if (!validacionDeRetorno) {
			switch (opcionMenu) {

			case 1:
				validacionDeRetorno = utn_GetInt(&kilometros,
								"Ingrese kilometros","error, ingrese kilometros de nuevo", 16000, 0, 3);
				break;

			case 2:
				validacionDeRetorno = utn_GetInt(&opcionMenu,
								"1-Ingrese precio de vuelos",
								"Error, ingrese precio de vuelos correctamente", 3, 1, 2);
				break;
			case 3:
				if(precioDeLatam == tarjetaDeDebito){
				tarjetaDeDebito = (precioDeLatam * 0.1) - precioDeLatam;
				}else if(precioDeAerolineas == tarjetaDeDebito){
					tarjetaDeDebito = (precioDeAerolineas * 0.1) - precioDeAerolineas;
				}

				if(precioDeLatam == tarjetaDeCredito){
				tarjetaDeCredito = (precioDeLatam * 0.25) + precioDeLatam;
				}else if(precioDeAerolineas == tarjetaDeCredito){
					tarjetaDeCredito = (precioDeAerolineas * 0.25) + precioDeAerolineas;
				}

				if(precioDeAerolineas == bitcoin){
					precioDeAerolineas = precioDeAerolineas * bitcoin;
				}else if(precioDeLatam == bitcoin){
					precioDeLatam = precioDeLatam * bitcoin;
				}

				if(y == precioDeAerolineas){
					kilometros++;
					precioDeAerolineas = precioDeAerolineas * kilometros;
				}else if(z == precioDeLatam){
					kilometros++;
					precioDeLatam = precioDeLatam * kilometros;
				}
				if(diferenciaDePrecios == precioDeAerolineas && diferenciaDePrecios == precioDeLatam ){
					diferenciaDePrecios = precioDeAerolineas - precioDeLatam;
				}

				break;
			case 4:
				printf("informar resultados");

				break;
			case 5:
				printf("carga forzada de datos");

				break;
			}
		}
	} while (opcionMenu != 6);

	return 0;
}

