/* * * * * * *
 * Module providing several hash functions for strings
 *
 * created for COMP20007 Design of Algorithms 2017
 * by Matt Farrugia <matt.farrugia@unimelb.edu.au>
 * 
 * additional hash function implementations by ...
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "strhash.h"

// hash everything to a random value (mod size)
unsigned int random_hash(const char *key, unsigned int size) {
	return rand() % size;
}

// hash everything to zero
unsigned int zero_hash(const char *key, unsigned int size) {
	return 0;
}


/* * *
 * ADD YOUR OWN HASH FUNCTIONS HERE
 */


// generate a hash value for key (a string) to a hash table of size entries,
// using hash method 'method'
// guarantees a return value between 0 (inclusive) and size (non inclusive)
unsigned int hash(const char *key, unsigned int size, char method) {
	switch(method) {
		// really bad hash functions:
		case '0':
			return zero_hash(key, size);
		case 'r':
			return random_hash(key, size);
		
		// once you have implemented your own hash functions,
		// add cases to this function to access them from main.c

		default:
			fprintf(stderr, "unknown hashing method '%c'\n", method);
			exit(1);
	}
}

// return the string name of a hash function specified by method
char *name(char method) {
	switch(method) {
		case '0':
			return "zero hash";
		case 'r':
			return "random hash";
		
		// once you have implemented your own hash functions,
		// add cases to this function to access their names from main.c

		default:
			return "unknown";
	}
}
