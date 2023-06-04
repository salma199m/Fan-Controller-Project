
#include"dc_motor.h"
#include"timer0.h"
#include"std_types.h"
#include"lm35_sensor.h"
#include "lcd.h"
#include"adc.h"

int main(void)
{
	uint8 temp;
	ADC_configType Adc_config = { INTERNAL, F_CPU_8 };

	LCD_init();
	DcMotor_init();
	ADC_init(&Adc_config);
	LCD_moveCursor(0, 4);
	LCD_displayString("FAN is ");
	LCD_moveCursor(1, 4);
	LCD_displayString("Temp =    C");

	while (1) {
		temp = LM35_getTemperature();
		if (temp >= 120)
		{
			LCD_moveCursor(0, 10);
			LCD_displayString("ON ");
			LCD_moveCursor(1, 10);
			LCD_intgerToString(temp);
			DcMotor_Rotate(CW, 100);
		}
		else if (temp >= 100 && temp < 120)
		{
			LCD_moveCursor(0, 10);
			LCD_displayString("ON ");
			LCD_moveCursor(1, 10);
			LCD_intgerToString(temp);
			DcMotor_Rotate(CW, 75);
		}
		else if (temp >= 90 && temp < 100)
		{
			LCD_moveCursor(0, 10);
			LCD_displayString("ON ");
			LCD_moveCursor(1, 10);
			LCD_intgerToString(temp);
			DcMotor_Rotate(CW, 75);
			LCD_displayCharacter(' ');
		}
		else if (temp >= 60 && temp < 90)
		{
			LCD_moveCursor(0, 10);
			LCD_displayString("ON ");
			LCD_moveCursor(1, 10);
			LCD_intgerToString(temp);
			DcMotor_Rotate(CW, 50);
			LCD_displayCharacter(' ');
		}
		else if (temp >= 30 && temp < 60)
		{
			LCD_moveCursor(0, 10);
			LCD_displayString("ON ");
			LCD_displayCharacter(' ');
			LCD_moveCursor(1, 10);
			LCD_intgerToString(temp);
			DcMotor_Rotate(CW, 25);
			LCD_displayCharacter(' ');
		}
		else
		{
			LCD_moveCursor(0, 10);
			LCD_displayString("OFF");
			LCD_moveCursor(1, 10);
			LCD_intgerToString(temp);
			DcMotor_Rotate(STOP, 0);
			LCD_displayCharacter(' ');
		}
	}
}

