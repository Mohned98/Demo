
#include "ATmega32_RegisterMap.h"
#include "DIO_Interface.h"
#include "Bit_Math.h"

void Dio_SetPinDirection(Dio_PortType port, Dio_PinType pin, Dio_PinDirType mode)
{
	if (mode == OUTPUT)
	{
		switch (port)
		{
			case DIO_PORTA:
				SET_BIT(DDRA, pin);
				break;
			case DIO_PORTB:
				SET_BIT(DDRB, pin);
				break;
			case DIO_PORTC:
				SET_BIT(DDRC, pin);
				break;
			case DIO_PORTD:
				SET_BIT(DDRD, pin);
				break;
			default:
				break;
		}
	}
	else
	{
		switch (port)
		{
			case DIO_PORTA:
				CLEAR_BIT(DDRA, pin);
				break;
			case DIO_PORTB:
				CLEAR_BIT(DDRB, pin);
				break;
			case DIO_PORTC:
				CLEAR_BIT(DDRC, pin);
				break;
			case DIO_PORTD:
				CLEAR_BIT(DDRD, pin);
				break;
			default:
				break;
		}
	}

}

void Dio_SetPortDirection(Dio_PortType port, uint8 mode)
{
	switch (port)
	{
		case DIO_PORTA:
			DDRA = mode;
			break;
		case DIO_PORTB:
			DDRB = mode;
			break;
		case DIO_PORTC:
			DDRC = mode;
			break;
		case DIO_PORTD:
			DDRD = mode;
			break;
		default:
			break;
	}
}


void Dio_WritePin(Dio_PortType port, Dio_PinType pin, Dio_PinStateType state)
{
	if (state == HIGH)
	{
		switch (port) {
			case DIO_PORTA:
				SET_BIT(PORTA, pin);
				break;
			case DIO_PORTB:
				SET_BIT(PORTB, pin);
				break;
			case DIO_PORTC:
				SET_BIT(PORTC, pin);
				break;
			case DIO_PORTD:
				SET_BIT(PORTD, pin);
				break;
			default:
				break;
		}
	}
	else
	{
		switch (port)
		{
			case DIO_PORTA:
				CLEAR_BIT(PORTA, pin);
				break;
			case DIO_PORTB:
				CLEAR_BIT(PORTB, pin);
				break;
			case DIO_PORTC:
				CLEAR_BIT(PORTC, pin);
				break;
			case DIO_PORTD:
				CLEAR_BIT(PORTD, pin);
				break;
			default:
				break;
		}
	}
}

void Dio_WritePort(Dio_PortType port, uint8 state)
{

}

Dio_PinStateType Dio_ReadPin(Dio_PortType port, Dio_PinType pin)
{
	return 0;
}

uint8 Dio_ReadPort(Dio_PortType port)
{
	switch (port)
		{
			case DIO_PORTA:
				return PINA;
			case DIO_PORTB:
				return PINB;
			case DIO_PORTC:
				return PINC;
			case DIO_PORTD:
				return PIND;
			default:
				return 0;
		}
}

Dio_PinStateType Dio_TogglePin(Dio_PortType port, Dio_PinType pin)
{
	return 0;
}

