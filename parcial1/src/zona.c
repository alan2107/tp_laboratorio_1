#include "Zona.h"


/// @brief
///
/// @param zonasCenso
/// @param largo
/// @return
int inicializarZonasCenso(Zona *zonas, int largo) {
	int retorno = -1;
	if(zonas != NULL && largo > 0) {
		for(int i = 0; i < largo; i++) {
			zonas[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}


/// @brief
///
/// @param zonasCenso
/// @param largo
/// @param id
/// @param calle1
/// @param calle2
/// @param calle3
/// @param calle4
/// @param localidad
/// @return
int agregarZonaCenso(Zona *zonas, int largo, int id, char calle1[], char calle2[], char calle3[], char calle4[], int localidad) {
	int retorno = -1;
	if(zonas != NULL && largo > 0 && id > 0 && calle1 != NULL && calle2 != NULL && calle3 != NULL && calle4 != NULL && localidad >= 1000) {
		for(int i = 0; i < largo; i++) {
			if(zonas[i].isEmpty == TRUE) {
				zonas[i].idZona = id;
				strncpy(zonas[i].manzana[0], calle1, sizeof(zonas[i].manzana[0]));
				strncpy(zonas[i].manzana[1], calle2, sizeof(zonas[i].manzana[1]));
				strncpy(zonas[i].manzana[2], calle3, sizeof(zonas[i].manzana[2]));
				strncpy(zonas[i].manzana[3], calle4, sizeof(zonas[i].manzana[3]));
				switch(localidad) {
				case 1000:
					strncpy(zonas[i].localidad, "LOMAS", sizeof(zonas[i].localidad));
					break;
				case 1001:
					strncpy(zonas[i].localidad, "LANUS", sizeof(zonas[i].localidad));
					break;
				case 1002:
					strncpy(zonas[i].localidad, "BANFIELD", sizeof(zonas[i].localidad));
					break;
				case 1003:
					strncpy(zonas[i].localidad, "TEMPERLEY", sizeof(zonas[i].localidad));
					break;
				case 1004:
					strncpy(zonas[i].localidad, "KORN", sizeof(zonas[i].localidad));
					break;
				case 1005:
					strncpy(zonas[i].localidad, "BURZACO", sizeof(zonas[i].localidad));
					break;
				case 1006:
					strncpy(zonas[i].localidad, "QUILMES", sizeof(zonas[i].localidad));
					break;
				case 1007:
					strncpy(zonas[i].localidad, "AVELLANEDA", sizeof(zonas[i].localidad));
					break;
				case 1008:
					strncpy(zonas[i].localidad, "LAVALLOL", sizeof(zonas[i].localidad));
					break;
				case 1009:
					strncpy(zonas[i].localidad, "LUISGUILLON", sizeof(zonas[i].localidad));
					break;
				}
				zonas[i].estadoZonaCenso = PENDIENTE;
				zonas[i].isEmpty = FALSE;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


/// @brief
///
/// @param zonasCenso
/// @param largo
/// @return
int hayZonasDeCenso(Zona *zonas, int largo) {
	int retorno = -1;
	if(zonas != NULL && largo > 0) {
		for(int i = 0; i < largo; i++) {
			if(zonas[i].isEmpty == FALSE) {
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


/// @brief
///
/// @param zonasCenso
/// @param largo
/// @param id
/// @return
int encontrarZonaCensoPendientePorId(Zona *zonas, int largo, int id) {
	int retorno = -1;
	if(zonas != NULL && largo > 0 && id > 0) {
		for(int i = 0; i < largo; i++) {
			if(zonas[i].isEmpty == FALSE && zonas[i].estadoZonaCenso == PENDIENTE && zonas[i].idZona == id) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
