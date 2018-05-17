#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

/* One of the lessons here is to see that if we want to use a function to malloc something that
 * is a POINTER in the CALLER of the function, then we must send in the ADDRESS of the POINTER
 * to that function.
 *
 * Recap: if we want to use a function to modify a VARIABLE in the caller
 *        then the CALLER needs to send in the ADDRESS of the VARIABLE
 *
 * Similarly: if we want to use a function to modify a POINTER in the caller
 *            then the CALLER needs to send in the ADDRESS of the POINTER
 *
 * In the code below, ll_add_to_head and ll_add_to_tail are dynamically creating new
 * nodes to be added to the linked list. Any dynamic creation of a node must be via
 * malloc.
 */

int ll_add_to_head( llnode **head, int val) {
    llnode *old_head;
   if (head == NULL) {
      return -1;
   }
        old_head = *head;

   *head = ( llnode *) malloc(sizeof( llnode));
   (*head) -> val = val;
   (*head) -> next = old_head;
   (*head) -> prev = old_head -> prev;
   old_head -> prev = *head;
   (old_head -> next) -> prev = old_head;
        return 0;
}

int ll_add_to_tail( llnode **head, int val) {
   if (head == NULL) {
      return -1;
   }
   if (*head == NULL) {
        *head = (llnode *) malloc(sizeof(llnode));
        (*head) -> val = val;
        (*head) -> next = NULL;
        (*head) -> prev = NULL;
   }
   else if ((*head)-> next == NULL) {
      (*head)-> next = ( llnode *) malloc(sizeof( llnode));
      ((*head) -> next ) -> val = val;
      ((*head) -> next) -> next = NULL;
      ((*head) -> next) -> prev = *head;
      return 0;
   } else { /* recursively call ll_add_to_tail until we get to the tail
                                        which is the point where the pointer is NULL */
      return ll_add_to_tail(&((*head)->next), val);
   }
}

int ll_print( llnode *p) {
   if (p==NULL) {
      return 0;
   } else {
      printf("val = %d\n",p->val);
 return ll_print(p->next);
   }
}

int ll_free( llnode *p) {
   if (p==NULL) {
      return -1;
   } else {
       llnode *f=p->next;
      free(p);
      return ll_free(f);
   }
}

int ll_find_by_value (llnode *pList, int val){
        if (pList == NULL){
                return -1;
        }
        if (pList ->val == val){
                return 0;
        }
        else{
                return ll_find_by_value (pList -> next,val);
        }
}

int ll_del_from_tail (llnode **ppList){
        if (ppList == NULL){
                return -1;
        }
        if ((*ppList)-> next == NULL) {
                free(*ppList);
                *ppList = NULL;
        }
        else if ((((*ppList) -> next)-> next) ==NULL){

                free ( (*ppList)->next);

                (*ppList)-> next = NULL;
        }
        else {
                return ll_del_from_tail( &((*ppList)->next) );

        }
}

int ll_del_from_head (llnode **ppList){

        if (ppList == NULL){
                return -1;
        }
        else{
                llnode *tmp;

                if ( (*ppList)-> next == NULL) {
                   free(*ppList);
                *ppList = NULL;
                }
                else {
                        tmp = (*ppList)-> next;

                        free (*ppList);
 (*ppList)= tmp;

                        (*ppList)-> prev = NULL;
                }

        }
        return 0;
}

int ll_del_by_value (llnode **ppList, int val){
        if (ppList == NULL){
                return -1;
        }
        if ((*ppList) ->val == val){
                ll_del_from_head(&(*ppList));
        }
        if ((*ppList) == NULL){
                return -1;
        }
        else{
                return ll_del_by_value (&((*ppList) ->next),val);
        }
        return 0;
}

int ll_sort(llnode **ppList){
         llnode *current;
        int swapped = 0;
        int temp =0;
        current = NULL;

        if (ppList ==NULL){
                return -1;
        }
        if ((*ppList) -> next == NULL){
                return -1;
        }
        while (swapped == 0){
                swapped = -1;
                current = *ppList;
                while ((current -> next) != NULL){
                        if ( (current-> next ->val) < (current -> val)){
                                temp= (current ->val);
                                current -> val = current ->next -> val;
                                current -> next -> val  = temp;
                                swapped = 0;
                        }
                current = current ->next;
                }
        }
        return 1;
}
int ll_concat (llnode **pSrcA, llnode **pSrcB){
        if ((pSrcA) == NULL){
                (*pSrcA) = (*pSrcB);
        }
        if (pSrcB == NULL){
                (*pSrcA) = (*pSrcA);
        }
        else{
                return ll_concat (&((*pSrcA) -> next),& (*pSrcB));
  }
        return 0;
}

int ll_insert_in_order(llnode **ppList,int val) {
   llnode *prev = NULL;
   llnode *curr = NULL;
        if (ppList == NULL) {
                return -1;
        }

   if (*ppList == NULL) {
      return ll_add_to_head(ppList,val);
   }
   if ((*ppList) -> val > val) {
      return ll_add_to_head(ppList,val);
   }
    else {
      prev = *ppList;
      curr = (*ppList)->next;
      while(curr != NULL) {
         if (curr->val > val) {
            break;
         }
        else {
            prev = curr;
            curr = prev->next;
         }
      }
      prev->next = (llnode *) malloc(sizeof(llnode));
      prev->next->val  = val;
      prev->next->next = curr;
      return 0;
   }
}
