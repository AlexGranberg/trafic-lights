#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#define BIT_SET(a, b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b)))) 

#define YELLOW 2
#define RED 3
#define GREEN 1

void trafficLights(){

BIT_SET(DDRB,YELLOW);
BIT_SET(DDRB, RED);
BIT_SET(DDRB, GREEN);
	while(1){
		BIT_SET(PORTB, GREEN);
		BIT_CLEAR(PORTB, YELLOW);
		BIT_CLEAR(PORTB, RED);
		_delay_ms(5000);
		BIT_CLEAR(PORTB, GREEN);
		BIT_SET(PORTB, YELLOW);
		BIT_CLEAR(PORTB, RED);
		_delay_ms(1500);
		BIT_CLEAR(PORTB, GREEN);
		BIT_CLEAR(PORTB, YELLOW);
		BIT_SET(PORTB, RED);
		_delay_ms(8000);
		BIT_CLEAR(PORTB, GREEN);
		BIT_SET(PORTB, YELLOW);
		BIT_CLEAR(PORTB, RED);
		_delay_ms(1500);
	}

}

int main(void)
{
	trafficLights();
	return 0;
}