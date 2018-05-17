#include <stdio.h>
#include <stdlib.h>
struct bstNode {
   int val;
   struct bstNode *l;
   struct bstNode *r;
};
typedef struct bstNode bstNode;

struct que {
   int val;
   struct que *next;
}; typedef struct que que;
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
int add_bst(bstNode **root,int val) {
   if (root == NULL) { return -1; }
   if (*root == NULL) {
        *root = (bstNode*)malloc(sizeof(bstNode));
        (*root) -> val = val;
        (*root) -> l = NULL;
        (*root) -> r = NULL;

   } else {
        if (val > (*root) -> val){
                        return add_bst(&(*root) -> r,val);
                }
        else if (val < (*root) -> val){
                        return add_bst(&(*root) -> l,val);
                }



   }
   return 0;
}
int printTreeInOrder(bstNode *root){
        if (root == NULL ) { return -1; }



        printTreeInOrder(root -> l);
        printf("%d\n",root -> val);

        printTreeInOrder(root -> r);


        return 0;
}
int printLevelOrder(bstNode *root){
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
int help1(que *x, bstNode *xx){
        if (xx == NULL) {return -1;}
        if (xx -> l != NULL) {
                push(&x,xx -> l -> val);
        }
        if (xx -> r != NULL) {
                push(&x,xx -> r -> val);
        }
        help1(x,xx->l);
        help1(x,xx->r);
        return 0;
}

int main(void) {
   bstNode *root=NULL;
   int value = 0;
   while (scanf("%d",&value) != EOF) {

        add_bst(&root,value);
   }


   printTreeInOrder(root);

   return 0;
}
