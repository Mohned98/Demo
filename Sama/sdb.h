/*
  here i include the header file which i defined data types in it to make struct
  that have all data about student to use it in function of project.
*/
#ifndef SDB_H_
#define SDB_H_
#include "STD.h"


typedef struct SimpleDb
{
 uint32 Student_ID;
 uint32 Student_year;
 uint32 Course1_ID;
 uint32 Course1_grade;
 uint32 Course2_ID;
 uint32 Course2_grade;
 uint32 Course3_ID;
 uint32 Course3_grade;
} student;
//all function i used declaration
bool SDB_IsFull (int32 studentcounter);
uint8 SDB_GetUsedSize();
bool SDB_AddEntry();
void SDB_DeletEntry (uint32 id);
bool SDB_ReadEntry (uint32 id);
bool SDB_IsIdExist (uint32 id);

//i was trying to make dynamic array but it did't work
//int *ptr;
/*
int sum=0;
clrscr();
ptr=(int*) malloc(10*sizeof(int));
for(int i=3;i<=10;i++){

		ptr[i];

}
*/
#endif /* SDB_H_ */
