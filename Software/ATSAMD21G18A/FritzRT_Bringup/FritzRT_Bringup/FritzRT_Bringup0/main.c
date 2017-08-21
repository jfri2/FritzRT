#include <atmel_start.h>
#include <hal_gpio.h>
#include <hal_delay.h>
#include "./app/app.h"

int main(void)
{
	// Initializes MCU, MCU drivers and middleware
	atmel_start_init();

    // Initialize application and application drivers
    app_init();

    // Application Loop
	while (1) 
    {
        gpio_set_pin_level(PIN_SPI_CTRL_SCK, true);
        gpio_set_pin_level(PIN_LED_RX, true);
        gpio_set_pin_level(PIN_LED_TX, true);
        delay_ms(1000);
        gpio_set_pin_level(PIN_SPI_CTRL_SCK, false);
        gpio_set_pin_level(PIN_LED_RX, false);
        gpio_set_pin_level(PIN_LED_TX, false);
        delay_ms(1000);
	}
}
