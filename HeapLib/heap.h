typedef struct{
   int *store;
   unsigned int size;
   unsigned int end;
}HeapType;

int initHeap (HeapType *pHeap,int size);
int addHeap(HeapType *pHeap, int key);
int help1(HeapType *pHeap,int end ) ;
int findHeap(HeapType *pHeap, int key);
int help2(HeapType *pHeap,int pos );
int delHeap(HeapType *pHeap, int *key) ;
int inorder  (HeapType *pHeap, int **output, int *o_size);
int help3(HeapType *pHeap,int pos, int * arr, int count );
int preorder (HeapType *pHeap, int **output, int *o_size);
int help4(HeapType *pHeap,int pos, int * arr, int count );
int postorder(HeapType *pHeap, int **output, int *o_size);
int help5(HeapType *pHeap,int pos, int * arr, int count );
