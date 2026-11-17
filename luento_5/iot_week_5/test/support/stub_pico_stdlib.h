/*
Stub library for faking pico-sdk.
*/

#ifndef PICO_STUB_DEFINED
#define PICO_STUB_DEFINED

#include <stdint.h>
#include <stdbool.h>

#define PICO_DEFAULT_LED_PIN 25
#define GPIO_OUT 1u
#define GPIO_IN 0u
#define GPIO_IRQ_EDGE_FALL 0x4u

typedef uint64_t absolute_time_t;
typedef void (*gpio_irq_callback_t)(unsigned int, uint32_t);

int64_t absolute_time_diff_us(absolute_time_t, absolute_time_t);
absolute_time_t get_absolute_time(void);

void stdio_init_all(void);
void gpio_init(unsigned int);
void gpio_set_dir(unsigned int, bool);
void gpio_set_input_hysteresis_enabled(unsigned int, bool);
void gpio_set_irq_enabled_with_callback(unsigned int, uint32_t, bool, gpio_irq_callback_t);
void sleep_ms(uint32_t);

#endif
