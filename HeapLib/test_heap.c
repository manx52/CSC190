#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main(void) {
        HeapType *pHeap;
        int i;
        int *out;
        int *size = malloc(sizeof(int));
        int *rr;
        int *k = malloc(sizeof(int));
        pHeap =  (HeapType*)malloc(sizeof(HeapType)) ;
        initHeap(pHeap,7);
        addHeap(pHeap,10);
        addHeap(pHeap,5);
        addHeap(pHeap,7);
        addHeap(pHeap,3);
        addHeap(pHeap,2);

        inorder(pHeap,&rr,size);
        for (i = 0; i < pHeap -> end;i++) {
               printf("%d,", rr[i]);

        }
        printf("\n");
        preorder(pHeap,&rr,size);
        for (i = 0; i < pHeap -> end;i++) {
               printf("%d,", rr[i]);

        }
        printf("\n");
        postorder(pHeap,&rr,size);
        for (i = 0; i < pHeap -> end;i++) {
               printf("%d,", rr[i]);

        }
        printf("\n");
        printf("%d\n",findHeap(pHeap,7));
        delHeap(pHeap,k );
        printf("%d\n",*k);

        for (i = 0; i < pHeap -> end;i++) {
               printf("%d,", pHeap->store[i]);

        }



        return 0;
}

