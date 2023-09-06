#include <util/delay.h>
#include "Led_Interface.h"

int main(void) {
	Led_Init(LED2);
	while(1)
	{
		Led_On(LED2);
		_delay_ms(1000);
		Led_Off(LED2);
		_delay_ms(1000);
	}

	return 0;



}
