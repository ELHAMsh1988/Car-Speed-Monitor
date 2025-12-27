#include "speed.h"

#define WHEEL_CIRCUMFERENCE 2.0 // متر (برای شبیه‌سازی)

float calculate_speed(uint16_t pulses) {
    // فرض: هر پالس = یک چرخش
    // سرعت = فاصله / زمان
    return (WHEEL_CIRCUMFERENCE * pulses) * 3.6; // km/h
}
