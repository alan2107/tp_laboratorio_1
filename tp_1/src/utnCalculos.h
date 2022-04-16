/*
 * utnCalculos.h
 *
 *  Created on: 16 abr 2022
 *      Author: alan_
 */

#ifndef UTNCALCULOS_H_
#define UTNCALCULOS_H_
#include <stdio.h>

/// @brief
///
/// @param pNumeroIngresado
/// @param descuento
/// @param resultado
/// @return
void getDiscount(float * pNumeroIngresado,float * descuento, float *resultado);
/// @brief
///
/// @param pNumeroIngresado
/// @param interes
/// @param resultado
/// @return
void getPriceWithInteres(float * pNumeroIngresado, float * interes, float * resultado);

void getPriceDifference(float * precioUno, float * precioDos, float * resultado);
void getBitcoinPrice(float * precio, float * precioBitcoin,float * resultado);
void getUnitPrice(float * precio, int * kilometros, float * resultado);
#endif /* UTNCALCULOS_H_ */
