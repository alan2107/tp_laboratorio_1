/*
 * utnEntrada.h
 *
 *  Created on: 14 abr 2022
 *      Author: alan_
 */

#ifndef UTNENTRADA_H_
#define UTNENTRADA_H_
#include <stdio.h>

int getFloat(float * pNumeroIngresado,char * mensaje,char * mensajeError,
        float maximo, float minimo, int maximoDeReintentos);

int utn_GetInt(int * pNumeroIngresado,char * mensaje,char * mensajeError,
        int maximo, int minimo, int maximoDeReintentos);

#endif /* UTNENTRADA_H_ */
