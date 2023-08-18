#include <stdio.h>

void SDB_APP() {
    uint8 choice;

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add entry\n");
        printf("2. Get used size in database\n");
        printf("3. Read student data\n");
        printf("4. Get list of all student IDs\n");
        printf("5. Check if ID exists\n");
        printf("6. Delete student data\n");
        printf("7. Check if database is full\n");
        printf("0. Exit\n");

        scanf("%hhu", &choice);

        if (choice == 0) {
            break;
        }

        SDB_action(choice);
    }
}

void SDB_action(uint8 choice) {
    switch (choice) {
        case 1:
            if (SDB_AddEntry()) {
                printf("Student data added successfully.\n");
            } else {
                printf("Failed to add student data.\n");
            }
            break;

            case 2:
            printf("Used size: %d\n", SDB_GetUsedSize());
            break;
        case 3: {
            uint32 id;
            printf("Enter student ID: ");
            scanf("%u", &id);
            SDB_ReadEntry(id);
            break;
        }
        case 4: {
            uint8 count;
            uint32 list[10]; // Assuming maximum of 10 students
            SDB_GetList(&count, list);
            printf("Student IDs: ");
            for (uint8 i = 0; i < count; ++i) {
                printf("%u ", list[i]);
            }
            printf("\n");
            break;
        }
        case 5: {
            uint32 id;
            printf("Enter student ID: ");
            scanf("%u", &id);
            if (SDB_IsIdExist(id)) {
                printf("ID exists.\n");
            } else {
                printf("ID does not exist.\n");
            }
            break;
        }
        case 6: {
            uint32 id;
            printf("Enter student ID to delete: ");
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
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;

    }
}
