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
#include "pico/stdlib.h"

#define GPIO_PIN_BUTTON 22

// Relevant setup functions
void setup()
{
    stdio_init_all();

    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);

    gpio_init(GPIO_PIN_BUTTON);
    gpio_set_dir(GPIO_PIN_BUTTON, GPIO_IN);
    gpio_set_input_hysteresis_enabled(GPIO_PIN_BUTTON, 1);

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

    for (;;)
    {
        current_state = gpio_get(GPIO_PIN_BUTTON);
        if (current_state != last_state)
        {
            if (current_state == 1)
            {
                total_presses++;
                printf("Button has been pressed %u times in total.\n", total_presses);
            }
            last_state = current_state;
        }

        sleep_ms(5);
    }

    return 0;
}