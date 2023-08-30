#include <stdio.h>
#include "helperSDB.h"

extern uint8 num_of_element;  //indication to the enrolled students
extern simpleDb *dbptr;    //the size id constant for now until i figure out how to use malloc

void SDB_DeletEntry (uint32 id)
{
	for (int i = 0; i < num_of_element ; i++)
	{
		if (((dbptr + i)->student_ID) == id)  //the for loop will be completed and i = size of array if the id is not in the DB
		{
			(dbptr + i)->student_year =  (dbptr + i  +1)->student_year;
			(dbptr + i)->student_ID = (dbptr + i+1)->student_ID ;
			(dbptr + i)->Course1_ID = (dbptr + i +1)->Course1_ID ;
			(dbptr + i)->Course1_grade = (dbptr + i+1)->Course1_grade ;
			(dbptr + i)->Course2_ID = (dbptr + i+1)->Course2_ID ;
			(dbptr + i)->Course2_grade =(dbptr + i+1)->Course2_grade ;
			(dbptr + i)->Course3_ID = (dbptr + i+1)->Course3_ID ;
			(dbptr + i)->Course3_grade = (dbptr + i+1)->Course3_grade ;
		}
		num_of_element--;
	}
}

