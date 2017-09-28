/** @file sx1238.h
*
* @brief @todo A description of the module’s purpose.
*
* @par
* COPYRIGHT NOTICE: (c) 2017 John Fritz
* All rights reserved.
*/

#ifndef _SX1238_H
#define _SX1238_H

/******************************************************************************
Includes
******************************************************************************/
#include "sx1238_reg.h"

/******************************************************************************
Defines
******************************************************************************/

/******************************************************************************
Public Data Types
******************************************************************************/
typedef enum
{
    SX1238_CONTINUOUS = 0,
    SX1238_PACKET
} sx1238_data_mode_t;

typedef enum
{
    MAP_0 = 0,
    MAP_1,
    MAP_2,
    MAP_3
} sx1238_dio_mapping_t;

typedef struct
{
    // @todo: put in init/config parameters. Edit: Maybe not do this..
} sx1238_config;

typedef struct
{
    bool mode_ready         : 1;
    bool tempchange_lowbat  : 1;
    bool pll_lock           : 1;
    bool auto_mode          : 1;
    bool rssi_preamdetect   : 1;
    bool sync_address       : 1
} sx1238_flags_t;

/******************************************************************************
Public Variable Declarations
******************************************************************************/
sx1238_mode_t           sx1238_mode;
sx1238_data_mode_t      sx1238_data_mode;
sx1238_flags_t          sx1238_flags;
sx1238_dio_mapping_t    sx1238_dio0_mapping;
sx1238_dio_mapping_t    sx1238_dio1_mapping;
sx1238_dio_mapping_t    sx1238_dio2_mapping;
sx1238_dio_mapping_t    sx1238_dio3_mapping;
sx1238_dio_mapping_t    sx1238_dio4_mapping;
sx1238_dio_mapping_t    sx1238_dio5_mapping;


/******************************************************************************
Public Function Declarations
******************************************************************************/
// Note: these functions need to be called in the ISR for DIOs 1-5
void sx1238_dio1_isr_handler(void);
void sx1238_dio2_isr_handler(void);
void sx1238_dio3_isr_handler(void);
void sx1238_dio4_isr_handler(void);
void sx1238_dio5_isr_handler(void);

void sx1238_init(void);
void sx1238_mode_get(void);


#endif // _SX1238_H
