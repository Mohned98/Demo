#include <stdio.h>
#include "SDB.h"

static student database[MAX_STUDENTS]; //arrray that has the database that takes the max number of studients(10)
static uint8 counter = 0; //counter to count number of students in the data base

bool SDB_IsFull() //function that returns if the database is full
{
	setbuf(stdout,NULL);
    return (counter >= MAX_STUDENTS);
}

uint32 SDB_GetUsedSize() //function that returns how many studients saved in the database
{
	setbuf(stdout,NULL);
    //printf("%d",numStudents);
	return counter;
}

bool SDB_AddEntry() //function to add new student to the database
{
	setbuf(stdout,NULL);
    if (SDB_IsFull()) //this condetion checks if the database is full so the user cant add more students
    {
        return false;
    }

    student newStudent;//creating new student 

    //taking from the user the studients info.
    printf("Enter Student ID: \n");
    scanf("%u", &newStudent.Student_ID);
    printf("Enter Student Year: \n");
    scanf("%u", &newStudent.Student_year);
    printf("Enter Course 1 ID: \n");
    scanf("%u", &newStudent.Course1_ID);
    printf("Enter Course 1 grade: \n");
    scanf("%u", &newStudent.Course1_grade);
    printf("Enter Course 2 ID: \n");
    scanf("%u", &newStudent.Course2_ID);
    printf("Enter Course 2 grade: \n");
    scanf("%u", &newStudent.Course2_grade);
    printf("Enter Course 3 ID: \n");
    scanf("%u", &newStudent.Course3_ID);
    printf("Enter Course 3 grade: \n");
    scanf("%u", &newStudent.Course3_grade);
   
    database[counter++] = newStudent; 
    return true;
}

void SDB_DeleteEntry(uint32 id) //function to delete any student from the database
{
	setbuf(stdout,NULL);
    for (uint8 i = 0; i < counter; i++) //loop to get the id the user entered from the database
    {
        if (database[i].Student_ID == id)   //this condetion checks if the id the user entered is the same as each id stored to reach the accurate database 
        {
            for (uint8 j = i; j < counter - 1; j++) 
            {
                database[j] = database[j + 1]; //deleting the id by the id after insted of it
            }
            counter--;
            printf("Student with ID %u deleted.\n", id);
            return;
        }
    }
    printf("Student with ID %u not found.\n", id); //if the id the user entered doesn't exeist print this line 
}

bool SDB_ReadEntry(uint32 id) //function to print the studients info by getting his id
{
	setbuf(stdout,NULL);
    for (uint8 i = 0; i < counter; i++) //loop to get the id the user entered from the database
    {
        if (database[i].Student_ID == id) //this condetion checks if the id the user entered is the same as each id stored to reach the accurate database
        {
        printf("Student ID: %u\n", database[i].Student_ID);
        printf("Student year: %u\n", database[i].Student_year);
        printf("Student Course 1 ID: %u\n", database[i].Course1_ID);
        printf("Student Course 1 Grade: %u\n", database[i].Course1_grade);
        printf("Student Course 2 ID: %u\n", database[i].Course2_ID);            //print studient info.
        printf("Student Course 2 grade: %u\n", database[i].Course2_grade);
        printf("Student Course 3 ID: %u\n", database[i].Course3_ID);
        printf("Student Course 3 grade: %u\n", database[i].Course3_grade);
            
        printf("1\n");
          return true;
        }
        }
    printf("0\n");
    return false;
    }


void SDB_GetList(uint8 *count, uint32 *list) //function to make list of ids
{
	setbuf(stdout,NULL);
    *count = counter; //set the pointer to the counter
    for (uint8 i = 0; i < counter; i++) 
    {
        list[i] = database[i].Student_ID;    //loop to print number of each studient and his id
    }
}

bool SDB_IsIdExist(uint32 id) //function to check if the id exists or no
{
	setbuf(stdout,NULL);
    for (uint8 i = 0; i < counter; i++) //loop to get the id the user entered from the database
    {
        if (database[i].Student_ID == id) //this condetion checks if the id the user entered is the same as each id stored to reach the accurate database
        {
            return true;
        }
    }
    return false;
}
