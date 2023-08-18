
#ifndef SDB_H_
#define SDB_H_
#define MAX_STUDENTS 10
#include "STD.h"

// Define a structure to represent student data
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

//Define each function's Datatype and what Datatype it needs
bool SDB_IsFull();
uint32 SDB_GetUsedSize();
bool SDB_AddEntry();
void SDB_DeleteEntry(uint32 id);
bool SDB_ReadEntry(uint32 id);
void SDB_GetList(uint8 *count, uint32 *list);
bool SDB_IsIdExist(uint32 id);


#endif /* SDB_H_ */
