#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STD.h"
#include "SDB.h"
#include "SDB_APP.h"
#include "linkedlist.h"

struct node* start=NULL;


void SDB_APP ()
{
	 int choice;
	 	 	 	 	 	printf("                MENU                             \n");
		                printf(" 1. To add entry, enter 1  \n");
		                printf(" 2. To get used size in database, enter 2   \n");
		                printf(" 3. To read student data, enter 3    \n");
		                printf(" 4. To get the list of all student IDs, enter 4  \n");
		                printf(" 5. To check is ID is existed, enter 5       \n");
		                printf(" 6. To delete student data, enter 6      \n");
		                printf(" 7. To check is database is full, enter 7        \n");
		                printf(" 8. To exit enter 0       \n");
		                printf("--------------------------------------\n");
		  while(1)
		                {

              printf("Enter your choice:\n");
	                scanf("%d",&choice);
	                if(choice==0)
	                {
	                	break;
	                }
	                else
	                { SDB_action ( choice, start);

	                }

		                }

}
void SDB_action (uint8 choice,struct node* start )
{int key;
student data ;


		            switch (choice)   {
		                        case 1:
		                        				printf("please enter the data");
		                        				printf("please enter Student_ID");
		                        		        scanf("%d",data.Student_ID);
		                        		        printf("please enter Student_year");
		                        		        scanf("%d",data.Student_year);
		                        				printf("please enter Course_ID");
		                        				scanf("%d",data.Course1_ID);
		                        				printf("please enter Course1_GRADE");
		                        				scanf("%d",data.Course1_grade);
		                        				printf("please enter Course2_ID");
		                        				scanf("%d",data.Course2_ID);
		                        				printf("please enter Course2_GRADE");
		                        				scanf("%d",data.Course2_grade);
		                        				printf("please enter Course3_ID");
		                        				scanf("%d",data.Course3_ID);
		                        				printf("please enter Course3_GRADE");
		                        				scanf("%d",data.Course3_grade);
		                        				if(start==NULL)
		                        				{
		                        					insertfirstnode(data);
		                        				}
		                        				else
		                        				{
		                        					SDB_AddEntry(data,start);
		                        				}
		                        					break;

		                        case 2:

		                        		 		printf("used size is %d \n", SDB_GetUsedSize(start));
		                                        break;
		                        case 3:
		                        				printf("please enter id");
		                        				scanf("%d", &key);
		                        				SDB_ReadEntry ( key);
		                                        break;
		                        case 4:
		                        				SDB_GetList ();
		                                        break;
		                        case 5:
		                        				printf("please enter id:");
		                        				scanf("%d", &key);
		                        				SDB_IsIdExist(key);
		                                        break;
		                        case 6:			printf("please enter id");
                								scanf("%d", &key);
		                        	 	 	 	SDB_DeletEntry(key);
		                                        break;
		                        case 7:
		                        				if (SDB_IsFull(start)== true)
		                        				{
		                        					printf("is full");
		                        				}
		                        				else
		                        				{
		                        					printf("No \n");
		                        				}

		                                        break;

		                        case 0:

		                       		           break;
		                        default:
		                                        printf("   Wrong Choice ");
		                                        break;
		                }
}
