#include <stdio.h>
#include "STD.h"
#include "SDB.h"

// Counter of number of students in DB
int counterstu;
// Student DB (Array of Struct of 10 Students)
student studentArray[10];

void initializeDB()
{
    counterstu = 0;
}

/*
 * Descriptions: check if DB is full or not
 * Return:
 *        True --> full
 *        False --> still has places for students to add
 */
bool SDB_IsFull()
{
    if (counterstu == 10)
    {
        return true;
    }
    return false;
}

/*
 * Descriptions: Get size of used DB
 * Errors handled:
 *              Can't add id that exists
 *              Can't add to full DB
 * Return:
 *        Number of students in DB
 */
uint8 SDB_GetUsedSize()
{
    return counterstu;
}

/*
 * Descriptions: Add students to DB
 * Errors handled:
 *              Can't add id that exists
 *              Can't add to full DB
 * Return:
 *        True --> Added Successfully
 *        False --> Cannot be added
 */

bool SDB_AddEntry()
{
    if (!SDB_IsFull())
    {
        printf("Enter Student id: ");
        scanf("%d", &studentArray[counterstu].Student_ID);
        int idExists = 0;
        for (int i = 0; i < counterstu; ++i)
        {
            if (studentArray[i].Student_ID == studentArray[counterstu].Student_ID)
                idExists = 1;
        }
        if (!idExists)
        {
            printf("Enter Student Year: ");
            scanf("%d", &studentArray[counterstu].Student_year);
            printf("Enter Student Course1_ID: ");
            scanf("%d", &studentArray[counterstu].Course1_ID);
            printf("Enter Student Course1_grade: ");
            scanf("%d", &studentArray[counterstu].Course1_grade);
            printf("Enter Student Course2_ID: ");
            scanf("%d", &studentArray[counterstu].Course2_ID);
            printf("Enter Student Course2_grade: ");
            scanf("%d", &studentArray[counterstu].Course2_grade);
            printf("Enter Student Course3_ID: ");
            scanf("%d", &studentArray[counterstu].Course3_ID);
            printf("Enter Student Course3_grade: ");
            scanf("%d", &studentArray[counterstu].Course3_grade);
            counterstu++;
            return true;
        }
        else
        {    //id Already exists
            printf("Id Already Exist \n");
            return false;
        }
    }
    else
    {
        printf("Full DB!!!\n");
        return false;
    }
}

/*
 * Descriptions: Delete students to DB using id
 * Errors handled:
 *              Can't delete id that exists
 *              Can't delete to empty DB
 * Return:
 *          Void
 */
void SDB_DeleteEntry(uint32 id) {
    int index = -1;
    //Search for ID
    for (int i = 0; i < counterstu; ++i)
    {
        if (studentArray[i].Student_ID == id)
        {
            index = i;
        }
    }
    //Not found
    if (index == -1)
    {
        printf("Id not found to delete \n");
    }
    else
    {   //Found
        //shift until Counter - 1
        for (int i = index; i < counterstu - 1; ++i)
        {
            studentArray[i] = studentArray[i + 1];
        }
        //Decrement counter (delete student)
        counterstu--;
        printf("Student of id %d deleted Successfully\n", id);
    }
}

/*
 * Descriptions: get student info from DB using id
 * Errors handled:
 *              Can't get info of id that exists
 * Return:
 *         True --> Read and found
 *         False --> Cannot Read
 */
bool SDB_ReadEntry(uint32 id)
{
    int index = -1;
    //Search for ID
    for (int i = 0; i < counterstu; ++i)
    {
        if (studentArray[i].Student_ID == id) {
            index = i;
        }
    }
    //Not found
    if (index == -1)
    {
        return false;
    }
    else {
    	//Found (EXISTS)
        printf("Student id: %d\n", studentArray[index].Student_ID);
        printf("Student Year: %d\n", studentArray[index].Student_year);
        printf("Student Course1_ID: %d\n", studentArray[index].Course1_ID);
        printf("Student Course1_grade: %d\n", studentArray[index].Course1_grade);
        printf("Student Course2_ID: %d\n", studentArray[index].Course2_ID);
        printf("Student Course2_grade: %d\n", studentArray[index].Course2_grade);
        printf("Student Course3_ID: %d\n", studentArray[index].Course3_ID);
        printf("Student Course3_grade: %d\n", studentArray[index].Course3_grade);
        return true;
    }
}

/*
 * Descriptions: List all student IDs from DB
 * Return:
 *         Void
 */
void SDB_GetList(uint8 *count, uint32 *list)
{
    *count = counterstu;
    for (int i = 0; i < counterstu; ++i)
    {
        list[i] = studentArray[i].Student_ID;
    }
}

/*
 * Descriptions: Check Existence of Students in DB using id
 * Return:
 *         True --> Exist
 *         False --> Not Exists
 */
bool SDB_IsIdExist(uint32 id)
{
    int index = -1;
    //Search for ID
    for (int i = 0; i < counterstu; ++i)
    {
        if (studentArray[i].Student_ID == id)
        {
            index = i;
        }
    }
    //Not found
    if (index == -1)
    {
        return false;
    }
    else
    {
        return true;
    }
}




