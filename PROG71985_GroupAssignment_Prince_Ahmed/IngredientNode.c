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
#include "IngredientNode.h"

#include <stdio.h>
#include <stdlib.h>


PINODE createIngredientNode(INGREDIENT ingredient) {

	PINODE newNode = (PINODE)malloc(sizeof(INODE));

	if (!newNode) {

		fprintf(stderr, "error allocating memory\n");
		return (PINODE)NULL;
	}

	newNode->ingredientData = ingredient;
	newNode->next = NULL;

	return newNode;

}

PINODE getNextIngredientNode(PINODE ingredientNode) {

	return ingredientNode->next;

}

void setNextIngredientNode(PINODE sourceIngredientNode, PINODE newNextIngredientNode) {

	sourceIngredientNode->next = newNextIngredientNode;

}

PINGREDIENT getIngredientData(PINODE ingredientNode) {

	return &(ingredientNode->ingredientData);

}

void removeIngredientNode(PINODE ingredientNode) {

	free(ingredientNode);

}