/*
 * SDB.c
 *
 *  Created on: Aug 17, 2023
 *      Author: Eid Elsayed Okda
 */
#include<stdio.h>
#include<stdlib.h>
#include"STD.h"
#include "SDB.h"
uint32 students_num=0;
 student st;
typedef struct node
{
	 student st;
	 struct node * next;
}node;
node *head ;

bool database_full()
	{
	if(students_num==10)
	   {
		printf("The database is full\n");
		return true;

	   }
	else
	   {
		printf("The database is not full\n");
		return false;
	   }
	}
uint8 SDB_GetUsedSize()
{
	printf("The number of students : %d\n",students_num);

	return students_num;
}
void SDB_DeletEntry (uint32 id)
{

	fflush(stdin);
	  node *temp = head, *prev;
	    // If head node itself holds the key to be deleted
	    if (temp != NULL && temp->st.Student_ID == id) {
	        head = temp->next; // Changed head
	        free(temp); // free old head

	    }

	    // Search for the key to be deleted, keep track of the
	    // previous node as we need to change 'prev->next'
	    while (temp != NULL && temp->st.Student_ID != id) {
	        prev = temp;
	        temp = temp->next;
	    }

	    // If id was not present in linked list
	    if (temp == NULL)
	        return;


	    // Unlink the node from linked list
	    prev->next = temp->next;
	    free(temp); // Free memory
	    students_num--;
	}
bool SDB_ReadEntry(int id)
{
	fflush(stdin);
  node* current = head;
  while (current != NULL) {
  if (current->st.Student_ID == id)
  {
	  printf("The ID exists in the database\n");
	  			printf("The student Id : %d",current->st.Student_ID);
	  			printf("The student year : %u",current->st.Student_year);
	  			printf("The course 1 Id : %u",current->st.Course1_ID);
	  			printf("The course 1 Grade : %u",current->st.Course1_grade);
	  			printf("The course 2 ID : %u",current->st.Course2_ID);
	  			printf("The course 2 Grade : %u",current->st.Course2_grade);
	  			printf("The course 3 ID : %u",current->st.Course3_ID);
	  			printf("The course 3 Grade : %u",current->st.Course3_grade);

  }
  else printf("The ID does not exist in the database\n");
  current = current->next;
  }
  return 1;
}
void SDB_GetList (node *print)
{
	fflush(stdin);
	int c=0;
	printf("The number of IDs of students:%u\n",students_num);
	while (print != NULL)
	{
		c++;
	 printf(" Student Id %d : %d  \n",c, print->st.Student_ID);
	  print = print->next;
    }
}

bool SDB_IsIdExist () {
	fflush(stdin);
  node* current = head;
  int id;
	printf("Enter the id");
	scanf("%d",&id);
  while (current != NULL) {
  if (current->st.Student_ID == id)
  {
	 printf("The ID exists in the database\n");
	  return 1;
  }
  else printf("The ID does not exist in the database\n");
  current = current->next;
  }
  return 1;
}
bool SDB_AddEntry()
{
    node *newNode;
    node *nodetemp;
    student nodeData;
    int nodeCounter; //nodeCounter is student number

    //allocate memory for starting node
    head = (node*)malloc(sizeof(node));

   //at this point you can check if the memory allocation is
   //and stop the program if not
    int numberOfNodes;
    	printf("Input the number of students you want to add:");
    	scanf("%d ", &numberOfNodes);
    printf("input data for student 1 ");
    createNodeList(nodeData);
            //save user input to the data element of the node
    head->st = nodeData;
            //initialize the nodes next pointer to null
            head->next = NULL;
            //Point the buffer to address of the first node
            nodetemp = head;
            for(nodeCounter =2; nodeCounter<=numberOfNodes; nodeCounter++)
                    {

                        newNode = (struct node*)malloc(sizeof(struct node));

                        //exit if new node cannot be allocated
                        if(newNode == NULL)
                        {
                            printf("Memory cannot be allocated.");
                            break;
                        }
                        else
                        {

                        	printf("input data for student %d",students_num);
                        	createNodeList(nodeData);
                            newNode->st = nodeData;
                            newNode->next = NULL;

                            //Link the previous node to the current node
                            nodetemp->next = newNode;
                            //copies address of current node
                            nodetemp = nodetemp->next;
                        }

                    }
            return true;

}
 void createNodeList(student st)
{
	students_num++;
	fflush(stdin);
	printf("\nEnter Student ID:");
	scanf("%d",&(st.Student_ID));
	printf("Enter Student year:");
	scanf("%u",&(st.Student_year));
	printf("Enter Course 1 ID:");
	scanf("%u",&(st.Course1_ID));
	printf("Enter Course 1 Grade:");
	scanf("%u",&(st.Course1_grade));
	printf("Enter Course 2 ID:");
	scanf("%u",&(st.Course2_ID));
	printf("Enter Course 2 Grade:");
	scanf("%u",&(st.Course2_grade));
	printf("Enter Course 3 ID:");
	scanf("%u",&(st.Course3_ID));
	printf("Enter Course 3 Grade:");
	scanf("%u",&(st.Course3_grade));
	printf("The data is added\n ");

}
