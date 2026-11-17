#include "pico/stdlib.h"

int pico_led_init(void)
{
#if defined(PICO_DEFAULT_LED_PIN)
    // A device like Pico that uses a GPIO for the LED will define PICO_DEFAULT_LED_PIN
    // so we can use normal GPIO functionality to turn the led on and off
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
    return PICO_OK;
#endif

    gpio_init(20);
    gpio_set_di4r(20, GPIO_IN);
}

#ifndef LED_DELAY_MS
#define LED_DELAY_MS 250
#endif

void pico_flip_led()
{
#if defined(PICO_DEFAULT_LED_PIN)
    // Just set the GPIO on or off
    gpio_put(PICO_DEFAULT_LED_PIN, !gpio_get(PICO_DEFAULT_LED_PIN));
#endif
}

void main()
{
    int rc = pico_led_init();
    hard_assert(rc == PICO_OK);
    while (true)
    {
        pico_flip_led();
        sleep_ms(LED_DELAY_MS);
    }
}
