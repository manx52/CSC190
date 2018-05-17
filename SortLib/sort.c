
1/*
 ============================================================================
 Name        : testf.c
 Author      : Jonathan Spraggett
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void selecsort(int arr[],int size);
void insertsort(int arr[],int size);
void bubsort(int arr[],int size);

int main(void)
{
	int arr[] = {4, 65, 2, -31, 0, 99, 3, 83, 782, 1};
   int n = sizeof(arr)/ sizeof(arr[0]);
   bubsort(arr,n);

   for (int k = 0 ; k < n; k++)
               printf("%i\t", arr[k]);

   return 0;
}

void selecsort(int arr[], int size) {
	for (int i = 0; i < size ; i++ ) {
		int min = i;
		for (int j = i +1; j < size; j++) {
			if (arr[j] < arr[min]){
				min = j;
			}
		}
		if (min != i){
				int m = arr[min];
				arr[min] = arr[i];
				arr[i] = m;
		}

	}

}

void insertsort(int arr[], int size) {
	int j, element;
   for (int i = 1; i < size; i++) {

	  for (j = i, element = arr[i];j > 0 && element < arr[j - 1]; j--) {
		   arr[j] = arr[j - 1];

	   }
	   arr[j] = element;
   }


}

void bubsort(int arr[], int size) {
	int e;
	for (int i = 0; i < size; i++) {
		for (int j = 1; j < size; j++) {
		 if (arr[j - 1] > arr [j]) {
				e = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = e;
			}

		}

	}


}

