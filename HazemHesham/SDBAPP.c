#include <stdio.h>
#include <stdlib.h>
#include "DataTypes.h"
#include "SDBAPP.h"
#include "SDB.h"
#define max 20

Int8 check[max];
uint16 choice = 9;

/*	SDB_action function receives the users choice from the menu and calls the function that corresponds to the users requirement
 * 	switch case used as it executes faster than if conditions and increases readability of the code
 */

void SDB_action(uint16 choice)
{
	uint32 ID, id, ID_list[size];
	uint8 ID_count = 0;

	switch(choice)
	{
		case 0:
		break;

		case 1:
			if(SDB_IsFull() == true)
				printf("\n*** Database is full *** \n\n");
			else
			{
				if(SDB_AddEntry() == true)
					printf("*** Data entered successfully *** \n\n");
				else
					printf("\n*** Invalid Entry *** \n\n");
			}
			break;

		case 2:
			printf("\n *** Number of students in the database: %d *** \n\n", SDB_GetUsedSize());
			break;

		case 3:
			printf("\nEnter student ID: ");
			scanf("%s", &check);
			if(check_digit(check) == true)
			{
				ID = atoi(check);
				if(SDB_ReadEntry(ID) == true)
					printf("*** ID exists in database *** \n\n");
				else
					printf("\n*** ID does not exist in database *** \n\n");
			}
			else
				printf("\n *** Invalid Entry *** \n\n");
			break;

		case 4:
			ID_count = SDB_GetUsedSize();
			if(ID_count != 0)
			{
				SDB_GetList(&ID_count, ID_list);
				printf("\nStudent ID list: \n");
				for(uint32 i = 0; i < ID_count; i++)
					printf("Student %d ID: %d \n", i + 1, ID_list[i]);
				printf("\n*** ID list displayed successfully *** \n\n");
			}
			else
				printf("\n*** No student ID's in database *** \n\n");
			break;

		case 5:
			printf("Enter ID to check if exists: ");
			scanf("%s", &check);
			if(check_digit(check) == true)
			{
				id = atoi(check);
				if(SDB_IsIdExist(id) == true)
					printf("\n*** student with ID: %d exists *** \n\n", id);
				else
					printf("\n*** student with ID: %d does not exist *** \n\n", id);
			}
			else
				printf("\n *** Invalid Entry *** \n\n");
			break;

		case 6:
			printf("Enter ID to delete: ");
			scanf("%s", &check);
			if(check_digit(check) == true)
			{
				id = atoi(check);
				if(SDB_GetUsedSize() != 0)
					SDB_DeleteEntry(id);
				else
					printf("\n*** There are no students in database to delete *** \n\n");
			}
			else
				printf("\n*** Invalid Entry *** \n\n");
			break;

		case 7:
			if(SDB_IsFull() == true)
				printf("\n*** Database is full ***\n\n");
			else
				printf("\n*** Database is not full ***\n\n");
			break;
	}

}

/*	SDB_APP function is a super loop that acts as a menu to the user
 * 	after getting the users choice it calls the function SDB_action if the entry was correct
 * 	if the user entry was 0 it shuts down the program by exiting the super loop
 */

void SDB_APP()
{
	while(choice != 0)
	{
		printf("Enter 1, To add entry \n");
		printf("Enter 2, To get used size in database \n");
		printf("Enter 3, To read student data \n");
		printf("Enter 4, To get the list of all student ID's \n");
		printf("Enter 5, To check if the ID exists \n");
		printf("Enter 6, To delete student data \n");
		printf("Enter 7, To check if database is full \n");
		printf("Enter 0, To exit \n");
		printf("\nUser entry: ");
		scanf("%s",&check);

		if(check_digit(check) == true)
		{
			choice = atoi(check);
			if(choice >= 0 && choice < 8)
				SDB_action(choice);
			else
			{
				printf("\n*** Invalid Entry *** \n\n");
				choice = 9;
			}
		}
		else
		{
			printf("\n*** Invalid Entry *** \n\n");
			choice = 9;
		}
	}
	printf("\n*** Program Shutdown ***");
}
