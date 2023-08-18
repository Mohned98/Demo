#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_
#include "SDB.h"
#include "STD.h"

struct node {
   student data;
   struct node *next;

}node;



void printList();
void insertfirstnode(student data);
void insertatend(student data);
void insertafternode(struct node *list, student data);
void deleteatbegin();
void deleteatend();
void deletenode(uint32  key);
int searchlist(uint32  key);
int getSize(struct node* head);
int display(uint32  key);





#endif /* LINKED_LIST_H_ */
