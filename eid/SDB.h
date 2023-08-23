/*
 * SDB.h
 *
 *  Created on: Aug 17, 2023
 *      Author: Eid Elsayed Okda
 */
#include "STD.h"
#ifndef SDB_H_
#define SDB_H_
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
}student;
extern uint32 students_num;
extern void SDB_APP ();
extern void SDB_action();
typedef struct node node ;
bool extern database_full();
void extern SDB_AddEntry();
uint8 extern SDB_GetUsedSize();
void extern SDB_DeletEntry ();
bool extern SDB_ReadEntry ();
void extern SDB_GetList ();
bool extern SDB_IsIdExist ();
#endif /* SDB_H_ */
