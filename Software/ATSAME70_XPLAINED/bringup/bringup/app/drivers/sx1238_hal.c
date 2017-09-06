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
Private Constants
******************************************************************************/
static const uint8_t WNR_READ_BM = 0x7F;
static const uint8_t WNR_WRITE_BM = 0x80;

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
/*!
* @brief Writes a byte to the SX1238 using SX1238 control spi
* @param[in] addr  Address on SX1238 to write to
* @param[in] data  Byte to write
* @return void
*/
void sx1238_hal_write(uint8_t addr, uint8_t data)
{
    // Load address into spi buffer and set to write access
    sx1238_hal_spi_byte_rw_buffer[0] = (addr | WNR_WRITE_BM);
    sx1238_hal_spi_byte_rw_buffer[1] = data;

    // Create spi transfer struct
    struct spi_xfer temp_xfer = 
    {
        .txbuf = sx1238_hal_spi_byte_rw_buffer,
        .rxbuf = sx1238_hal_spi_byte_rw_buffer,
        .size = SX1238_SPI_BYTE_RW_BUFFER_SIZE
    };

    // Do spi transfer
    sx1238_hal_spi_start();    
    spi_m_sync_transfer(&CTRL_SPI, &temp_xfer);
    sx1238_hal_spi_stop();
}

/*!
* @brief Reads a byte to the SX1238 using SX1238 control spi
* @param[in] addr  Address on SX1238 to read from
* @return uint8_t  Byte read from SX1238
*/
uint8_t sx1238_hal_read(uint8_t addr)
{
    sx1238_hal_spi_byte_rw_buffer[0] = (addr & WNR_READ_BM);
    sx1238_hal_spi_byte_rw_buffer[1] = 0x00;

    // Create spi transfer struct
    struct spi_xfer temp_xfer =
    {
        .txbuf = sx1238_hal_spi_rw_buffer,
        .rxbuf = sx1238_hal_spi_rw_buffer,
        .size = SX1238_SPI_BYTE_RW_BUFFER_SIZE
    };

    // Do spi transfer
    sx1238_hal_spi_start();
    spi_m_sync_transfer(&CTRL_SPI, &temp_xfer);
    sx1238_hal_spi_stop();

    // Return data read from SX1238
    return (sx1238_hal_spi_rw_buffer[1]);
}

/*!
* @brief Writes a buffer of data to the SX1238 over SX1238 control spi
* @param[in] addr  Start address to write to
* @param[in] *buffer  Pointer to data buffer to write to SX1238
* @param[in] size  Number of data bytes to write to SX1238
* @return void
*/
void sx1238_hal_write_buffer(uint8_t addr, uint8_t *buffer, uint16_t size)
{
    // Load address into spi buffer and set to write access
    sx1238_hal_spi_rw_buffer[0] = (addr | WNR_WRITE_BM);
    
    // Load data from buffer passed to this function to spi buffer
    for (uint16_t i = 0; i < size; i++)
    {
        sx1238_hal_spi_rw_buffer[i + 1] = buffer[i];
    }

    // Create spi transfer struct
    struct spi_xfer temp_xfer =
    {
        .txbuf = sx1238_hal_spi_rw_buffer,
        .rxbuf = sx1238_hal_spi_rw_buffer,
        .size = size + 1
    };

    // Do spi transfer
    sx1238_hal_spi_start();
    spi_m_sync_transfer(&CTRL_SPI, &temp_xfer);
    sx1238_hal_spi_stop();    
}

/*!
* @brief Reads a buffer of data from the SX1238 over SX1238 control spi
* @param[in] addr  Start address to read from
* @param[out] *buffer  Pointer to data buffer to store data read from SX1238
* @param[in] size  Number of data bytes to read
* @return void
*/
void sx1238_hal_read_buffer(uint8_t addr, uint8_t *buffer, uint16_t size)
{
    // Load address into spi buffer and set to read access
    sx1238_hal_spi_rw_buffer[0] = (addr & WNR_READ_BM);

    // Create spi transfer struct
    struct spi_xfer temp_xfer =
    {
        .txbuf = sx1238_hal_spi_rw_buffer,
        .rxbuf = sx1238_hal_spi_rw_buffer,
        .size = SX1238_SPI_BYTE_RW_BUFFER_SIZE
    };

    // Do spi transfer
    sx1238_hal_spi_start();
    spi_m_sync_transfer(&CTRL_SPI, &temp_xfer);
    sx1238_hal_spi_stop();
    
    // Move data from temp spi buffer to buffer passed to this function
    for (uint16_t i = 0; i < size; i++)
    {
        buffer[i] = sx1238_hal_spi_rw_buffer[i + 1];
    }
}

/*!
* @brief Resets SX1238
* @return void
*/
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
