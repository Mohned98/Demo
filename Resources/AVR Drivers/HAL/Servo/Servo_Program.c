#include "Servo_Interface.h"
#include "DIO_Interface.h"
#include "Timer1_Interface.h"

#define MIN_SERVO_DUTYCYCLE  5
#define MAX_SERVO_DUTYCYCLE  24

#define MIN_SERVO_ANGLE      0
#define MAX_SERVO_ANGLE      180

void Servo_Init(void)
{
	Dio_SetPinDirection(DIO_PORTD, PIN4, OUTPUT);  /* Configure OC1B pin as output */
	Timer1_Init();
	Timer1_Start();
}

void Servo_SetAngle(uint8 angle)
{
	/* The linear equation is y = mx + c
	 * y -> Duty Cycle
	 * x -> Angle
	 * m -> Slope = dy/dx (dy = max duty cycle - min duty cycle) & (dx = max angle - min angle)
	 * c -> min value for y (duty cycle)
	 * */

	uint8 deltaServoAngle = MAX_SERVO_ANGLE - MIN_SERVO_ANGLE;
	uint8 deltaDutyCycle = MAX_SERVO_DUTYCYCLE - MIN_SERVO_DUTYCYCLE;
	uint8 requiredDutyCycle = ((deltaDutyCycle * angle) / deltaServoAngle) + MIN_SERVO_DUTYCYCLE;
	Timer1_SetPWM(requiredDutyCycle);
}
