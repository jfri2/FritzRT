#include <atmel_start.h>
#include "./app/app.h"
#include "./app/drivers/task_delay.h"

#define TASK_LED_STACK_SIZE (108 / sizeof(portSTACK_TYPE))
#define TASK_LED_STACK_PRIORITY (tskIDLE_PRIORITY + 1)

#define TASK_CONSOLE_STACK_SIZE (300 / sizeof(portSTACK_TYPE))
#define TASK_CONSOL_STACK_PRIORITY (tskIDLE_PRIORITY + 0)

static TaskHandle_t xCreatedLedTask;
static TaskHandle_t xCreatedConsoleTask;

void task_led_create(void);
void task_console_create(void);
void task_led(void *p);
void task_console(void *p);

int main(void)
{
	// Initializes MCU, drivers and middleware
	atmel_start_init();
    app_init();

	// Create tasks
    task_led_create();
    task_console_create();

    // Start RTOS scheduler
    vTaskStartScheduler();

    // Should never return!
    return 0;
}

void task_led_create(void)
{
    // Create task to make LED blink
    if (xTaskCreate(task_led, "Led", TASK_LED_STACK_SIZE, NULL, TASK_LED_STACK_PRIORITY, xCreatedLedTask) != pdPASS)
    {
        while (1);
    }    
}

void task_console_create(void)
{
    // Create task to handle console I/O
    if (xTaskCreate(task_console, "Console", TASK_CONSOLE_STACK_SIZE, NULL, TASK_CONSOL_STACK_PRIORITY, xCreatedConsoleTask) != pdPASS)
    {
        while (1);
    }
}

void task_led(void *p)
{
    (void)p;
    while (1)
    {
        // todo
        task_delay_ms(500);
    }
}

void task_console(void *p)
{
    (void)p;
    while (1)
    {
        // todo
        task_delay_ms(10);
    }
}
