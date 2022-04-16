/*
 * utnCalculos.c
 *
 *  Created on: 16 abr 2022
 *      Author: alan_
 */
#include <stdio.h>
/// @brief
///
/// @param pNumeroIngresado
/// @param descuento
/// @param resultado
/// @return
int getFloat(float * pNumeroIngresado, descuento, resultado){
	float auxDescuento;
    float auxNumeroIngresado;
    float auxResultado;
    int retorno;
    auxDescuento = descuento;
    retorno = -1;

    if(pNumeroIngresado != NULL && descuento > 0 && resultado > 0){
    	auxResultado = (auxNumeroIngresado * auxDescuento) - auxNumeroIngresado;
    	* pNumeroIngresado = auxResultado;

    }

    return retorno;
}
/// @brief
///
/// @param pNumeroIngresado
/// @param interes
/// @param resultado
/// @return
int getFloat(float * pNumeroIngresado, interes, resultado){

    float auxInteres;
	float auxNumeroIngresado;
    float auxResultado;
    int retorno;
    auxInteres = interes;

    retorno = -1;

    if(pNumeroIngresado != NULL && interes > 0 && resultado > 0){
    	auxResultado = (auxNumeroIngresado * interes) + auxNumeroIngresado;
    	* pNumeroIngresado = auxResultado;
    }

    return retorno;
}
