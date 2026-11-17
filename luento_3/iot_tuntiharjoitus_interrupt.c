/*
IoT ja sulautetut järjestelmät – perusteet

Tuntiharjoitus:

Kirjoita lyhyt C-ohjelma, joka laskee napinpainalluksia GPIO-pinniin
kytketystä painonapista, ja tulostaa arvon muuttuessa uuden arvon
terminaaliin (stdout)

Huomioikaa, että mallikytkennässä luettavan pinnin tila on käännetty,
eli kun nappia painetaan, tila on 0, ei 1.
*/

#include <stdio.h>
#include <stdint.h>
#include "pico/stdlib.h"

#define GPIO_PIN_BUTTON 22

uint32_t total_presses = 0;
absolute_time_t last_press_at;

// Interrupt callback for button press
void button_press_callback(unsigned int gpio, long unsigned int event_mask)
{
    if (gpio != GPIO_PIN_BUTTON || !(event_mask & GPIO_IRQ_EDGE_FALL))
    {
        return;
    }

    absolute_time_t time_now = get_absolute_time();
    int64_t timediff = absolute_time_diff_us(last_press_at, time_now);

    if (timediff / 1000 > 100)
    {
        total_presses++;
        printf("Button has been pressed %u times in total.\n", total_presses);
        last_press_at = time_now;
    }

    return;
}

// Relevant setup functions
void setup()
{
    stdio_init_all();

    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);

    gpio_init(GPIO_PIN_BUTTON);
    gpio_set_dir(GPIO_PIN_BUTTON, GPIO_IN);
    gpio_set_input_hysteresis_enabled(GPIO_PIN_BUTTON, 1);

    gpio_set_irq_enabled_with_callback(GPIO_PIN_BUTTON, GPIO_IRQ_EDGE_FALL, true, button_press_callback);

    printf("Initialization done\n");
}

// Main program
int main()
{
    setup();

    // Suoritettava ohjelma tähän
    unsigned int total_presses = 0;
    unsigned int last_state = 1;
    unsigned int current_state = 1;

    printf("Button hasn't been pressed yet.\n");

    last_press_at = get_absolute_time();

    for (;;)
    {
        sleep_ms(1000);
    }

    return 0;
}
