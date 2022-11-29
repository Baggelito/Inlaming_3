
#include "header.h"


// Update visar vad som händer när du trycker på knappen och vilka tillstånd som finns för lamporna.
void fsm_update(void)
{
	switch(diod)
	{
		case LED_STATE_OFF:
		{
			if(NEXT_BUTTON_PRESSED)
			{
				diod = LED_STATE_BLINK;
			}
			
			break;
		}
		case LED_STATE_BLINK:
		{
			if(NEXT_BUTTON_PRESSED)
			{
				diod = LED_STATE_OFF;
			}
			break;
		}
	}
	
}


// Output används i main för att koden ska förstå vilken tillstånd den ska skicka ut
void fsm_set_output(void)
{
	LEDS_OFF;
	
	if(diod == LED_STATE_OFF)LEDS_OFF;
	else if(diod == LED_STATE_BLINK) led_blink();
	
	
	return;
}