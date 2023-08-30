#ifndef SDBAPP_C_INCLUDED
#define SDBAPP_C_INCLUDED
#include <stdio.h>
#include "SDB.h"
#include "STD.h"
void SDB_action(uint8 choice);

void SDB_APP() {
    uint8 choice;

    while (1) {
        printf("Options:\n");
        printf("1. Add entry\n");
        printf("2. Get used size in database\n");
        printf("3. Read student data\n");
        printf("4. Get the list of all student IDs\n");
        printf("5. Check if ID exists\n");
        printf("6. Delete student data\n");
        printf("7. Check if database is full\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%hhu", &choice);

        if (choice == 0) {
            break; // Exit the super loop
        }

        SDB_action(choice);
    }
}


void SDB_action(uint8 choice) {
    switch (choice) {
        case 1:
            SDB_AddEntry();
            break;
        case 2:
            printf("Used size in database: %d\n", SDB_GetUsedSize());
            break;
        case 3: {
            uint32 id;
            printf("Enter Student ID: ");
            scanf("%u", &id);
            SDB_ReadEntry(id);
            break;
        }
        case 4:

              printf("Getting the list of all student IDs...\n");
              void SDB_GetList(uint8* count, uint32* list);


            break;
        case 5: {
            uint32 id;
            printf("Enter Student ID: ");
            scanf("%u", &id);
            bool SDB_IsIdExist(uint32 id);

            break;
        }
        case 6: {
            uint32 id;
            printf("Enter Student ID: ");
            scanf("%u", &id);
            SDB_DeleteEntry(id);
            break;
        }
        case 7:


            if (SDB_IsFull()) {
                printf("Database is full.\n");
            } else {
                printf("Database is not full.\n");
            }
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
}




#endif // SDBAPP_C_INCLUDED
