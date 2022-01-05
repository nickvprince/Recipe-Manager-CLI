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
#define _CRT_SECURE_NO_WARNINGS

#include "Ingredient.h"

#include <string.h>
#include <stdlib.h>

INGREDIENT createIngredient(int id, char* ingredientName, float quantity, char* measurement) {
	
	INGREDIENT ingredient;
	ingredient.id = id;
	strcpy(ingredient.name, ingredientName);
	ingredient.quantity = quantity;
	strcpy(ingredient.measurement, measurement);
	
	return ingredient;

}

int getIngredientID(INGREDIENT ingredient) {
	return ingredient.id;
}

char* getIngredientName(INGREDIENT ingredient) {
	return ingredient.name;
}

float getIngredientQuantity(INGREDIENT ingredient) {
	return ingredient.quantity;
}

char* getIngredientMeasurement(INGREDIENT ingredient) {
	return ingredient.measurement;
}

bool compareIngredientID(INGREDIENT ingredient, int id) {
	if (ingredient.id == id) {
		return true;
	} else {
		return false;
	}
}