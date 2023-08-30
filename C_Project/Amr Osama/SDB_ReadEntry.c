#include <stdio.h>
#include "helperSDB.h"


extern uint8 size;
extern simpleDb *dbptr;

bool SDB_ReadEntry (uint32 id){

	int i = 0 ;

	for (; i < size ;i++)
	{
		if (((dbptr + i)->student_ID) == id)  //the for loop will be completed and i = size of array if the id is not in the DB
		{
			break;
		}

	}

	if (i == size)
		return false;

	else
	{
		printf(" ________________________________________\n");
		printf("| The student id is :             %d     |\n", (dbptr + i)->student_ID);
		printf("| The student year is :           %d     |\n", (dbptr + i)->student_year);
		printf("| The student course 1 id is :    %d     |\n", (dbptr + i)->Course1_ID);
		printf("| The student course 1 grade is : %d     |\n", (dbptr + i)->Course1_grade);
		printf("| The student course 2 id is :    %d     |\n", (dbptr + i)->Course2_ID);
		printf("| The student course 2 grade is : %d     |\n", (dbptr + i)->Course2_grade);
		printf("| The student course 3 id is :    %d     |\n", (dbptr + i)->Course3_ID);
		printf("| The student course 3 grade is : %d     |\n", (dbptr + i)->Course3_grade);
		printf("|________________________________________|\n");
		return true;
	}
}


