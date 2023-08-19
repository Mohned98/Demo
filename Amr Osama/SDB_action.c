#include <stdio.h>
#include "helperSDB.h"


extern uint8 num_of_element ;
extern uint8 size ;


void SDB_action(uint8 choice) {

//**********************************************************************

	if (choice == 1)	//add entry
	{
		bool in_add = true;  // in_add determines whether i'm in add entry or not
		while(in_add)
		{
			if (num_of_element < size)
			{
				printf ("You are in the \"add entry\" option\n");

				if (SDB_AddEntry())
				{
					printf("the data has been successfully entered\n");
					in_add = false;
				}
				else
				{
					printf("The data you entered is wrong, please try again\n");
					keep_in_loop( &in_add );
				}
			}
			else
			{
				in_add = false ;
				printf("The database is full \n""You can't add more students\n");
			}
		}
	}

//**********************************************************************

	else if (choice == 2)     //size of database
	{
		printf ("The used size of the database is : %d\n",num_of_element );
		printf ("The free space in the database is : %d\n",size - num_of_element );
	}

//**********************************************************************

	else if (choice == 3)   //read entry using id
			{
		bool in_read = true;
		while (in_read)
		{
			uint32 id;

			if (num_of_element > 0)
			{
				printf("Please enter the id you are searching for \n");

				if (scan_clr_buf(&id))  // if the id entered is valid scan_clr_buf returns 1
				{
					if (SDB_ReadEntry(id) == 0)  //checking if the database contains any elements
					{
						printf("the id is not in the database \n");
						keep_in_loop(&in_read);
					}
					else
					{
						in_read = false;
					}
				}

				else
				{
					printf("the id you entered is not valid\n");
					keep_in_loop(&in_read);
				}
			}
			else
			{
				printf("the database is empty \n");
				in_read = false;
			}
		}
	}

//**********************************************************************

	else if(choice == 5)	//check if the id exist in the database
	{

		uint32 id;

		if(num_of_element>0)   //the database must contain elements to search for
		{
			if (scan_clr_buf( &id))
			{
				if(SDB_IsIdExist(id) == 0)
					printf("the id is not in the database \n");
				else
					printf("the id is present in the database \n");
			}

			else
			{
				printf("the id you entered is not valid\n");
			}
		}
		else
		{
			printf("the database is empty \n");
		}

	}

//**********************************************************************

	else if (choice==6)		//to delete student data
	{
		uint32 id;
		if(num_of_element>0)   //the database must contain elements to search for
		{
			printf("Enter the id you want to delete\n");
			if (scan_clr_buf( &id))
			{
				if(SDB_IsIdExist(id) == 1)
				{
					SDB_DeletEntry(id);
					printf("The data to the id %d has been deleted successfully\n", id);
				}
				else
				{
					printf("The id is not in the data base\n");
				}

			}
		}
		else
		{
			printf("The database is empty \n");
		}
	}

//**********************************************************************

	else if (choice == 7)   //to check if full
	{
		if(size == num_of_element)
			printf("The database is full \n");

		else
			printf ("The database is not full \n"
				"The available spaces are : %d", size - num_of_element);
	}

}



