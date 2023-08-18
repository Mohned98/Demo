#ifndef SDB_H_
#define SDB_H_

#include "DataTypes.h"
#define size 10

typedef struct SimpleDb{
	uint32 Student_ID;
	uint32 Student_year;
	uint32 Course1_ID;
	uint32 Course1_grade;
	uint32 Course2_ID;
	uint32 Course2_grade;
	uint32 Course3_ID;
	uint32 Course3_grade;
}student;

bool check_digit (Int8 arr[]);

bool SDB_IsFull ();

bool SDB_AddEntry();

bool SDB_ReadEntry (uint32);

bool SDB_IsIdExist (uint32);

uint8 SDB_GetUsedSize();

void SDB_DeleteEntry (uint32);

void SDB_GetList (uint8 *count, uint32 *list);


#endif /* SDB_H_ */
