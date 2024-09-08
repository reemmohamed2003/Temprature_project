/*
 * temp project.c
 *
 * Created: 9/8/2024 7:57:53 PM
 * Author : Al-Arab
 */ 

#include <avr/io.h>
#define F_CPU  8000000UL
#include <util/delay.h>
#include "LCD.h"
#include "ADC.h"


int main(void)
{
	unsigned short x ;
	LCD_vInit();
	ADC_vinit();
	LCD_movecursor(1,1);
	LCD_vSend_string("TEMP IS:");
	while(1)
	{
		
		x=(ADC_u16Read()*0.25);
		
		if(x<10)
		{
			LCD_movecursor(1,9);
			LCD_vSend_char(30);
			LCD_vSend_char((x%10)+'0');
			LCD_vSend_char(0xDF);
			LCD_vSend_char('c');
		}
		else if( x<100)
		{
			LCD_movecursor(1,9);
			LCD_vSend_char((x/10)+'0');
			LCD_vSend_char((x%10)+'0');
			LCD_vSend_char(0XDF);
			LCD_vSend_char('c');
			
			
		}
		
	}
}
