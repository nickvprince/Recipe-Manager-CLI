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
#pragma once
#include "Recipe.h"

typedef struct recipenode {

	RECIPE recipeData;
	struct recipenode* next;

}RNODE, *PRNODE;

PRNODE createRecipeNode(RECIPE);
PRNODE getNextRecipeNode(PRNODE);
void setNextRecipeNode(PRNODE, PRNODE);
PRECIPE getRecipeData(PRNODE);
void setRecipeData(PRNODE, RECIPE);
void removeRecipeNode(PRNODE);