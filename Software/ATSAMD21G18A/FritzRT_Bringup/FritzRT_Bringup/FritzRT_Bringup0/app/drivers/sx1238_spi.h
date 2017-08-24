/** @file sx1238_spi.h
*
* @brief @todo A description of the module�s purpose. 
*
* @par
* COPYRIGHT NOTICE: (c) 2017 John Fritz
* All rights reserved.
*/

#ifndef _SX1238_SPI_H
#define _SX1238_SPI_H

/******************************************************************************
Includes
******************************************************************************/
#include <stdint.h>

/******************************************************************************
Defines
******************************************************************************/

/******************************************************************************
Public Data Types
******************************************************************************/

/******************************************************************************
Public Variable Declarations
******************************************************************************/

/******************************************************************************
Public Function Declarations
******************************************************************************/
void sx1238_spi_tx_buffer_write(uint8_t *byte, uint32_t bytes);
void sx1238_spi_rx_buffer_write(uint8_t *byte, uint32_t bytes);
void sx1238_spi_xfer_bytes(uint32_t bytes);
void sx1238_spi_stop(void);
void sx1238_spi_start(void);

#endif // _SX1238_SPI_H