/*
 *	  Description: Functions related to user input
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
#include "User.h"
#include "Ingredient.h"

#include <stdbool.h>

#define MAX_NAME_LENGTH 255
#define MAX_ACCEPTABLE_INPUT 1
#define LOWERCASE_STR_LENGTH 2

char* getUserInput();
char* getMenuInput();
char* checkInputSize(char*);
int getRecipeIDInput();
bool checkYesNo();
bool yesNoShowMenuAgain();
INGREDIENT getIngredientInput(int id);
bool yesNoAddIngredient();
bool yesNoAddEditIngredient();
char* convertStringToUpper(char*);
char* removeSpacesAndFormat(char*);