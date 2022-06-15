#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "Censista.h"
#include "Fecha.h"
#include "localidad.h"
#include "Zona.h"
#include "Informes.h"
#include "menus.h"

int main(void) {
	setbuf(stdout, NULL);
	int retorno = -1;
	Censista censistas[50];
	Zona zonasCenso[50];
	int opcion;
	int auxId;
	char auxNombre[25];
	char auxApellido[25];
	int auxDia;
	int auxMes;
	int auxAnio;
	int auxEdad;
	char auxCalle[30];
	int auxAltura;
	int idBuscado;
	int posicionCensistaEncontrada;
	int posicionZonaCensoEncontrada;
	char auxCalle1[30];
	char auxCalle2[30];
	char auxCalle3[30];
	char auxCalle4[30];
	int auxLocalidad;
	int auxCensadosPresencialmente;
	int auxCensadosVirtualmente;
	int auxAusentes;
	//	int localidades[10] = {LOMAS, LANUS, BANFIELD, TEMPERLEY, KORN, BURZACO, QUILMES, AVELLANEDA, LAVALLOL, LUISGUILLON};

	printf("Bienvenido: \n");

	if (initCensistas(censistas, MAX_CENSISTAS) == 0
			&& inicializarZonasCenso(zonasCenso, MAX_CENSISTAS) == 0) {
		do {
			menuPrincipal();
			if (getInt(&opcion, "\n Ingrese una opci�n del men� principal: ",
					"Error: la opci�n ingresada es inv�lida", 1, 10, -1) == 0) {
				switch (opcion) {
				case 1:
					auxId = setId();
					if (getWords(auxNombre, sizeof(auxNombre),
							"\n Ingrese el nombre: ",
							"Error: el nombre ingresado es inv�lido", 3) == 0) {
						if (getWords(auxApellido, sizeof(auxApellido),
								"Ingrese el apellido: ",
								"Error: el apellido ingresado es inv�lido, 3",
								3) == 0) {
							if (getInt(&auxDia,
									"Ingrese el d�a de nacimiento: ",
									"Error: el d�a de nacimiento ingresado es inv�lido",
									1, 31, 3) == 0) {
								if (getInt(&auxMes,
										"Ingrese el mes de nacimiento: ",
										"Error: el mes de nacimiento ingresado es inv�lido",
										1, 12, 3) == 0) {
									if (getInt(&auxAnio,
											"Ingrese el a�o de nacimiento: ",
											"Error: el a�o de nacimiento ingresado es inv�lido",
											1922, 2004, 3) == 0) {
										if (getInt(&auxEdad,
												"Ingrese la edad: ",
												"Error: la edad ingresada es inv�lida",
												18, 100, 3) == 0) {
											if (getWords(auxCalle,
													sizeof(auxCalle),
													"Ingrese la calle del domicilio: ",
													"Error: la calle del domicilio ingresada es inv�lida",
													3) == 0) {
												if (getInt(&auxAltura,
														"Ingrese la altura del domicilio: ",
														"Error: la altura del domicilio ingresado es inv�lido",
														1, 15000, 3) == 0) {
													addCensista(censistas,
															MAX_CENSISTAS,
															auxId, auxNombre,
															auxApellido, auxDia,
															auxMes, auxAnio,
															auxEdad, auxCalle,
															auxAltura);
												}
											}
										}
									}
								}
							}
						}
					}
					break;

				case 2:
					if (hayCensistas(censistas, MAX_CENSISTAS) == 0) {
						if (getInt(&idBuscado,
								"\nIngrese el ID del censista a modificar: ",
								"Error: el ID ingresado es inv�lido", 1, -1, 3)
								== 0) {
							if ((posicionCensistaEncontrada =
									findCensistaLiberadoById(censistas,
											MAX_CENSISTAS, idBuscado)) != -1) {
								do {
									submenuModificar();
									if (getInt(&opcion,
											"\nIngrese una opci�n del submen� modificaci�n: ",
											"Error: la opci�n ingresada es inv�lida",
											1, 6, -1) == 0) {
										switch (opcion) {
										case 1:
											if (getWords(auxNombre,
													sizeof(auxNombre),
													"\nIngrese el nuevo nombre: ",
													"Error: el nuevo nombre ingresado es inv�lido",
													3) == 0) {
												strncpy(
														censistas[posicionCensistaEncontrada].nombre,
														auxNombre,
														sizeof(censistas[posicionCensistaEncontrada].nombre));
											}
											break;
										case 2:
											if (getWords(auxApellido,
													sizeof(auxApellido),
													"\nIngrese el nuevo apellido: ",
													"Error: el nuevo apellido ingresado es inv�lido",
													3) == 0) {
												strncpy(
														censistas[posicionCensistaEncontrada].apellido,
														auxApellido,
														sizeof(censistas[posicionCensistaEncontrada].apellido));
											}
											break;
										case 3:
											do {
												submenuModificarNacimiento();
												if (getInt(&opcion,
														"\nIngrese la opci�n del submen� modificar fecha de nacimiento: ",
														"Error: la opci�n ingresada es inv�lida",
														1, 4, -1) == 0) {
													switch (opcion) {
													case 1:
														if (getInt(&auxDia,
																"\nIngrese el nuevo d�a de nacimiento: ",
																"Error: el nuevo d�a de nacimiento ingresado es inv�lido",
																1, 31, 3)
																== 0) {
															censistas[posicionCensistaEncontrada].nacimiento.dia =
																	auxDia;
														}
														break;
													case 2:
														if (getInt(&auxMes,
																"\nIngrese el nuevo mes de nacimiento: ",
																"Error: el nuevo mes de nacimiento ingresado es inv�lido",
																1, 12, 3)
																== 0) {
															censistas[posicionCensistaEncontrada].nacimiento.mes =
																	auxMes;
														}
														break;
													case 3:
														if (getInt(&auxAnio,
																"\nIngrese el nuevo a�o de nacimiento: ",
																"Error: el nuevo a�o de nacimiento ingresado es inv�lido",
																1922, 2004, 3)
																== 0) {
															censistas[posicionCensistaEncontrada].nacimiento.anio =
																	auxAnio;
														}
														break;
													}
												}
											} while (opcion != 4);
											break;
										case 4:
											if (getInt(&auxEdad,
													"\nIngrese la nueva edad: ",
													"Error: la nueva edad ingresada es inv�lida",
													18, 100, 3) == 0) {
												censistas[posicionCensistaEncontrada].edad =
														auxEdad;
											}
											break;
										case 5:
											do {
												submenuModificarDomicilio();
												if (getInt(&opcion,
														"\nIngrese la opci�n del submen� modificar domicilio: ",
														"Error: la opci�n ingresada es inv�lida",
														1, 3, -1) == 0) {
													switch (opcion) {
													case 1:
														if (getWords(auxCalle,
																sizeof(auxCalle),
																"\nIngrese la nueva calle del domicilio: ",
																"Error: la nueva calle del domicilio ingresada es inv�lida",
																3) == 0) {
															strncpy(
																	censistas[posicionCensistaEncontrada].domicilio.calle,
																	auxCalle,
																	sizeof(censistas[posicionCensistaEncontrada].domicilio.calle));
														}
														break;
													case 2:
														if (getInt(&auxAltura,
																"\nIngrese la nueva altura del domicilio: ",
																"Error: la nueva altura del domicilio ingresada es inv�lida",
																1, 15000, 3)
																== 0) {
															censistas[posicionCensistaEncontrada].domicilio.altura =
																	auxAltura;
														}
														break;
													}
												}
											} while (opcion != 3);
											break;
										}
									}
								} while (opcion != 6);
							}
						}
					}
					break;

				case 3:
					if (hayCensistas(censistas, MAX_CENSISTAS) == 0) {
						if (getInt(&idBuscado,
								"\nIngrese el ID del censista a dar de baja: ",
								"Error: el ID ingresado es inv�lido", 1, -1, 3)
								== 0) {
							removeCensistaById(censistas, MAX_CENSISTAS,
									idBuscado);
						}
					}
					break;

				case 4:
					auxId = setId();
					if (getWords(auxCalle1, sizeof(auxCalle1),
							"\nIngrese la 1� calle: ",
							"Error: la calle ingresada es inv�lida", 3) == 0) {
						if (getWords(auxCalle2, sizeof(auxCalle2),
								"Ingrese la 2� calle: ",
								"Error: la calle ingresada es inv�lida", 3)
								== 0) {
							if (getWords(auxCalle3, sizeof(auxCalle3),
									"Ingrese la 3� calle: ",
									"Error: la calle ingresada es inv�lida", 3)
									== 0) {
								if (getWords(auxCalle4, sizeof(auxCalle4),
										"Ingrese la 4� calle: ",
										"Error: la calle ingresada es inv�lida",
										3) == 0) {
									printf("\n[1000] LOMAS"
											"\n[1001] LANUS"
											"\n[1002] BANFIELD"
											"\n[1003] TEMPERLEY"
											"\n[1004] KORN"
											"\n[1005] BURZACO"
											"\n[1006] QUILMES"
											"\n[1007] AVELLANEDA"
											"\n[1008] LAVALLOL"
											"\n[1009] LUISGUILLON");
									if (getInt(&auxLocalidad,
											"\nIngrese la localidad: ",
											"Error: la localidad ingresada es inv�lida",
											1000, 1009, 3) == 0) {
										agregarZonaCenso(zonasCenso,
												MAX_CENSISTAS, auxId, auxCalle1,
												auxCalle2, auxCalle3, auxCalle4,
												auxLocalidad);
									}
								}
							}
						}
					}
					break;

				case 5:
					if (hayCensistas(censistas, MAX_CENSISTAS) == 0
							&& hayZonasDeCenso(zonasCenso, MAX_CENSISTAS)
									== 0) {
						if (getInt(&idBuscado,
								"\nIngrese el ID de la zona a asignar: ",
								"Error: el ID ingresado es inv�lido", 1, -1, 3)
								== 0) {
							if ((posicionZonaCensoEncontrada =
									encontrarZonaCensoPendientePorId(zonasCenso,
											MAX_CENSISTAS, idBuscado)) != -1) {
								if (getInt(&idBuscado,
										"Ingrese el ID del censista asignado: ",
										"Error: el ID ingresado es inv�lido", 1,
										-1, 3) == 0) {
									if ((posicionCensistaEncontrada =
											findCensistaLiberadoById(censistas,
													MAX_CENSISTAS, idBuscado))
											!= -1) {
										zonasCenso[posicionZonaCensoEncontrada].idCensista =
												censistas[posicionCensistaEncontrada].idCensista;
										censistas[posicionCensistaEncontrada].estadoCensista =
												ACTIVO;
									}
								}
							}
						}
					}
					break;

				case 6:
					if (hayCensistasActivos(censistas, MAX_CENSISTAS) == 0
							&& hayZonasDeCenso(zonasCenso, MAX_CENSISTAS)
									== 0) {
						if (getInt(&idBuscado,
								"\nIngrese el ID de la zona a finalizar: ",
								"Error: el ID ingresado es inv�lido", 1, -1, 3)
								== 0) {
							if ((posicionZonaCensoEncontrada =
									encontrarZonaCensoPendientePorId(zonasCenso,
											MAX_CENSISTAS, idBuscado)) != -1) {
								if (getInt(&auxCensadosPresencialmente,
										"Ingrese la cantidad de censados presencialmente: ",
										"Error: la cantidad ingresada es inv�lida",
										0, -1, 3) == 0) {
									if (getInt(&auxCensadosVirtualmente,
											"Ingrese la cantidad de censados virtualmente: ",
											"Error: la cantidad ingresada es inv�lida",
											0, -1, 3) == 0) {
										if (getInt(&auxAusentes,
												"Ingrese la cantidad de ausentes: ",
												"Error: la cantidad ingresada es inv�lida",
												0, -1, 3) == 0) {
											zonasCenso[posicionZonaCensoEncontrada].censadosPresencialmente =
													auxCensadosPresencialmente;
											zonasCenso[posicionZonaCensoEncontrada].censadosVirtualmente =
													auxCensadosVirtualmente;
											zonasCenso[posicionZonaCensoEncontrada].ausentes =
													auxAusentes;
											zonasCenso[posicionZonaCensoEncontrada].estadoZonaCenso =
													FINALIZADA;
											for (int i = 0; i < MAX_CENSISTAS;
													i++) {
												if (censistas[i].isEmpty
														== FALSE
														&& zonasCenso[posicionZonaCensoEncontrada].idCensista
																== censistas[i].idCensista) {
													censistas[i].estadoCensista =
															LIBERADO;
													break;
												}
											}
										}
									}
								}
							}
						}
					}
					break;

				case 7:
					if (hayCensistas(censistas, MAX_CENSISTAS) == 0) {
						printCensistas(censistas, MAX_CENSISTAS);
						printf("\n");
						pressAnyKey("para volver al Men� Principal");
					}
					break;

				case 8:
					if (hayZonasDeCenso(zonasCenso, MAX_CENSISTAS) == 0) {
						printZonasCenso(zonasCenso, censistas, MAX_CENSISTAS);
						printf("\n");
						pressAnyKey("para volver al Men� Principal");
					}
					break;

				case 9:
					if (hayCensistas(censistas, MAX_CENSISTAS) == 0
							&& hayZonasDeCenso(zonasCenso, MAX_CENSISTAS)
									== 0) {
						do {
							submenuInformar();
							if (getInt(&opcion,
									"\nIngrese una opci�n del men� Informes: ",
									"Error: la opci�n ingresada es inv�lida", 1,
									6, -1) == 0) {
								switch (opcion) {
								case 1:
									informar1(censistas, zonasCenso,
											MAX_CENSISTAS);
									break;
								case 2:
									do {
										submenuInformar2();
										if (getInt(&opcion,
												"\nIngrese una opci�n del men� Informes: ",
												"Error: la opci�n ingresada es inv�lida",
												1, 5, -1) == 0) {
											switch (opcion) {
											case 1:
												break;
											case 2:
												break;
											case 3:
												break;
											case 4:
												break;
											}
										}
									} while (opcion != 5);
									break;
								case 3:
									informar3(zonasCenso, MAX_CENSISTAS);
									break;
								case 4:
									informar4(zonasCenso, censistas,
											MAX_CENSISTAS);
									break;
								case 5:
									do {
										submenuInformar5();
										if (getInt(&opcion,
												"\nIngrese una opci�n del men� Informes: ",
												"Error: la opci�n ingresada es inv�lida",
												1, 3, -1) == 0) {
											switch (opcion) {
											case 1:
												break;
											case 2:
												break;
											}
										}
									} while (opcion != 3);
									break;
								}
							}
						} while (opcion != 6);
					}
					break;

				case 10:
					printf("\nGracias por usar el programa");
					retorno = 0;
					break;
				}
			}
		} while (opcion != 10);
	}

	return retorno;
}

