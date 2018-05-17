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
int  popCheck (llnode *head, char val) {
        if (head == NULL) {
                return 1;
        }
        if ((head -> next) == NULL) {
                if ((head -> value) == val) {
                        return 0;
                }
                else {
                        return 1;
                }
        }
        else {
                return popCheck(head -> next, val);
        }
}
int main(void) {
   char value=0;
   int rvalue=0;
   char rr = 0;
   int count = -1;
   int  neg = 1;
   int check = 0;
   llnode *input_list=NULL;

   while (scanf("%c",&value) != EOF) {
         count += 1;
        if (((value == '(') || (value == '{')) || (value == '[') )  {
                push(&input_list,value);

        }
        if (((value == ')') || (value == '}')) || (value == ']') )  {
                char store = 0;
                if (value == ')') {
                        store = '(';
                }
                else if (value == '}') {
                        store = '{';

                }
                else {
                         store = '[';
                }
                neg = popCheck(input_list,store);
                if (neg == 0) {
                        rvalue =pop(&input_list,&rr);
                        neg = 1;
                }
                else {
                        check = 1;
                        break;
     }
        }


   }
  if (input_list == NULL && check == 0) {
        printf("PASS\n");
  }
  else {
        printf("FAIL,%d\n",count);
  }

   return 0;
}
