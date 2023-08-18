/*
 * SDBAPP.c
 *
 *  Created on: Aug 17, 2023
 *      Author: Eid Elsayed Okda
 */
#include<stdio.h>
#include "STD.h"
#include "SDB.h"  // to know students_num to use it in the for loop in the SDB_action function
void SDB_APP ()
{
	fflush(stdin);
	    int choice;  //choice is the index to execute a particular function in the super loop
	    while(1)
	    {
		    printf("To add entry enter 1 \nTo get used size in database, enter 2\nTo read student data, enter 3\nTo get the list of all student IDs, enter 4\nTo check is ID is existed, enter 5\nTo delete student data, enter 6\nTo check is database is full, enter 7\nTo exit enter 0\n");
			scanf("%d",&choice);
	    	if(choice!=0)
	    	{
		      SDB_action(choice);
	    	}
	    	else
	    		{
	    		printf("exiting");
	    		break;
	    		}
		}

}
//node *head;
void SDB_action (int choice)
{
	/*
	 * for loop to check the input if it is valid or not
	 * c is counter to check how many times the
	 *
	 *
	 * */
	/*int32 c;
	for(int32 i=0;i<students_num;i++)
	{
		if (*ptr_choice!=i)
		{
			c++;
		}
	}
	if(c!=0)
	{
		printf("Wrong input please enter a number from 0 to 7\n");
		c=0;
		SDB_APP();
	}*/

	if(choice>0 && choice<8)
	{
		uint32 id;
		switch(choice)
		{
		case 1: SDB_AddEntry(); // to add a student data
			break;
		case 2:SDB_GetUsedSize();
			break;
		case 3:printf("Enter the id : ");
		     scanf("%d",&id);
			SDB_ReadEntry (id);
			break;
		case 4:SDB_GetList ();
			break;
		case 5:SDB_IsIdExist ();
			break;
		case 6:
			printf("Enter the id : ");
			scanf("%d",&id);
			SDB_DeletEntry (id);
			break;
		case 7:database_full();
			break;
		}

	}
void SDB_APP ();     // to ask the user again for the choice

}
