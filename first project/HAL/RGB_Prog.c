
#include "StdTypes.h"
#include "Timers.h"
#include "RGB_Int.h"


#define  F_CPU   8000000
#include <util/delay.h>


u8 RGB_Colors[12][3]={{255,255,255},
{255,0,0},
{0,255,0},
{0,0,255},
{255,255,0},
{255,0,255},
{0,255,255},
{153,255,255},
{255,128,0},
{255,51,153},
{153,51,255},
{255,0,127}
};


void RGB_Init (void)
{
	TIMER0_Init(TIMER0_FASTPWM_MODE,TIMER0_SCALER_8);
	TIMER0_OC0Mode(OC0_NON_INVERTING);// ocp
	//TIMER0_SetCompareUnit(255); // write register compare match
	
	Timer1_Init(TIMER1_FASTPWM_ICR_TOP_MODE,TIMER1_SCALER_8); // TOP
	Timer1_OCRA1Mode(OCRA_NON_INVERTING); // toggle on it
	Timer1_OCRB1Mode(OCRB_NON_INVERTING);// toggle on it
	ICR1=255;
}

void Moving_All_Color(void)
{
	static u8 ind=0;
	
	OCR1B=RGB_Colors[ind][0]; // red
	OCR1A=RGB_Colors[ind][1]; //green
	TIMER0_SetCompareUnit(RGB_Colors[ind][2]);// blue
	
	ind++;
	_delay_ms(1500);
	if(12==ind)
	{
		ind=0;
	}
}