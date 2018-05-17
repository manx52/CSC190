#include <stdio.h>
#include <stdlib.h>

struct llnode {
   char value;
   struct llnode *next;
};
typedef struct llnode llnode;

int push(llnode **x,char value) {
   if (x==NULL) { return -1; }
   if (*x==NULL) {
      *x = (llnode *) malloc(sizeof(llnode));
      (*x)->value = value;
      (*x)->next = NULL;
      return 0;
   } else {
      return push(&((*x)->next),value);
   }
}

int llnode_print_from_head(llnode *x) {
   if (x==NULL) { return 0; }
   else {
      printf("%c\n",x->value);
      return llnode_print_from_head(x->next);
   }
}

int llnode_print_from_tail(llnode *x) {
   if (x==NULL) { return 0; }
   else {
      if (x->next == NULL) {
         printf("%c\n",x->value);
         return 0;
      } else {
         llnode_print_from_tail(x->next);
         printf("%c\n",x->value);
         return 0;
      }
   }
}

int llnode_add_to_head (llnode **head, char val){
         llnode *old_head;
        if (head == NULL) {
                return -1;
        }
        old_head = *head;

        *head = ( llnode *) malloc(sizeof( llnode));
        (*head) -> value = val;
        (*head) -> next = old_head;
        return 0;
}

int pop(llnode **x, char *return_value) {
        if (x == NULL) { return -1;}

        if ((*x)-> next  == NULL) {
                *return_value = (*x) -> value;
                free(*x);
 *x = NULL;
                return 0;
        }
        else {
                return pop(&((*x)-> next), return_value);
        }

}
int main(void) {
   int n=0;
   char value=0;
   int rvalue=0;
   char rr = 0;
   llnode *input_list=NULL;

   while (scanf("%c",&value) != EOF) {
      n=n+1;
      push(&input_list,value);
   }
   printf("INFO: you enter %d items\n",n);
   rvalue =pop(&input_list,&rr);

   if ( !(rvalue==0) ) { printf("ERR: llnode_print returned an error\n"); }
    return 0;
}
