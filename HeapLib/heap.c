#include <stdio.h>
#include <stdlib.h>
#include "heap.h"


int initHeap (HeapType *pHeap,int size){
        int i;
        if (pHeap == NULL) {
                return -1;
        }
        pHeap -> store = (int*)malloc(sizeof(int) * size);
        pHeap -> size = size;
        pHeap -> end = 0;
        for (i = 0; i < pHeap -> size;i++) {
                /*pHeap -> store[i] = 0;*/

        }
        return 0;


}

int addHeap(HeapType *pHeap, int key) {
        if (pHeap == NULL){
                return -1;
        }
        if ((pHeap -> end + 1) <= pHeap -> size) {
                pHeap -> store[pHeap->end] = key;
                help1(pHeap,pHeap -> end);
                pHeap -> end += 1;

        }
        return 0;

}
int help1(HeapType *pHeap,int end ) {
        if (end >= 1) {
                int parent;
                if (end % 2 == 0){
                        parent = (end - 2)/2;
                }
                else{
                         parent = (end - 1)/2;
                }
                if (parent < 0) {
                        return -1;

                }
                if (pHeap -> store[end] > pHeap -> store[parent]){
                        int tmp;
                        tmp = pHeap -> store[parent];
                        pHeap -> store[parent] = pHeap -> store[end];
                        pHeap -> store[end] = tmp;
                        return help1(pHeap, end -1);
                }

        }
        else{
                return -1;

        }
        return 0;
                      }

int findHeap(HeapType *pHeap, int key) {
        int i;
        if (pHeap == NULL || pHeap -> store == NULL) {
                return -1;
        }
        for (i = 0; i < pHeap -> end;i++) {
                if(pHeap -> store[i] == key) {
                        return 1;
                }
        }
        return 0;
}



int help2(HeapType *pHeap,int pos ) {
        int l;
        int r;
        l = (2 * pos) + 1;
        r = (2 * pos) + 2;
        if (l >= pHeap -> end ) {
                return 0;
        }

        if (pHeap -> store[l] > pHeap -> store[pos]){
                int tmp;
                tmp = pHeap -> store[pos];
                pHeap -> store[pos] = pHeap -> store[l];
                pHeap -> store[l] = tmp;
                tmp =  help2(pHeap,l );
        }
        if ( r >= pHeap -> end) {
                return 0;
        }

        if(pHeap -> store[r] > pHeap -> store[pos]){
                int tmp;
                tmp = pHeap -> store[pos];
                pHeap -> store[pos] = pHeap -> store[r];
                pHeap -> store[r] = tmp;
                tmp = help2(pHeap,r);

        }
        return 0;
}
int delHeap(HeapType *pHeap, int *key) {
        int k;
        if (pHeap == NULL || (pHeap -> end == 0)) { return -1;}
        *key = pHeap -> store[0];
        pHeap -> store[0] = pHeap -> store[(pHeap -> end)-1];
        pHeap -> end -= 1;
        pHeap -> store[pHeap -> end] = 0;
        k = 0;
        k =help2(pHeap, 0);
        return k;
}

int inorder  (HeapType *pHeap, int **output, int *o_size) {
        if (pHeap == NULL ) {return -1;}
                         *o_size = pHeap -> end;
        *output = (int*)malloc(sizeof(int) * (*o_size));
        help3(pHeap,0,*output,0);
        return 0;
}
int help3(HeapType *pHeap,int pos, int * arr, int count ) {
        int l,ll;
        int r;
        int tmp;
        l = (2 * pos) + 1;
        r = (2 * pos) + 2;
        ll = (2 * l) + 1;
        if (l >=  pHeap -> end ) {
                arr[count] = pHeap -> store[pos];
                count += 1;
                return count;
        }
        count = help3(pHeap,l,arr,count);

        arr[count] = pHeap -> store[pos];
        count += 1;
        if ( r >=  pHeap -> end) {
                arr[count] = pHeap -> store[pos];
                count += 1;
                return count;
        }


        count = help3(pHeap,r,arr,count);
        return count;



}

int preorder (HeapType *pHeap, int **output, int *o_size) {
        if (pHeap == NULL ) {return -1;}
        *o_size = pHeap -> end;
        *output = (int*)malloc(sizeof(int) * (*o_size));
        help4(pHeap,0,*output,0);
        return 0;
}
int help4(HeapType *pHeap,int pos, int * arr, int count ) {
        int l,ll;
        int r;
        int tmp;
        l = (2 * pos) + 1;
        r = (2 * pos) + 2;
        ll = (2 * l) + 1;
        arr[count] = pHeap -> store[pos];
        count += 1;
if (l >=  pHeap -> end ) {
                return count;
        }
        count = help4(pHeap,l,arr,count);

        if ( r >=  pHeap -> end) {
                arr[count] = pHeap -> store[pos];
                count += 1;
                return count;
        }

        count = help4(pHeap,r,arr,count);
        return count;



}
int postorder(HeapType *pHeap, int **output, int *o_size) {
         if (pHeap == NULL ) {return -1;}
        *o_size = pHeap -> end;
        *output = (int*)malloc(sizeof(int) * (*o_size));
        help5(pHeap,0,*output,0);
        return 0;


}
int help5(HeapType *pHeap,int pos, int * arr, int count ) {
        int l,ll;
        int r;
        int tmp;
        l = (2 * pos) + 1;
        r = (2 * pos) + 2;
        ll = (2 * l) + 1;
        if (l >=  pHeap -> end ) {
                arr[count] = pHeap -> store[pos];
                count += 1;
                return count;
        }
        count = help5(pHeap,l,arr,count);

        if ( r >=  pHeap -> end) {
                arr[count] = pHeap -> store[pos];
                count += 1;
                return count;
        }

        count = help5(pHeap,r,arr,count);
        arr[count] = pHeap -> store[pos];
        count += 1;
        return count;



}
