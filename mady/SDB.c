#include "SDB.h"
#ifndef SDB_C_INCLUDED
#define SDB_C_INCLUDED
#define MAX_STUDENTS 10

student studentDatabase[MAX_STUDENTS];
uint8 usedSize = 0;

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

    uint32 id, year, course1Id, course1Grade, course2Id, course2Grade, course3Id, course3Grade;


    printf("Enter Student ID: ");
    scanf("%u", &id);
    printf("Enter Student Year: ");
    scanf("%u", &year);
    printf("Enter Course 1 ID: ");
    scanf("%u", &course1Id);
    printf("Enter Course 1 Grade: ");
    scanf("%u", &course1Grade);
    printf("Enter Course 2 ID: ");
    scanf("%u", &course2Id);
    printf("Enter Course 2 Grade: ");
    scanf("%u", &course2Grade);
    printf("Enter Course 3 ID: ");
    scanf("%u", &course3Id);
    printf("Enter Course 3 Grade: ");
    scanf("%u", &course3Grade);


    studentDatabase[usedSize].Student_ID = id;
    studentDatabase[usedSize].Student_year = year;
    studentDatabase[usedSize].Course1_ID = course1Id;
    studentDatabase[usedSize].Course1_grade = course1Grade;
    studentDatabase[usedSize].Course2_ID = course2Id;
    studentDatabase[usedSize].Course2_grade = course2Grade;
    studentDatabase[usedSize].Course3_ID = course3Id;
    studentDatabase[usedSize].Course3_grade = course3Grade;

    usedSize++;
    return true;
}

void SDB_DeleteEntry(uint32 id) {
    int i;
    for (i = 0; i < usedSize; i++) {
        if (studentDatabase[i].Student_ID == id) {
            // Shift the elements after the deleted entry to the left
            for (int j = i; j < usedSize - 1; j++) {
                studentDatabase[j] = studentDatabase[j + 1];
            }
            usedSize--;
            break;
        }
    }
}

bool SDB_ReadEntry(uint32 id) {
    int i;
    for (i = 0; i < usedSize; i++) {
        if (studentDatabase[i].Student_ID == id) {
            // Print the student data
            printf("Student ID: %u\n", studentDatabase[i].Student_ID);
            printf("Student Year: %u\n", studentDatabase[i].Student_year);
            printf("Course 1 ID: %u\n", studentDatabase[i].Course1_ID);
            printf("Course 1 Grade: %u\n", studentDatabase[i].Course1_grade);
            printf("Course 2 ID: %u\n", studentDatabase[i].Course2_ID);
            printf("Course 2 Grade: %u\n", studentDatabase[i].Course2_grade);
            printf("Course 3 ID: %u\n", studentDatabase[i].Course3_ID);
            printf("Course 3 Grade: %u\n", studentDatabase[i].Course3_grade);
            return true;
        }
    }
    return false;
}

void SDB_GetList(uint8* count, uint32* list) {
    int i;
    for (i = 0; i < usedSize; i++) {
        list[i] = studentDatabase[i].Student_ID;
    }
    *count = usedSize;
}

bool SDB_IsIdExist(uint32 id) {
    int i;
    for (i = 0; i < usedSize; i++) {
        if (studentDatabase[i].Student_ID == id) {
            return true;
        }
    }
    return false;
}


#endif // SDB_C_INCLUDED
