#include <stdio.h>
#include <stdlib.h>
#include "DataTypes.h"
#include "SDB.h"
#include "SDBAPP.h"

student student_data[size];
uint16 entry_count = 0, actual_size = size;

/*	SDB_GetUsedSize function gets the size of the data entered in the database
 * 	it returns the variable entry_count which is incremented every time an entry
 * 	is added to the database
 */
uint8 SDB_GetUsedSize()
{
	return entry_count;
}

/*	check_duplicate function checks for duplicate student ID's in the database.
 * 	the function is private to this c file "static"
 * 	it takes the ID entered by the user and checks if there is another ID with the same exact value in a loop
 * 	if a duplicate ID was found it returns true
 * 	if a duplicate ID was not found it returns false
 */

bool static check_duplicate(uint32 duplicate_id)
{
	uint16 duplicate_number = 0;
	for(int32 i = 0; i < actual_size; i++)
	{
		if(duplicate_id == student_data[i].Student_ID)
			duplicate_number++;

		if(duplicate_number > 1) // as it counts the entered id by the user
			return true;
	}
	return false;
}

/*	check_digit function checks if the entry of the user is correct or not.
 * 	checks if the entry is a digit, an alphabet or a special character by comparing each byte of the array of char by its ASCII value
 * 	as 0 -> 48(ASCII) and 9 -> 57(ASCII)
 * 	returns true if the entry is correct, else returns false
 */

bool check_digit (Int8 arr[])
{
	for(int32 i = 0; i < actual_size; i++)
	{
		if(arr[i] == '\0')
			break;
		if(!(arr[i] >= 48 && arr[i] <= 57)) // checks if char is a digit or not
			return false;
	}
	return true;
}

/*	SDB_AddEntry function adds the user entries to the database.
 * 	receive each entry by the user in an array of characters to be able to check if the entries are correct or not
 * 	after the check, each entry is converted back to integer data type through "atoi" function (Argument to integer)
 * 	returns true if data is added successfully to the database, else returns false
 */

bool SDB_AddEntry()
{
	uint16 student_number = entry_count + 1;
	Int8 temp[20];

	printf("\nEnter data for student %hu: \n", student_number);
	printf("Student ID: ");
	scanf("%s", &temp);
	if(check_digit(temp) == true)
	{
		if(check_duplicate(atoi(temp)) == true)
		{
			printf("\n*** ID already exists in database ***\n");
			return false;
		}
		student_data[entry_count].Student_ID = atoi(temp);
	}
	else
		return false;

	printf("Student Year: ");
	scanf("%s", &temp);
	if(check_digit(temp) == true)
		student_data[entry_count].Student_year = atoi(temp);
	else
			return false;

	printf("Course 1 ID: ");
	scanf("%s", &temp);
		if(check_digit(temp) == true)
			student_data[entry_count].Course1_ID = atoi(temp);
		else
				return false;

	printf("Course 1 Grade: ");
	scanf("%s", &temp);
	if(check_digit(temp) == true)
		student_data[entry_count].Course1_grade = atoi(temp);
	else
		return false;

	printf("Course 2 ID: ");
	scanf("%s", &temp);
	if(check_digit(temp) == true)
		student_data[entry_count].Course2_ID = atoi(temp);
	else
		return false;

	printf("Course 2 Grade: ");
	scanf("%s", &temp);
	if(check_digit(temp) == true)
		student_data[entry_count].Course2_grade = atoi(temp);
	else
		return false;

	printf("Course 3 ID: ");
	scanf("%s", &temp);
	if(check_digit(temp) == true)
		student_data[entry_count].Course3_ID = atoi(temp);
	else
		return false;

	printf("Course 3 Grade: ");
	scanf("%s", &temp);
	if(check_digit(temp) == true)
		student_data[entry_count].Course3_grade = atoi(temp);
	else
		return false;

	entry_count++;
	printf("\n");
	if(actual_size < size)
		actual_size++;

	return true;
}

/*	SDB_ReadEntry function gets a student id from the user and prints the student's data from database
 * 	it searches linearly for the ID in the database if the ID exists it prints the data of this student
 * 	returns true if data was printed successfully, else returns false
 */

bool SDB_ReadEntry (uint32 ID)
{
	for(int32 i = 0; i < actual_size; i++)
	{
		if(student_data[i].Student_ID == ID)
		{
			printf("\nStudent ID: %d", student_data[i].Student_ID);
			printf("\nStudent Year: %d", student_data[i].Student_year);
			printf("\nCourse 1 ID: %d", student_data[i].Course1_ID);
			printf("\nCourse 1 Grade: %d", student_data[i].Course1_grade);
			printf("\nCourse 2 ID: %d", student_data[i].Course2_ID);
			printf("\nCourse 2 Grade: %d", student_data[i].Course2_grade);
			printf("\nCourse 3 ID: %d", student_data[i].Course3_ID);
			printf("\nCourse 3 Grade: %d \n\n", student_data[i].Course3_grade);
			return true;
		}
	}
	return false;
}

/*	SDB_IsIdExist function searches for the ID entered by the user in the database
 * 	Linearly searches for the ID. returns true if it exists, else returns false
 */

bool SDB_IsIdExist (uint32 id)
{
	for(int32 i = 0; i < actual_size; i++)
	{
		if(id == student_data[i].Student_ID)
			return true;
	}
	return false;
}

/*	SDB_IsFull function checks if the database is full or not
 * 	if the number of entries was equal to the maximum size of the database then the database is full
 * 	returns true if it's full, else returns false
 */

bool SDB_IsFull ()
{
	if(entry_count == size)
		return true;
	else
		return false;
}

/*	SDB_DeleteEntry function deletes the data of the entered student ID
 * 	to delete data from a fixed size array we must shift the required index to delete to the end of the array
 * 	then reduce the size of the array by ignoring the last index
 * 	void function has no return
 */

void SDB_DeleteEntry (uint32 id)
{
	uint16 index = 11; //initialized with value outside range of array
	for(int32 i = 0; i < actual_size; i++)
	{
		if(student_data[i].Student_ID == id)
			index = i;
	}

	if(index == 11) //id was not found in database
	{
		printf("\n*** ID does not exist ***\n\n");
		return;
	}
	else
	{
		for(int32 j = index - 1; j < actual_size - 1; j++)
		{
			student_data[j].Student_ID = student_data[j + 1].Student_ID;
			student_data[j].Student_year = student_data[j + 1].Student_year;
			student_data[j].Course1_ID = student_data[j + 1].Course1_ID;
			student_data[j].Course1_grade = student_data[j + 1].Course1_grade;
			student_data[j].Course2_ID = student_data[j + 1].Course2_ID;
			student_data[j].Course2_grade = student_data[j + 1].Course2_grade;
			student_data[j].Course3_ID = student_data[j + 1].Course3_ID;
			student_data[j].Course3_grade = student_data[j + 1].Course3_grade;
		}
		actual_size--;
		entry_count--;
		printf("\n*** Data deleted successfully ***\n\n");
	}
}

/*	SDB_GetList function gets a pointer to the number of students in the database and an array of integers
 * 	it copies the student ID's into the array of integers
 * 	void function has no return
 */

void SDB_GetList (uint8 *count, uint32 *list)
{
	for(uint32 i = 0; i < *count; i++)
		list[i] = student_data[i].Student_ID;
}
