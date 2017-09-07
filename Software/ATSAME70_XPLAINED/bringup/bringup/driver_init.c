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

void delay_driver_init(void)
{
	delay_init(SysTick);
}

/* The USB module requires a GCLK_USB of 48 MHz ~ 0.25% clock
 * for low speed and full speed operation. */
#if (CONF_USBHS_SRC == CONF_SRC_USB_48M)
#if (CONF_USBHS_FREQUENCY > (48000000 + 48000000 / 400)) || (CONF_USBHS_FREQUENCY < (48000000 - 48000000 / 400))
#warning USB clock should be 48MHz ~ 0.25% clock, check your configuration!
#endif
#endif

void USB_DEVICE_INSTANCE_CLOCK_init(void)
{
	_pmc_enable_periph_clock(ID_USBHS);
}

void USB_DEVICE_INSTANCE_init(void)
{
	USB_DEVICE_INSTANCE_CLOCK_init();
	usb_d_init();
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

	// GPIO on PC31

	// Set pin direction to output
	gpio_set_pin_direction(PIN_SX1238_RESET, GPIO_DIRECTION_OUT);

	gpio_set_pin_level(PIN_SX1238_RESET,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	gpio_set_pin_function(PIN_SX1238_RESET, GPIO_PIN_FUNCTION_OFF);

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

	delay_driver_init();

	USB_DEVICE_INSTANCE_init();
}
