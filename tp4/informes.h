#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Utn.h"
#include "Controller.h"
#include "Passenger.h"
#include "LinkedList.h"
#include "Parser.h"

#ifndef INFORMES_H_
#define INFORMES_H_

int ll_count(LinkedList* this, int (*fn)(void* element));
LinkedList* ll_filter(LinkedList* this, int (*fn)(void* element));
LinkedList* ll_map(LinkedList* this, void (*fn)(void* element));


#endif /* INFORMES_H_ */
