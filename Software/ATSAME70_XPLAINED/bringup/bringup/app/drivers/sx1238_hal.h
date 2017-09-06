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
#include <stdint.h>

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
<<<<<<< HEAD:Software/ATSAME70_XPLAINED/bringup/bringup/app/drivers/sx1238_hal.h
void sx1238_hal_write(uint8_t addr, uint8_t data);
uint8_t sx1238_hal_read(uint8_t addr);
void sx1238_hal_write_buffer(uint8_t addr, uint8_t *buffer, uint16_t size);
void sx1238_hal_read_buffer(uint8_t addr, uint8_t *buffer, uint16_t size);
<<<<<<< HEAD:Software/ATSAME70_XPLAINED/bringup/bringup/app/drivers/sx1238_hal.h
=======

/******************************************************************************
Public Inline Functions
******************************************************************************/
inline void sx1238_hal_delay_ms(uint16_t ms)
{
    delay_ms(ms);
}
>>>>>>> 5c86e46b7419287310aca17eae006f9d7e42162a:Software/ATSAMD21G18A/FritzRT_Bringup/FritzRT_Bringup/FritzRT_Bringup0/app/drivers/sx1238_hal.h
=======
void sx1238_write(uint8_t addr, uint8_t data);
uint8_t sx1238_read(uint8_t addr);
void sx1238_write_buffer(uint8_t addr, uint8_t *buffer, uint16_t size);
void sx1238_read_buffer(uint8_t addr, uint8_t *buffer, uint16_t size);
>>>>>>> parent of 5c86e46... Updated HAL:Software/ATSAMD21G18A/FritzRT_Bringup/FritzRT_Bringup/FritzRT_Bringup0/app/drivers/sx1238_hal.h

#endif // _SX1238_HAL_H
