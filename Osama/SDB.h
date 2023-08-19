
#ifndef SDB_H_
#define SDB_H_
#define MAX_STUDENTS 10
#include "STD.h"

// The structure used to make the database for all the students.
typedef struct {
    uint32 Student_ID;
    uint32 Student_year;
    uint32 Course1_ID;
    uint32 Course1_grade;
    uint32 Course2_ID;
    uint32 Course2_grade;
    uint32 Course3_ID;
    uint32 Course3_grade;
} student;

// The function of the process that will be used on the database.

bool SDB_IsFull(); /* check if the database is full or not.
                      (True = Database is full)  ,   (False = else)
                     */

uint32 SDB_GetUsedSize(); /* get how many students in your database have added
                              (return: The number of students)*/

bool SDB_AddEntry(); // Add the data required to fill the database asked by the user

void SDB_DeleteEntry(uint32 id); //: delete the student data with the given id

bool SDB_ReadEntry(uint32 id); //print the data of the user by searching on his data by the given id

void SDB_GetList(uint8 *count, uint32 *list); // it gets the number of id's in the count

bool SDB_IsIdExist(uint32 id); // Checks if the given id is exist


#endif
