/*
 *	  Description: Structure of an ingredient and operational functions
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
#define NUM_ITEMS_IN_INGREDIENT 4 
#define MAX_INGREDIENTS 100
#define MAX_NAME 50
#define NUM_OF_MEASUREMENTS_FOR_READ 10

#include <stdbool.h>

typedef struct ingredient {

	int id;
	char name[MAX_NAME];
	float quantity;
	char measurement[MAX_NAME];

}INGREDIENT, *PINGREDIENT;

INGREDIENT createIngredient(int, char*, float, char*);
int getIngredientID(INGREDIENT ingredient);
char* getIngredientName(INGREDIENT);
float getIngredientQuantity(INGREDIENT);
char* getIngredientMeasurement(INGREDIENT);
bool compareIngredientID(INGREDIENT, int);