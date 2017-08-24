#include <atmel_start.h>
#include "./app/app.h"

int main(void)
{
	// Initializes MCU, MCU drivers and middleware
	atmel_start_init();

    // Initialize application and application drivers
    //app_init();

    // Turn on all user LEDs
    gpio_set_pin_level(PIN_LED_RX, false);
    gpio_set_pin_level(PIN_LED_TX, false);

    // Application Loop
	while (1) 
    {
        gpio_toggle_pin_level(PIN_LED_RX);
        gpio_toggle_pin_level(PIN_LED_TX);
	}
}

void SysTick_Handler(void)
{
    static uint32_t systck_count = 0;
    systck_count++;
}