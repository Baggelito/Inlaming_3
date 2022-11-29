
#include "header.h"


//Beroende på vilket tal du skriver i led_blink(...) i main avgör hur lång delayen är mellan lamporna
void delay_ms(const uint16_t delay_time_ms)
{
	for (uint16_t i = 0; i < delay_time_ms; ++i)
	{
		_delay_ms(1);
	}

	return;
}


//Vilken ordning lamporna blinkar i.
void led_blink(const uint16_t delay_time_ms)
{
	
	if(diod == LED_STATE_BLINK)
	{
		LED3_OFF;
		LED1_ON;
		delay_ms(delay_time_ms);
		LED1_OFF;
		LED2_ON;
		delay_ms(delay_time_ms);
		LED2_OFF;
		LED3_ON;
		delay_ms(delay_time_ms);
		
		return;
	}
} 
