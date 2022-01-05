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
#include "Ingredient.h"

typedef struct ingredientnode {

	INGREDIENT ingredientData;
	struct ingredientnode* next;

}INODE, *PINODE;

PINODE createIngredientNode(INGREDIENT);
PINODE getNextIngredientNode(PINODE);
void setNextIngredientNode(PINODE, PINODE);
PINGREDIENT getIngredientData(PINODE);
void removeIngredientNode(PINODE);