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

void trafficLights() {
    static unsigned long prev_millis = 0;
    static int state = GREEN;
    unsigned long current_millis = millis();
    unsigned long elapsed_millis = current_millis - prev_millis;

    switch (state) {
        case GREEN:
            if (elapsed_millis >= 2000) {
                BIT_CLEAR(PORTB, YELLOW);
                BIT_CLEAR(PORTB, RED);
                BIT_SET(PORTB, GREEN);
                state = YELLOW;
                prev_millis = current_millis;
            }
            break;
        case YELLOW:
            if (elapsed_millis >= 8000) {
                if (BIT_CHECK(PORTB, GREEN)) {
                    BIT_CLEAR(PORTB, GREEN);
					BIT_CLEAR(PORTB, RED);
                    BIT_SET(PORTB, YELLOW);
                    state = RED;
                    prev_millis = current_millis;
                } else {
                    BIT_CLEAR(PORTB, GREEN);
					BIT_CLEAR(PORTB, RED);
                    BIT_SET(PORTB, YELLOW);
                    state = GREEN;
                    prev_millis = current_millis;
                }
            }
            break;
        case RED:
            if (elapsed_millis >= 2000) {
                BIT_CLEAR(PORTB, GREEN);
                BIT_CLEAR(PORTB, YELLOW);
                BIT_SET(PORTB, RED);
                state = YELLOW;
                prev_millis = current_millis;
            }
            break;
    }
}

int main(void) {
    init_millis(16000000UL);
    sei();

    BIT_SET(DDRB, YELLOW);
    BIT_SET(DDRB, RED);
    BIT_SET(DDRB, GREEN);

    BIT_CLEAR(PORTB, YELLOW);
    BIT_CLEAR(PORTB, RED);
    BIT_SET(PORTB, GREEN);

    while (1) {
        trafficLights();
    }

    return 0;
}
