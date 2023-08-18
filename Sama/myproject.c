#include <stdio.h>
#include <stdlib.h>
#include "STD.h"
#include "SDB.h"
int main(void) {
	setbuf(stdout,NULL);
	SDB_APP();
	return 0;
}
