#include<stdio.h>
#include "SDB.h"

void SDB_APP();

int main() 
{
	setbuf(stdout,NULL);
    
    printf("***********************************\n");
    printf("*welcome to Amit studient project:*\n");
    printf("***********************************\n");

    SDB_APP(); //call the function that will begin the project

    return 0;
}
