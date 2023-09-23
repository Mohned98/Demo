#include <util/delay.h>
#include "Led_Interface.h"
#include "Ext_Int_Interface.h"
#include "GIE_Interface.h"
#include "ADC_Interface.h"

//void INT0_Handler(void);

int main(void)
{
	Led_Init(LED0);
	Led_Init(LED1);
	Led_Init(LED2);
	ADC_Init();
	while(1)
	{
		uint16 reading = ADC_Read();
		if (reading < 128 && ADC_Read() > 0) {
			Led_Off(LED0);
			Led_Off(LED1);
			Led_Off(LED2);
		} else if (reading < 256 && ADC_Read() > 128) {
			Led_On(LED0);
			Led_Off(LED1);
			Led_Off(LED2);
		} else if (reading < 384 && ADC_Read() > 256) {
			Led_Off(LED0);
			Led_On(LED1);
			Led_Off(LED2);
		} else if (reading < 512 && ADC_Read() > 384) {
			Led_On(LED0);
			Led_On(LED1);
			Led_Off(LED2);
		} else if (reading < 640 && ADC_Read() > 512) {
			Led_Off(LED0);
			Led_Off(LED1);
			Led_On(LED2);
		} else if (reading < 768 && ADC_Read() > 640) {
			Led_On(LED0);
			Led_Off(LED1);
			Led_On(LED2);
		} else if (reading < 896 && ADC_Read() > 768) {
			Led_Off(LED0);
			Led_On(LED1);
			Led_On(LED2);
		} else {
			Led_On(LED0);
			Led_On(LED1);
			Led_On(LED2);
		}
	}

	return 0;

}

//void INT0_Handler(void)
//{
//	Led_On(LED1);
//	_delay_ms(1000);
//	Led_Off(LED1);
//	_delay_ms(1000);
//}
