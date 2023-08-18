#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SDB.h"

//max number constant
#define MAX_STUDENTS 10
//database array of type student its index is max student number
student database[MAX_STUDENTS];
//student counter
uint8 numStudents;


//function to check if database full or not by using of counter and max student
bool SDB_IsFull (uint8 numStudents)
{
	if(numStudents>=MAX_STUDENTS)
	{
		return true;
	}
	else
	{
		return false;
	}

}

//functin to return the counter of student which means the size of db
uint8 SDB_GetUsedSize()
{
	return numStudents;
}

//to add the student in array of data type (struct)
bool SDB_AddEntry()
{
	if(numStudents>=MAX_STUDENTS)
		{
		    printf("sorry,database is full");
		    return false;
		}
	else
	{
	printf("enter the Student_ID:\n");
	scanf("%u",&database[numStudents].Student_ID);
	printf("enter the Student_year:\n");
    scanf("%u",&database[numStudents].Student_year);
	printf("enter the Course1_ID:\n");
	scanf("%u",&database[numStudents].Course1_ID);
	printf("enter the Course1_grade:\n");
	scanf("%u",&database[numStudents].Course1_grade);
	printf("enter the Course2_ID:\n");
	scanf("%u",&database[numStudents].Course2_ID);
	printf("enter the Course2_grade:\n");
    scanf("%u",&database[numStudents].Course2_grade);
	printf("enter the Course3_ID:\n");
	scanf("%u",&database[numStudents].Course3_ID);
	printf("enter the Course3_grade:\n");
	scanf("%u",&database[numStudents].Course3_grade);
	numStudents++;
    return true;
	}
}

//delete function
void SDB_DeletEntry (uint32 id)
{
    printf("\n enter the student id you want to delete :\n");
    scanf("%d",&id);

	for (uint8 i = 0; i < numStudents; i++)
	{
	if(database[i].Student_ID==id)
	{
	for (uint8 j = i; j < numStudents - 1; j++)
	{
		 database[j] = database[j + 1];
	}
	numStudents--;
	printf("\n Entry with ID %d deleted \n", id);
	return;
	}

	}

   printf("\n Entry with ID %d not found \n", id);

}

//enter a for loop to check the avalibilty of existance of the id inside the database by check index and display its data
bool SDB_ReadEntry (uint32 id)
{
	printf("\n enter the id of student to display its data:\n");
	scanf("\n%u",&id);

	for(uint8 i=0;i<numStudents;i++)
	{
		if(database[i].Student_ID==id)
			{
				printf("Student_ID:%d\n",database[i].Student_ID);
				printf("Student_year:%d\n",database[i].Student_year);
				printf("Course1_ID:%d\n",database[i].Course1_ID);
				printf("Course1_grade:%d\n",database[i].Course1_grade);
				printf("Course2_ID:%d\n",database[i].Course2_ID);
				printf("Course2_grade:%d\n",database[i].Course2_grade);
				printf("Course3_ID:%d\n",database[i].Course3_ID);
				printf("Course3_grade:%d\n",database[i].Course3_grade);
				return true;
			}
	}

	printf("\n id number not found \n");
	return false;
}

/*
 * void SDB_GetList (uint8 * count, uint32 * list)
{
	    *count = numStudents;
	    for (uint8 i = 0; i < numStudents; i++)
        {
	        list[i] = database[i].Student_ID;
	    }
}
 */


//enter a for loop to check the avalibilty of existance of the id inside the database
bool SDB_IsIdExist (uint32 id)
{
	    printf("\n enter the id you want to check:\n");
		scanf("\n%u",&id);

		for(uint8 i=0;i<numStudents;i++)
		{
			if(database[i].Student_ID==id)
				{
				printf("\n the id is exist \n");
				}
			    return true;
		}

		printf("\n id number not found \n");
		return false;
}













