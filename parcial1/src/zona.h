#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"

#ifndef ZONA_H_
#define ZONA_H_

#define LOMAS 1000
#define LANUS 1001
#define BANFIELD 1002
#define TEMPERLEY 1003
#define KORN 1004
#define BURZACO 1005
#define QUILMES 1006
#define AVELLANEDA 1007
#define LAVALLOL 1008
#define LUISGUILLON 1009
#define PENDIENTE 3000
#define FINALIZADA 3001


struct {
	int idZona;
	char manzana[4][64];
	char localidad[64];
	int censadosPresencialmente;
	int censadosVirtualmente;
	int ausentes;
	int idCensista;
	int estadoZonaCenso;
	int isEmpty;
} typedef Zona;


int inicializarZonasCenso(Zona *zonasCenso, int largo);
int agregarZonaCenso(Zona *zonasCenso, int largo, int id, char calle1[], char calle2[], char calle3[], char calle4[], int localidad) ;
int hayZonasDeCenso(Zona *zonasCenso, int largo);
int encontrarZonaCensoPendientePorId(Zona *zonasCenso, int largo, int id);
#endif /* ZONA_H_ */
