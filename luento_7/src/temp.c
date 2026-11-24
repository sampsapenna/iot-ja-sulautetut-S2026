/*
Periodic task to blink the onboard LED of the pico.
*/

#include <stdio.h>

#include "FreeRTOS.h"
#include "task.h"

#include "hardware/adc.h"

#include "temp.h"

/*
Periodically read the pico onboard temperature.
*/
void vPeriodicTemperatureTask(void *pvParameters)
{
    for (;;)
    {
        /* 12-bit conversion, assume max value == ADC_VREF == 3.3 V */
        const float conversionFactor = 3.3f / (1 << 12);

        float adc = (float)adc_read() * conversionFactor;
        float tempC = 27.0f - (adc - 0.706f) / 0.001721f;

        printf("info:temperature:%f\n", tempC);

        vTaskDelay(pdMS_TO_TICKS(15000));
    }
}
