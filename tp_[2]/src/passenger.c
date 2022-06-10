/*
 * passenger.c
 *
 *  Created on: 14 may 2022
 *      Author: alan_
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int initPassengers(Passenger* list, int len){

	int i;
	int retorno = 0;

	if(len > 0 && len != NULL){
		for(i=0; i< len; i++){
			list[i].isEmpty = 0;
		}
	}else {
		retorno = -1;
	}
	return retorno;
}

/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/

int addPassenger(Passenger* list, int len, int id, char name[],char
lastName[],float price,int typePassenger, char flycode[]){
	int i;
	int retorno = 0;

	if(len != NULL && len > 0 && list->isEmpty){
		list->isEmpty = len
	}




	return retorno;
}
















