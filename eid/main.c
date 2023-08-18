/*
 * main.c
 *
 *  Created on: Aug 17, 2023
 *      Author: Eid Elsayed Okda
 */
#include<stdio.h>
#include<stdlib.h>
#include"SDB.h"
int main()
{
	setbuf(stdout,NULL);
	printf("The minimum of students is 3 and the maximum is 10\n");
	SDB_APP ();

		return 0;
}
