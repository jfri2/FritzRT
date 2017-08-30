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
struct timer_descriptor      TIMER_0;

struct usart_sync_descriptor USART_0;

void CTRL_SPI_PORT_init(void)
{

	// Set pin direction to output
	gpio_set_pin_direction(PIN_SPI_CTRL_MOSI, GPIO_DIRECTION_OUT);

	gpio_set_pin_level(PIN_SPI_CTRL_MOSI,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	gpio_set_pin_function(PIN_SPI_CTRL_MOSI, PINMUX_PA16C_SERCOM1_PAD0);

	// Set pin direction to output
	gpio_set_pin_direction(PIN_SPI_CTRL_SCK, GPIO_DIRECTION_OUT);

	gpio_set_pin_level(PIN_SPI_CTRL_SCK,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	gpio_set_pin_function(PIN_SPI_CTRL_SCK, PINMUX_PA17C_SERCOM1_PAD1);

	// Set pin direction to input
	gpio_set_pin_direction(PIN_SPI_CTRL_MISO, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PIN_SPI_CTRL_MISO,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

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

void delay_driver_init(void)
{
	delay_init(SysTick);
}

/**
 * \brief Timer initialization function
 *
 * Enables Timer peripheral, clocks and initializes Timer driver
 */
static void TIMER_0_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, TC3);
	_gclk_enable_channel(TC3_GCLK_ID, CONF_GCLK_TC3_SRC);

	timer_init(&TIMER_0, TC3, _tc_get_timer());
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

	delay_driver_init();

	TIMER_0_init();
}
