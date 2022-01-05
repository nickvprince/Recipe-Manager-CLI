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

#pragma once

#define MAX_NAME_LENGTH 255

char* allocateCharArray();
char* reallocateCharArray(char* str, int size);