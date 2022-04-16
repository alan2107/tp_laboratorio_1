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
#include "utnCalculos.h"

int main(void) {
	setbuf(stdout, NULL);
	int opcionMenu,kilometros, validacionDeRetorno,kilometrosForzados;
	float tarjetaDeDebito, tarjetaDeCredito, bitcoin,precioDeAerolineas, precioDeLatam, diferenciaDePrecios,precioUnitario, descuento ,interes;
	char y , z;

	kilometros = 0;
	kilometrosForzados = 10000;
	precioDeAerolineas= 10000;
	precioDeLatam = 15000;
	bitcoin = 4606954.55;
	descuento = 0.1;
	interes = 0.25;

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
				if(y == precioDeAerolineas){
									kilometros++;
									precioDeAerolineas = precioDeAerolineas * kilometros;
								}else if(z == precioDeLatam){
									kilometros++;
									precioDeLatam = precioDeLatam * kilometros;
								}
				break;
			case 3:
				getFloat(&precioDeAerolineas, descuento, tarjetaDeDebito);
				getFloat(&precioDeLatam, descuento, tarjetaDeDebito);

				getFloat(&precioDeAerolineas, interes, tarjetaDeCredito);
				getFloat(&precioDeLatam, interes, tarjetaDeCredito);

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

				precioUnitario = precioDeAerolineas;
				precioUnitario = precioDeLatam;

				break;
			case 4:
				    printf("precio de Aerolineas : %f" ,precioDeAerolineas);
										printf("precio con tarjeta de debito : %f" ,tarjetaDeDebito);
										printf("precio con tarjeta de debito : %f" ,tarjetaDeCredito);
										printf("precio pagando con Bitcoin : %f" ,bitcoin);
										printf("Precio Unitario : %f" ,precioUnitario);

					printf("precio de Aerolineas : %f" ,precioDeLatam);
										printf("precio con tarjeta de debito : %f" ,tarjetaDeDebito);
										printf("precio con tarjeta de debito : %f" ,tarjetaDeCredito);
										printf("precio pagando con Bitcoin : %f" ,bitcoin);
										printf("Precio Unitario : %f" ,precioUnitario);

					printf("la diferencia de precio es: %f", diferenciaDePrecios);


				break;
			case 5:
				printf("carga forzada de datos");

				break;
			}
		}
	} while (opcionMenu != 6);

	return 0;
}

