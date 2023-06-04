 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega16 ADC driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

/*******************************************************************************
 *                                Types Declaration                            *
 *******************************************************************************/
typedef enum
{
	F_CPU_CLOCK_2=1 ,F_CPU_CLOCK_4,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024
}ADC_Prescaler;

typedef enum {
	AREF=0, AVCC=1, INTERNAL=3
} ADC_ReferenceVolatge;

typedef struct{
	ADC_ReferenceVolatge ref_volt;
	 ADC_Prescaler prescaler;
}ADC_configType;
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_configType*config_ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
