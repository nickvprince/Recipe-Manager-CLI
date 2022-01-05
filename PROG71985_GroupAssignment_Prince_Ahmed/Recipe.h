/*
 *	  Description: Structure of a recipe and operational functions
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
#define MAX_NAME 50

#include "IngredientADT.h"

#include <stdbool.h>

typedef struct recipe {

	int id;
	char name[MAX_NAME];
	ILIST ingredientArray;

}RECIPE, *PRECIPE;

RECIPE createRecipe(char*, int);
char* getRecipeName(RECIPE);
int getRecipeID(RECIPE);
PILIST getIngredientList(PRECIPE);
bool compareRecipeID(RECIPE, int);
bool compareRecipeSearchWord(RECIPE, char*);
void addIngredientToRecipe(PRECIPE, INGREDIENT);
void editRecipeID(PRECIPE, int);