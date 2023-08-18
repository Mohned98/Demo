#ifndef SDB.h
#define SDB.h

#define "std.h"

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

bool SDB_IsFull ();
uint8 SDB_GetUsedSize();
bool SDB_AddEntry();
Void SDB_DeletEntry (uint32 id);
bool SDB_ReadEntry (uint32 id);
Void SDB_GetList (uint8 * count, uint32 * list);
Bool SDB_IsIdExist (uint32 id);

#endif /* SDB_H_ */
