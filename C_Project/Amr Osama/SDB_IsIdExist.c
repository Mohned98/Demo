#include <stdio.h>
#include "helperSDB.h"


extern uint8 num_of_element;
extern simpleDb *dbptr;

bool SDB_IsIdExist (uint32 id){	 //returns false if the id is not present

	int i = 0 ;

	for (; i < num_of_element ;i++)
	{
		if (((dbptr + i)->student_ID) == id)  //the for loop will be completed and i = size of array if the id is not in the DB
		{
			break;
		}
	}

	if (i == num_of_element)
		return false;

	else
		return true;

}

