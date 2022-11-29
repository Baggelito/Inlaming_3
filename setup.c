
#include "header.h"

//Static inline är att koden läs en gång och sen kopierars in i setup. Detta gör att koden går snabbare att läsa av.
static inline void init_ports(void);
static inline void init_interrupts(void);

led_state_t diod = LED_STATE_OFF;

//Setup är vissar för koden vilka portar som den ska använda
void setup()
{
	init_interrupts();
	init_ports();
	
	return;
}

//Till delar vilken portar lampor och knappar tillhör
static inline void init_ports()
{
	DDRB = (1 << LED1) | (1 << LED2) | (1 << LED3);
	PORTB = (1 << NEXT_BUTTON);
	
	return;
}

//Skriver asembel kod för att få en fungerande interrupt som bestämmer om det ska vara en stigande eller fallande flank.

static inline void init_interrupts()
{
	asm("SEI"); // När man ska börja skriva asemble kod.
	PCICR = (1 << PCIE0);
	PCMSK0 = (1 << NEXT_BUTTON);
	
	EICRA = (1 << ISC00) | (1 << ISC01); // stigande flank
	EIMSK = (1 << INT0);
	
	return;
}

