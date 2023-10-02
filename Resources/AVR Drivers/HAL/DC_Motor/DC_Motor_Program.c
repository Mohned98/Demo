#include "DC_Motor_Interface.h"
#include "DC_Motor_Config.h"
#include "DIO_Interface.h"
#include "Timer0_Interface.h"

void DC_Motor_Init(void)
{
	Dio_SetPinDirection(DC_MOTOR_INPUT1_PORT, DC_MOTOR_INPUT1_PIN, OUTPUT);
	Dio_SetPinDirection(DC_MOTOR_INPUT2_PORT, DC_MOTOR_INPUT2_PIN, OUTPUT);

	/*CONFIGRE PIN OC0 AS OUTPUT */
	Dio_SetPinDirection(DIO_PORTB, PIN3, OUTPUT);

	/*INTIAILZE TIMER FOR PWM TO CONTROL SPEED OF MOTOR*/
	Timer0_Init();
	Timer0_Start();
}

void DC_Motor_AntiClockWise(void)
{
	Dio_WritePin(DC_MOTOR_INPUT1_PORT, DC_MOTOR_INPUT1_PIN, HIGH);
	Dio_WritePin(DC_MOTOR_INPUT1_PORT, DC_MOTOR_INPUT2_PIN, LOW);
}

void DC_Motor_ClockWise(void)
{
	Dio_WritePin(DC_MOTOR_INPUT1_PORT, DC_MOTOR_INPUT1_PIN, LOW);
	Dio_WritePin(DC_MOTOR_INPUT1_PORT, DC_MOTOR_INPUT2_PIN, HIGH);
}

void DC_Motor_OFF(void)
{
	Dio_WritePin(DC_MOTOR_INPUT1_PORT, DC_MOTOR_INPUT1_PIN, LOW);
	Dio_WritePin(DC_MOTOR_INPUT1_PORT, DC_MOTOR_INPUT2_PIN, LOW);
}

void DC_Motor_FullSpeed(void)
{
	Timer0_SetPWM(100);
}

void DC_Motor_NormalSpeed(void)
{
	Timer0_SetPWM(50);
}

