/**
 * ADC.c
 *
 * Created: 8/23/2024 3:06:48 AM
 *  Author: Reem Mohamed
 */ 
#include <avr/io.h>
#include "STD_Macros.h"

void ADC_vinit(void)
{
	SET_BIT(ADMUX,REFS0); //configure VREF
	SET_BIT(ADMUX,REFS1);
	SET_BIT(ADCSRA,ADEN); //enable ADC
	//adjust ADC clock//
	SET_BIT(ADCSRA,ADPS2);
	SET_BIT(ADCSRA,ADPS1);	
}
unsigned short ADC_u16Read(void)
{
	unsigned short read_val;
	SET_BIT(ADCSRA,ADSC);
	while(READ_BIT(ADCSRA,ADIF)==0); //stay in your position till ADIF become 1
	SET_BIT(ADCSRA,ADIF); //clear ADIF
	read_val=(ADCL);
	read_val|=(ADCH<<8);
	return read_val;
	
}
