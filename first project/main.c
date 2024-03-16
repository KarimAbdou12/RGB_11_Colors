
#include "StdTypes.h"
#include "MemMap.h"
#include "DIO_Int.h"
#include "MOTOR_Int.h"
#include "ECU_Int.h"
#include "STEPPER_Int.h"
#include "LCD_Int.h"
#include "KEYPAD_Int.h"
#include "CALCULATOR_Int.h"
#include "ADC_Int.h"
#include "Timers.h"
#include "Sensors_Int.h"
#include "Math.h"
#include "RGB_Int.h"
#include "INTERPOLATION_Int.h"
#include "FIRESYSTEM_Int.h"



#define  F_CPU   8000000
#include <util/delay.h>



int main(void)
{
	
	DIO_Init();
	
	LCD_Init();
	KEYPAD_Init();
	//MOTOR_Init();
	
	//PORTC=0xff;
	
	ADC_Init(VREF_AVCC,ADC_SCALER_64);
	
	//sei();
	RGB_Init();
	
	while (1)
	{
		Moving_All_Color();
	}
	
	
}



/*
ISR(TIMER0_OV_vect)
{
	static u8 flag=0;
		
	if (flag==0)
	{
		DIO_WritePin(PINC0,HIGH);
		TCNT0=216;
		flag=1;

	}
	else if (flag==1)
	{
		DIO_WritePin(PINC0,LOW);
		TCNT0=96;
		flag=0;
	}
	
	
}
*//*
ISR(TIMER0_OV_vect)
{
	
	static u16 c1=0;
	
	c1++;
	TCNT0=216;
	if (c1==40)
	{
		DIO_WritePin(PINC0,HIGH);
	}
	else if (c1==80)
	{
		DIO_WritePin(PINC0,LOW);
		c1=0;
	}
	
}



ISR(TIMER0_OV_vect)
{
	
	static u16 c=0;
	static u16 c1=0;
	c++;
    c1++;
	if (c==64)
	{
		DIO_TogglePin(PINC0);
		c=0;
	}
	if (c1==80)
	{
		DIO_TogglePin(PINC1);
	
		c1=0;
	}
	
}

/*

ISR(TIMER0_OV_vect) // for 1 sec 
{
	static u16 c1=0;
	c1++;
	if (c1==3907)
	{
		DIO_TogglePin(PINC4);
		TCNT0=192;
		c1=0;
	}
}

ISR(TIMER0_OV_vect)
{
	
	static u16 c1=0;
	
	c1++;
    TCNT0=6;
	if (c1==4000)
	{
		DIO_TogglePin(PINC4);
		
		c1=0;
	}
*/