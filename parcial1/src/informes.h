#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "Censista.h"
#include "Zona.h"

#ifndef INFORMES_H_
#define INFORMES_H_


int printZonasCenso(Zona *zonasCenso, Censista *censistas, int largo);


int informar1(Censista *censistas, Zona *zonasCenso, int largo);
int informar3(Zona *zonas, int largo);
int informar4(Zona *zonas, Censista *censistas, int largo);

#endif /* INFORMES_H_ */
