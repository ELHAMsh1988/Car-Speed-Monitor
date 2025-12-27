#include "timer.h"

void timer_init(void) {
    // Timer1 با پریود 1 ثانیه
    TCCR1B |= (1<<WGM12);   // CTC mode
    OCR1A = 15624;           // برای F_CPU=16MHz و prescaler=1024
    TIMSK1 |= (1<<OCIE1A);   // فعال کردن وقفه
    TCCR1B |= (1<<CS12)|(1<<CS10); // prescaler=1024
    sei();
}

volatile uint8_t tick = 0;

ISR(TIMER1_COMPA_vect) {
    tick = 1;
}
