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
#define _CRT_SECURE_NO_WARNINGS
#include "IngredientADT.h"
#include "Recipe.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ILIST createIngredientList() {
	ILIST newList = { 0 };
	return newList;
}

bool addIngredientToList(PILIST thisIngredientList, INGREDIENT thisIngredient) {

	PINODE newNode = createIngredientNode(thisIngredient);
	if (!newNode) {
		return false;
	}
	// If ingredient list is empty
	if (thisIngredientList->list == NULL) {
		setNextIngredientNode(newNode, thisIngredientList->list);
		thisIngredientList->list = newNode;
	} else {
		PINODE currNode = thisIngredientList->list;
		// Find the last node
		while (getNextIngredientNode(currNode) != NULL) {
			currNode = getNextIngredientNode(currNode);
		}
		setNextIngredientNode(currNode, newNode);
		return true;
	}
}

bool displayIngredients(PILIST thisIngredientList) {

	if (thisIngredientList->list == NULL) {
		printf("Err: No ingredients found");
		return false;;
	} else {
		PINODE currNode = thisIngredientList->list;
		PINODE tempNode = thisIngredientList->list;

		int currIngredientID = 0;
		char* currIngredientName = "";
		float currIngredientQuantity = 0.0f;
		char* currIngredientMeasurement = "";
		
		while (currNode != NULL) {
			
			currIngredientID = getIngredientID(*getIngredientData(currNode));
			currIngredientName = getIngredientName(*getIngredientData(currNode));
			currIngredientQuantity = getIngredientQuantity(*getIngredientData(currNode));
			currIngredientMeasurement = getIngredientMeasurement(*getIngredientData(currNode));
			
			char biggestIngredientName[MAX_NAME] = { "" };
			int biggestIngredientSize = 0;

			//Find the largest ingredient name by iterating through the ingredient list 
			while (tempNode != NULL) {
				char* tempIngredientName = getIngredientName(*getIngredientData(tempNode));
				if (getNextIngredientNode(tempNode) != NULL) {
					char* tempNextIngredientName = getIngredientName(*getIngredientData(getNextIngredientNode(tempNode)));

					// If the biggest ingredient name length is smaller than the current ingredient replace the variable
					if (strlen(biggestIngredientName) < strlen(tempIngredientName)) {
						strcpy(biggestIngredientName, tempIngredientName);
						biggestIngredientSize = strlen(biggestIngredientName);

					// If the biggest ingredient name length is smaller than the next ingredient in the list replace the variable
					} else if (strlen(biggestIngredientName) < strlen(tempNextIngredientName)) {
						strcpy(biggestIngredientName, tempNextIngredientName);
						biggestIngredientSize = strlen(biggestIngredientName);
					}
				}
				tempNode = getNextIngredientNode(tempNode);
			}
			int currIngredientNameSize = strlen(currIngredientName);

			// Concatenate the difference amount of spaces onto the ends of the other ingredients
			// Forces the strings to the same size (for console formatting)
			while (currIngredientNameSize < biggestIngredientSize) {
				strcat(currIngredientName, " ");
				currIngredientNameSize++;
			}
			printf("\t%d) %s\t%0.2f\t%s\n", currIngredientID, currIngredientName, currIngredientQuantity, currIngredientMeasurement);
			
			currNode = getNextIngredientNode(currNode);
			tempNode = thisIngredientList->list;
		}
		return true;
	}
}

PINGREDIENT getIngredientFromIngredientList(PILIST thisIngredientList, int ingredientOption) {

	if (thisIngredientList->list == NULL) {

		printf("Err: No ingredients found");
		return NULL;

	} else {

		PINODE currNode = thisIngredientList->list;
		//Compares and finds the selected ingredient ID in the list
		while (currNode != NULL) {

			if (compareIngredientID(*getIngredientData(currNode), ingredientOption)) {
				return getIngredientData(currNode);
			}
			currNode = getNextIngredientNode(currNode);
		}
		return NULL;
	}
}

int getLastIngredientID(PILIST thisIngredientList) {

	if (thisIngredientList->list == NULL) {

		printf("Err: No ingredients found");
		return;

	} else {

		PINODE currNode = thisIngredientList->list;
		int currRecipeID;
		//Iterates until the last ingredient and returns its ID
		while (currNode != NULL) {

			currRecipeID = getIngredientID(*getIngredientData(currNode));
			currNode = getNextIngredientNode(currNode);
		}
		return currRecipeID;
	}
}