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

#define _CRT_SECURE_NO_WARNINGS

#include "User.h"
#include "Allocation.h"

#include <stdio.h>
#include <string.h>

USER* getUsersFromFile() {

	FILE* login;
	login = fopen(LOGIN_FILE, "r");

	if (login == NULL) {
		printf("Unable to open the login file.\n");
		exit(EXIT_FAILURE);
	}

	char* tempUsername = allocateCharArray();
	char* tempPassword = allocateCharArray();


	USER userArray[MAX_USERS] = { NULL };
	int currLine = 0;

	// Users are read in per line in the text file (Username [tab] Password)
	while (fscanf(login, "%s\t%s[^\n]", tempUsername, tempPassword) != EOF) {

		tempUsername = reallocateCharArray(tempUsername, strlen(tempUsername));
		tempPassword = reallocateCharArray(tempPassword, strlen(tempPassword));

		USER tempUser = createUser(tempUsername, tempPassword);

		strcpy(userArray[currLine].username, tempUser.username);
		strcpy(userArray[currLine].password, tempUser.password);

		currLine++;
	}

	free(tempUsername);
	free(tempPassword);

	printf("\n");

	fflush(login);
	fclose(login);

	return userArray;

}

void writeUserToFile(char* username, char* password) {
	char* line = allocateCharArray();
	FILE* userFile = fopen(LOGIN_FILE, "a");

	if (userFile == NULL) {
		printf("Recipe list file cannot be found\n");
	} else {
		
		// Users are written in per line in the text file (Username [tab] Password)
		sprintf(line, "\n%s\t%s", username, password);
		line = reallocateCharArray(line, strlen(line));
		fprintf(userFile, "%s", line);
	}

	free(line);
	fflush(userFile);
	fclose(userFile);
}

USER createUser(char* username, char* password) {
	
	USER currUser;

	strcpy(currUser.username, username);
	strcpy(currUser.password, password);

	return currUser;

}

char* getUsername(USER * userArray, int pos) {

	char* username = allocateCharArray();
	strcpy(username, userArray[pos].username);

	return username;

}

char* getPassword(USER * userArray, int pos) {

	char* password = allocateCharArray();
	strcpy(password, userArray[pos].password);

	return password;

}

int getSizeOfUserArray(USER * userArray) {

	int sizeOfArray = 0;

	while (strcmp(getUsername(userArray, sizeOfArray), "") != 0 ||
		strcmp(getPassword(userArray, sizeOfArray), "") != 0) {

		sizeOfArray++;

	}

	return sizeOfArray;

}

