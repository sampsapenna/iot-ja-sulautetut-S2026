
#ifndef INTERRUPT_WITH_SKIP_H
#define INTERRUPT_WITH_SKIP_H

#include <stdint.h>

void handle_button_printout(void);
void button_press_callback(unsigned int gpio, uint32_t event_mask);
void setup(void);
int run_main(void);

// Not pre-defining main in header

#endif // INTERRUPT_WITH_SKIP_H
