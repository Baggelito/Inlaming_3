#include "header.h"



ISR(PCINT0_vect)
{
	if(NEXT_BUTTON_PRESSED)
	{
		fsm_update();
	}
}
