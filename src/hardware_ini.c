#include "hardware_ini.h"

void user_button_setup(void) {
    rcc_periph_clock_enable(USER_BUTTON_PORT_RCC);
    gpio_mode_setup(USER_BUTTON_PORT, GPIO_MODE_INPUT, GPIO_PUPD_PULLDOWN, USER_BUTTON_PIN);
}

void swd_setup(void) {
    rcc_periph_clock_enable(SWD_PORT_RCC);
    gpio_mode_setup(SWD_PORT, GPIO_MODE_AF, GPIO_PUPD_NONE,
            SWDCLK_PIN | SWDIO_PIN);

    gpio_set_af(SWD_PORT, GPIO_AF0, SWDCLK_PIN);
    gpio_set_af(SWD_PORT, GPIO_AF0, SWDIO_PIN);
}

void clock_setup() {
    rcc_clock_setup_hsi(&rcc_hsi_configs[RCC_CLOCK_HSI_48MHZ]);
}

void usart_setup(void) {
    rcc_periph_clock_enable(USART_PORT_RCC);
    rcc_periph_clock_enable(RCC_GPIOA);

    gpio_mode_setup(USART_PORT, GPIO_MODE_AF, GPIO_PUPD_NONE, USART_TX_PIN | USART_RX_PIN);
    gpio_set_af(USART_PORT, USART_AF_NUM, USART_TX_PIN | USART_RX_PIN);

    usart_set_baudrate(USART1, 115200);
    usart_set_databits(USART1, 8);
    usart_set_stopbits(USART1, USART_STOPBITS_1);
    usart_set_mode(USART1, USART_MODE_TX_RX);
    usart_set_parity(USART1, USART_PARITY_NONE);
    usart_set_flow_control(USART1, USART_FLOWCONTROL_NONE);

    usart_enable(USART1);
}

void spi1_setup(void) {
    rcc_periph_clock_enable(RCC_SPI1);
    /* For SPI signal pins */
    rcc_periph_clock_enable(RCC_GPIOA);
    /* For SPI chip select pin */
    rcc_periph_clock_enable(RCC_GPIOE);

    gpio_mode_setup(GYRO_SPI_CS_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GYRO_SPI_CS_PIN);
    /* Disable comminication at the beginning */
    gpio_set(GYRO_SPI_CS_PORT, GYRO_SPI_CS_PIN);

    /* set GPIO pins as AF. MISO, MOSI and SCK have the same port (!) */
    gpio_mode_setup(GYRO_SPI_MISO_PORT, GPIO_MODE_AF, GPIO_PUPD_NONE,
            GYRO_SPI_MISO_PIN | GYRO_SPI_MOSI_PIN | GYRO_SPI_SCK_PIN);

    gpio_set_af(GYRO_SPI_MISO_PORT, GYRO_SPI_AF_NUM,
            GYRO_SPI_MISO_PIN | GYRO_SPI_MOSI_PIN | GYRO_SPI_SCK_PIN);

    spi_set_master_mode(SPI1);
    spi_set_baudrate_prescaler(SPI1, SPI_CR1_BR_FPCLK_DIV_64);
    spi_set_clock_polarity_0(SPI1);
    spi_set_clock_phase_0(SPI1);
    spi_set_full_duplex_mode(SPI1);
    spi_set_unidirectional_mode(SPI1);
    spi_send_msb_first(SPI1);
    spi_enable_software_slave_management(SPI1);
    spi_set_nss_high(SPI1);
    spi_set_data_size(SPI1, SPI_CR2_DS_8BIT);
    spi_fifo_reception_threshold_8bit(SPI1);
    spi_enable(SPI1);
}
