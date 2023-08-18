#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SDB.h"
#include "STD.h"
#include "SDBAPP.h"
#define MAX_STUDENTS 10
static uint8 numStudents;
static uint8 id;

void SDB_APP()
{
    while (1)
    {
        printf("1. To add entry, enter 1\n"
               "2. To get used size in database, enter 2\n"
        	   "3. To read student data, enter 3 \n"
        	   "4. To check is ID is existed, enter 4\n"
               "5. To delete student data, enter 5\n"
        	   "6. To check is database is full, enter 6\n"
        	   "7. To exit enter 7 \n"
               "Enter your choice: ");
        uint8 choose;
        scanf("%u",&choose);


        if(choose==0)
        {
        	break;
        }
        SDB_action(choose);
    }
}


void SDB_action(uint8 choose)
{
    switch (choose)
    {
     case 1:
     if (SDB_AddEntry())
     {
     printf("\nEntry added successfully.\n\n");
     }
     break;

     case 2:
     printf("\nUsed size in the database:%d\n\n", SDB_GetUsedSize());
     break;

     case 3:
     SDB_ReadEntry(id);
     break;

     case 4:
     SDB_IsIdExist (id);
     break;

     case 5:
     SDB_DeletEntry(id);
     break;

     case 6:
    	 if (SDB_IsFull(numStudents))
    	 {
    	   printf("\nDatabase is full\n\n");
    	 }
    	 else
    	 {
    	   printf("\nDatabase is not full\n\n");
    	 }
     break;

     case 7:
     printf("\nExiting the program.\n\n");
     exit(0);

     default:
     printf("\n not valid\n");
    }
}


