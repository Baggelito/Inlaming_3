
//Skapar ett eget biblotek 
#ifndef HEADER_H_
#define HEADER_H_

#define F_CPU 16000000UL // sätter klockslaget till 16Mhz

//Vilka biblotek jag använder mig av
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

//PORTB
#define LED1 0
#define LED2 1
#define LED3 2

#define NEXT_BUTTON 5

//PORTD
#define RESER_BUTTON 2 

//Ger knappar och dioder sin angiven port
#define LED1_ON PORTB |= (1 << LED1)
#define LED2_ON PORTB |= (1 << LED2)
#define LED3_ON PORTB |= (1 << LED3)

#define LED1_OFF PORTB &= ~(1 << LED1)
#define LED2_OFF PORTB &= ~(1 << LED2)
#define LED3_OFF PORTB &= ~(1 << LED3)

#define LEDS_ON PORTB |= (1 << LED1) | (1 << LED2) | (1 << LED3)
#define LEDS_OFF PORTB &= ~((1 << LED1) | (1 << LED2) | (1 << LED3))


#define NEXT_BUTTON_PRESSED (PINB &(1 << NEXT_BUTTON))


typedef enum {false, true} bool;
	
typedef	enum 
{
	LED_STATE_OFF,
	LED_STATE_BLINK
	
}led_state_t;

extern led_state_t diod; // Global variabel, synlig överallt.


void setup(void);
void fsm_update(void);
void fsm_set_output(void);
void led_blink();
void delay_ms(const uint16_t delay_time_ms);



#endif /* HEADER_H_ */