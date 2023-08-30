#include <stdio.h>
#include "SDB.h"

void SDB_action(uint8 choice);

void SDB_APP() 
{
	setbuf(stdout,NULL);
    uint32 choice;

    while (1) //super loop
    {
        printf("\nOptions:\n");
        printf("1. Add entry\n");
        printf("2. Get used size in database\n");
        printf("3. Read student data\n");
        printf("4. Get the list of all student IDs\n");
        printf("5. Check if ID is existed\n");
        printf("6. Delete student data\n");
        printf("7. Check if database is full\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);     //take the user choice 

        SDB_action(choice); //send the choice to the action function
    }
}

void SDB_action(uint8 choice) 
{
	setbuf(stdout,NULL);
    switch (choice) //takes the user's choice and make the action that belonges to it using switch cases
    {
        case (1): //add student
        {
            if (SDB_AddEntry()) 
            {
                printf("Student data added successfully.\n");
            } else 
            {
                printf("Student data not added.\n");
            }
            break;
        }
        case (2): //get how many students
        {
            printf("Used size in database: %d\n", SDB_GetUsedSize());
            break;
        }
        case (3): //get info of id
        {
            uint32 readId;
            printf("Enter Student ID to read: ");
            scanf("%u", &readId);
            SDB_ReadEntry(readId);
            break;
        }
        case (4): //get list of ids
        {
            uint8 count;
            uint32 list[MAX_STUDENTS];
            SDB_GetList(&count, list);
            printf("List of student IDs:\n");
            for (uint8 i = 0; i < count; i++) 
            {
                printf("%u\n", list[i]);
            }
            break;
        }
        case (5): //check if id exist
        {
            uint32 checkId;
            printf("Enter ID to check: ");
            scanf("%u", &checkId);
            if (SDB_IsIdExist(checkId)) 
            {
                printf("ID %u exists in the database.\n", checkId);
            } else 
            {
                printf("ID %u does not exist in the database.\n", checkId);
            }
            break;
        }
        case (6): //delete any student
        {
            uint32 deleteId;
            printf("Enter Student ID to delete: ");
            scanf("%u", &deleteId);
            SDB_DeleteEntry(deleteId);
            break;
        }
        case (7): //check if database is full
        {
            if (SDB_IsFull()) 
            {
                printf("Database is full.\n");
            } else 
            {
                printf("Database is not full.\n");
            }
            break;
        }
        case (0)://break or exit
        {
            printf("Exiting.\n");
            break;
        }
        default: 
        {
            printf("Invalid choice.\n");
            break;
        }
    }
}

