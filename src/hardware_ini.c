#include "hardware_ini.h"

void user_button_setup(void) {
    rcc_periph_clock_enable(USER_BUTTON_PORT_RCC);
    gpio_mode_setup(USER_BUTTON_PORT, GPIO_MODE_INPUT, GPIO_PUPD_PULLDOWN, USER_BUTTON_PIN);
}

void swd_setup(void) {
    rcc_periph_clock_enable(SWD_PORT_RCC);
    gpio_set_af(SWD_PORT, GPIO_AF0, SWDCLK_PIN);
    gpio_set_af(SWD_PORT, GPIO_AF0, SWDIO_PIN);
}

void uart_setup(void) {
    rcc_periph_clock_enable(UART_PORT_RCC);
    /* First of all, before setup disable the UART */
    usart_disable(USART1);
}
