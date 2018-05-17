/*
 ============================================================================
 Name        : ff.c
 Author      : Jonathan Spraggett
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{

    int binary[8];
    int j,k,l,m;

for ( l = 0; l <= 8; l++)
    binary[l] = 0;


char n[100];
printf("Give word: ");
scanf("%s",n);

m = strlen(n);
    for (int i = 0; n[i] != '\0'; i++) {
        for ( l = 0; l <= 8; l++)
            binary[l] = 0;

            l = 0;
    // calculate binary digits by repeatedly dividing by 2
        for ( j = 0; n[i] != 0; j++, n[i] /= 2)
            binary[j] = n[i] % 2;

        j = 0;
    // print out binary array
        for (k = 7 ; k >= 0; k--)
            printf("%i", binary[k]);

        k = 7;
        printf(" ");
    }



    return 0;
}
