/*
 *	  Description: Functions for allocating and reallocating character arrays
 *
 *    Name:		Nick Prince
 *    Email:	nprince3037@conestogac.on.ca
 *    Course:	PROG71985 - Fall2020
 *
 *    Name:		Islam Ahmed
 *    Email:	Iahmed9886@conestogac.on.ca
 *    Course:	PROG71985 - Fall2020
 */

#include "Allocation.h"
#include <stdlib.h>
#include <string.h>

char* allocateCharArray() {
	char* str;
	str = (char*)malloc(MAX_NAME_LENGTH);
	memset(str, 0, MAX_NAME_LENGTH);
	return str;
}

char* reallocateCharArray(char* str, int size) {
	char* reallocatedStr = (char*)realloc(str, size * sizeof(char*));
	return reallocatedStr;
}