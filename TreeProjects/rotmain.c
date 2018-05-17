#include <stdio.h>
#include <stdlib.h>
#include "avl.h"


int main(void) {
   avlNode *root;
   avlNode *root2;
   avlNode *root3;
   add_bst(&root,5);
   add_bst(&root,3);
   add_bst(&root,14);
   add_bst(&root,15);
   add_bst(&root,11);
   add_bst(&root,10);
   add_bst(&root,12);
   root2 = NULL;
   add_bst(&root2,14);
   add_bst(&root2,5);
   add_bst(&root2,3);
   add_bst(&root2,15);
   add_bst(&root2,11);
   add_bst(&root2,10);
   add_bst(&root2,12);
   root3=NULL;
   add_bst(&root3,5);
   add_bst(&root3,3);
   add_bst(&root3,7);
   add_bst(&root3,6);
   add_bst(&root3,8);


   printf("%d\n",isAVL(&root));
   printf("%d\n",isAVL(&root2));
   printf("%d\n",isAVL(&root3));
   printLevelOrder(root3);
   printf("\n");
   rotate(&root3,0);
   printLevelOrder(root3);
   printf("\n");

   printLevelOrder(root);
   printf("\n");
   dblrotate(&root,0);
   printLevelOrder(root);
   printf("\n");
   printLevelOrder(root2);
   printf("\n");
   dblrotate(&root2,1);
   printLevelOrder(root2);
   printf("\n");
   printf("%d\n",isAVL(&root));
   printf("%d\n",isAVL(&root2));


   return 0;

}
