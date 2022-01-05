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
#include "RecipeNode.h"

#include <stdbool.h>

typedef struct RecipeADT {

	PRNODE list;

}RLIST, *PRLIST;

RLIST createRecipeList();
bool addRecipeToList(PRLIST, RECIPE);
bool removeRecipeFromList(PRLIST, int);
void getRecipeListFromADT(PRLIST);
PRECIPE getRecipeFromRecipeList(PRLIST, int);
bool checkRecipeExists(PRLIST, int);
bool displayRecipe(PRLIST, int);
int getLastRecipeID(PRLIST);
bool searchRecipesInRecipeList(PRLIST, char*);
bool showRecipeListAToZ(PRLIST);
//int compare(const void*, const void*);