#ifndef BOARD_PORT_PINS_H
#define BOARD_PORT_PINS_H

#include "libopencm3/stm32/gpio.h"
#include "libopencm3/stm32/rcc.h"
/***********************************/
/* user buttons defines */
/***********************************/
#define USER_BUTTON_PORT_RCC  RCC_GPIOA
#define USER_BUTTON_PORT      GPIOA
#define USER_BUTTON_PIN       GPIO0

/***********************************/
/* SWD defines */
/***********************************/
#define SWD_PORT_RCC    RCC_GPIOA
#define SWD_AF_MODE     GPIO_AF0
#define SWD_PORT        GPIOA
#define SWDIO_PIN       GPIO13
#define SWDCLK_PIN      GPIO14

/***********************************/
/* UART defines */
/***********************************/
#define UART_PORT_RCC   RCC_USART1
#define UART_PORT       GPIOA
#define UART_CK_PIN     GPIO8
#define UART_TX_PIN     GPIO9
#define UART_RX_PIN     GPIO10
#define UART_CTS_PIN    GPIO11
#define UART_RTS_PIN    GPIO12

/***********************************/
/* Gyroscope SPI defines */
/***********************************/
/* Chip select port and pin */
#define GYRO_SPI_CS_PORT    GPIOE
#define GYRO_SPI_CS_PIN     GPIO3

/* SCK port and pin */
#define GYRO_SPI_SCK_PORT   GPIOA
#define GYRO_SPI_SCK_PIN    GPIO5

/* MISO and MOSI  ports and pins */
#define GYRO_SPI_MISO_PORT  GPIOA
#define GYRO_SPI_MISO_PIN   GPIO6
#define GYRO_SPI_MOSI_PORT  GPIOA
#define GYRO_SPI_MOSI_PIN   GPIO7

#endif /* BOARD_PORT_PINS_H */
