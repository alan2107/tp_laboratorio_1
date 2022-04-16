/*
 * utnEntrada.c
 *
 *  Created on: 14 abr 2022
 *      Author: alan_
 */

#include <stdio.h>
/// @brief
///
/// @param pNumeroIngresado
/// @param mensaje
/// @param mensajeError
/// @param maximo
/// @param minimo
/// @param maximoDeReintentos
/// @return
int getFloat(float * pNumeroIngresado,char * mensaje,char * mensajeError,
        float maximo, float minimo, int maximoDeReintentos){

    float auxNumeroIngresado;
    int retorno;
    retorno = -1;

    if(pNumeroIngresado != NULL && maximo >= minimo && maximoDeReintentos>= 0){
        do{
            printf("%s", mensaje);
            scanf("%f", &auxNumeroIngresado);
            maximoDeReintentos--;

            if(auxNumeroIngresado >= minimo && auxNumeroIngresado <= maximo){
                        *pNumeroIngresado = auxNumeroIngresado;
                        retorno = 0;
                        break;
            }else{
                printf("%s", mensajeError);
            }

        }while(maximoDeReintentos > 0);
    }

    return retorno;
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
int utn_GetInt(int * pNumeroIngresado,char * mensaje,char * mensajeError,
        int maximo, int minimo, int maximoDeReintentos){

    int auxNumeroIngresado;
    int retorno= -1;


    if(pNumeroIngresado != NULL && maximo >= minimo && maximoDeReintentos>= 0){
        do{
            printf("%s", mensaje);
            scanf("%d", &auxNumeroIngresado);
            maximoDeReintentos--;

            if(auxNumeroIngresado >= minimo && auxNumeroIngresado <= maximo){
                        *pNumeroIngresado = auxNumeroIngresado;
                        retorno = 0;
                        break;
            }else{
                printf("%s", mensajeError);
            }

        }while(maximoDeReintentos > 0);

    }
    return retorno;
}
