/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_examples.h"
#include "driver_init.h"
#include "utils.h"

/**
 * Example task of using CTRL_SPI to echo using the IO abstraction.
 */
void CTRL_SPI_example_task(void *p)
{
	struct io_descriptor *io;
	uint16_t              data;

	(void)p;

	spi_m_os_get_io_descriptor(&CTRL_SPI, &io);

	for (;;) {
		if (io_read(io, (uint8_t *)&data, 2) == 2) {
			/* read OK, handle data. */;
		} else {
			/* error. */;
		}
	}
}

void delay_example(void)
{
	delay_ms(5000);
}
