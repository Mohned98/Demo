#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STD.h"
#include "SDB.h"
/*
 * Descriptions: Input a choice and send to SDB_action function
 * Errors handled:Entering number >8 or <0
 */
void SDB_APP()
{
    printf("choose your Choice from:\n"
           "1. To add entry, enter 1 \n"
           "2. To get used size in database, enter 2\n"
           "3. To read student data, enter 3 \n"
           "4. To get the list of all student IDs, enter 4\n"
           "5. To check is ID is existed, enter 5 \n"
           "6. To delete student data, enter 6\n"
           "7. To check is database is full, enter 7\n"
           "8. To exit enter 0\n"
    );
    while (1)
    {
        printf("Your Choice is: ");
        uint8 choice;
        scanf("%d", &choice);
        if (choice == 8)
            break;
        else
            SDB_action(choice);
    }
}

/*
 * Descriptions: Action of the choice
 * Return:
 *         Void
 */
void SDB_action(uint8 choice)
{
    if (choice == 1)
    {
        if (SDB_AddEntry())
        {
            printf("Student Added Successfully\n");
        }
        else
        {
            printf("Student didn't Added\n");
        }
    }
    else if (choice == 2)
    {
        printf("Size  used In DB %d out of 10\n", SDB_GetUsedSize());
    }
    else if (choice == 3)
    {
        printf("Enter Student id to get data: ");
        uint8 id;
        scanf("%d", &id);
        if (SDB_ReadEntry(id))
        {
            printf("Student of id %d Read Successfully\n", id);
        }
        else
        {
            printf("Not found to Read!!!\n");
        }
    }
    else if (choice == 4)
    {
        uint32 list[10];
        uint8 countOfStudents = 0;
        SDB_GetList(&countOfStudents, list);
        printf("Count = %d\n", countOfStudents);
        for (int i = 0; i < countOfStudents; ++i)
        {
            printf("st %d = %d\n", i + 1, list[i]);
        }
        SDB_GetList(&countOfStudents, list);
    }
    else if (choice == 5)
    {
        printf("Enter Student id to check existence: ");
        uint8 id;
        scanf("%d", &id);
        if (SDB_IsIdExist(id))
            printf("The id is Exist\n");
        else
            printf("The id is Not Exist\n");
    }
    else if (choice == 6)
    {
        printf("Enter Student id of student be deleted: ");
        uint8 id;
        scanf("%d", &id);
        SDB_DeleteEntry(id);
    }
    else if (choice == 7)
    {
        if (SDB_IsFull())
        {
            printf("DB is full\n");
        }
        else
        {
            printf("DB isn't full --> still have places to add more students\n");
        }
    }
    else
    {
        printf("Invalid Entry --> choose from 1 to 8\n");
    }
}
