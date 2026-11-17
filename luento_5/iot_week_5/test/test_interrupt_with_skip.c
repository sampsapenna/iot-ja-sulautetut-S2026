
#ifdef TEST

#include <stdbool.h>
#include "unity.h"
#include "mock_stub_pico_stdlib.h"

#include "interrupt_with_skip.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_button_press_callback_IncorrectGPIOPin()
{
    button_press_callback(10, 0);
}

void test_button_press_callback_NoFallingEdgeInEventMask()
{
    button_press_callback(22, 0);
}

void test_button_press_callback_NotEnoughTimeElapsedSinceLastPress()
{
    get_absolute_time_IgnoreAndReturn(5000);
    absolute_time_diff_us_ExpectAndReturn(0, 5000, 5000);
    button_press_callback(22, 0x4u);
}

void test_button_press_callback_Nominal()
{
    get_absolute_time_IgnoreAndReturn(20000);
    absolute_time_diff_us_ExpectAndReturn(0, 20000, 20000);
    button_press_callback(22, 0x4u);
}

void test_setup_Nominal()
{
    stdio_init_all_Expect();
    gpio_init_Expect(25);
    gpio_set_dir_Expect(25, 1u);
    gpio_init_Expect(22);
    gpio_set_dir_Expect(22, 0u);
    gpio_set_input_hysteresis_enabled_Expect(22, true);
    gpio_set_irq_enabled_with_callback_Expect(22, 0x4u, true, button_press_callback);

    setup();
}

void test_run_main_Nominal()
{
    // Can't mock setup() call for now, so copy over the whole call chain
    stdio_init_all_Expect();
    gpio_init_Expect(25);
    gpio_set_dir_Expect(25, 1u);
    gpio_init_Expect(22);
    gpio_set_dir_Expect(22, 0u);
    gpio_set_input_hysteresis_enabled_Expect(22, true);
    gpio_set_irq_enabled_with_callback_Expect(22, 0x4u, true, button_press_callback);

    get_absolute_time_ExpectAndReturn(0);
    sleep_ms_Expect(1000);

    int run_main_ret = run_main();
    TEST_ASSERT_EQUAL_INT(0, run_main_ret);
}

#endif // TEST
