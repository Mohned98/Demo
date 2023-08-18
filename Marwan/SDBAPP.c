#include <stdio.h>
#include "SDB.h"

void SDB_action(uint8 choice);

void SDB_APP() { //Function that starts the Program
	setbuf(stdout,NULL);
    uint32 choice;

    while (1) { //Reoccuring loop that only exits if you choose to
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
        scanf("%d", &choice);

        if (choice == 0) { //End program
            printf("Exiting.\n");
            break;
        }

        SDB_action(choice);
    }
}

void SDB_action(uint8 choice) {
	setbuf(stdout,NULL);
    switch (choice) {
        case (1): { //Adding Data to Database
            if (SDB_AddEntry()) {
                printf("Student data added successfully.\n");
            } else {
                printf("Student data not added.\n");
            }
            break;
        }
        case (2): { //Getting the used size of the Database
            printf("Used size in database: %d\n", SDB_GetUsedSize());
            break;
        }
        case (3): { //Showing all data for a specific ID
            uint32 readId;
            printf("Enter Student ID to read: ");
            scanf("%u", &readId);
            SDB_ReadEntry(readId);
            break;
        }
        case (4): { //Getting a list of all IDs in Database
            uint8 count;
            uint32 list[MAX_STUDENTS];
            SDB_GetList(&count, list);
            printf("List of student IDs:\n");
            for (uint8 i = 0; i < count; i++) {
                printf("%u\n", list[i]);
            }
            break;
        }
        case (5): { //Checking if entered ID is in the Database or not
            uint32 checkId;
            printf("Enter ID to check: ");
            scanf("%u", &checkId);
            if (SDB_IsIdExist(checkId)) {
                printf("ID %u exists in the database.\n", checkId);
            } else {
                printf("ID %u does not exist in the database.\n", checkId);
            }
            break;
        }
        case (6): { //Delete data for a specific ID
            uint32 deleteId;
            printf("Enter Student ID to delete: ");
            scanf("%u", &deleteId);
            SDB_DeleteEntry(deleteId);
            break;
        }
        case (7): { //Checking if the Database is full or not
            if (SDB_IsFull()) {
                printf("Database is full.\n");
            } else {
                printf("Database is not full.\n");
            }
            break;
        }
        default: {
            printf("Invalid choice.\n");
            break;
        }
    }
}

