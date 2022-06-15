#include "Informes.h"


/// @brief
///
/// @param zonasCenso
/// @param censistas
/// @param largo
/// @return
int printZonasCenso(Zona *zonas, Censista *censistas, int largo) {
	int retorno = -1;
	int flagCensistaEncontrado = FALSE;
	if(zonas != NULL && censistas != NULL && largo > 0) {
		for(int i = 0; i < largo; i++) {
			if(zonas[i].isEmpty == FALSE) {
				printf("\nID: %d | Manzana: %s, %s, %s, %s | Localidad: %s | Censista: ", zonas[i].idZona, zonas[i].manzana[0], zonas[i].manzana[1], zonas[i].manzana[2], zonas[i].manzana[3], zonas[i].localidad);
				for(int j = 0; j < MAX_CENSISTAS; j++) {
					if(censistas[j].isEmpty == FALSE && zonas[i].idCensista == censistas[j].idCensista) {
						printf("%s %s", censistas[j].nombre, censistas[j].apellido);
						flagCensistaEncontrado = TRUE;
						break;
					}
				}
				if(flagCensistaEncontrado == FALSE) {
					printf("SIN ASIGNAR");
				}
				printf(" | Presenciales: %d | Virtuales: %d | Ausentes: %d | Estado: ", zonas[i].censadosPresencialmente, zonas[i].censadosVirtualmente, zonas[i].ausentes);
				switch(zonas[i].estadoZonaCenso) {
				case 3000:
					printf("PENDIENTE");
					break;
				case 3001:
					printf("FINALIZADA");
					break;
				}
			}
		}
	}
	return retorno;
}


int informar1(Censista *censistas, Zona *zonas, int largo) {
	int retorno = -1;
	int contadorInforme1 = 0;

	if(censistas != NULL && zonas != NULL && largo > 0) {
		for(int i = 0; i < largo; i++) {
			if(zonas[i].isEmpty == FALSE && zonas[i].estadoZonaCenso == PENDIENTE) {
				for(int j = 0; j < largo; j++) {
					if(censistas[j].isEmpty == FALSE && zonas[i].idCensista == censistas[j].idCensista) {
						contadorInforme1++;
					}
				}
			}
		}
		printf("\nCantidad de censistas activos con zona pendiente: %d\n", contadorInforme1);
		retorno = 0;
	}
	return retorno;
}

int informar3(Zona *zonas, int largo) {
	int retorno = -1;
	int flagInforme3 = 0;
	int ausentesInforme3;
	char localidadInforme3[64];
	if(zonas != NULL && largo > 0) {
		for(int i = 0; i < largo; i++) {
			if(zonas[i].isEmpty == FALSE) {
				if(flagInforme3 == 0) {
					ausentesInforme3 = zonas[i].ausentes;
					strncpy(localidadInforme3, zonas[i].localidad, sizeof(localidadInforme3));
					flagInforme3 = 1;
				}
				if(flagInforme3 == 1 && zonas[i].ausentes > ausentesInforme3) {
					strncpy(localidadInforme3, zonas[i].localidad, sizeof(localidadInforme3));
					ausentesInforme3 = zonas[i].ausentes;
				}
			}
		}
		printf("Localidad con más ausentes: %s con %d\n", localidadInforme3, ausentesInforme3);
	}
	return retorno;
}

int informar4(Zona *zonas, Censista *censistas, int largo) {
	int retorno = -1;
	int censadosTotal;
	int flagInforme4 = 0;
	int censadosInforme4;
	int censistaInforme4;
	if(zonas != NULL && censistas != NULL && largo > 0) {
		for(int i = 0; i < largo; i++) {
			if(zonas[i].isEmpty == FALSE) {
				censadosTotal = zonas[i].censadosPresencialmente + zonas[i].censadosVirtualmente;
				if(flagInforme4 == 0) {
					censadosInforme4 = censadosTotal;
					censistaInforme4 = zonas[i].idCensista;
					flagInforme4 = 1;
				}
				if(flagInforme4 == 1 && censadosTotal > censadosInforme4) {
					censistaInforme4 = zonas[i].idCensista;
					censadosInforme4 = censadosTotal;
				}
			}
		}
		for(int i = 0; i < largo; i++) {
			if(censistas[i].isEmpty == FALSE && censistas[i].idCensista == censistaInforme4) {
				printf("Censista cuya zona fue la más censada: %s %s con %d censados\n", censistas[i].nombre, censistas[i].apellido, censadosInforme4);
				break;
			}
		}
	}
	return retorno;
}
