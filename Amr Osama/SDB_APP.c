#include <stdio.h>
#include <stdlib.h>
#include "SDB.h"
#include "helperSDB.h"

uint8 num_of_element;
uint8 size;
simpleDb *dbptr = NULL;

void SDB_APP() {

	uint8 choice;
	bool in_app = true ;
	bool size_flag = true;


	while (size_flag)
	{
		printf("Enter the size of the desired database \n");
		if (scan_clr_buf( (uint32 *) &size) == 1 && (size >= 3 && size <= 10))
		{
			printf("The size of the database is : %d\n", size);
			dbptr = (simpleDb*) malloc(size * sizeof(simpleDb));
			size_flag = false;
		}

		else
		{
			printf("Please enter a valid size between 3 and 10\n");
			keep_in_loop(&size_flag);
			if ( size_flag == false)  //if the user enters zero from the keep_in_loop function in_app will be false to exit the program
			{
				in_app = false;
			}
		}
	}


	while (in_app)
	{
		printf (" ______________________________________________\n");
		printf ("|1.To add entry, enter 1                       |\n"
				"|2.To get used size in database, enter 2       |\n"
			    "|3.To read student data, enter 3               |\n"
			    "|4.To get the list of all student IDs, enter 4 |\n"
			    "|5.To check if ID exist, enter 5               |\n"
			    "|6.To delete student data, enter 6             |\n"
			    "|7.To check if database is full, enter 7       |\n"
			    "|8.To exit enter 0                             |\n");
		printf ("|______________________________________________|\n");

		if ( scan_clr_buf( (uint32 *) &choice) != 0 && (choice >= 0 && choice <= 7))
		{
			if (choice == 0)
			{
				in_app = false;
			}
			else
			{
				SDB_action(choice);
				in_app = true;
			}
		}
		else
		{
			printf("Please enter a correct number between 1 and 7 to the corresponding feature in the  menu below\n");
		}
	}
		free ( dbptr );
}
