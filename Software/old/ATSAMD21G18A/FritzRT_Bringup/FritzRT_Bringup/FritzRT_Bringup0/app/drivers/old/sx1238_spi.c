/** @file sx1238_spi.c
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
#include "sx1238_spi.h"

/******************************************************************************
Defines
******************************************************************************/
#define SX1238_SPI_TX_BUFFER_SIZE  256
#define SX1238_SPI_RX_BUFFER_SIZE  256

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

static uint8_t sx1238_ctrl_spi_tx_buffer[SX1238_SPI_TX_BUFFER_SIZE] = {0};
static uint32_t sx1238_ctrl_spi_tx_buffer_head = 0;
static uint32_t sx1238_ctrl_spi_tx_buffer_tail = 0;

static uint8_t sx1238_ctrl_spi_rx_buffer[SX1238_SPI_RX_BUFFER_SIZE] = {0};
static uint32_t sx1238_ctrl_spi_rx_buffer_head = 0;
static uint32_t sx1238_ctrl_spi_rx_buffer_tail = 0;

/******************************************************************************
Private Function Declarations
******************************************************************************/
void sx1238_spi_tx_buffer_read(uint8_t *buffer, uint32_t bytes);
void sx1238_spi_rx_buffer_write(uint8_t *buffer, uint32_t bytes);
void sx1238_spi_start(void);
void sx1238_spi_stop(void);

/******************************************************************************
Public Function Definitions
******************************************************************************/
/*!
* @brief Write bytes to SX1238 control SPI transmit buffer
* @param[in] c  Pointer to buffer to write into SX1238 control SPI transmit buffer
* @param[in] bytes  Number of bytes to write
* @return void
*/
void sx1238_spi_tx_buffer_write(uint8_t *buffer, uint32_t bytes)
{
    for (uint32_t i = 0; i < bytes; i++)
    {
        sx1238_ctrl_spi_tx_buffer[sx1238_ctrl_spi_tx_buffer_head] = buffer[i];
        sx1238_ctrl_spi_tx_buffer_head++;

        // Wrap head of circular buffer
        if (sx1238_ctrl_spi_tx_buffer_head >= SX1238_SPI_TX_BUFFER_SIZE - 1)
        {
            sx1238_ctrl_spi_tx_buffer_head = 0;
        }
    }
}

/*!
* @brief Read bytes from SX1238 control SPI receive buffer
* @param[out] c  Pointer to buffer to store bytes read from SX1238 control SPI receive buffer
* @param[in] bytes  Number of bytes to read
* @return void
*/
void sx1238_spi_rx_buffer_read(uint8_t *buffer, uint32_t bytes)
{
    for (uint32_t i = 0; i < bytes; i++)
    {
        buffer[i] = sx1238_ctrl_spi_rx_buffer[sx1238_ctrl_spi_rx_buffer_tail];
        sx1238_ctrl_spi_rx_buffer_tail++;

        // Wrap tail of circular buffer
        if (sx1238_ctrl_spi_rx_buffer_tail >= SX1238_SPI_RX_BUFFER_SIZE - 1)
        {
            sx1238_ctrl_spi_rx_buffer_tail = 0;
        }
    }
}

/*!
* @brief Transfers bytes between SX1238 Tx/Rx Control SPI buffers and the SX1238
* @param[in] bytes  Number of bytes to transfer
* @return void
*/
void sx1238_spi_xfer_bytes(uint32_t bytes)
{
    //spi_m_sync_transfer(&CTRL_SPI, spi_xfer);
    // @todo: write spi drier
}

/*!
* @brief Starts SX1238 control SPI
* @return void
*/
void sx1238_spi_start(void)
{
    gpio_set_pin_level(PIN_SPI_CTRL_CS, false);
    spi_m_sync_get_io_descriptor(&CTRL_SPI, &sx1238_ctrl_spi_io);
    spi_m_sync_enable(&CTRL_SPI);
}

/*!
* @brief Stops SX1238 control SPI
* @return void
*/
void sx1238_spi_stop(void)
{
    spi_m_sync_get_io_descriptor(&CTRL_SPI, &sx1238_ctrl_spi_io);
    spi_m_sync_disable(&CTRL_SPI);
    gpio_set_pin_level(PIN_SPI_CTRL_CS, true);
}

/******************************************************************************
Private Function Definitions
******************************************************************************/
/*!
* @brief Read bytes to SX1238 control SPI transmit buffer
* @param[in] c  Pointer to buffer to store bytes read from SX1238 control SPI transmit buffer
* @param[in] bytes  Number of bytes to read
* @return void
*/
void sx1238_spi_tx_buffer_read(uint8_t *buffer, uint32_t bytes)
{
    for (uint32_t i = 0; i < bytes; i++)
    {
        buffer[i] = sx1238_ctrl_spi_tx_buffer[sx1238_ctrl_spi_tx_buffer_tail];
        sx1238_ctrl_spi_tx_buffer_tail++;

        // Wrap tail of circular buffer
        if (sx1238_ctrl_spi_tx_buffer_tail >= SX1238_SPI_TX_BUFFER_SIZE - 1)
        {
            sx1238_ctrl_spi_tx_buffer_tail = 0;
        }
    }
}

/*!
* @brief Write bytes to SX1238 control SPI receive buffer
* @param[out] c  Pointer to buffer to write into SX1238 control SPI receive buffer
* @param[in] bytes  Number of bytes to write
* @return void
*/
void sx1238_spi_rx_buffer_write(uint8_t *buffer, uint32_t bytes)
{
    for (uint32_t i = 0; i < bytes; i++)
    {
        sx1238_ctrl_spi_rx_buffer[sx1238_ctrl_spi_rx_buffer_head] = buffer[i];
        sx1238_ctrl_spi_rx_buffer_head++;

        // Wrap head of circular buffer
        if (sx1238_ctrl_spi_rx_buffer_head >= SX1238_SPI_RX_BUFFER_SIZE - 1)
        {
            sx1238_ctrl_spi_rx_buffer_head = 0;
        }
    }
}
