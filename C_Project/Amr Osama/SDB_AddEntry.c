#include <stdio.h>
#include "helperSDB.h"

extern uint8 num_of_element;  //indication to the enrolled students
extern simpleDb *dbptr;


bool SDB_AddEntry()  //return true if the data is added successfully
{

	printf("please enter the student %d id\n",num_of_element+1);

	if(scan_clr_buf ( &(dbptr + num_of_element)->student_ID ) == 0)
		return false;

///////////////////////

	printf("please enter the student %d year\n",num_of_element+1);

	if(scan_clr_buf ( &(dbptr + num_of_element)->student_year )== 0)
		return false;

///////////////////////

	printf("please enter the %d course 1 id\n",num_of_element+1);

	if(scan_clr_buf (&(dbptr + num_of_element)->Course1_ID)  == 0)
		return false;

///////////////////////

	printf("please enter the %d course 1 grade\n",num_of_element+1);

	if( scan_clr_buf(&(dbptr + num_of_element)->Course1_grade)== 0)
		return false;

///////////////////////

	printf("please enter the %d course 2 id\n",num_of_element+1);

	if( scan_clr_buf(&(dbptr + num_of_element)->Course2_ID) == 0)
		return false;

///////////////////////
	printf("please enter the %d course 2 grade\n",num_of_element+1);


	if( scan_clr_buf( &(dbptr + num_of_element)->Course2_grade) == 0)
		return false;

///////////////////////

	printf("please enter the %d course 3 id\n",num_of_element+1);

	if( scan_clr_buf(&(dbptr + num_of_element)->Course3_ID) == 0)
		return false;

///////////////////////

	printf("please enter the %d course 3 grade\n",num_of_element+1);

	if( scan_clr_buf(&(dbptr + num_of_element)->Course3_grade) == 0)
		return false;

///////////////////////

	num_of_element++; //if the data is entered successfully the indication to the number of students increase
	return true;
}
