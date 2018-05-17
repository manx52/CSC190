/*
 ============================================================================
 Name        : testff.c
 Author      : Jonathan Spraggett
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
int binSearch(int key, int array[], int min,int max);

int main(void) {

	int n[] = {-1,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
	int m = sizeof(n) / sizeof(n[0]);
	int nn = binSearch(15,n,0,m);
	printf("Index: %i",nn);

	return 0;
}

int binSearch(int key, int array[], int min,int max) {

	if (max >= min) {

		int midpoint = min + (max - min)/2;

		if (array[midpoint] < key) {
			return binSearch(key,array,midpoint + 1,max);

		}
		else if (array[midpoint] > key) {
			return binSearch(key,array,min,midpoint - 1);

		}
		else {
			return midpoint;

		}
	}

	return -1;
}

