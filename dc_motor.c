/*
 * dc_motor.c
 *
 *  Created on: ٠٧‏/٠٤‏/٢٠٢٣
 *      Author: lap shop
 */

#include "gpio.h"
#include "dc_motor.h"
#include"timer0.h"
#include "common_macros.h"

void DcMotor_init(void)
{
	/*Setup the direction for the two motor pins through the gpio driver*/
	GPIO_setupPinDirection(PORTB_ID,PIN0_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID,PIN1_ID, PIN_OUTPUT);
	/*Stop the DC Motor at the beginning */
	GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
	GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
	//DcMotor_Rotate(STOP, 0);
}

void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	switch (state)
	{
		case STOP:
			GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
			GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
			break;
		case CW:
			GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_HIGH);
			GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
			PWM_Timer0_Start(speed);
			break;
		case ACW:
			GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_HIGH);
			GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
			PWM_Timer0_Start(speed);
			break;
		}

}
