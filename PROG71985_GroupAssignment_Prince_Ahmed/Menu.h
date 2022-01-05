/*
 *	  Description: Functions related to the main menu
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
#include "User.h"
#include "Input.h"
#include "Login.h"
#include "FileIO.h"

#include <stdbool.h>

void displayLogo();
void displayAccountFunctions();
bool getAccountOption(USER*);
void displayRecipeFunctions();
bool getRecipeMenuOption(PRLIST);
void displayRecipeList(PRLIST);