/*
 * dc_motor.h
 *
 *  Created on: ٠٧‏/٠٤‏/٢٠٢٣
 *      Author: lap shop
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"
/* DC Motor HW Ports and Pins Ids */
#define DC_MOTOR_IN1_PORT_ID       PORTB_ID
#define DC_MOTOR_IN1_PIN_ID        PIN0_ID
#define DC_MOTOR_IN2_PORT_ID       PORTB_ID
#define DC_MOTOR_IN2_PIN_ID        PIN1_ID

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum DC_MOTOR_State {
	STOP, CW, ACW
} DcMotor_State;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void DcMotor_init(void);

void DcMotor_Rotate(DcMotor_State state ,uint8 speed);

#endif /* DC_MOTOR_H_ */
