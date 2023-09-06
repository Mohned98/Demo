#include <util/delay.h>
#include "Led_Interface.h"

int main(void) {
	Led_Init(LED0);
	while(1)
	{
		Led_On(LED0);
		_delay_ms(1000);
		Led_Off(LED0);
		_delay_ms(1000);
	}



	return 0;



}
