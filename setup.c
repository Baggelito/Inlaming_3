
#include "header.h"

//Static inline �r att koden l�s en g�ng och sen kopierars in i setup. Detta g�r att koden g�r snabbare att l�sa av.
static inline void init_ports(void);
static inline void init_interrupts(void);

led_state_t diod = LED_STATE_OFF;

//Setup �r vissar f�r koden vilka portar som den ska anv�nda
void setup()
{
	init_interrupts();
	init_ports();
	
	return;
}

//Till delar vilken portar lampor och knappar tillh�r
static inline void init_ports()
{
	DDRB = (1 << LED1) | (1 << LED2) | (1 << LED3);
	PORTB = (1 << NEXT_BUTTON);
	
	return;
}

//Skriver asembel kod f�r att f� en fungerande interrupt som best�mmer om det ska vara en stigande eller fallande flank.

static inline void init_interrupts()
{
	asm("SEI"); // N�r man ska b�rja skriva asemble kod.
	PCICR = (1 << PCIE0);
	PCMSK0 = (1 << NEXT_BUTTON);
	
	EICRA = (1 << ISC00) | (1 << ISC01); // stigande flank
	EIMSK = (1 << INT0);
	
	return;
}

