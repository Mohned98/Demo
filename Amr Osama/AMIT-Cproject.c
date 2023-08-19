
#include <stdio.h>
#include "SDB.h"

int main(void) {

	setbuf(stdout,NULL);


	SDB_APP();

	printf("you left the app\n");


}
