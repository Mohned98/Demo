#include <util/delay.h>
#include "Led_Interface.h"
#include "Ext_Int_Interface.h"
#include "GIE_Interface.h"
void INT0_Handler(void);

int main(void)
{
	Led_Init(LED1);
	Ext_Int_Enable(EXT_INT0);
	Ext_Int_Init(EXT_INT0);
	Ext_Int_SetCallBack(EXT_INT0, INT0_Handler);
	GIE_Enable();
	while(1)
	{
	}

	return 0;

}

void INT0_Handler(void)
{
	Led_On(LED1);
	_delay_ms(1000);
	Led_Off(LED1);
	_delay_ms(1000);
}
