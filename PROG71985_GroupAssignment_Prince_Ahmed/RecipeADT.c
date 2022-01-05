/*
 *	  Description: Fully operational ADT system for recipe management
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
#include "RecipeADT.h"
#include "Menu.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

RLIST createRecipeList() {
	RLIST newList = { 0 };
	return newList;
}

bool addRecipeToList(PRLIST thisRecipeList, RECIPE thisRecipe) {

	PRNODE newNode = createRecipeNode(thisRecipe);

	if (!newNode) {
		return false;
	}
	// If list is empty
	if (thisRecipeList->list == NULL) {
		setNextRecipeNode(newNode, thisRecipeList->list);
		thisRecipeList->list = newNode;
	} else {

		PRNODE currNode = thisRecipeList->list;
		// Find the last node
		while (getNextRecipeNode(currNode) != NULL) {
			currNode = getNextRecipeNode(currNode);
		}

		setNextRecipeNode(currNode, newNode);
		return true;
	}
}

bool removeRecipeFromList(PRLIST thisRecipeList, int recipeIDToBeDeleted) {

	PRNODE currNode = thisRecipeList->list;

	//If deleting the only recipe in the list
	if (compareRecipeID(*getRecipeData(currNode), recipeIDToBeDeleted)) {
		if (getNextRecipeNode(currNode) != NULL) {
			thisRecipeList->list = getNextRecipeNode(currNode);
		} else {
			thisRecipeList->list = NULL;
		}
		removeRecipeNode(currNode);
		return true;
	}

	PRNODE prev = NULL;

	//Iterate until recipe is found
	while (currNode != NULL && !compareRecipeID(*getRecipeData(currNode), recipeIDToBeDeleted - 1)) {
		prev = currNode;
		currNode = getNextRecipeNode(currNode);
	}

	if (currNode == NULL) {
		return false;
	}
	// If deleting the first node, set the list to the 2nd node
	if (prev == NULL) {
		currNode = thisRecipeList->list;
		thisRecipeList->list = getNextRecipeNode(thisRecipeList->list);
	} else {
		setNextRecipeNode(prev, getNextRecipeNode(currNode));
	}
	
	removeRecipeNode(currNode);
	return true;
}

void getRecipeListFromADT(PRLIST thisRecipeList) {

	if (thisRecipeList->list == NULL) {

		printf("Err: No recipes found\n");
		return;

	} else {

		PRNODE currNode = thisRecipeList->list;

		// Iterates through all the nodes and displays each recipe with each iteration
		while (currNode != NULL) {

			char* currRecipeName = getRecipeName(*getRecipeData(currNode));
			int currRecipeID = getRecipeID(*getRecipeData(currNode));
			printf("%d) %s\n", currRecipeID + 1, currRecipeName);
			currNode = getNextRecipeNode(currNode);
		}
	}
}

PRECIPE getRecipeFromRecipeList(PRLIST thisRecipeList, int recipeOption) {

	if (thisRecipeList->list == NULL) {

		printf("Err: No recipes found\n");
		return NULL;

	} else {

		PRNODE currNode = thisRecipeList->list;
		// Iterates through all the nodes and compares the selection with the recipe ID's in the list
		while (currNode != NULL) {

			if (compareRecipeID(*getRecipeData(currNode), recipeOption - 1)) {
				return getRecipeData(currNode);
			}
			currNode = getNextRecipeNode(currNode);
		}
		return NULL;
	}
}

bool checkRecipeExists(PRLIST thisRecipeList, int recipeOption) {

	if (thisRecipeList->list == NULL) {

		printf("Err: No recipes found\n");
		return false;;

	} else {

		PRNODE currNode = thisRecipeList->list;
		// Iterates through all the nodes and checks if the selection exists
		while (currNode != NULL) {

			if (compareRecipeID(*getRecipeData(currNode), recipeOption - 1)) {
				return true;
			}
			currNode = getNextRecipeNode(currNode);
		}
		return false;
	}
}

bool displayRecipe(PRLIST thisRecipeList, int recipeOption) {

	if (thisRecipeList->list == NULL) {

		printf("Err: No recipes found\n");
		return false;

	} else {

		PRNODE currNode = thisRecipeList->list;

		while (currNode != NULL) {
			if (compareRecipeID(*getRecipeData(currNode), recipeOption - 1)) {
				char* currRecipeName = getRecipeName(*getRecipeData(currNode));
				printf("\n%s:\n", currRecipeName);
				displayIngredients(getIngredientList(getRecipeData(currNode)));
				return true;
			}
			currNode = getNextRecipeNode(currNode);
		}
	}
}

int getLastRecipeID(PRLIST thisRecipeList) {

	// Return -1 if no recipes exist. This will start the ID count at 0 when a user
	// creates the first recipe in the list
	int currRecipeID = -1;

	if (thisRecipeList->list == NULL) {

		return currRecipeID;

	} else {

		PRNODE currNode = thisRecipeList->list;
		//Iterates until the last node, then returns the ID of the last recipe
		while (currNode != NULL) {

			currRecipeID = getRecipeID(*getRecipeData(currNode));
			currNode = getNextRecipeNode(currNode);
		}
		return currRecipeID;
	}
}

bool searchRecipesInRecipeList(PRLIST thisRecipeList, char* searchWord) {

	if (thisRecipeList->list == NULL) {

		printf("Err: No recipes found\n");
		return false;

	} else {

		PRNODE currNode = thisRecipeList->list;
		RLIST searchedRecipeList = createRecipeList();
		//Iterates through each node and adds each recipe that matches the searchWord
		//Only compares from the beginning of the recipe name
		while (currNode != NULL) {

			if (compareRecipeSearchWord(*getRecipeData(currNode), searchWord)) {
				RECIPE currRecipe = *getRecipeData(currNode);
				addRecipeToList(&searchedRecipeList, currRecipe);
			}
			currNode = getNextRecipeNode(currNode);
		}

		if (&searchedRecipeList == NULL) {
			return false;
		} else {
			displayRecipeList(&searchedRecipeList);
			return true;
		}
	}
}

bool showRecipeListAToZ(PRLIST thisRecipeList) {

	if (thisRecipeList->list == NULL) {

		printf("Err: No recipes found\n");
		return false;

	} else {

		RLIST sortedRecipeList = *thisRecipeList;
		PRNODE currNode = sortedRecipeList.list;
		PRNODE nextNode = getNextRecipeNode(currNode);

		//Bubble sort
		while (currNode != NULL) {
			nextNode = getNextRecipeNode(currNode);
			while (nextNode != NULL) {

				char* currRecipeName = getRecipeName(*getRecipeData(currNode));
				char* nextRecipeName = getRecipeName(*getRecipeData(nextNode));

				if (strcmp(currRecipeName, nextRecipeName) > 0) {
					//Swap node data
					RECIPE temp = *getRecipeData(currNode);
					setRecipeData(currNode, *getRecipeData(nextNode));
					setRecipeData(nextNode, temp);
				}
				nextNode = getNextRecipeNode(nextNode);
			}
			currNode = getNextRecipeNode(currNode);
		}

		displayRecipeList(&sortedRecipeList);

		return true;
	}
}