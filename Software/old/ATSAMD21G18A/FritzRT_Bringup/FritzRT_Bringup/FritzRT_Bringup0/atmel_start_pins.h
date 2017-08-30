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

// SAMD21 has 8 pin functions

#define GPIO_PIN_FUNCTION_A 0
#define GPIO_PIN_FUNCTION_B 1
#define GPIO_PIN_FUNCTION_C 2
#define GPIO_PIN_FUNCTION_D 3
#define GPIO_PIN_FUNCTION_E 4
#define GPIO_PIN_FUNCTION_F 5
#define GPIO_PIN_FUNCTION_G 6
#define GPIO_PIN_FUNCTION_H 7

#define PIN_SX1238_DIO5 GPIO(GPIO_PORTA, 6)
#define PIN_SX138_DIO2 GPIO(GPIO_PORTA, 8)
#define PIN_SX1238_DIO1 GPIO(GPIO_PORTA, 9)
#define PIN_UART_TX GPIO(GPIO_PORTA, 10)
#define PIN_UART_RX GPIO(GPIO_PORTA, 11)
#define PIN_SPI_CTRL_MOSI GPIO(GPIO_PORTA, 16)
#define PIN_SPI_CTRL_SCK GPIO(GPIO_PORTA, 17)
#define PIN_SPI_CTRL_CS GPIO(GPIO_PORTA, 18)
#define PIN_SPI_CTRL_MISO GPIO(GPIO_PORTA, 19)
#define PIN_SX1238_DIO3 GPIO(GPIO_PORTA, 20)
#define PIN_SX1238_DIO4 GPIO(GPIO_PORTA, 21)
#define PIN_LED_TX GPIO(GPIO_PORTA, 27)
#define PIN_LED_RX GPIO(GPIO_PORTB, 3)

#endif // ATMEL_START_PINS_H_INCLUDED
