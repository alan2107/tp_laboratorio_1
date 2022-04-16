/*
 * utnCalculos.c
 *
 *  Created on: 16 abr 2022
 *      Author: alan_
 */
#include <stdio.h>

void getDiscount(float * pNumeroIngresado,float * descuento, float *resultado){
    float auxResultado;
    if(pNumeroIngresado != NULL && descuento > 0){
    	auxResultado = * pNumeroIngresado - (*pNumeroIngresado * *descuento);
    	* resultado = auxResultado;
    }

 return;
}

void getPriceWithInteres(float * pNumeroIngresado, float * interes, float * resultado){
    float auxResultado;
    if(pNumeroIngresado != NULL && interes > 0){
    	auxResultado = (*pNumeroIngresado * *interes) + * pNumeroIngresado ;
    	* resultado = auxResultado;
    }
    return;
}
void getPriceDifference(float * precioUno, float * precioDos, float * resultado){
	float auxResultado = 0;

	auxResultado = * precioUno - * precioDos;
	if(auxResultado < 0){
		auxResultado = auxResultado * -1;
	}
	* resultado = auxResultado;
	return;
}

void getBitcoinPrice(float * precio, float * precioBitcoin,float * resultado){
float auxResultado = 0;
auxResultado = *precio / *precioBitcoin;
*resultado = auxResultado;
return;
}

void getUnitPrice(float * precio, int * kilometros, float * resultado){
	float auxResultado = 0;
	auxResultado = *precio / *kilometros;
	*resultado = auxResultado;
	return;
}
