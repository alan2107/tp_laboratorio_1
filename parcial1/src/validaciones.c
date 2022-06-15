#include "validaciones.h"


static int auxGetInt(int *entry);
static int auxGetFloat(float *entry);
static int getString(char *entry, int lenght);
static int isInt(char *string, int lenght);
static int isFloat(char *string, int lenght);

static int auxGetWords(char *entry, int lenght);
static int isWords(char *string, int len);
static int auxGetCode(char *entrada, int len);
static int esCodigo(char *string, int len);


/// @brief
///
/// @param message
void pressAnyKey(char *message) {
	char anyKey;

	if(message != NULL) {
		printf("\nPresione cualquier tecla %s", message);
		fflush(stdin);
		scanf("%c", &anyKey);
	}
}

/// @brief
///
/// @param errorMessage
/// @param anyKeyMessage
void error(char *errorMessage, char *anyKeyMessage) {
	if(errorMessage != NULL && anyKeyMessage != NULL) {
		printf("\n%s", errorMessage);
		pressAnyKey(anyKeyMessage);
	}
}


/// @brief
///
/// @param entry
/// @param message
/// @param errorMessage
/// @param minimum
/// @param maximum
/// @param attempts
/// @return
int getInt(int *entrada, char *mensaje, char *mensajeError, int minimo, int maximo, int intentos) {
	int retorno = -1;
	int auxEntrada;

	if(entrada != NULL && mensaje != NULL && mensajeError != NULL && (minimo == -1 || minimo <= maximo || maximo == -1) && (intentos == -1 || intentos > 0)) {
		do {
			printf("%s", mensaje);

			if(auxGetInt(&auxEntrada) == 0 && ((minimo == -1 && auxEntrada <= maximo) || (maximo == -1 && auxEntrada >= minimo) || (auxEntrada >= minimo && auxEntrada <= maximo))) {
				*entrada = auxEntrada;
				retorno = 0;
				break;
			}
			else {
				printf("\n%s", mensajeError);

				if(intentos == 0) {
					break;
				}
				else if(intentos != -1) {
					intentos--;
				}
			}
		} while(intentos == -1 || intentos > 0);
	}

	return retorno;
}
/// @brief
///
/// @param entry
/// @return
static int auxGetInt(int *entry) {
	int Return = -1;
	char auxEntry[64];

	if(entry != NULL && getString(auxEntry, sizeof(auxEntry)) == 0 && isInt(auxEntry, sizeof(auxEntry))) {
		*entry = atoi(auxEntry);
		Return = 0;
	}

	return Return;
}
/// @brief
///
/// @param string
/// @param lenght
/// @return
static int isInt(char *string, int lenght) {
	int Return = -1;

	if(string != NULL && lenght > 0) {
		Return = 1;

		for(int i = 0; i < lenght && string[i] != '\0'; i++) {
			if(i == 0 && (string[i] == '-' || string[i] == '+')) {
				continue;
			}
			if(string[i] < '0' || string[i] > '9') {
				Return = 0;
				break;
			}
		}
	}

	return Return;
}

/// @brief
///
/// @param entry
/// @param message
/// @param errorMessage
/// @param minimum
/// @param maximum
/// @param attempts
/// @return
int getFloat(float *entry, char *message, char *errorMessage, float minimum, float maximum, int attempts) {
	int Return = -1;
	float auxEntry;

	if(entry != NULL && message != NULL && errorMessage != NULL && (minimum == -1 || minimum <= maximum || maximum == -1) && (attempts == -1 || attempts > 0)) {
		do {
			printf("%s", message);

			if(auxGetFloat(&auxEntry) == 0 && ((minimum == -1 && auxEntry <= maximum) || (maximum == -1 && auxEntry >= minimum) || (auxEntry >= minimum && auxEntry <= maximum))) {
				*entry = auxEntry;
				Return = 0;
				break;
			}
			else {
				printf("\n%s", errorMessage);

				if(attempts == 0) {
					break;
				}
				else if(attempts != -1) {
					attempts--;
				}
			}
		} while(attempts == -1 || attempts > 0);
	}

	return Return;
}
/// @brief
///
/// @param entry
/// @return
static int auxGetFloat(float *entry) {
	int Return = -1;
	char auxEntry[64];

	if(entry != NULL && getString(auxEntry, sizeof(auxEntry)) == 0 && isFloat(auxEntry, sizeof(auxEntry))) {
		*entry = atof(auxEntry);
		Return = 0;
	}

	return Return;
}
/// @brief
///
/// @param string
/// @param lenght
/// @return
static int isFloat(char *string, int lenght) {
	int Return = -1;
	int flagPoint = FALSE;

	if(string != NULL && lenght > 0) {
		Return = 1;

		for(int i = 0; i < lenght && string[i] != '\0'; i++) {
			if(i == 0 && (string[i] == '-' || string[i] == '+')) {
				continue;
			}
			if(string[i] < '0' || string[i] > '9' ) {
				if(string[i] == '.' && flagPoint == FALSE) {
					flagPoint = TRUE;
				}
				else {
					Return = 0;
					break;
				}
			}
		}
	}

	return Return;
}

