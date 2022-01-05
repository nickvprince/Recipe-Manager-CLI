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

#pragma once
#include "RecipeADT.h"

RLIST readRecipeList();
PRECIPE readRecipe(RLIST, char*, int);
void deleteRecipeTextFile(PRLIST, int);
void writeRecipeList(PRLIST);
void writeRecipe(PRECIPE, char*);