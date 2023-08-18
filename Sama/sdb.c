/*
 * SDB.c
 *
 *  Created on: Aug 13, 2023
 *      Author: sama Saeed
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STD.h"
#include "SDB.h"


//used static array to store element
//max element is 10
//min element is 3
#define maximum_student 10
#define minimum_student 3

 student db[maximum_student]; //array to store student
 uint32 studentcounter;

//function to check db is full or not
bool SDB_IsFull (int32 studentcounter){
	if(studentcounter>maximum_student )
	{

		return true;
		}
		else
		{
			return false;
		}
		}
//function to get size and store it in counter
uint8 SDB_GetUsedSize(){
	return studentcounter;
}
//function to add student to db
bool SDB_AddEntry(){
	if(studentcounter>maximum_student )
		{
			printf("The database is full ");
			return 0;
		}
	else
	{
		printf("Enter student_ID");
		scanf("%u",&db[studentcounter].Student_ID);
		printf("Enter Student_year");
		scanf("%u",&db[studentcounter].Student_year);
		printf("Enter Course1_ID");
		scanf("%u",&db[studentcounter].Course1_ID);
		printf("Enter Course1_grade");
		scanf("%u",&db[studentcounter].Course1_grade);
		printf("Enter Course2_ID");
	    scanf("%u",&db[studentcounter].Course2_ID);
	    printf("Enter Course2_grade");
	    scanf("%u",&db[studentcounter].Course1_grade);
	    printf("Enter Course3_ID");
	    scanf("%u",&db[studentcounter].Course3_ID);
	    printf("Enter Course3_grade");
	   	scanf("%u",&db[studentcounter].Course3_grade);
	   	studentcounter++;
        return 1;

	}

}



//function to delete entry

void SDB_DeletEntry (uint32 id){
	printf("please enter student_id to delete");
	scanf("%u",&id);
	for(uint32 i =0;i<studentcounter;i++){
if(db[i].Student_ID==id){
	for(uint32 j=i;j<studentcounter-1;j++){
		db[j]=db[j+1];
	}
	studentcounter--;
	printf("The student  with ID deleted\n ",id);
return;
}
	}


}


//function to display data about student
bool SDB_ReadEntry (uint32 id){
	//uint32 s_id;
	printf("please enter student_id to display his data");
		scanf("%u",&id);
		for(uint32 i=0;i<=studentcounter;i++){
			if(db[i].Student_ID==id){
				printf("student ID : %u \n",db[i].Student_ID);
				printf("student year : %u \n",db[i].Student_year);
				printf("student course_1_ID : %u \n ",db[i].Course1_ID);
				printf("student course_1_grade : %u \n",db[i].Course1_grade);
				printf("student course_2_ID :  %u \n ",db[i].Course2_ID);
				printf("student course_2_grade : %u \n",db[i].Course2_grade);
				printf("student course_3_ID : %u \n ",db[i].Course3_ID);
				printf("student course_3_grade : %u \n ",db[i].Course3_grade);
				return true;
			}

			else
				printf("The student not found ");
			    return false;

		}

}

//function to check this student is exist or not
bool SDB_IsIdExist (uint32 id){
	printf("Enter ID you want to check");
	scanf("%d",&id);
	if(db[studentcounter].Student_ID==id){
		printf("the student found\n");
			return true;
		}
		else
		{
			printf("the student not found\n");
			return false;
		}
}





