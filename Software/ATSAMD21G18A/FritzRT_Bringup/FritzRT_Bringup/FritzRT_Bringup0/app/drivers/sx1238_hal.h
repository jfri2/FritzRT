/** @file sx1238_hal.h
*
* @brief @todo A description of the module’s purpose.
*
* @par
* COPYRIGHT NOTICE: (c) 2017 John Fritz
* All rights reserved.
*/

#ifndef _SX1238_HAL_H
#define _SX1238_HAL_H

/******************************************************************************
Includes
******************************************************************************/
#include <atmel_start.h>
#include <utils.h>

/******************************************************************************
Defines
******************************************************************************/
#define SX1238_SPI_RW_BUFFER_MAX_SIZE   256
#define SX1238_SPI_BYTE_RW_BUFFER_SIZE  2

/******************************************************************************
Public Data Types
******************************************************************************/

/******************************************************************************
Public Variable Declarations
******************************************************************************/

/******************************************************************************
Public Function Declarations
******************************************************************************/
void sx1238_write(uint8_t addr, uint8_t data);
uint8_t sx1238_read(uint8_t addr);
void sx1238_write_buffer(uint8_t addr, uint8_t *buffer, uint16_t size);
void sx1238_read_buffer(uint8_t addr, uint8_t *buffer, uint16_t size);

#endif // _SX1238_HAL_H
