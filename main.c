#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include "millis.h"

#define BIT_SET(a, b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b)))) 

#define YELLOW 2
#define RED 3
#define GREEN 1

void trafficLights(){



}

int main(void)
{

	init_millis(16000000UL);
	unsigned long prev_millis1;
	unsigned long prev_millis2;
	unsigned long prev_millis3;
	unsigned long prev_millis4;
	prev_millis1 = millis();
	prev_millis2 = millis();
	prev_millis3 = millis();
	prev_millis4 = millis();
	sei();

BIT_SET(DDRB, YELLOW);
BIT_SET(DDRB, RED);
BIT_SET(DDRB, GREEN);

while(1){
	if(millis() - prev_millis1 > 1000){
		BIT_SET(PORTB, GREEN);
		BIT_CLEAR(PORTB, YELLOW);
		BIT_CLEAR(PORTB, RED);
		prev_millis1 = millis();
			if(millis() - prev_millis2 > 3000){
				BIT_CLEAR(PORTB, GREEN);
				BIT_SET(PORTB, YELLOW);
				BIT_CLEAR(PORTB, RED);
				prev_millis1 = millis();
					if(millis() - prev_millis3 > 7000){
						BIT_CLEAR(PORTB, GREEN);
						BIT_CLEAR(PORTB, YELLOW);
						BIT_SET(PORTB, RED);
						prev_millis1 = millis();
							if(millis() - prev_millis4 > 11000){
								BIT_CLEAR(PORTB, GREEN);
								BIT_SET(PORTB, YELLOW);
								BIT_CLEAR(PORTB, RED);
								prev_millis1 = millis();
							}
					}
			}
	}
	// else if(millis() - prev_millis2 > 3000){
	// 		BIT_CLEAR(PORTB, GREEN);
	// 		BIT_SET(PORTB, YELLOW);
	// 		BIT_CLEAR(PORTB, RED);
	// 		prev_millis2 = millis();
	// // }
	// else if(millis() - prev_millis3 > 3000){
	// 		BIT_CLEAR(PORTB, GREEN);
	// 		BIT_CLEAR(PORTB, YELLOW);
	// 		BIT_SET(PORTB, RED);
	// 		prev_millis4 = millis();
	// // }
	// else if(millis() - prev_millis4 > 3000){
	// 		BIT_CLEAR(PORTB, GREEN);
	// 		BIT_SET(PORTB, YELLOW);
	// 		BIT_CLEAR(PORTB, RED);
	// 		prev_millis2 = millis();
	// 	}
	}
	return 0;
}