/* For code copied from FreeRTOS community examples. */
/*
 * FreeRTOS V202212.00
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * https://www.FreeRTOS.org
 * https://github.com/FreeRTOS
 *
 */

/* For any additional code that was implemented. */
/*
 * Copyright (C) 2026 Sampsa penna.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/* Scheduler include files. */
#include "FreeRTOS.h"
#include "task.h"

/* Library includes. */
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#if (mainRUN_ON_CORE == 1)
#include "pico/multicore.h"
#endif

/* Source include files. */
#include "blink.h"
// #include "logger.h"
#include "temp.h"
#include "FreeRTOS_conv.h"

/* Define demo task priorities. */
#define mainLOGGER_PRIORITY (tskIDLE_PRIORITY + 1UL)
#define mainTEMPERATURE_PRIORITY (tskIDLE_PRIORITY + 2UL)
#define mainBLINK_PRIORITY (tskIDLE_PRIORITY + 3UL)

void prvMainTaskLauncher()
{
    xTaskCreate(&vPeriodicBlinkTask, "BlinkTask", configMINIMAL_STACK_SIZE,
                NULL, mainBLINK_PRIORITY, NULL);
    xTaskCreate(&vPeriodicTemperatureTask, "TemperatureTask", configMINIMAL_STACK_SIZE,
                NULL, mainTEMPERATURE_PRIORITY, NULL);

    vTaskStartScheduler();
}

static void prvSetupHardware(void)
{
    stdio_init_all();
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, 1);
    gpio_put(PICO_DEFAULT_LED_PIN, !PICO_DEFAULT_LED_PIN_INVERTED);

    adc_init();
    adc_set_temp_sensor_enabled(1);
    adc_select_input(4);
}

void vLaunch(void)
{
    prvMainTaskLauncher();
}

int main(void)
{
    /* Configure the hardware ready to run the demo. */
    prvSetupHardware();

    sleep_ms(2000);

    const char *rtos_name;
#if (portSUPPORT_SMP == 1)
    rtos_name = "FreeRTOS SMP";
#else
    rtos_name = "FreeRTOS";
#endif

#if (portSUPPORT_SMP == 1) && (configNUMBER_OF_CORES == 2)
    printf("%s on both cores:\n", rtos_name);
    vLaunch();
#endif

#if (mainRUN_ON_CORE == 1)
    printf("%s on core 1:\n", rtos_name);
    multicore_launch_core1(vLaunch);
    while (true)
        ;
#else
    printf("%s on core 0:\n", rtos_name);
    vLaunch();
#endif

    return 0;
}
