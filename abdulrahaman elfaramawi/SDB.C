#include "SDB.h"

#define MAX_STUDENTS 10

static student database[MAX_STUDENTS];
static uint8 usedSize = 0;

bool SDB_IsFull() {
    return usedSize >= MAX_STUDENTS;
}

uint8 SDB_GetUsedSize() {
    return usedSize;
}

bool SDB_AddEntry() {
    if (SDB_IsFull()) {
        return false;
    }
    // Code to add a new student to the database

    student newStudent;
    printf("Enter Student ID: ");
    scanf("%u", &newStudent.Student_ID);
    printf("Enter Student year: ");
    scanf("%u", &newStudent.Student_year);
    printf("Enter Course 1 ID: ");
    scanf("%u", &newStudent.Course1_ID);
    printf("Enter Course 1 grade: ");
    scanf("%u", &newStudent.Course1_grade);
    printf("Enter Course 2 ID: ");
    scanf("%u", &newStudent.Course2_ID);
    printf("Enter Course 2 grade: ");
    scanf("%u", &newStudent.Course2_grade);
    printf("Enter Course 3 ID: ");
    scanf("%u", &newStudent.Course3_ID);
    printf("Enter Course 3 grade: ");
    scanf("%u", &newStudent.Course3_grade);

    database[usedSize++] = newStudent;
    return true;
}
    // Code to delete a student with the given ID from the database
void SDB_DeleteEntry(uint32 id) {
    for (uint8 i = 0; i < usedSize; ++i) {
        if (database[i].Student_ID == id) {
            // Move last student to current index and decrement count
            database[i] = database[--usedSize];
            printf("Student with ID %u deleted.\n", id);
             return;
        }
    }
    printf("Student with ID %u not found.\n", id);


}
      // Code to read and print student data based on the given ID
bool SDB_ReadEntry(uint32 id) {
     for (uint8 i = 0; i < usedSize; ++i) {
        if (database[i].Student_ID == id) {
            printf("Student ID: %u\n", database[i].Student_ID);
            printf("Student year: %u\n", database[i].Student_year);
            printf("Course 1 ID: %u\n", database[i].Course1_ID);
            printf("Course 1 grade: %u\n", database[i].Course1_grade);
            printf("Course 2 ID: %u\n", database[i].Course2_ID);
            printf("Course 2 grade: %u\n", database[i].Course2_grade);
            printf("Course 3 ID: %u\n", database[i].Course3_ID);
            printf("Course 3 grade: %u\n", database[i].Course3_grade);

            return true;
        }
    }
    printf("Student with ID %u not found.\n", id);

    return false;
}

     // Code to populate the list of student IDs
void SDB_GetList(uint8 *count, uint32 *list) {
    *count = usedSize;
    for (uint8 i = 0; i < usedSize; ++i) {
        list[i] = database[i].Student_ID;
    }

}

     // Code to check if a student with the given ID exists in the database
bool SDB_IsIdExist(uint32 id) {
     for (uint8 i = 0; i < usedSize; ++i) {
        if (database[i].Student_ID == id) {
            return true;
        }
    }

    return false;
}
