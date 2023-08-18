#include <stdio.h>
#include <stdlib.h>
#include "SDB.h"
#include "STD.h"
#include "SDB_APP.h"
int main(void) {
	setbuf(stdout,NULL);
	initializeDB();
	SDB_APP();
	return 0;
}
