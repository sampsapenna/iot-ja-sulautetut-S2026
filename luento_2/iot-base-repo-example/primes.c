#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"

int setup(void)
{
    // Set up stdio
    stdio_init_all();
    printf("Initialized standard IO\n");
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
    return 0;
}

int loop(void)
{
    printf("Print primes between 100000 and 200000\n");

    for (int i = 100000; i <= 200000; i++)
    {
        int ceiling = i / 2;
        int j = 2;
        for (; j <= ceiling; j++)
        {
            if (i % j == 0)
            {
                // printf("%d is not a prime, divides by %d.\n", i, j);
                break;
            }
        }
        if (j > ceiling)
        {
            printf("%d is a prime, doesn't divide with by anything.\n", i);
        }
    }

    printf("Execution finished.\n");

    return 0;
}

int main(void)
{
    char placeholder[10];
    setup();

    sleep_ms(2500);

    printf("Begin printing primes? y/N\n");
    scanf("%c", placeholder);

    return loop();
}
