/*
 *	  Description: Fully operational ADT subsystem for ingredient management
 *
 *    Name:		Nick Prince
 *    Email:	nprince3037@conestogac.on.ca
 *    Course:	PROG71985 - Fall2020
 *
 *    Name:		Islam Ahmed
 *    Email:	Iahmed9886@conestogac.on.ca
 *    Course:	PROG71985 - Fall2020
 */
#pragma once
#include "IngredientNode.h"

#include <stdbool.h>

typedef struct ingredientADT {

	PINODE list;

}ILIST, *PILIST;

ILIST createIngredientList();
bool addIngredientToList(PILIST, INGREDIENT);
bool displayIngredients(PILIST);
PINGREDIENT getIngredientFromIngredientList(PILIST, int);
int getLastIngredientID(PILIST);