#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef ARRAYVUELO_H_
#define ARRAYVUELO_H_

#define ACTIVE 1
#define DELAYED 2
#define CANCELLED 3

struct {
	int id;
	char flyCode[10];
	int flightStatus;
	int isEmpty;
} typedef Flight;

int initFlights(Flight *list, int lenght);

int addFlight(Flight *list, int lenght, int id, char flyCode[], int flightStatus);

int findFlightById(Flight *list, int lenght, int id);

int removeFlight(Flight *list, int lenght, int id);


#endif /* ARRAYVUELO_H_ */