/// @brief
///
/// @param entry
/// @param lenght
/// @return
static int getString(char *entry, int lenght) {
	int Return = -1;
	char auxEntry[4096];

	if(entry != NULL && lenght > 0) {
		fflush(stdin);

		if(fgets(auxEntry, sizeof(auxEntry), stdin) != NULL) {
			if(auxEntry[strnlen(auxEntry, sizeof(auxEntry)) - 1] == '\n') {
				auxEntry[strnlen(auxEntry, sizeof(auxEntry)) - 1] = '\0';
			}
			if(strnlen(auxEntry, sizeof(auxEntry)) <= lenght) {
				strncpy(entry, auxEntry, lenght);
				Return = 0;
			}
		}
	}

	return Return;
}


/// @brief
///
/// @param entry
/// @param lenght
/// @param message
/// @param errorMessage
/// @param attempts
/// @return
int getWords(char *entry, int lenght, char *message, char *errorMessage, int attempts) {
	int Return = -1;
	char auxEntry[4096];

	if(entry != NULL && lenght > 0 && message != NULL && errorMessage != NULL && (attempts == -1 || attempts > 0)) {
		do {
			printf("%s", message);

			if(auxGetWords(auxEntry, sizeof(auxEntry)) == 0 && strnlen(auxEntry, sizeof(auxEntry)) < lenght) {
				strncpy(entry, auxEntry, lenght);
				Return = 0;
				break;
			}
			else {
				printf("\n%s", errorMessage);

				if(attempts == 0) {
					break;
				}
				else if(attempts != -1) {
					attempts--;
				}
			}
		} while(attempts == -1 || attempts > 0);
	}

	return Return;
}
/// @brief
///
/// @param entry
/// @param lenght
/// @return
static int auxGetWords(char *entrada, int len) {
	int retorno = -1;
	char auxEntry[4096];

	if(entrada != NULL && getString(auxEntry, sizeof(auxEntry)) == 0 && isWords(auxEntry, sizeof(auxEntry)) && strnlen(auxEntry, sizeof(auxEntry)) < len) {
		strncpy(entrada, auxEntry, len);
		retorno = 0;
	}

	return retorno;
}
/// @brief
///
/// @param string
/// @param lenght
/// @return
static int isWords(char *string, int len) {
	int retorno = -1;

	if(string != NULL && len > 0) {
		retorno = 1;

		for(int i = 0; i < len && string[i] != '\0'; i++) {
			if((string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z') && string[i] != ' ') {
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

/// @brief
///
/// @param entry
/// @param lenght
/// @param message
/// @param errorMessage
/// @param attempts
/// @return
int getCode(char entrada[], int len, char *mensaje, char *errorMensaje, int intentos) {
	int retorno = -1;
	char auxEntrada[4096];

	if(entrada != NULL && len > 0 && mensaje != NULL && errorMensaje != NULL && (intentos == -1 || intentos > 0)) {
		do {
			printf("%s", mensaje);

			if(auxGetCode(auxEntrada, sizeof(auxEntrada)) == 0 && strnlen(auxEntrada, sizeof(auxEntrada)) < len) {
				strncpy(entrada, auxEntrada, len);
				retorno = 0;
				break;
			}
			else {
				printf("\n%s", errorMensaje);

				if(intentos == 0) {
					break;
				}
				else if(intentos != -1) {
					intentos--;
				}
			}
		} while(intentos == -1 || intentos > 0);
	}

	return retorno;
}
/// @brief
///
/// @param entry
/// @param lenght
/// @return
static int auxGetCode(char *entrada, int len) {
	int retorno = -1;
	char auxEntrada[4096];

	if(entrada != NULL && len > 0) {
		if(getString(auxEntrada, sizeof(auxEntrada)) == 0 && esCodigo(auxEntrada, sizeof(auxEntrada)) && strnlen(auxEntrada, sizeof(auxEntrada)) < len) {
			strncpy(entrada, auxEntrada, len);
			retorno = 0;
		}
	}

	return retorno;
}
/// @brief
///
/// @param string
/// @param lenght
/// @return
static int esCodigo(char *string, int len) {
	int retorno = -1;

	if(string != NULL && len > 0) {
		retorno = 1;

		for(int i = 0; i < len && string[i] != '\0'; i++) {
			if((string[i] < '0' || string[i] > '9' ) && (string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z')) {
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}


/// @brief
///
/// @param result
/// @param number
/// @param numberSubtracted
/// @return
int substraerNumero(float *resultado, float numero, float numeroSubstraido) {
	int retorno = -1;

	if(resultado != NULL && numeroSubstraido != 0) {
		*resultado = numero - numeroSubstraido;
		retorno = 0;
	}

	return retorno;
}

/// @brief
///
/// @param result
/// @param dividend
/// @param divider
/// @return
int divisionDeCalculos(float *resultado, float dividendo, float divisor) {
	int retorno = -1;

	if(resultado != NULL && divisor != 0) {
		*resultado = dividendo / divisor;
		retorno = 0;
	}

	return retorno;
}

/// @brief
///
/// @param result
/// @param number
/// @param percentage
/// @return
int calcularPorcentaje(float *resultado, float numero, float porcentaje) {
	int retorno = -1;

	if(resultado != NULL && porcentaje != 0) {
		*resultado = numero + (numero * porcentaje / 100);
		retorno = 0;
	}

	return retorno;
}
