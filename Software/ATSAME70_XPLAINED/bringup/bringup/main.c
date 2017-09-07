#include <atmel_start.h>
#include "./app/app.h"

uint8_t test_message[] = "testing...\n";

int main(void)
{
	// Initializes MCU, drivers and middleware
	atmel_start_init();

    app_init();

	// Replace with your application code
	while (1) 
    {
        cdcdf_acm_write(test_message, strlen((char *)test_message));
        delay_ms(1000);
	}
}
