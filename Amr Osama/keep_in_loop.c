#include <stdio.h>
#include "helperSDB.h"

void keep_in_loop(bool *flag) {


	printf("If you want to try again press \"1\"\n");
	printf("If you want to exit this option press \"0\"\n");

	uint8 exit_contin_choice;

	bool scan_state = true;
	bool in_exit_cotin = true;

	while (scan_state || in_exit_cotin)
	{
		scan_state = scan_clr_buf( (uint32 *)& exit_contin_choice);   //to prevent the user from entering a non integer

		if (scan_state == 1 && (exit_contin_choice == 1 || exit_contin_choice == 0))
		{
			if (exit_contin_choice == 1)	//by entering 1 this function loop is broken but the calling function loop is not"flag is still true"
			{
				in_exit_cotin = false;
				scan_state = false;
			}
			else							//by entering 0 the this function loop and the calling function loop are broken"flag is false"
			{
				in_exit_cotin = false;
				scan_state = false;
				*flag = false;
			}
		}
		else//the meaning of not entering the if is that the user did'nt press 1 or 0
		{
			printf("Press \"1\"to try again or press \"0\"to exit this option\n");

		}
	}
}

