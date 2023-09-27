#include "GIE_Interface.h"
#include "EXT_INT_Interface.h"
#include "Button_Interface.h"
#include "Led_Interface.h"
#include "Buzzer_Interface.h"
#include "DIO_Interface.h"
#include "ADC_Interface.h"


int main(){


	Led_Init(LED0);
	Led_Init(LED1);
	Led_Init(LED2);
	ADC_Init();
	ADC_Enable();


	while (true){
		uint16 adc_reading = ADC_Read();
	if (adc_reading>500)
	{
		Led_On(LED0);
	}
	else
	{
		Led_Off(LED0);
	}
	}

}


