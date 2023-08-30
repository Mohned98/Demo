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
	    int choice=1;  //choice is the index to execute a particular function in the super loop
	    while(1)
	    {
		printf("To add entry enter 1 \nTo get used size in database, enter 2\nTo read student data, enter 3\nTo get the list of all student IDs, enter 4\nTo check is ID is existed, enter 5\nTo delete student data, enter 6\nTo check is database is full, enter 7\nTo exit enter 0\n");
		printf("choice : ");
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

void SDB_action (int choice)
{
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
