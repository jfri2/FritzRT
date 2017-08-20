/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <peripheral_clk_config.h>
#include <utils.h>
#include <hal_init.h>
#include <hpl_gclk_base.h>
#include <hpl_pm_base.h>

struct spi_m_sync_descriptor CTRL_SPI;

struct usart_sync_descriptor USART_0;

void CTRL_SPI_PORT_init(void)
{

	gpio_set_pin_function(PIN_SPI_CTRL_MOSI, PINMUX_PA16C_SERCOM1_PAD0);

	gpio_set_pin_function(PIN_SPI_CTRL_SCK, PINMUX_PA17C_SERCOM1_PAD1);

	gpio_set_pin_function(PIN_SPI_CTRL_MISO, PINMUX_PA19C_SERCOM1_PAD3);
}

void CTRL_SPI_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, SERCOM1);
	_gclk_enable_channel(SERCOM1_GCLK_ID_CORE, CONF_GCLK_SERCOM1_CORE_SRC);
}

void CTRL_SPI_init(void)
{
	CTRL_SPI_CLOCK_init();
	spi_m_sync_init(&CTRL_SPI, SERCOM1);
	CTRL_SPI_PORT_init();
}

void USART_0_PORT_init(void)
{

	gpio_set_pin_function(PIN_UART_TX, PINMUX_PA10D_SERCOM2_PAD2);

	gpio_set_pin_function(PIN_UART_RX, PINMUX_PA11D_SERCOM2_PAD3);
}

void USART_0_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, SERCOM2);
	_gclk_enable_channel(SERCOM2_GCLK_ID_CORE, CONF_GCLK_SERCOM2_CORE_SRC);
}

void USART_0_init(void)
{
	USART_0_CLOCK_init();
	usart_sync_init(&USART_0, SERCOM2, (void *)NULL);
	USART_0_PORT_init();
}

void USB_0_PORT_init(void)
{

	gpio_set_pin_direction(PIN_USB_DN,
	                       // <y> Pin direction
	                       // <id> pad_direction
	                       // <GPIO_DIRECTION_OFF"> Off
	                       // <GPIO_DIRECTION_IN"> In
	                       // <GPIO_DIRECTION_OUT"> Out
	                       GPIO_DIRECTION_OUT);

	gpio_set_pin_level(PIN_USB_DN,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	gpio_set_pin_pull_mode(PIN_USB_DN,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PIN_USB_DN,
	                      // <y> Pin function
	                      // <id> pad_function
	                      // <i> Auto : use driver pinmux if signal is imported by driver, else turn off function
	                      // <PINMUX_PA24G_USB_DM"> Auto
	                      // <GPIO_PIN_FUNCTION_OFF"> Off
	                      // <GPIO_PIN_FUNCTION_A"> A
	                      // <GPIO_PIN_FUNCTION_B"> B
	                      // <GPIO_PIN_FUNCTION_C"> C
	                      // <GPIO_PIN_FUNCTION_D"> D
	                      // <GPIO_PIN_FUNCTION_E"> E
	                      // <GPIO_PIN_FUNCTION_F"> F
	                      // <GPIO_PIN_FUNCTION_G"> G
	                      // <GPIO_PIN_FUNCTION_H"> H
	                      PINMUX_PA24G_USB_DM);

	gpio_set_pin_direction(PIN_USB_DP,
	                       // <y> Pin direction
	                       // <id> pad_direction
	                       // <GPIO_DIRECTION_OFF"> Off
	                       // <GPIO_DIRECTION_IN"> In
	                       // <GPIO_DIRECTION_OUT"> Out
	                       GPIO_DIRECTION_OUT);

	gpio_set_pin_level(PIN_USB_DP,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	gpio_set_pin_pull_mode(PIN_USB_DP,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PIN_USB_DP,
	                      // <y> Pin function
	                      // <id> pad_function
	                      // <i> Auto : use driver pinmux if signal is imported by driver, else turn off function
	                      // <PINMUX_PA25G_USB_DP"> Auto
	                      // <GPIO_PIN_FUNCTION_OFF"> Off
	                      // <GPIO_PIN_FUNCTION_A"> A
	                      // <GPIO_PIN_FUNCTION_B"> B
	                      // <GPIO_PIN_FUNCTION_C"> C
	                      // <GPIO_PIN_FUNCTION_D"> D
	                      // <GPIO_PIN_FUNCTION_E"> E
	                      // <GPIO_PIN_FUNCTION_F"> F
	                      // <GPIO_PIN_FUNCTION_G"> G
	                      // <GPIO_PIN_FUNCTION_H"> H
	                      PINMUX_PA25G_USB_DP);
}

/* The USB module requires a GCLK_USB of 48 MHz ~ 0.25% clock
 * for low speed and full speed operation. */
#if (CONF_GCLK_USB_FREQUENCY > (48000000 + 48000000 / 400)) || (CONF_GCLK_USB_FREQUENCY < (48000000 - 48000000 / 400))
#warning USB clock should be 48MHz ~ 0.25% clock, check your configuration!
#endif

void USB_0_CLOCK_init(void)
{

	_pm_enable_bus_clock(PM_BUS_APBB, USB);
	_pm_enable_bus_clock(PM_BUS_AHB, USB);
	_gclk_enable_channel(USB_GCLK_ID, CONF_GCLK_USB_SRC);
}

void USB_0_init(void)
{
	USB_0_CLOCK_init();
	usb_d_init();
	USB_0_PORT_init();
}

void system_init(void)
{
	init_mcu();

	// GPIO on PA06

	// Set pin direction to input
	gpio_set_pin_direction(PIN_SX1238_DIO5, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_SX1238_DIO5,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_UP);

	gpio_set_pin_function(PIN_SX1238_DIO5, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA08

	// Set pin direction to input
	gpio_set_pin_direction(PIN_SX138_DIO2, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_SX138_DIO2,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_UP);

	gpio_set_pin_function(PIN_SX138_DIO2, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA09

	// Set pin direction to input
	gpio_set_pin_direction(PIN_SX1238_DIO1, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_SX1238_DIO1,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_UP);

	gpio_set_pin_function(PIN_SX1238_DIO1, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA18

	// Set pin direction to output
	gpio_set_pin_direction(PIN_SPI_CTRL_CS, GPIO_DIRECTION_OUT);

	gpio_set_pin_level(PIN_SPI_CTRL_CS,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	gpio_set_pin_function(PIN_SPI_CTRL_CS, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA20

	// Set pin direction to input
	gpio_set_pin_direction(PIN_SX1238_DIO3, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_SX1238_DIO3,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_UP);

	gpio_set_pin_function(PIN_SX1238_DIO3, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA21

	// Set pin direction to input
	gpio_set_pin_direction(PIN_SX1238_DIO4, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_SX1238_DIO4,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_UP);

	gpio_set_pin_function(PIN_SX1238_DIO4, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA27

	// Set pin direction to output
	gpio_set_pin_direction(PIN_LED_TX, GPIO_DIRECTION_OUT);

	gpio_set_pin_level(PIN_LED_TX,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	gpio_set_pin_function(PIN_LED_TX, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB03

	// Set pin direction to output
	gpio_set_pin_direction(PIN_LED_RX, GPIO_DIRECTION_OUT);

	gpio_set_pin_level(PIN_LED_RX,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	gpio_set_pin_function(PIN_LED_RX, GPIO_PIN_FUNCTION_OFF);

	CTRL_SPI_init();

	USART_0_init();

	USB_0_init();
}
