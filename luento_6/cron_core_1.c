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

    printf("Hello RTC!\n");

    char datetime_buf[256];
    char *datetime_str = &datetime_buf[0];

    // Start on Friday 5th of June 2020 15:45:00
    // (same as pico docs example, FYI)
    datetime_t t = {
        .year = 2020,
        .month = 06,
        .day = 05,
        .dotw = 5, // 0 is Sunday, so 5 is Friday
        .hour = 15,
        .min = 45,
        .sec = 00};

    // Start the RTC
    rtc_init();
    rtc_set_datetime(&t);

    // clk_sys is >2000x faster than clk_rtc, so datetime is not updated immediately when rtc_get_datetime() is called.
    // The delay is up to 3 RTC clock cycles (which is 64us with the default clock settings)
    sleep_us(64);

    return;
}

typedef struct CRON_EVENT
{
    short dotw;
    short month;
    short dotm;
    short hour;
    short minute;
    char cron_command[256];
} CRON_EVENT;

typedef struct CRON_EVENT_LIST
{
    CRON_EVENT *events;
    int len_events;
} CRON_EVENT_LIST;

void parse_cron_line(CRON_EVENT *c_event, const char *cron_line)
{
    sscanf(
        cron_line,
        "%d %d %d %d %d %s",
        c_event.minute,
        c_event.hour,
        c_event.dotm,
        c_event.month,
        c_event.dotw,
        c_event.cron_command);

    return;
}

bool cron_repeating_callback(__unused struct repeating_timer *t)
{
    char cron_line_example[] = "0 0 0 0 0 test";

    CRON_EVENT event;
    parse_cron_line(&event, cron_line_example);

    datetime_t t;
    rtc_get_datetime(&t);

    if (
        t.dotw == event.dotw && t.month == event.month && t.hour == event.hour)
    {
        printf("Call to run the following task: %s\n", event.cron_command);
    }

    return true;
}

void launch_repeating_timer_core_1()
{
    struct repeating_timer timer;
    add_repeating_timer_ms(1000, cron_repeating_callback, NULL, &timer);

    for (;;)
    {
        sleep_ms(60000);
    }
}

int main()
{
    setup();

    multicore_launch_core1(launch_repeating_timer_core_1());

    int total_slept = 0;

    for (;;)
    {
        sleep_ms(5000);
        total_slept += 5;
        printf("Now slept for %d seconds.\n", total_slept);
    }
}
