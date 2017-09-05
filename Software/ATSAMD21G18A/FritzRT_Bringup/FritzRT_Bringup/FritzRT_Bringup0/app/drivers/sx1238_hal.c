/** @file sx1238_hal.c
*
* @brief @todo A description of the module’s purpose.
*
* @par
* COPYRIGHT NOTICE: (c) 2017 John Fritz
* All rights reserved.
*/

/******************************************************************************
Includes
******************************************************************************/
#include <stdbool.h>
#include <atmel_start.h>
#include "sx1238_hal.h"

/******************************************************************************
Defines
******************************************************************************/
#define SX1238_SPI_RW_BUFFER_MAX_SIZE   256
#define SX1238_SPI_BYTE_RW_BUFFER_SIZE  2

/******************************************************************************
Private Data Types
******************************************************************************/

/******************************************************************************
Public Variable Definitions
******************************************************************************/

/******************************************************************************
Private Variables
******************************************************************************/
static struct io_descriptor *sx1238_ctrl_spi_io;
uint8_t sx1238_hal_spi_byte_rw_buffer[SX1238_SPI_BYTE_RW_BUFFER_SIZE] = {0};
uint8_t sx1238_hal_spi_rw_buffer[SX1238_SPI_RW_BUFFER_MAX_SIZE] = {0};

/******************************************************************************
Private Function Declarations
******************************************************************************/
void sx1238_hal_spi_stop(void);
void sx1238_hal_spi_start(void);

/******************************************************************************
Public Function Definitions
******************************************************************************/
void sx1238_hal_write(uint8_t addr, uint8_t data)
{
    sx1238_hal_spi_byte_rw_buffer[0] = addr;
    sx1238_hal_spi_byte_rw_buffer[1] = data;

    struct spi_xfer temp_xfer = 
    {
        .txbuf = sx1238_hal_spi_byte_rw_buffer,
        .rxbuf = sx1238_hal_spi_byte_rw_buffer,
        .size = SX1238_SPI_BYTE_RW_BUFFER_SIZE
    };

    sx1238_hal_spi_start();    
    spi_m_sync_transfer(&CTRL_SPI, &temp_xfer);
    sx1238_hal_spi_stop();
}

uint8_t sx1238_hal_read(uint8_t addr)
{
    sx1238_hal_spi_byte_rw_buffer[0] = addr;
    sx1238_hal_spi_byte_rw_buffer[1] = 0x00;

    struct spi_xfer temp_xfer =
    {
        .txbuf = sx1238_hal_spi_byte_rw_buffer,
        .rxbuf = sx1238_hal_spi_byte_rw_buffer,
        .size = SX1238_SPI_BYTE_RW_BUFFER_SIZE
    };

    sx1238_hal_spi_start();
    spi_m_sync_transfer(&CTRL_SPI, &temp_xfer);
    sx1238_hal_spi_stop();

    return (sx1238_hal_spi_byte_rw_buffer[1]);
}

void sx1238_hal_write_buffer(uint8_t addr, uint8_t *buffer, uint16_t size)
{
    sx1238_hal_spi_rw_buffer[0] = addr;

    for (uint16_t i = 0; i < size; i++)
    {
        sx1238_hal_spi_rw_buffer[i + 1] = buffer[i];
    }

    struct spi_xfer temp_xfer =
    {
        .txbuf = sx1238_hal_spi_rw_buffer,
        .rxbuf = sx1238_hal_spi_rw_buffer,
        .size = SX1238_SPI_BYTE_RW_BUFFER_SIZE
    };

    sx1238_hal_spi_start();
    spi_m_sync_transfer(&CTRL_SPI, &temp_xfer);
    sx1238_hal_spi_stop();
}

void sx1238_hal_read_buffer(uint8_t addr, uint8_t *buffer, uint16_t size)
{
    sx1238_hal_spi_rw_buffer[0] = addr;

    for (uint16_t i = 0; i < size; i++)
    {
        sx1238_hal_spi_rw_buffer[i + 1] = buffer[i];
    }

    struct spi_xfer temp_xfer =
    {
        .txbuf = sx1238_hal_spi_rw_buffer,
        .rxbuf = sx1238_hal_spi_rw_buffer,
        .size = SX1238_SPI_BYTE_RW_BUFFER_SIZE
    };

    sx1238_hal_spi_start();
    spi_m_sync_transfer(&CTRL_SPI, &temp_xfer);
    sx1238_hal_spi_stop();
}

void sx1238_hal_reset(void)
{
    gpio_set_pin_level(PIN_SX1238_RESET, false);
    sx1238_hal_delay_ms(1);
    gpio_set_pin_level(PIN_SX1238_RESET, true);
    sx1238_hal_delay_ms(10);
}

/******************************************************************************
Private Function Definitions
******************************************************************************/
/*!
* @brief Starts SX1238 control SPI
* @return void
*/
void sx1238_hal_spi_start(void)
{
    gpio_set_pin_level(PIN_SPI_CTRL_CS, false);
    spi_m_sync_get_io_descriptor(&CTRL_SPI, &sx1238_ctrl_spi_io);
    spi_m_sync_enable(&CTRL_SPI);
}

/*!
* @brief Stops SX1238 control SPI
* @return void
*/
void sx1238_hal_spi_stop(void)
{
    spi_m_sync_get_io_descriptor(&CTRL_SPI, &sx1238_ctrl_spi_io);
    spi_m_sync_disable(&CTRL_SPI);
    gpio_set_pin_level(PIN_SPI_CTRL_CS, true);
}
