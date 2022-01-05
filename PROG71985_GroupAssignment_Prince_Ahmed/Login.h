/*
 *	  Description: Login functions
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
#define MAX_NAME_LENGTH 255

#include "User.h"
#include "Input.h"
#include <stdbool.h>

bool getLoginFromUser(USER*);
void createAccount();
bool checkCreds(char*, char*, USER*);
bool checkUsernameExists(char*, USER*);