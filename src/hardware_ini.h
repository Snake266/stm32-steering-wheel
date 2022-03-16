#ifndef HARDWARE_INI_H
#define HARDWARE_INI_H

#include "libopencm3/stm32/rcc.h"
#include "libopencm3/stm32/gpio.h"
#include "libopencm3/stm32/usart.h"
#include "libopencm3/stm32/spi.h"

#include "hardware_defines.h"

/* Function that setups GPIOA0 as input */
void user_button_setup(void);

/* Function that setup swd */
void swd_setup(void);

void clock_setup(void);

void usart_setup(void);

/* Setup SPI1 */
void spi1_setup(void);
#endif /* HARDWARE_INI_H */
