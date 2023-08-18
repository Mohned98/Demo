#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "STD.h"





extern struct node *head = NULL;
struct node *current = NULL;

// display the list
void printList(){
   struct node *p = head;
   printf("\n[");

   //start from the beginning
   while(p != NULL) {
      printf(" %d \n",p->data.Student_ID);
      /*//printf(" %d\n ",p->data.Student_year);
      //printf(" %d \n",p->data.Course1_ID);
      //printf(" %d \n",p->data.Course1_grade);
      //printf(" %d \n",p->data.Course2_ID);
      //printf(" %d \n",p->data.Course2_grade);
      //printf(" %d \n",p->data.Course3_ID);
      //printf(" %d \n",p->data.Course3_grade);
     // printf("////////////////////////////////////////////////////\n");*/

      p = p->next;
   }
   printf("]");
}

//insertion at the beginning
void insertfirstnode(student data){

   //create a link
   struct node *lk = (struct node*) malloc(sizeof(struct node));
   lk->data.Student_ID = data.Student_ID;
   lk->data.Student_year = data.Student_year;
   lk->data.Course1_ID = data.Course1_ID;
   lk->data.Course1_grade = data.Course1_grade;
   lk->data.Course2_ID = data.Course2_ID;
   lk->data.Course2_grade= data.Course2_grade;
   lk->data.Course3_ID = data.Course3_ID;
   lk->data.Course3_grade = data.Course3_grade;



   //point first to  first node
   head = lk;
}
void insertatend(student data){

   //create a link
   struct node *lk = (struct node*) malloc(sizeof(struct node));
   lk->data.Student_ID = data.Student_ID;
      lk->data.Student_year = data.Student_year;
      lk->data.Course1_ID = data.Course1_ID;
      lk->data.Course1_grade = data.Course1_grade;
      lk->data.Course2_ID = data.Course2_ID;
      lk->data.Course2_grade= data.Course2_grade;
      lk->data.Course3_ID = data.Course3_ID;
      lk->data.Course3_grade = data.Course3_grade;

   struct node *linkedlist = head;

   // point it to old first node
   while(linkedlist->next != NULL)
      linkedlist = linkedlist->next;

   //point first to new first node
   linkedlist->next = lk;
}
void insertafternode(struct node *list, student data){
   struct node *lk = (struct node*) malloc(sizeof(struct node));
   lk->data.Student_ID = data.Student_ID;
      lk->data.Student_year = data.Student_year;
      lk->data.Course1_ID = data.Course1_ID;
      lk->data.Course1_grade = data.Course1_grade;
      lk->data.Course2_ID = data.Course2_ID;
      lk->data.Course2_grade= data.Course2_grade;
      lk->data.Course3_ID = data.Course3_ID;
      lk->data.Course3_grade = data.Course3_grade;

   lk->next = list->next;
   list->next = lk;
}
void deleteatbegin(){
   head = head->next;
}
void deleteatend(){
   struct node *linkedlist = head;
   while (linkedlist->next->next != NULL)
      linkedlist = linkedlist->next;
   linkedlist->next = NULL;
}
void deletenode(uint32  key){
   struct node *temp = head, *prev;
   if (temp != NULL && temp->data.Student_ID == key) {
      head = temp->next;
      return;
   }

   // Find the key to be deleted
   while (temp != NULL && temp->data.Student_ID != key) {
      prev = temp;
      temp = temp->next;
   }

   // If the key is not present
   if (temp == NULL) return;

   // Remove the node
   prev->next = temp->next;
}
int searchlist(uint32  key){
   struct node *temp = head;
   while(temp != NULL) {
      if (temp->data.Student_ID == key) {
         return 1;
      }
      temp=temp->next;
   }
   return 0;
}
int getSize(struct node* head)
{
    int count = 0; // Initialize count
    struct node* current = head; // Initialize current
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;

}


int display(uint32  key){
   struct node *temp = head;
   while(temp != NULL) {
      if (temp->data.Student_ID == key) {
    	  printf(" %d \n",temp->data.Student_ID);
    	        printf(" %d\n ",temp->data.Student_year);
    	        printf(" %d \n",temp->data.Course1_ID);
    	        printf(" %d \n",temp->data.Course1_grade);
    	        printf(" %d \n",temp->data.Course2_ID);
    	        printf(" %d \n",temp->data.Course2_grade);
    	        printf(" %d \n",temp->data.Course3_ID);
    	        printf(" %d \n",temp->data.Course3_grade);
         return 1;
      }
      temp=temp->next;
   }
   return 0;
}


