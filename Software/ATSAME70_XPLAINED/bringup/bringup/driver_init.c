/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <hal_init.h>
#include <hpl_pmc.h>
#include <peripheral_clk_config.h>
#include <utils.h>

struct spi_m_sync_descriptor CTRL_SPI;

void CTRL_SPI_PORT_init(void)
{

	gpio_set_pin_function(PIN_SPI_CTRL_MISO, PINMUX_PD20B_SPI0_MISO);

	gpio_set_pin_function(PIN_SPI_CTRL_MOSI, PINMUX_PD21B_SPI0_MOSI);

	gpio_set_pin_function(PIN_SPI_CTRL_SCK, PINMUX_PD22B_SPI0_SPCK);
}

void CTRL_SPI_CLOCK_init(void)
{
	_pmc_enable_periph_clock(ID_SPI0);
}

void CTRL_SPI_init(void)
{
	CTRL_SPI_CLOCK_init();
	spi_m_sync_init(&CTRL_SPI, SPI0);
	CTRL_SPI_PORT_init();
}

void system_init(void)
{
	init_mcu();

	_pmc_enable_periph_clock(ID_PIOC);

	_pmc_enable_periph_clock(ID_PIOD);

	/* Disable Watchdog*/
	hri_wdt_set_MR_WDDIS_bit(WDT);

	// GPIO on PC8

	// Set pin direction to output
	gpio_set_pin_direction(PIN_LED, GPIO_DIRECTION_OUT);

	gpio_set_pin_level(PIN_LED,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	gpio_set_pin_function(PIN_LED, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PD25

	// Set pin direction to output
	gpio_set_pin_direction(PIN_SPI_CTRL_CS, GPIO_DIRECTION_OUT);

	gpio_set_pin_level(PIN_SPI_CTRL_CS,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	gpio_set_pin_function(PIN_SPI_CTRL_CS, GPIO_PIN_FUNCTION_OFF);

	CTRL_SPI_init();
}
