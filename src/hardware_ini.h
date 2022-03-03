#ifndef HARDWARE_INI_H
#define HARDWARE_INI_H

#include "libopencm3/stm32/rcc.h"
#include "libopencm3/stm32/gpio.h"
#include "libopencm3/stm32/usart.h"

#include "hardware_defines.h"

void user_button_setup(void);

void swd_setup(void);

void clock_setup(void);

void uart_setup(void);
#endif /* HARDWARE_INI_H */
