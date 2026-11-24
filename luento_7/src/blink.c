/*
Periodic task to blink the onboard LED of the pico.
*/

#include <stdio.h>

#include "FreeRTOS.h"
#include "task.h"

#include "hardware/rtc.h"
#include "pico/stdlib.h"
#include "pico/util/datetime.h"

#include "blink.h"

/*
Periodically blink the onboard led of Pico.
*/
void vPeriodicBlinkTask(void *pvParameters)
{
    for (;;)
    {
        gpio_put(PICO_DEFAULT_LED_PIN, 1);
        printf("info:led:on\n");
        vTaskDelay(pdMS_TO_TICKS(500));
        // Pause aeration for the specified duration to allow compressor
        // to cool down
        gpio_put(PICO_DEFAULT_LED_PIN, 0);
        printf("info:led:off\n");
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}
