struct avlNode {
   int balance; /* -1 Left, 0 balanced, +1 Right */
   int val;
   struct avlNode *l;
   struct avlNode *r;
};
typedef struct avlNode avlNode;

struct que {
   int val;
   struct que *next;
}; typedef struct que que;

int push(que **x,int val);
int add_bst(avlNode **root,int val);
int isAVL(avlNode **root);
int getHeight(avlNode **root);

int printTreeInOrder(avlNode *root);
int printLevelOrder(avlNode *root);

int help1(que *x, avlNode *xx);
int rotate(avlNode **root,unsigned int Left0_Right1);
int dblrotate(avlNode **root,unsigned int MajLMinR0_MajRMinL1);
