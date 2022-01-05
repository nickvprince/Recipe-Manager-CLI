/*
 *	  Description: File management functions for a recipe manager
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
#define MAX_INPUT 256

#define RECIPE_LIST_NAME "Recipe Manager/RecipeList.txt"
#define RECIPE_DIR "Recipe Manager/Recipes/"

#include "FileIO.h"
#include "Allocation.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


RLIST readRecipeList() {

	RLIST recipeList = createRecipeList();
	FILE* listFile = fopen(RECIPE_LIST_NAME, "r");

	if (listFile == NULL) {

		printf("Recipe list file cannot be found, Initizalizing\n");
		listFile = fopen(RECIPE_LIST_NAME, "w");
		fclose(listFile);
		return recipeList;

	} else if (listFile != NULL) {

		int i = 0;
		char* tempRecipeFileName = allocateCharArray();
		// recipe list file contains a single string (RECIPENAME.txt) on each line
		while (fscanf(listFile, "%s", tempRecipeFileName) != EOF) {

			// after a recipe is read from the list, the ingredient data is read from the recipe's unique file
			PRECIPE recipe = readRecipe(recipeList, tempRecipeFileName, i);
			
			if (recipe != NULL) {
				addRecipeToList(&recipeList, *recipe);
				i++;
			}
		}
		free(tempRecipeFileName);
	}

	fclose(listFile);

	return recipeList;
}

PRECIPE readRecipe(RLIST recipeList, char* recipeFileName, int recipeID) {

	// Gets recipe directory
	char* recipeDir = allocateCharArray();
	sprintf(recipeDir, "%s%s", RECIPE_DIR, recipeFileName);
	char* tempRecipeName = recipeFileName;
	char* txt = ".txt";

	// removes ".txt" from the recipeFileName, to later be used in the recipe ADT
	for (int i = 0; i < strlen(txt); i++) {
		tempRecipeName[strlen(tempRecipeName) - 1] = '\0';
	}

	FILE* recipeFile = fopen(recipeDir, "r");

	if (recipeFile == NULL) {
		return NULL;
	}

	RECIPE tempRecipe = createRecipe(tempRecipeName, recipeID);

	int i = 0;

	char* tempIngredientID = allocateCharArray();
	char* tempIngredientName = allocateCharArray();
	char* tempIngredientQuantity = allocateCharArray();
	char* tempIngredientMeasurment = allocateCharArray();

	// Ingredients are read in one line at a time in the format: ID, NAME, QUANITIY, MEASUREMENT
	while (fscanf(recipeFile, "%s\t%s\t%s\t%s[^\n]", tempIngredientID, tempIngredientName, tempIngredientQuantity, tempIngredientMeasurment) != EOF){
			
		// Convert char* to proper types
		int ingredientID = atoi(tempIngredientID);
		tempIngredientName = reallocateCharArray(tempIngredientName, strlen(tempIngredientName));
		float ingredientQuantity = atof(tempIngredientQuantity);
		tempIngredientMeasurment = reallocateCharArray(tempIngredientMeasurment, strlen(tempIngredientMeasurment));

		// Create ingredient with ingredient info, then add ingredient to recipe
		INGREDIENT ingredient = createIngredient(ingredientID, tempIngredientName, ingredientQuantity, tempIngredientMeasurment);

		addIngredientToRecipe(&(tempRecipe), ingredient);

		i++;
	}

	free(tempIngredientID);
	free(tempIngredientName);
	free(tempIngredientQuantity);
	free(tempIngredientMeasurment);
	
	free(recipeDir);
	fclose(recipeFile);

	return &tempRecipe;

}

void deleteRecipeTextFile(PRLIST recipeList, int recipeOption) {

	if (getRecipeFromRecipeList(recipeList, recipeOption) == NULL) {
		printf("Recipe not Found\n");
	} else {
		char* removeRecipeFile = allocateCharArray();
		char* recipeName = getRecipeName(*getRecipeFromRecipeList(recipeList, recipeOption));
		char* dir = RECIPE_DIR;

		// Generates a file directory to be deleted/removed
		sprintf(removeRecipeFile, "%s%s.txt", RECIPE_DIR, recipeName);

		if (remove(removeRecipeFile) == 0) {
			printf("FILE: %s.txt has been removed\n", recipeName);
		} else {
			printf("FILE: %s.txt could not be found\n", recipeName);
		}
		free(removeRecipeFile);
	}
}

void writeRecipeList(PRLIST recipeList) {
	
	char* line = allocateCharArray();
	FILE* listFile = fopen(RECIPE_LIST_NAME, "w");

	if (listFile == NULL) {

		printf("Recipe list file cannot be found, Initizalizing\n");
		listFile = fopen(RECIPE_LIST_NAME, "w");
		fclose(listFile);

	} else { 
		// Start at 1 because recipe IDs are displayed to the user 1->X
		int i = 1;
		while (i <= getLastRecipeID(recipeList) + 1) {

			if (getRecipeFromRecipeList(recipeList, i)) {
				char* recipeName = getRecipeName(*getRecipeFromRecipeList(recipeList, i));

				sprintf(line, "%s.txt\n", recipeName);
				line = reallocateCharArray(line, strlen(line));
				fprintf(listFile, "%s", line);

				writeRecipe(getRecipeFromRecipeList(recipeList, i), line);

			}
			i++;
		}
	}

	free(line);
	fflush(listFile);
	fclose(listFile);

}

void writeRecipe(PRECIPE recipe, char* recipeFileName) {

	char* line = allocateCharArray();
	char* recipeDir = allocateCharArray();
	// Generates a recipe directory
	sprintf(recipeDir, "%s%s", RECIPE_DIR, recipeFileName);
	strtok(recipeDir, "\n");
	FILE* recipeFile = fopen(recipeDir, "w");

	if (recipeFile == NULL) {
		return;
	} else {
		int tempIngredientID = 1;
		PILIST ingredientList = getIngredientList(recipe);
		// Ingredients are written one line at a time in the format: ID, NAME, QUANITIY, MEASUREMENT
		while (getIngredientFromIngredientList(ingredientList, tempIngredientID)) {
			
			INGREDIENT currIngredient = *getIngredientFromIngredientList(ingredientList, tempIngredientID);

			char* tempIngredientName = getIngredientName(currIngredient);
			float tempIngredientQuantity = getIngredientQuantity(currIngredient);
			char* tempIngredientMeasurment = getIngredientMeasurement(currIngredient);

			// %0.2f for consistency with the quantity values
			sprintf(line, "%d\t%s\t%0.2f\t%s\n", tempIngredientID, tempIngredientName, tempIngredientQuantity, tempIngredientMeasurment);
			line = reallocateCharArray(line, strlen(line));
			fprintf(recipeFile, "%s", line);

			tempIngredientID++;
		}
	}

	free(line);
	free(recipeDir);
	fflush(recipeFile);
	fclose(recipeFile);

}