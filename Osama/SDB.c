#include <stdio.h>
#include "SDB.h"

static student database[MAX_STUDENTS];
static uint8 numStudents = 0;

bool SDB_IsFull() {
	setbuf(stdout,NULL);
    return (numStudents >= MAX_STUDENTS);
}

uint32 SDB_GetUsedSize() {
	setbuf(stdout,NULL);

	return numStudents;
}

bool SDB_AddEntry() {
	setbuf(stdout,NULL);
    if (SDB_IsFull()) {
        return false;
    }

    student newStudent;
    printf("Enter Student_ID: \n");
    scanf("%u", &newStudent.Student_ID);
    printf("Enter Student_Year: \n");
    scanf("%u", &newStudent.Student_year);
    printf("Enter Course_1 ID: \n");
    scanf("%u", &newStudent.Course1_ID);
    printf("Enter Course_1 grade: \n");
    scanf("%u", &newStudent.Course1_grade);
    printf("Enter Course_2 ID: \n");
    scanf("%u", &newStudent.Course2_ID);
    printf("Enter Course_2 grade: \n");
    scanf("%u", &newStudent.Course2_grade);
    printf("Enter Course_3 ID: \n");
    scanf("%u", &newStudent.Course3_ID);
    printf("Enter Course_3 grade: \n");
    scanf("%u", &newStudent.Course3_grade);
    // Similar prompts for other fields
    database[numStudents++] = newStudent;
    return true;
}

void SDB_DeleteEntry(uint32 id) {
	setbuf(stdout,NULL);
    for (uint8 i = 0; i < numStudents; i++) {
        if (database[i].Student_ID == id) {
            for (uint8 j = i; j < numStudents - 1; j++) {
                database[j] = database[j + 1];
            }
            numStudents--;
            printf("Student with ID %u deleted.\n", id);
            return;
        }
    }
    printf("Student that have ID %u is not found.\n", id);
}

bool SDB_ReadEntry(uint32 id) {
	setbuf(stdout,NULL);
    for (uint8 i = 0; i < numStudents; i++) {
        if (database[i].Student_ID == id) {
        printf("Student ID: %u\n", database[i].Student_ID);
        printf("Student year: %u\n", database[i].Student_year);
        printf("Student Course 1 ID: %u\n", database[i].Course1_ID);
        printf("Student Course 1 Grade: %u\n", database[i].Course1_grade);
        printf("Student Course 2 ID: %u\n", database[i].Course2_ID);
        printf("Student Course 2 grade: %u\n", database[i].Course2_grade);
        printf("Student Course 3 ID: %u\n", database[i].Course3_ID);
        printf("Student Course 3 grade: %u\n", database[i].Course3_grade);
            // Print other fields
        printf("1\n");
          return true;
        }
        }
    printf("0\n");
    return false;
    }


void SDB_GetList(uint8 *count, uint32 *list) {
	setbuf(stdout,NULL);
    *count = numStudents;
    for (uint8 i = 0; i < numStudents; i++) {
        list[i] = database[i].Student_ID;
    }
}

bool SDB_IsIdExist(uint32 id) {
	setbuf(stdout,NULL);
    for (uint8 i = 0; i < numStudents; i++) {
        if (database[i].Student_ID == id) {
            return true;
        }
    }
    return false;
}


