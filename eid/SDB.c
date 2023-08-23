/*
 * SDB.c
 *
 *  Created on: Aug 17, 2023
 *      Author: Eid Elsayed Okda
 */
#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include"STD.h"
#include "SDB.h"
uint32 students_num=0;
student st;
typedef struct node
{
	 student st;
	 struct node * next;
}node;


node *head,*newstudent ;


void SDB_AddEntry()
{
	node* temp;
	head=0;
//	 newstudent=(node *)malloc(sizeof(node));
	 uint32 numberofstudents,num;
	 printf("Enter the number of students you want to add : ");
	 while(1)
		 {
		 fflush(stdin);

		 scanf("%d",&num);
		 numberofstudents=num+students_num;
		 if(numberofstudents<3 || numberofstudents>10)
		 {
			 printf("Invalid number\nThe range of the data base (3:10) students\n");
			 printf("The number of students now = %d\n",students_num);
			 printf("Enter the number of students you want to add : ");
		 }
		 else
		 {
			 break;
		 }
		 }

	 for(int i=0;i<num;i++)
	 {
		 newstudent=(node *)malloc(sizeof(node));
		 students_num++;
		 int num_of_digits=0;
		 int check=1;
		 printf("Please, enter the data in numbers\n");
		 printf("Student %d data",i+1);
		 printf("\nEnter Student %d ID (4 digits) : ",i+1);
     while(check!=0)
      {
		 scanf("%u",&newstudent->st.Student_ID);
		int num =newstudent->st.Student_ID;
		 for( num_of_digits=0;num!=0;num_of_digits++)//to check if the input is number or not
		 {
			 num /=10;
		 }
		 if(num_of_digits==4)
		 {
			 check=0;
		 }
		 else
		 {
			 fflush(stdin);
			 printf("Wrong input\nPlease try again and  enter the data in 4 digits.\n ");
			 printf("Enter Student %d ID (4 digits)  : ",i+1);
		 }
      }

     check=1;
		 printf("Enter Student %d year (4 digits) : ",i+1);
		 while(check!=0)
		      {

				 scanf("%u",&newstudent->st.Student_year);
				int num =(int)newstudent->st.Student_year;
				 for( num_of_digits=0;num!=0;num_of_digits++)//to check if the input is number or not
				 {
					 num /=10;
				 }
				 if(num_of_digits==4)
				 {
					 check=0;
				 }
				 else
				 {
					 fflush(stdin);
					 printf("Wrong input\nPlease try again and  enter the data in 4 digits.\n ");
					 printf("Enter Student %d year (4 digits) : ",i+1);
				 }
		      }
		 printf("Enter Course 1 ID (4 digits) :");
		 check=1;
		 while(check!=0)
		      {

				 scanf("%u",&newstudent->st.Course1_ID);
				int num =(int)newstudent->st.Course1_ID;
				 for( num_of_digits=0;num!=0;num_of_digits++)//to check if the input is number or not
				 {
					 num /=10;
				 }
				 if(num_of_digits==4)
				 {
					 check=0;
				 }
				 else
				 {
					 fflush(stdin);
					 printf("Wrong input\nPlease try again and  enter the data in 4 digits.\n ");
					 printf("Enter Course 1 ID (4 digits) :");
				 }
		      }
		 printf("Enter Course 1 Grade (2 digits) :");
		 check=1;
		 while(check!=0)
		      {

				 scanf("%u",&newstudent->st.Course1_grade);
				int num =(int)newstudent->st.Course1_grade;
				 for( num_of_digits=0;num!=0;num_of_digits++)//to check if the input is number or not
				 {
					 num /=10;
				 }
				 if(num_of_digits==2)
				 {
					 check=0;
				 }
				 else
				 {
					 fflush(stdin);
					 printf("Wrong input\nPlease try again and  enter the data in 2 digits.\n ");
					 printf("Enter Course 1 Grade (2 digits) :");
				 }
		      }
		 printf("Enter Course 2 ID (4 digits) :");
		 check=1;
		 while(check!=0)
		      {
				 scanf("%u",&newstudent->st.Course2_ID);
				int num =(int)newstudent->st.Course2_ID;
				 for( num_of_digits=0;num!=0;num_of_digits++)//to check if the input is number or not
				 {
					 num /=10;
				 }
				 if(num_of_digits==4)
				 {
					 check=0;
				 }
				 else
				 {
					 fflush(stdin);
					 printf("Wrong input\nPlease try again and  enter the data in 4 digits.\n ");
					 printf("Enter Course 2 ID (4 digits ):");
				 }
		      }
		 printf("Enter Course 2 Grade (2 digits) :");
		 check=1;
		 while(check!=0)
		      {
				 scanf("%u",&newstudent->st.Course2_grade);
				int num =(int)newstudent->st.Course2_grade;
				 for( num_of_digits=0;num!=0;num_of_digits++)//to check if the input is number or not
				 {
					 num /=10;
				 }
				 if(num_of_digits==2)
				 {
					 check=0;
				 }
				 else
				 {
					 fflush(stdin);
					 printf("Wrong input\nPlease try again and  enter the data in 2 digits.\n ");
					 printf("Enter Course 2 Grade (2 digits) :");
				 }
		      }
		 printf("Enter Course 3 ID (4 digits) :");
		 check=1;
		 while(check!=0)
		      {
				 scanf("%u",&newstudent->st.Course3_ID);
				int num =(int)newstudent->st.Course3_ID;
				 for( num_of_digits=0;num!=0;num_of_digits++)//to check if the input is number or not
				 {
					 num /=10;
				 }
				 if(num_of_digits==4)
				 {
					 check=0;
				 }
				 else
				 {
					 fflush(stdin);
					 printf("Wrong input\nPlease try again and  enter the data in 4 digits.\n ");
					 printf("Enter Course 3 ID (4 digits) :");
				 }
		      }
		 check =1;
		 printf("Enter Course 3 Grade (2 digits) :");
		 while(check!=0)
		      {
				 scanf("%u",&newstudent->st.Course3_grade);
				int num =(int)newstudent->st.Course3_grade;
				 for( num_of_digits=0;num!=0;num_of_digits++)//to check if the input is number or not
				 {
					 num /=10;
				 }
				 if(num_of_digits==2)
				 {
					 check=0;
				 }
				 else
				 {
					 fflush(stdin);
					 printf("Wrong input\nPlease try again and  enter the data in 2 digits.\n ");
					 printf("Enter Course 3 Grade (2 digits) :");
				 }
		      }

		 printf("The data of student %d is added in the database. \n ",students_num);//students_num is the index of student in the data base not the index of the students entered in this action
	     newstudent->next=0;
		 if(head==0)
		 {
			 head=temp=newstudent;
		 }
		 else
		 {
			 temp->next=newstudent;
			 temp=newstudent;
		 }

	 }
	 temp=head;
}




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
	//fflush(stdin);
	  node *prev, *temp = head;
	    // If head node itself holds the key to be deleted
	    if (temp != NULL && temp->st.Student_ID == id)
	    {
	    	students_num--;
	        head = temp->next; // Changed head
	        free(temp); // free old head
	        printf("The data is deleted from the database\n");
	        return;
	    }

	    // Search for the key to be deleted, keep track of the
	    // previous node as we need to change 'prev->next'
	    while (temp != NULL && temp->st.Student_ID != id)
	    {
	        prev = temp;
	        temp = temp->next;
	    }

	    // If id was not present in linked list
	    	if( temp==NULL)
	    		{
	    			printf("This ID isn't exist in the database\n");
	    			return;
	    		}
	    // if the database is empty
	    	if( students_num==0)
	    		{
	    			printf("No students in the database\n");
	    			return;
	    		}
	    // Unlink the node from linked list
	    	students_num--;
	    prev->next = temp->next;
	    free(temp); // Free memory
	    printf("The data is deleted from the database\n");
	}



