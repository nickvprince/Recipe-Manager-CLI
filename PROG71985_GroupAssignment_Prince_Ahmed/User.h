/*
 *	  Description: File IO based login functions
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

#include <stdio.h> 
#include <stdlib.h>

#define MAX_NAME_LENGTH 255
#define MAX_USERS 50
#define LOGIN_FILE "Recipe Manager/Accounts.txt"

typedef struct user {

	char username[MAX_NAME_LENGTH];
	char password[MAX_NAME_LENGTH];

} USER;

USER* getUsersFromFile();
void writeUserToFile(char*, char*);
USER createUser(char*, char*);
char* getUsername(USER*, int);
char* getPassword(USER*, int);
int getSizeOfUserArray(USER*);