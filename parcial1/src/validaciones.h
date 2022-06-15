#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

#define FALSE 0
#define TRUE 1

void pressAnyKey(char *message);
void error(char *errorMessage, char *anyKeyMessage);

int getInt(int *entrada, char *mensaje, char *mensajeError, int minimo, int maximo, int intentos);
int getFloat(float *entry, char *message, char *errorMessage, float minimum, float maximum, int attempts);
int getWords(char *entry, int lenght, char *message, char *errorMessage, int attempts);
int getCode(char entrada[], int len, char *mensaje, char *errorMensaje, int intentos);

int substraerNumero(float *resultado, float numero, float numeroSubstraido);
int divisionDeCalculos(float *resultado, float dividendo, float divisor);
int calcularPorcentaje(float *resultado, float numero, float porcentaje);

#endif /* VALIDACIONES_H_ */
