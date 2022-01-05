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
#include "RecipeNode.h"

#include <stdio.h>
#include <stdlib.h>


PRNODE createRecipeNode(RECIPE recipe) {

	PRNODE newNode = (PRNODE)malloc(sizeof(RNODE));

	if (!newNode) {

		fprintf(stderr, "error allocating memory\n");
		return (PRNODE)NULL;
	}

	newNode->recipeData = recipe;
	newNode->next = NULL;

	return newNode;

}

PRNODE getNextRecipeNode(PRNODE recipeNode) {

	return recipeNode->next;

}

void setNextRecipeNode(PRNODE sourceRecipeNode, PRNODE newNextRecipeNode) {

	sourceRecipeNode->next = newNextRecipeNode;

}

PRECIPE getRecipeData(PRNODE recipeNode) {

	return &(recipeNode->recipeData);

}

void setRecipeData(PRNODE recipeNode, RECIPE recipe) {
	recipeNode->recipeData = recipe;
}

void removeRecipeNode(PRNODE recipeNode) {

	free(recipeNode);

}