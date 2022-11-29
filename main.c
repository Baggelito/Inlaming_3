
//Använder mig av mitt egna biblotek 
#include "header.h"

//Main är programmet körs.
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

