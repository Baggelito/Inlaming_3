
//Anv�nder mig av mitt egna biblotek 
#include "header.h"

//Main �r programmet k�rs.
int main(void)
{
    setup();
	
	while (1) 
	{ 
	   led_blink(100);
       fsm_set_output();
	}
	
	return 0;
}

