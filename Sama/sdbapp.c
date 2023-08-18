#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STD.h"
#include "SDB.h"
#define maximum_student 10
#define minimum_student 3
 student db[maximum_student]; //array to store student
 uint32 studentcounter;
 uint32 id;

//used super loop to make program always open until user exit it
 //and here i take the number of operation user want to make
 void SDB_APP()
 {
 	while(1){
 		 printf("1. To add entry, enter 1\n"
 		               "2. To get used size in database, enter 2\n"
 		        	   "3. To read student data, enter 3 \n"

 		        	   "4. To check is ID is existed, enter 4\n"
 		               "5. To delete student data, enter 5\n"
 		        	   "6. To check is database is full, enter 6\n"
 		        	   "7. To exit enter 7 \n"
 		               "Enter your choice: ");
 		                uint8 x;
 				        scanf("%hhu",&x);

 		        if(x==0)
 		        {
 		        	break;
 		        }
 		        SDB_action(x);
 	}

 }
 //this function has switch case to access all function cases that user can done
void SDB_action(uint8 x)
{

	switch(x)
	{
	case 1:
		if(SDB_AddEntry())
		{
			printf("added successfully\n");
		}
		else
		{
			printf("error\n");
		}
		break;
	case 2:
		SDB_GetUsedSize();
		printf("size used in db:%d\n",studentcounter);
	    break;
	case 3:
	  printf("The student data : %u \n", SDB_ReadEntry(id));
	    break;
	case 4:
		if(SDB_IsIdExist (id))
				{
					printf("student Exist\n");
				}
				else
				{
					printf("not Exist\n");
				}

	    break;
	case 5:
         SDB_DeletEntry (id);

	    break;
	case 6:
		if(SDB_IsFull (studentcounter)){
			printf("The data base is full");
		}
		else{
			printf("The data base still empty");
		}

	    break;
	case 7:
		printf("EXIT THE PROGRAM");
		exit(0);
	default:
	  printf("wrong operation");

	}
}



