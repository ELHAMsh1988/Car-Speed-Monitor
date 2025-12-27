#ifndef SENSORS_H
#define SENSORS_H

#include <avr/io.h>
#include <avr/interrupt.h>

void sensor_init(void);
volatile uint16_t get_pulse_count(void);

#endif
