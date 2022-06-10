/*
 * passenger.h
 *
 *  Created on: 14 may 2022
 *      Author: alan_
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

 struct{
int id;
char name[51];
char lastName[51];
float price;
char flycode[10];
int typePassenger;
int isEmpty;
} typedef Passenger;

int initPassengers(Passenger* list, int len);
int addPassenger(Passenger* list, int len, int id, char name[],char
lastName[],float price,int typePassenger, char flycode[]);
int findPassengerById(Passenger* list, int len,int id);
int removePassenger(Passenger* list, int len, int id);
int sortPassengers(Passenger* list, int len, int order);
int printPassenger(Passenger* list, int length);
int sortPassengers(Passenger* list, int len, int order);
#endif /* PASSENGER_H_ */
