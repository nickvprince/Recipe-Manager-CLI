/*
 *	  Description: Functions related to user input
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
#include "Allocation.h"
#include "User.h"
#include "Input.h"
#include "Login.h"

#include <ctype.h>
#include <string.h>
#include <stdio.h>

char* getUserInput() {

	int maxCount = sizeof(char);
	char* userInput = allocateCharArray();

	if (userInput == NULL) {

		printf("Memory could not be allocated");
		exit(EXIT_FAILURE);

	} else {

		char ch = NULL;
		int i = 0;

		// Accept input until user hits enter
		while ((ch = getchar()) != '\n' && ch != NULL) {

			userInput[i] = ch;
			i++;

			// Input starts at 1 byte and is reallocated everytime it increases by 1
			if (i == maxCount) {

				maxCount++;
				userInput = reallocateCharArray(userInput, maxCount);

				if (userInput == NULL) {

					printf("Memory could not be re-allocated");
					exit(EXIT_FAILURE);

				}
			}
		}

		// Replaces last char '\n' with NULL
		userInput[i] = NULL;

	}

	return userInput;

}

char* checkInputSize(char* userInputLetter) {

	int sizeOfInput = 0;

	// Counts size of input from user
	for (int i = 0; i < strlen(userInputLetter); i++) {
		if (userInputLetter[i] != NULL) {
			sizeOfInput++;
		}
	}

	// If user input is larger than 1 character, set to null for automatic invalid entry
	if (sizeOfInput > MAX_ACCEPTABLE_INPUT) {
		for (int i = 0; i < strlen(userInputLetter); i++) {
			userInputLetter[i] = NULL;
		}
	}

	return userInputLetter;

}

char* getMenuInput() {

	char* userInput = getUserInput();
	userInput = convertStringToUpper(userInput);
	userInput = checkInputSize(userInput);
	// Counts size of input from user
	for (int i = 0; i < strlen(userInput); i++) {
		if (userInput == '\n') {
			userInput = NULL;
		} else if (i > MAX_ACCEPTABLE_INPUT) {
			userInput = NULL;
		}
	}

	return userInput;
}


int getRecipeIDInput() {

	char* userInput = getUserInput();
	userInput = convertStringToUpper(userInput);
	int userInputAsInt = atoi(userInput);
	free(userInput);
	return userInputAsInt;

}

bool checkYesNo() {

	bool yesNo = false;
	bool validInput = false;
	do {
		char* userInput = getMenuInput();
		if (strcmp("N", userInput) == 0 || strcmp("NO", userInput) == 0) {
			free(userInput);
			yesNo = false;
			validInput = true;
		} else if (strcmp("Y", userInput) != 0 && strcmp("YES", userInput) != 0) {
			printf("\nYour Input Was Invalid\n");
			printf("\nPlease Enter Yes or No (Y/N): ");
			free(userInput);
			validInput = false;
		} else {
			free(userInput);
			yesNo = true;
			validInput = true;
		}
	} while (!validInput);
	return yesNo;
}

bool yesNoShowMenuAgain() {

	do {
		printf("\nWould you like to show the menu again? (Y/N): ");
		if (checkYesNo()) {
			return true;
		} else {
			return false;
		}

	} while (true);

}

INGREDIENT getIngredientInput(int id) {

	printf("\nPlease name your ingredient: ");
	char* userIngredientName = removeSpacesAndFormat(getUserInput());
	printf("Enter a measurement (Example: Cups, g, oz, etc.): ");
	char* userMeasurement;
	bool validOption;
	do {
		validOption = true;
		userMeasurement = getUserInput();

		//Check if numeric values were entered
		for (int i = 0; i < strlen(userMeasurement); i++) {
			if (isalpha(userMeasurement[i]) == 0) {
				validOption = false;
				break;
			}
		}

		if (validOption) {
			// If strlen is greater than 2 
			// (2 or less is the size of any lowercase measurement, such as ml, oz, g, etc)
			if (strlen(userMeasurement) > LOWERCASE_STR_LENGTH) {
				userMeasurement[0] = toupper(userMeasurement[0]);
			}
		} else {
			printf("Please enter a valid measurement: ");
			free(userMeasurement);
		}
		
	} while (!validOption);

	float userAmount;
	printf("How much? (Format = '0.00') (Enter 0 for no amount): ");
	do {
		validOption = true;
		char* userAmountAsChar = getUserInput();
		userAmount = atof(userAmountAsChar);

		//Check if alphbetically characters were entered
		for (int i = 0; i < strlen(userAmountAsChar); i++) {
			if (isalpha(userAmountAsChar[i]) > 0) {
				validOption = false;
				break;
			}
		}

		if (validOption) {
			//Check that value entered is not negative
			if (userAmount >= 0) {
				validOption = true;
			} else {
				printf("Please enter a valid number: ");
				validOption = false;
			}
		} else {
			printf("Please enter a valid number: ");
		}
		
		free(userAmountAsChar);
	} while (!validOption);

	INGREDIENT userIngredient = createIngredient(id, userIngredientName, userAmount, userMeasurement);
	free(userIngredientName);
	free(userMeasurement);
	return userIngredient;
}

bool yesNoAddIngredient() {

	do {
		printf("\nWould you like to add another ingredient? (Y/N): ");
		if (checkYesNo()) {
			return true;
		} else {
			return false;
		}

	} while (true);

}

bool yesNoAddEditIngredient() {

	do {
		printf("\nWould you like to add or edit another ingredient? (Y/N): ");
		if (checkYesNo()) {
			return true;
		} else {
			return false;
		}

	} while (true);
}

char* convertStringToUpper(char* input) {

	for (int i = 0; i < strlen(input); i++) {
		input[i] = toupper(input[i]);
	}
	return input;

}

char* removeSpacesAndFormat(char* input) {

	if (input == NULL) {
		return NULL;
	} else {
		input[0] = toupper(input[0]);
		int pos = 0;
		bool setCaps = false;
		for (int i = 0; i < strlen(input); i++) {
			//If space is detected, shift current letter to the position of the space
			if (input[i] != ' ') {
				if (setCaps) {
					input[pos++] = toupper(input[i]);
					setCaps = false;
				} else {
					input[pos++] = input[i];
				}
				
			} else {
				setCaps = true;;
			}
		}
		//null terminate the string after shifting
		input[pos] = '\0';
		return input;
	}
}