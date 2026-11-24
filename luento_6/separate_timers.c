#include <stdio.h>
#include <string.h>
#include "hardware/rtc.h"
#include "pico/stdlib.h"
#include "pico/util/datetime.h"
#include "pico/multicore.h"

void setup()
{
    stdio_init_all();
    // Sleep 2 seconds to avoid missing the serial output
    sleep_ms(2000);

    printf("Hello multicore!\n");

    return;
}

bool repeating_callback_core_1(__unused struct repeating_timer *t)
{
    printf("Callback called from core 1 after 17 seconds.\n");
    return true;
}

bool repeating_callback_core_0(__unused struct repeating_timer *t)
{
    printf("Callback called from core 0 after 6 seconds.\n");
    return true;
}

void launch_core_1_timer()
{
    printf("Starting timer on core 1...\n");

    struct repeating_timer timer_c1;
    add_repeating_timer_ms(17000, repeating_callback_core_1, NULL, &timer_c1);

    for (;;)
    {
        sleep_ms(60000);
    }
}

void launch_core_0_timer()
{
    printf("Starting timer on core 0...\n");

    struct repeating_timer timer_c0;
    add_repeating_timer_ms(6000, repeating_callback_core_0, NULL, &timer_c0);

    for (;;)
    {
        sleep_ms(60000);
    }
}

int main()
{
    setup();

    printf("Starting timers on both cores.\n");

    multicore_launch_core1(launch_core_1_timer);
    launch_core_0_timer();
}
