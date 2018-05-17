#include <stdio.h>
#include <stdlib.h>
#include "avl.h"
int push(que **x,int val){
        if (*x == NULL){
                *x = (que*)malloc(sizeof(que));
                (*x) -> val = val;
                (*x) -> next = NULL;
        }
        else{
                return push(&(*x) -> next,val);
        }
        return 0;
}
int add_bst(avlNode **root,int val) {
   if (root == NULL) { return -1; }
   if (*root == NULL) {
        *root = (avlNode*)malloc(sizeof(avlNode));
        (*root) -> val = val;
        (*root) -> l = NULL;
        (*root) -> r = NULL;
        (*root) -> balance = 0;
   } else {
        if (val >= (*root) -> val){
                        return add_bst(&(*root) -> r,val);
                }
        else{
                        return add_bst(&(*root) -> l,val);
                }



   }
   return 0;
}
int isAVL(avlNode **root){
        int l;
        int r;
        l = getHeight(&(*root) -> l);
        r = getHeight(&(*root) -> r);
        if (abs(l-r) == 1 || abs(l-r) == 0 ){
                return 0;
        }
        else {
                return -1;
        }

}
int getHeight(avlNode **root){
        int l;
        int r;
        if (*root == NULL) {
                return 0;
        }
        l = getHeight(&(*root) -> l);
        r = getHeight(&(*root) -> r);
        if (r>l) {
                return r + 1;
        }
        else {
                return l +1;
        }
}
int printTreeInOrder(avlNode *root){
        if (root == NULL ) { return -1; }



        printTreeInOrder(root -> l);
        printf("%d\n",root -> val);

        printTreeInOrder(root -> r);


        return 0;
}
int printLevelOrder(avlNode *root){
        que *qued;
        if (root == NULL) {
                return -1;
        }
        qued = (que*)malloc(sizeof(que));
        qued -> val = root -> val;
        qued -> next = NULL;
        help1(qued,root);
        while (qued != NULL){
                printf("%d ",qued -> val);
                qued = qued -> next;
        }
}
int help1(que *x, avlNode *xx){
        if (xx == NULL) {return -1;}
        if (xx -> l != NULL) {
                push(&x,(xx -> l) -> val);
        }
        if (xx -> r != NULL) {
                push(&x,(xx -> r) -> val);
        }
        help1(x,xx->l);
        help1(x,xx->r);

}

int rotate(avlNode **root,unsigned int Left0_Right1){
        if (Left0_Right1 == 0){
                avlNode *tmp;
                if ((*root) -> r != NULL) {
                        avlNode *tmp2;
                        tmp = (*root) -> r;
                        tmp2 = (*root) -> r -> l;
                        tmp -> l = *root;
                        tmp -> l -> r = tmp2;
                        *root = tmp;
                }
                else if ((*root) -> l != NULL) {
                        return (&(*root) -> r,Left0_Right1);
                }

        }
        else if (Left0_Right1 == 1){
                avlNode *tmp;
                if ((*root) -> l != NULL) {
                        avlNode *tmp2;
                        tmp = (*root) -> l;
                    tmp2 = (*root) -> l -> r;
                        tmp -> r = *root;
                        tmp -> r -> l = tmp2;
                        *root = tmp;
                }
                else if ((*root) -> r != NULL) {
                        return (&(*root) -> r,Left0_Right1);
                }

        }
        else {
                return -1;
        }
        return 0;
}
int dblrotate(avlNode **root,unsigned int MajLMinR0_MajRMinL1){
        if (MajLMinR0_MajRMinL1 == 0) {
                int result;
                result = rotate(&(*root)->r,1);
                if (result == 0) {
                        rotate(&(*root),0);
                }
                else {
                        return -1;
                }
        }
        else if (MajLMinR0_MajRMinL1 == 1) {
                int result;
                result = rotate(&(*root)->l,0);
                if (result == 0) {
                        rotate(&(*root),1);
                }
                else {
                        return -1;
                }

        }
        else {
                return -1;
        }
        return 0;
}
                         
