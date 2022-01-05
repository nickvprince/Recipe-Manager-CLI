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
#define _CRT_SECURE_NO_WARNINGS

#include "Recipe.h"
#include "RecipeADT.h"
#include "Input.h"
#include "Allocation.h"

#include <stdlib.h>
#include <string.h>
#include <ctype.h>

RECIPE createRecipe(char* name, int id) {
	RECIPE recipe;
	recipe.id = id;
	strcpy(recipe.name, name);
	recipe.ingredientArray = createIngredientList();
	return recipe;
}

char* getRecipeName(RECIPE recipe) {
	return recipe.name;
}

int getRecipeID(RECIPE recipe) {
	return recipe.id;
}

PILIST getIngredientList(PRECIPE recipe) {
	return &(recipe->ingredientArray);
}

bool compareRecipeID(RECIPE recipe, int id) {
	if (recipe.id == id) {
		return true;
	} else {
		return false;
	}
}

bool compareRecipeSearchWord(RECIPE recipe, char* searchWord) {
	int searchWordLength = strlen(searchWord);
	char* currRecipeWord = allocateCharArray();
	char* upperSearchWord = convertStringToUpper(searchWord);

	for (int i = 0; i < searchWordLength; i++) {
		currRecipeWord[i] = getRecipeName(recipe)[i];
	}

	if (strcmp(currRecipeWord, upperSearchWord) == 0) {
		free(currRecipeWord);
		return true;
	} else {
		free(currRecipeWord);
		return false;
	}
}

void addIngredientToRecipe(PRECIPE thisRecipe, INGREDIENT thisIngredient) {
	addIngredientToList(&thisRecipe->ingredientArray, thisIngredient);
}

void editRecipeID(PRECIPE thisRecipe, int ID) {
	thisRecipe->id = ID;
}

//void editRecipeName(PRECIPE thisRecipe, char* recipeName) {
//	strcpy(thisRecipe->name, recipeName);
//}