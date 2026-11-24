/*
Convenience / setup functions for FreeRTOS.
*/

#ifndef __FREERTOS_CONV_INCLUDED
#define __FREERTOS_CONV_INCLUDED

#include "task.h"

void vApplicationMallocFailedHook(void);
void vApplicationIdleHook(void);
void vApplicationTickHook(void);
void vApplicationStackOverflowHook(TaskHandle_t pxTask, char *pcTaskName);

#endif
