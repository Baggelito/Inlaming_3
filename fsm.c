
#include "header.h"


// Update visar vad som h�nder n�r du trycker p� knappen och vilka tillst�nd som finns f�r lamporna.
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


// Output anv�nds i main f�r att koden ska f�rst� vilken tillst�nd den ska skicka ut
void fsm_set_output(void)
{
	LEDS_OFF;
	
	if(diod == LED_STATE_OFF)LEDS_OFF;
	else if(diod == LED_STATE_BLINK) led_blink();
	
	
	return;
}