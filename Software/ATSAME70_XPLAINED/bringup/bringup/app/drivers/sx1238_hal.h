/** @file sx1238_hal.h
*
* @brief @todo A description of the module�s purpose.
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
#include "task_delay.h"

/******************************************************************************
Defines
******************************************************************************/
#define sx1238_hal_delay_ms(ms) ( task_delay_ms(ms) )

/******************************************************************************
Public Data Types
******************************************************************************/

/******************************************************************************
Public Variable Declarations
******************************************************************************/

/******************************************************************************
Public Function Declarations
******************************************************************************/
void sx1238_hal_write(uint8_t addr, uint8_t data);
uint8_t sx1238_hal_read(uint8_t addr);
void sx1238_hal_write_buffer(uint8_t addr, uint8_t *buffer, uint16_t size);
void sx1238_hal_read_buffer(uint8_t addr, uint8_t *buffer, uint16_t size);
void sx1238_hal_reset(void);

#endif // _SX1238_HAL_H
