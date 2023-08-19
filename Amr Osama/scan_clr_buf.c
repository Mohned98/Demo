
#include <stdio.h>
#include "helperSDB.h"




bool scan_clr_buf(uint32 *id)          //used to scan from the user and to clear the buffer in case of wrong entry to prevent infinite loop
{									//return zero if the  entry is a letter or a string
	uint8 clr_buff = 'a';

	if (scanf("%d", id) != 0)
	{
		while ((clr_buff = getchar()) != '\n')  {}
		return true;
	}

	else
	{
		while ((clr_buff = getchar()) != '\n')  {}
		return false;
	}
}