bool SDB_ReadEntry(int id)
{
  node* current = head;
  if(current==NULL)
  {
	  printf("The data base is empty.\n");
  }
  else
  {
	  uint32 c=1;
	  while(c !=0)
	  {
  if (current->st.Student_ID == id)
  {
	  printf("The ID exists in the database\n");
	  printf("The student Id : %d\n",current->st.Student_ID);
	  printf("The student year : %u\n",current->st.Student_year);
	  printf("The course 1 Id : %u\n",current->st.Course1_ID);
	  printf("The course 1 Grade : %u\n",current->st.Course1_grade);
	  printf("The course 2 ID : %u\n",current->st.Course2_ID);
	  printf("The course 2 Grade : %u\n",current->st.Course2_grade);
	  printf("The course 3 ID : %u\n",current->st.Course3_ID);
	  printf("The course 3 Grade : %u\n",current->st.Course3_grade);
	  c=5;
	  break;
  }

  else
  {
	  current = current->next;
  }
	  }
	  if(c!=5)
	  {
		  printf("The ID does not exist in the database\n");
	  }

  }
  return 1;
}



void SDB_GetList ()
{

	//fflush(stdin);
	node * print =head;
	int c=0;
	printf("The number of IDs of students:%u\n",students_num);
	while (print != NULL && c < students_num)
	{
		c++;
	 printf(" Student %d Id : %d  \n",c, print->st.Student_ID);
	  print = print->next;
    }
	if( students_num==0)
	{
		printf("No students in the database\n");
	}
}



bool SDB_IsIdExist () {
	fflush(stdin);
  node* current = head;
  int id;
  if(students_num==0)
  {
	  printf("The data base is empty");
  }
	printf("Enter the id : ");
	scanf("%d",&id);
  while (current != NULL)
  {
  if (current->st.Student_ID == id)
  {
	 printf("The ID exists in the database\n");
	  break;
  }
  else
	  {
	  current = current->next;
	  }
  }
  if(current==NULL)
  {
	  printf("The ID does not exist in the database\n");
  }
  return 1;
}




