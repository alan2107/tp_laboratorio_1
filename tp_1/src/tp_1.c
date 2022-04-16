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
	int opcionMenu, kilometros, validacionDeRetorno,kilometrosForzados,maximoNumeroDeReintento,flagCalculos;
	float bitcoin,precioDeAerolineas, precioDeLatam, diferenciaDePrecios,precioUnitario, descuento ,
	interes,ingresoAerolineas,ingresoLatam,precioDebitoAerolineas,precioDebitoLatam,precioCreditoAerolineas
	,precioCreditoLatam,precioConBitCoinAerolineas,precioConBitCoinLatam, diferenciaPrecio,
	precioAerolineaForzado,precioLatamForzado,precioUnitarioAerolineas,precioUnitarioLatam;

	flagCalculos = 0;
	precioAerolineaForzado= 162965;
	precioLatamForzado = 159339;
	maximoNumeroDeReintento = 3;
	kilometros = 0;
	kilometrosForzados = 7090;
	precioDeAerolineas= 0;
	precioDeLatam = 0;
	bitcoin = 4606954.55;
	descuento = 0.1;
	interes = 0.25;
	ingresoAerolineas = 0;
	ingresoLatam = 0;
	opcionMenu = 0;

	while(opcionMenu != 6){
		utn_GetInt(&opcionMenu,
				"MENU DE VUELO\n\n1-Ingrese Kilometros\n2-Ingrese precio de vuelo\n3-calcular costo\n4-Informar Resultado\n5-carga forzada de datos\n6-salir\n",
				"Error, ingrese correctamente una opcion valida",1, 2);

			switch (opcionMenu) {

			case 1:
				utn_GetInt(&kilometros,
								"Ingrese kilometros","error, ingrese kilometros de nuevo", 0, 3);
				break;

			case 2:
				if(kilometros == 0){
					printf("ingrese los kilometros en la opcion 1\n");
					break;
				}
				getFloat(&ingresoAerolineas ,"ingrese precio de aerolineas","Error, ingrese precio de aerolineas", 0,maximoNumeroDeReintento);
				getFloat(&ingresoLatam ,"ingrese precio de Latam","Error, ingrese precio de Latam", 0,maximoNumeroDeReintento);

				break;
			case 3:
				if(ingresoAerolineas == 0 || ingresoLatam == 0){
					printf("ingrese los precios en la opcion 2\n");
					break;
								}
					getDiscount(&ingresoAerolineas, &descuento, &precioDebitoAerolineas);
					getDiscount(&ingresoLatam, &descuento, &precioDebitoLatam);

					getPriceWithInteres(&ingresoAerolineas, &descuento, &precioCreditoAerolineas);
					getPriceWithInteres(&ingresoLatam, &descuento, &precioCreditoLatam);

					getBitcoinPrice(&ingresoAerolineas, &bitcoin,&precioConBitCoinAerolineas);
					getBitcoinPrice(&ingresoLatam, &bitcoin,&precioConBitCoinLatam);

					getUnitPrice(&ingresoAerolineas, &kilometros, &precioUnitarioAerolineas);
					getUnitPrice(&ingresoLatam, &kilometros, &precioUnitarioLatam);

					printf("precio por kilometros a Aerolineas: $ %.2f \n", precioUnitarioAerolineas);
					printf("precio por kilometros a latam: $ %.2f \n", precioUnitarioLatam);

					getPriceDifference( &ingresoAerolineas, &ingresoLatam, &diferenciaPrecio);
					printf("diferencia de precio: $ %.2f \n",diferenciaPrecio);

					flagCalculos = 1;

				break;
			case 4:
				if(flagCalculos == 0){
									printf("ejecute los calculos en la opcion 3\n");
									break;
												}
					printf("AEROLINEAS \n");
				    printf("precio: %.2f\n" ,ingresoAerolineas);
					printf("precio con tarjeta de debito : %.2f\n" ,precioDebitoAerolineas);
					printf("precio con tarjeta de credito : %.2f\n" ,precioCreditoAerolineas);
					printf("precio pagando con Bitcoin : %f\n" ,precioConBitCoinAerolineas );
					printf("Precio Unitario : %.2f\n" ,precioUnitarioAerolineas);

					printf("LATAM \n");
					printf("precio: %.2f\n" ,ingresoLatam);
					printf("precio con tarjeta de debito : %.2f\n" ,precioDebitoLatam);
					printf("precio con tarjeta de credito : %.2f\n" ,precioCreditoLatam);
					printf("precio pagando con Bitcoin : %f\n" ,precioConBitCoinLatam);
					printf("Precio Unitario : %.2f\n" ,precioUnitarioLatam);


					printf("la diferencia de precio es: %.2f\n", diferenciaPrecio);

				break;
			case 5:
				getDiscount(&precioAerolineaForzado, &descuento, &precioDebitoAerolineas);
				getDiscount(&precioLatamForzado, &descuento, &precioDebitoAerolineas);
				getPriceWithInteres(&ingresoAerolineas, &descuento, &precioCreditoAerolineas);
				getPriceWithInteres(&ingresoLatam, &descuento, &precioCreditoLatam);
				getUnitPrice(&precioAerolineaForzado, &kilometrosForzados, &precioUnitarioAerolineas);
				getUnitPrice(&precioLatamForzado, &kilometrosForzados, &precioUnitarioLatam);
				getBitcoinPrice(&precioAerolineaForzado, &bitcoin,&precioConBitCoinAerolineas);
				getBitcoinPrice(&precioLatamForzado, &bitcoin,&precioConBitCoinLatam);

				printf("AEROLINEAS \n");
								    printf("precio: %.2f\n" ,precioAerolineaForzado);
									printf("precio con tarjeta de debito : %.2f\n" ,precioDebitoAerolineas);
									printf("precio con tarjeta de credito : %.2f\n" ,precioCreditoAerolineas);
									printf("precio pagando con Bitcoin : %f\n" ,precioConBitCoinAerolineas );
									printf("Precio Unitario : %.2f\n" ,precioUnitarioAerolineas);

									printf("LATAM \n");
									printf("precio: %.2f\n" ,precioLatamForzado);
									printf("precio con tarjeta de debito : %.2f\n" ,precioDebitoLatam);
									printf("precio con tarjeta de credito: %.2f\n" ,precioCreditoLatam);
									printf("precio pagando con Bitcoin : %f\n" ,precioConBitCoinLatam);
									printf("Precio Unitario : %.2f\n" ,precioUnitarioLatam);


									printf("la diferencia de precio es: %.2f\n", diferenciaPrecio);
				break;
			case 6:
				printf("saliendo");
				break;
			default:
				printf("Error no ingresaste el numero de menu correcto");
				break;
			}

}

	return 0;
}

