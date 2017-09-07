/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */
#ifndef ATMEL_START_PINS_H_INCLUDED
#define ATMEL_START_PINS_H_INCLUDED

#include <hal_gpio.h>

// SAME70 has 4 pin functions

#define GPIO_PIN_FUNCTION_A 0
#define GPIO_PIN_FUNCTION_B 1
#define GPIO_PIN_FUNCTION_C 2
#define GPIO_PIN_FUNCTION_D 3

#define PIN_LED GPIO(GPIO_PORTC, 8)
#define PIN_SX1238_RESET GPIO(GPIO_PORTC, 31)
#define PIN_SPI_CTRL_MISO GPIO(GPIO_PORTD, 20)
#define PIN_SPI_CTRL_MOSI GPIO(GPIO_PORTD, 21)
#define PIN_SPI_CTRL_SCK GPIO(GPIO_PORTD, 22)
#define PIN_SPI_CTRL_CS GPIO(GPIO_PORTD, 25)

#endif // ATMEL_START_PINS_H_INCLUDED
