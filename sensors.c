#include "sensors.h"

volatile uint16_t pulse_count = 0;

void sensor_init(void) {
    // فرض: سنسور روی PD2 (INT0) وصل شده
    DDRD &= ~(1<<PD2);      // ورودی
    PORTD |= (1<<PD2);      // Pull-up فعال
    EICRA |= (1<<ISC01);    // حساس به لبه سقوط کننده
    EIMSK |= (1<<INT0);     // فعال کردن INT0
    sei();                  // فعال کردن وقفه‌ها
}

ISR(INT0_vect) {
    pulse_count++;
}

volatile uint16_t get_pulse_count(void) {
    return pulse_count;
}
