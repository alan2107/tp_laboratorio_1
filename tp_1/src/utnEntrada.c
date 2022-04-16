/*
 * utnEntrada.c
 *
 *  Created on: 14 abr 2022
 *      Author: alan_
 */

#include <stdio.h>
#include <stdlib.h>
/// @brief
///
/// @param pNumeroIngresado
/// @param mensaje
/// @param mensajeError
/// @param maximo
/// @param minimo
/// @param maximoDeReintentos
/// @return
void getFloat(float * pNumeroIngresado,char * mensaje,char * mensajeError, float minimo, int maximoDeReintentos){

    float auxNumeroIngresado;
    if(pNumeroIngresado != NULL &&  maximoDeReintentos>= 0){
        do{
            printf("%s \n", mensaje);
            scanf("%f" ,&auxNumeroIngresado);
            printf("\n");
            maximoDeReintentos--;

            if(auxNumeroIngresado >= minimo){
                        *pNumeroIngresado = auxNumeroIngresado;
                        printf("numeroIngresado: %.2f \n", auxNumeroIngresado);
                        break;
            }else{
                printf("%s", mensajeError);
            }

        }while(maximoDeReintentos > 0);
    }

    return;
}
/// @brief
///
/// @param pNumeroIngresado
/// @param mensaje
/// @param mensajeError
/// @param maximo
/// @param minimo
/// @param maximoDeReintentos
/// @return
void utn_GetInt(int * pNumeroIngresado,char * mensaje,char * mensajeError, int minimo, int maximoDeReintentos){

    int auxNumeroIngresado;
    if(pNumeroIngresado != NULL&& maximoDeReintentos>= 0){
        do{
            printf("%s \n", mensaje);
            scanf("%d", &auxNumeroIngresado);
            printf("\n");
            maximoDeReintentos--;

            if(auxNumeroIngresado >= minimo){
                        *pNumeroIngresado = auxNumeroIngresado;
                        break;
            }else{
                printf("%s", mensajeError);
            }

        }while(maximoDeReintentos > 0);

    }
    return;
}
