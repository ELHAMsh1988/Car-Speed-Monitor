#include <avr/io.h>
#include <util/delay.h>
#include "sensors.h"
#include "timer.h"
#include "speed.h"
#include <stdio.h>

int main(void) {
    sensor_init();
    timer_init();

    uint16_t last_pulses = 0;
    float speed = 0.0;

    while(1) {
        if(tick) {
            tick = 0;
            uint16_t pulses = get_pulse_count();
            uint16_t delta = pulses - last_pulses;
            last_pulses = pulses;
            speed = calculate_speed(delta);

            // اینجا می‌توانیم speed را روی LCD یا UART چاپ کنیم
            // برای مثال UART_Send(speed);
        }
    }
}
