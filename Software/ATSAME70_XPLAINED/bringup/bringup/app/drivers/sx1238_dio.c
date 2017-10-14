/** @file sx1238_dio.c
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
#include "sx1238.h"
#include "sx1238_reg.h"

/******************************************************************************
Defines
******************************************************************************/

/******************************************************************************
Private Data Types
******************************************************************************/
typedef enum
{
    SX1238_FIFO_EMPTY = 0,
    SX1238_FIFO_FULL,
    SX1238_FIFO_LEVEL,
    SX1238_FIFO_PAYLOAD_READY
} sx1238_fifo_status_t;

/******************************************************************************
Public Variable Definitions
******************************************************************************/

/******************************************************************************
Private Constants
******************************************************************************/

/******************************************************************************
Private Variables
******************************************************************************/
static sx1238_fifo_status_t fifo_status;


/******************************************************************************
Private Function Declarations
******************************************************************************/


/******************************************************************************
Public Function Definitions
******************************************************************************/
void sx1238_dio5_isr_handler(void)
{   
   /* 
       To avoid SPI read delay during an ISR, only the most recent
       sx1238_data_mode, sx1238_mode, and sx1238_dioX_mapping are read. 
   */
    switch (sx1238_data_mode)
    {
        case SX1238_CONTINUOUS:
            switch (sx1238_mode)
            {
                case SX1238_SLEEP:
                    switch (sx1238_dio5_mapping)
                    {
                        case MAP_0:
                            // Do nothing
                            break;
                            
                        case MAP_1:
                            // Do nothing
                            break;
                            
                        case MAP_2:
                            // Do nothing
                            break;
                         
                        case MAP_3:
                            // Do nothing
                            break;
                    }
                    break;
                
                case SX1238_STDBY:
                    switch (sx1238_dio5_mapping)
                    {
                        case MAP_0:
                            // CLK OUT
                            break;
                            
                        case MAP_1:
                            // Do nothing
                            break;
                            
                        case MAP_2:
                            // Do nothing
                            break;
                         
                        case MAP_3:
                            sx1238_flags.mode_ready = true;
                            break;
                    }
                    break;
                    
                case SX1238_FS_MODE_TX:
                case SX1238_FS_MODE_RX:
                    switch (sx1238_dio5_mapping)
                    {
                        case MAP_0:
                            // CLK OUT
                            break;
                            
                        case MAP_1:
                            sx1238_flags.pll_lock = true;
                            break;
                            
                        case MAP_2:
                            // Do nothing
                            break;
                         
                        case MAP_3:
                            sx1238_flags.mode_ready = true;
                            break;
                    }
                    break;
                    
                case SX1238_RX:
                    switch (sx1238_dio5_mapping)
                    {
                        case MAP_0:
                            // CLK OUT
                            break;
                            
                        case MAP_1:
                            sx1238_flags.pll_lock = true;
                            break;
                            
                        case MAP_2:
                            sx1238_flags.rssi_preamdetect = true;
                            break;
                         
                        case MAP_3:
                            sx1238_flags.mode_ready = true;
                            break;
                    }
                    break;
                    
                case SX1238_TX:
                    switch (sx1238_dio5_mapping)
                    {
                        case MAP_0:
                            // CLK OUT
                            break;
                            
                        case MAP_1:
                            sx1238_flags.pll_lock = true;
                            break;
                            
                        case MAP_2:
                            // Do nothing
                            break;
                         
                        case MAP_3:
                            sx1238_flags.mode_ready = true;
                            break;
                    }
                    break;
            }
            break;
            
        case SX1238_PACKET:
            switch (sx1238_mode)
            {
                case SX1238_SLEEP:
                    switch (sx1238_dio5_mapping)
                    {
                        case MAP_0:
                            // Do nothing
                            break;
                            
                        case MAP_1:
                            // Do nothing
                            break;
                            
                        case MAP_2:
                            // Do nothing
                            break;
                         
                        case MAP_3:
                            // Do nothing
                            break;
                    }
                    break;
                
                case SX1238_STDBY:
                    switch (sx1238_dio5_mapping)
                    {
                        case MAP_0:
                            // CLK OUT
                            break;
                            
                        case MAP_1:
                            // Do nothing
                            break;
                            
                        case MAP_2:
                            // Do nothing
                            break;
                         
                        case MAP_3:
                            sx1238_flags.mode_ready = true;
                            break;
                    }
                    break;
                
                case SX1238_FS_MODE_TX:
                case SX1238_FS_MODE_RX:
                    switch (sx1238_dio5_mapping)
                    {
                        case MAP_0:
                            // CLK OUT
                            break;
                            
                        case MAP_1:
                            sx1238_flags.pll_lock = true;
                            break;
                            
                        case MAP_2:
                            // Do nothing
                            break;
                         
                        case MAP_3:
                            sx1238_flags.mode_ready = true;
                            break;
                    }
                    break;
                
                case SX1238_RX:
                    switch (sx1238_dio5_mapping)
                    {
                        case MAP_0:
                            // CLK OUT
                            break;
                            
                        case MAP_1:
                            sx1238_flags.pll_lock = true;
                            break;
                            
                        case MAP_2:
                            // DATA
                            break;
                         
                        case MAP_3:
                            // @todo
                            break;
                    }
                    break;
                
                case SX1238_TX:
                    switch (sx1238_dio5_mapping)
                    {
                        case MAP_0:
                            // @todo
                            break;
                            
                        case MAP_1:
                            // @todo
                            break;
                            
                        case MAP_2:
                            // @todo
                            break;
                         
                        case MAP_3:
                            // @todo
                            break;
                    }
                break;
            break;
    }    
}

void sx1238_dio4_isr_handler(void)
{   
   /* 
       To avoid SPI read delay during an ISR, only the most recent
       sx1238_data_mode, sx1238_mode, and sx1238_dioX_mapping are read. 
   */
    switch (sx1238_data_mode)
    {
        case SX1238_CONTINUOUS:
            switch (sx1238_mode)
            {
                case SX1238_SLEEP:
                    switch (sx1238_dio4_mapping)
                    {
                        case MAP_0:
                            // Do nothing
                            break;
                            
                        case MAP_1:
                            // Do nothing
                            break;
                            
                        case MAP_2:
                            // Do nothing
                            break;
                         
                        case MAP_3:
                            // Do nothing
                            break;
                    }
                    break;
                
                case SX1238_STDBY:
                    switch (sx1238_dio4_mapping)
                    {
                        case MAP_0:
                            sx1238_flags.tempchange_lowbat = true;
                            break;
                            
                        case MAP_1:
                            // Do nothing
                            break;
                            
                        case MAP_2:
                            // Do nothing
                            break;
                         
                        case MAP_3:
                            sx1238_flags.mode_ready = true;
                            break;
                    }
                    break;
                    
                case SX1238_FS_MODE_TX:
                case SX1238_FS_MODE_RX:
                    switch (sx1238_dio4_mapping)
                    {
                        case MAP_0:
                            sx1238_flags.tempchange_lowbat = true;
                            break;
                            
                        case MAP_1:
                            sx1238_flags.pll_lock = true;
                            break;
                            
                        case MAP_2:
                            // Do nothing
                            break;
                         
                        case MAP_3:
                            sx1238_flags.mode_ready = true;
                            break;
                    }
                    break;
                    
                case SX1238_RX:
                    switch (sx1238_dio4_mapping)
                    {
                        case MAP_0:
                            sx1238_flags.tempchange_lowbat = true;
                            break;
                            
                        case MAP_1:
                            sx1238_flags.pll_lock = true;
                            break;
                            
                        case MAP_2:
                            sx1238_flags.timeout = true;
                            break;
                         
                        case MAP_3:
                            sx1238_flags.mode_ready = true;
                            break;
                    }
                    break;
                    
                case SX1238_TX:
                    switch (sx1238_dio4_mapping)
                    {
                        case MAP_0:
                            sx1238_flags.tempchange_lowbat = true;
                            break;
                            
                        case MAP_1:
                            sx1238_flags.pll_lock = true;
                            break;
                            
                        case MAP_2:
                            // Do nothing
                            break;
                         
                        case MAP_3:
                            sx1238_flags.mode_ready = true;
                            break;
                    }
                    break;
            }
            break;
            
        case SX1238_PACKET:
            switch (sx1238_mode)
            {
                case SX1238_SLEEP:
                    switch (sx1238_dio4_mapping)
                    {
                        case MAP_0:
                            // Do nothing
                            break;
                            
                        case MAP_1:
                            // Do nothing
                            break;
                            
                        case MAP_2:
                            // Do nothing
                            break;
                         
                        case MAP_3:
                            // Do nothing
                            break;
                    }
                    break;
                
                case SX1238_STDBY:
                    switch (sx1238_dio4_mapping)
                    {
                        case MAP_0:
                            sx1238_flags.tempchange_lowbat = true;
                            break;
                            
                        case MAP_1:
                            // Do nothing
                            break;
                            
                        case MAP_2:
                            // Do nothing
                            break;
                         
                        case MAP_3:
                            // Do nothing
                            break;
                    }
                    break;
                
                case SX1238_FS_MODE_TX:
                case SX1238_FS_MODE_RX:
                    switch (sx1238_dio4_mapping)
                    {
                        case MAP_0:
                            sx1238_flags.tempchange_lowbat = true;
                            break;
                            
                        case MAP_1:
                            sx1238_flags.pll_lock = true;
                            break;
                            
                        case MAP_2:
                            // Do nothing
                            break;
                         
                        case MAP_3:
                            // Do nothing
                            break;
                    }
                    break;
                
                case SX1238_RX:
                    switch (sx1238_dio4_mapping)
                    {
                        case MAP_0:
                            sx1238_flags.tempchange_lowbat = true;
                            break;
                            
                        case MAP_1:
                            sx1238_flags.pll_lock = true;
                            break;
                            
                        case MAP_2:
                            sx1238_flags.timeout = true;
                            break;
                         
                        case MAP_3:
                            sx1238_flags.rssi_preamdetect = true;
                            break;
                    }
                    break;
                
                case SX1238_TX:
                    switch (sx1238_dio4_mapping)
                    {
                        case MAP_0:
                            sx1238_flags.tempchange_lowbat = true;
                            break;
                            
                        case MAP_1:
                            sx1238_flags.pll_lock = true;
                            break;
                            
                        case MAP_2:
                            // Do nothing
                            break;
                         
                        case MAP_3:
                            // Do nothing
                            break;
                    }
                break;
            break;
    }    
}

void sx1238_dio3_isr_handler(void)
{   
   /* 
       To avoid SPI read delay during an ISR, only the most recent
       sx1238_data_mode, sx1238_mode, and sx1238_dioX_mapping are read. 
   */
    switch (sx1238_data_mode)
    {
        case SX1238_CONTINUOUS:
            switch (sx1238_mode)
            {
                case SX1238_SLEEP:
                    switch (sx1238_dio3_mapping)
                    {
                        case MAP_0:
                            // Do nothing
                            break;
                            
                        case MAP_1:
                            // Do nothing
                            break;
                            
                        case MAP_2:
                            // Do nothing
                            break;
                         
                        case MAP_3:
                            // Do nothing
                            break;
                    }
                    break;
                
                case SX1238_STDBY:
                    switch (sx1238_dio3_mapping)
                    {
                        case MAP_0:
                            // Do nothing
                            break;
                            
                        case MAP_1:
                            // Do nothing
                            break;
                            
                        case MAP_2:
                            // Do nothing
                            break;
                         
                        case MAP_3:
                            sx1238_flags.tempchange_lowbat = true;
                            break;
                    }
                    break;
                    
                case SX1238_FS_MODE_TX:
                case SX1238_FS_MODE_RX:
                    switch (sx1238_dio3_mapping)
                    {
                        case MAP_0:
                            // Do nothing
                            break;
                            
                        case MAP_1:
                            // Do nothing
                            break;
                            
                        case MAP_2:
                            sx1238_flags.auto_mode = true;
                            break;
                         
                        case MAP_3:
                            sx1238_flags.tempchange_lowbat = true;
                            break;
                    }
                    break;
                    
                case SX1238_RX:
                    switch (sx1238_dio3_mapping)
                    {
                        case MAP_0:
                            sx1238_flags.timeout = true;
                            break;
                            
                        case MAP_1:
                            sx1238_flags.rssi_preamdetect = true;
                            break;
                            
                        case MAP_2:
                            // Do nothing
                            break;
                         
                        case MAP_3:
                           sx1238_flags.tempchange_lowbat = true;
                            break;
                    }
                    break;
                    
                case SX1238_TX:
                    switch (sx1238_dio3_mapping)
                    {
                        case MAP_0:
                            // Do nothing
                            break;
                            
                        case MAP_1:
                            // Do nothing
                            break;
                            
                        case MAP_2:
                            // Do nothing
                            break;
                         
                        case MAP_3:
                            sx1238_flags.tempchange_lowbat = true;
                            break;
                    }
                    break;
            }
            break;
            
        case SX1238_PACKET:
            switch (sx1238_mode)
            {
                case SX1238_SLEEP:
                    switch (sx1238_dio3_mapping)
                    {
                        case MAP_0:
                            sx1238_flags.fifo_empty = true;
                            break;
                            
                        case MAP_1:
                            // Do nothing
                            break;
                            
                        case MAP_2:
                            sx1238_flags.fifo_empty = true;
                            break;
                         
                        case MAP_3:
                            sx1238_flags.fifo_empty = true;
                            break;
                    }
                    break;
                
                case SX1238_STDBY:
                    switch (sx1238_dio3_mapping)
                    {
                        case MAP_0:
                            sx1238_flags.fifo_empty = true;
                            break;
                            
                        case MAP_1:
                            // Do nothing
                            break;
                            
                        case MAP_2:
                            sx1238_flags.fifo_empty = true;
                            break;
                         
                        case MAP_3:
                            sx1238_flags.fifo_empty = true;
                            break;
                    }
                    break;
                
                case SX1238_FS_MODE_TX:
                case SX1238_FS_MODE_RX:
                    switch (sx1238_dio3_mapping)
                    {
                        case MAP_0:
                            sx1238_flags.fifo_empty = true;
                            break;
                            
                        case MAP_1:
                            // Do nothing
                            break;
                            
                        case MAP_2:
                            sx1238_flags.fifo_empty = true;
                            break;
                         
                        case MAP_3:
                            sx1238_flags.fifo_empty = true;
                            break;
                    }
                    break;
                
                case SX1238_RX:
                    switch (sx1238_dio3_mapping)
                    {
                        case MAP_0:
                            sx1238_flags.fifo_empty = true;
                            break;
                            
                        case MAP_1:
                            // Do nothing
                            break;
                            
                        case MAP_2:
                            sx1238_flags.fifo_empty = true;
                            break;
                         
                        case MAP_3:
                            sx1238_flags.fifo_empty = true;
                            break;
                    }
                    break;
                
                case SX1238_TX:
                    switch (sx1238_dio3_mapping)
                    {
                        case MAP_0:
                            sx1238_flags.fifo_empty = true;
                            break;
                            
                        case MAP_1:
                            sx1238_flags.tx_ready = true;
                            break;
                            
                        case MAP_2:
                            sx1238_flags.fifo_empty = true;
                            break;
                         
                        case MAP_3:
                            sx1238_flags.fifo_empty = true;
                            break;
                    }
                break;
            break;
    }    
}

void sx1238_dio2_isr_handler(void)
{   
   /* 
       To avoid SPI read delay during an ISR, only the most recent
       sx1238_data_mode, sx1238_mode, and sx1238_dioX_mapping are read. 
   */
    switch (sx1238_data_mode)
    {
        case SX1238_CONTINUOUS:
            switch (sx1238_mode)
            {
                case SX1238_SLEEP:
                    switch (sx1238_dio2_mapping)
                    {
                        case MAP_0:
                            // Do nothing
                            break;
                            
                        case MAP_1:
                            // Do nothing
                            break;
                            
                        case MAP_2:
                            // Do nothing
                            break;
                         
                        case MAP_3:
                            // Do nothing
                            break;
                    }
                    break;
                
                case SX1238_STDBY:
                    switch (sx1238_dio2_mapping)
                    {
                        case MAP_0:
                            // Do nothing
                            break;
                            
                        case MAP_1:
                            // Do nothing
                            break;
                            
                        case MAP_2:
                            // Do nothing
                            break;
                         
                        case MAP_3:
                            // Do nothing
                            break;
                    }
                    break;
                    
                case SX1238_FS_MODE_TX:
                case SX1238_FS_MODE_RX:
                    switch (sx1238_dio2_mapping)
                    {
                        case MAP_0:
                            // Do nothing
                            break;
                            
                        case MAP_1:
                            // Do nothing
                            break;
                            
                        case MAP_2:
                            // Do nothing
                            break;
                         
                        case MAP_3:
                            // Do nothing
                            break;
                    }
                    break;
                    
                case SX1238_RX:
                    switch (sx1238_dio2_mapping)
                    {
                        case MAP_0:
                            // DATA (in)
                            break;
                            
                        case MAP_1:
                            // DATA (in)
                            break;
                            
                        case MAP_2:
                            // DATA (in)
                            break;
                         
                        case MAP_3:
                            // DATA (in)
                            break;
                    }
                    break;
                    
                case SX1238_TX:
                    switch (sx1238_dio2_mapping)
                    {
                        case MAP_0:
                            // DATA (out)
                            break;
                            
                        case MAP_1:
                            // DATA (out)
                            break;
                            
                        case MAP_2:
                            // DATA (out)
                            break;
                         
                        case MAP_3:
                            // DATA (out)
                            break;
                    }
                    break;
            }
            break;
            
        case SX1238_PACKET:
            switch (sx1238_mode)
            {
                case SX1238_SLEEP:
                    switch (sx1238_dio2_mapping)
                    {
                        case MAP_0:
                            sx1238_flags.fifo_full = true;
                            break;
                            
                        case MAP_1:
                            // Do nothing
                            break;
                            
                        case MAP_2:
                            sx1238_flags.fifo_full = true;
                            break;
                         
                        case MAP_3:
                            sx1238_flags.fifo_full = true;
                            break;
                    }
                    break;
                
                case SX1238_STDBY:
                    switch (sx1238_dio2_mapping)
                    {
                        case MAP_0:
                            sx1238_flags.fifo_full = true;
                            break;
                            
                        case MAP_1:
                            // Do nothing
                            break;
                            
                        case MAP_2:
                            sx1238_flags.fifo_full = true;
                            break;
                         
                        case MAP_3:
                            sx1238_flags.fifo_full = true;
                            break;
                    }
                    break;
                
                case SX1238_FS_MODE_TX:
                case SX1238_FS_MODE_RX:
                    switch (sx1238_dio2_mapping)
                    {
                        case MAP_0:
                            sx1238_flags.fifo_full = true;
                            break;
                            
                        case MAP_1:
                            // Do nothing
                            break;
                            
                        case MAP_2:
                            sx1238_flags.fifo_full = true;
                            break;
                         
                        case MAP_3:
                            sx1238_flags.fifo_full = true;
                            break;
                    }
                    break;
                
                case SX1238_RX:
                    switch (sx1238_dio2_mapping)
                    {
                        case MAP_0:
                            sx1238_flags.fifo_full = true;
                            break;
                            
                        case MAP_1:
                            sx1238_flags.rx_ready = true;
                            break;
                            
                        case MAP_2:
                            sx1238_flags.timeout = true;
                            break;
                         
                        case MAP_3:
                            sx1238_flags.sync_address = true;
                            break;
                    }
                    break;
                
                case SX1238_TX:
                    switch (sx1238_dio2_mapping)
                    {
                        case MAP_0:
                            sx1238_flags.fifo_full = true;
                            break;
                            
                        case MAP_1:
                            // Do nothing
                            break;
                            
                        case MAP_2:
                            sx1238_flags.fifo_full = true;
                            break;
                         
                        case MAP_3:
                            sx1238_flags.fifo_full = true;
                            break;
                    }
                break;
            break;
    }    
}

void sx1238_dio1_isr_handler(void)
{   
   /* 
       To avoid SPI read delay during an ISR, only the most recent
       sx1238_data_mode, sx1238_mode, and sx1238_dioX_mapping are read. 
   */
    switch (sx1238_data_mode)
    {
        case SX1238_CONTINUOUS:
            switch (sx1238_mode)
            {
                case SX1238_SLEEP:
                    switch (sx1238_dio1_mapping)
                    {
                        case MAP_0:
                            // Do nothing
                            break;
                            
                        case MAP_1:
                            // Do nothing
                            break;
                            
                        case MAP_2:
                            // Do nothing
                            break;
                         
                        case MAP_3:
                            // Do nothing
                            break;
                    }
                    break;
                
                case SX1238_STDBY:
                    switch (sx1238_dio1_mapping)
                    {
                        case MAP_0:
                            // Do nothing
                            break;
                            
                        case MAP_1:
                            // Do nothing
                            break;
                            
                        case MAP_2:
                            // Do nothing
                            break;
                         
                        case MAP_3:
                            // Do nothing
                            break;
                    }
                    break;
                    
                case SX1238_FS_MODE_TX:
                case SX1238_FS_MODE_RX:
                    switch (sx1238_dio1_mapping)
                    {
                        case MAP_0:
                            // Do nothing
                            break;
                            
                        case MAP_1:
                            // Do nothing
                            break;
                            
                        case MAP_2:
                            // Do nothing
                            break;
                         
                        case MAP_3:
                            // Do nothing
                            break;
                    }
                    break;
                    
                case SX1238_RX:
                    switch (sx1238_dio1_mapping)
                    {
                        case MAP_0:
                            // DCLK in
                            break;
                            
                        case MAP_1:
                            sx1238_flags.rssi_preamdetect = true;
                            break;
                            
                        case MAP_2:
                            // Do nothing
                            break;
                         
                        case MAP_3:
                            // Do nothing
                            break;
                    }
                    break;
                    
                case SX1238_TX:
                    switch (sx1238_dio1_mapping)
                    {
                        case MAP_0:
                            // DCLK in
                            break;
                            
                        case MAP_1:
                            // Do nothing
                            break;
                            
                        case MAP_2:
                            // Do nothing
                            break;
                         
                        case MAP_3:
                            // Do nothing
                            break;
                    }
                    break;
            }
            break;
            
        case SX1238_PACKET:
            switch (sx1238_mode)
            {
                case SX1238_SLEEP:
                    switch (sx1238_dio1_mapping)
                    {
                        case MAP_0:
                            sx1238_flags.fifo_level = true;
                            break;
                            
                        case MAP_1:
                            sx1238_flags.fifo_empty = true;
                            break;
                            
                        case MAP_2:
                            sx1238_flags.fifo_full = true;
                            break;
                         
                        case MAP_3:
                            // Do nothing
                            break;
                    }
                    break;
                
                case SX1238_STDBY:
                    switch (sx1238_dio1_mapping)
                    {
                        case MAP_0:
                            sx1238_flags.fifo_level = true;
                            break;
                            
                        case MAP_1:
                            sx1238_flags.fifo_empty = true;
                            break;
                            
                        case MAP_2:
                            sx1238_flags.fifo_full = true;
                            break;
                         
                        case MAP_3:
                            // Do nothing
                            break;
                    }
                    break;
                
                case SX1238_FS_MODE_TX:
                case SX1238_FS_MODE_RX:
                    switch (sx1238_dio1_mapping)
                    {
                        case MAP_0:
                            sx1238_flags.fifo_level = true;
                            break;
                            
                        case MAP_1:
                            sx1238_flags.fifo_empty = true;
                            break;
                            
                        case MAP_2:
                            sx1238_flags.fifo_full = true;
                            break;
                         
                        case MAP_3:
                            // Do nothing
                            break;
                    }
                    break;
                
                case SX1238_RX:
                    switch (sx1238_dio1_mapping)
                    {
                        case MAP_0:
                            sx1238_flags.fifo_level = true;
                            break;
                            
                        case MAP_1:
                            sx1238_flags.fifo_empty = true;
                            break;
                            
                        case MAP_2:
                            sx1238_flags.fifo_full = true;
                            break;
                         
                        case MAP_3:
                            // Do nothing
                            break;
                    }
                    break;
                
                case SX1238_TX:
                    switch (sx1238_dio1_mapping)
                    {
                        case MAP_0:
                            sx1238_flags.fifo_level = true;
                            break;
                            
                        case MAP_1:
                            sx1238_flags.fifo_empty = true;
                            break;
                            
                        case MAP_2:
                            sx1238_flags.fifo_full = true;
                            break;
                         
                        case MAP_3:
                            // Do nothing
                            break;
                    }
                break;
            break;
    }    
}

void sx1238_dio0_isr_handler(void)
{   
   /* 
       To avoid SPI read delay during an ISR, only the most recent
       sx1238_data_mode, sx1238_mode, and sx1238_dioX_mapping are read. 
   */
    switch (sx1238_data_mode)
    {
        case SX1238_CONTINUOUS:
            switch (sx1238_mode)
            {
                case SX1238_SLEEP:
                    switch (sx1238_dio0_mapping)
                    {
                        case MAP_0:
                            // Do nothing
                            break;
                            
                        case MAP_1:
                            // Do nothing
                            break;
                            
                        case MAP_2:
                            // Do nothing
                            break;
                         
                        case MAP_3:
                            // Do nothing
                            break;
                    }
                    break;
                
                case SX1238_STDBY:
                    switch (sx1238_dio0_mapping)
                    {
                        case MAP_0:
                            // Do nothing
                            break;
                            
                        case MAP_1:
                            // Do nothing
                            break;
                            
                        case MAP_2:
                            // Do nothing
                            break;
                         
                        case MAP_3:
                            // Do nothing
                            break;
                    }
                    break;
                    
                case SX1238_FS_MODE_TX:
                case SX1238_FS_MODE_RX:
                    switch (sx1238_dio0_mapping)
                    {
                        case MAP_0:
                            // Do nothing
                            break;
                            
                        case MAP_1:
                            // Do nothing
                            break;
                            
                        case MAP_2:
                            // Do nothing
                            break;
                         
                        case MAP_3:
                            // Do nothing
                            break;
                    }
                    break;
                    
                case SX1238_RX:
                    switch (sx1238_dio0_mapping)
                    {
                        case MAP_0:
                            sx1238_flags.sync_address = true;
                            break;
                            
                        case MAP_1:
                            sx1238_flags.rssi_preamdetect = true;
                            break;
                            
                        case MAP_2:
                            sx1238_flags.rx_ready = true;
                            break;
                         
                        case MAP_3:
                            // Do nothing
                            break;
                    }
                    break;
                    
                case SX1238_TX:
                    switch (sx1238_dio0_mapping)
                    {
                        case MAP_0:
                            sx1238_flags.tx_ready = true;
                            break;
                            
                        case MAP_1:
                            // Do nothing
                            break;
                            
                        case MAP_2:
                            // Do nothing
                            break;
                         
                        case MAP_3:
                            // Do nothing
                            break;
                    }
                    break;
            }
            break;
            
        case SX1238_PACKET:
            switch (sx1238_mode)
            {
                case SX1238_SLEEP:
                    switch (sx1238_dio0_mapping)
                    {
                        case MAP_0:
                            // Do nothing
                            break;
                            
                        case MAP_1:
                            // Do nothing
                            break;
                            
                        case MAP_2:
                            // Do nothing
                            break;
                         
                        case MAP_3:
                            sx1238_flags.tempchange_lowbat = true;
                            break;
                    }
                    break;
                
                case SX1238_STDBY:
                    switch (sx1238_dio0_mapping)
                    {
                        case MAP_0:
                            // Do nothing
                            break;
                            
                        case MAP_1:
                            // Do nothing
                            break;
                            
                        case MAP_2:
                            // Do nothing
                            break;
                         
                        case MAP_3:
                            sx1238_flags.tempchange_lowbat = true;
                            break;
                    }
                    break;
                
                case SX1238_FS_MODE_TX:
                case SX1238_FS_MODE_RX:
                    switch (sx1238_dio0_mapping)
                    {
                        case MAP_0:
                            // Do nothing
                            break;
                            
                        case MAP_1:
                            // Do nothing
                            break;
                            
                        case MAP_2:
                            // Do nothing
                            break;
                         
                        case MAP_3:
                            sx1238_flags.tempchange_lowbat = true;
                            break;
                    }
                    break;
                
                case SX1238_RX:
                    switch (sx1238_dio0_mapping)
                    {
                        case MAP_0:
                            sx1238_flags.payload_ready = true;
                            break;
                            
                        case MAP_1:
                            sx1238_flags.crc_ok = true;
                            break;
                            
                        case MAP_2:
                            // Do nothing
                            break;
                         
                        case MAP_3:
                            sx1238_flags.tempchange_lowbat = true;
                            break;
                    }
                    break;
                
                case SX1238_TX:
                    switch (sx1238_dio0_mapping)
                    {
                        case MAP_0:
                            sx1238_flags.packet_sent = true;
                            break;
                            
                        case MAP_1:
                            // Do nothing
                            break;
                            
                        case MAP_2:
                            // Do nothing
                            break;
                         
                        case MAP_3:
                            sx1238_flags.tempchange_lowbat = true;
                            break;
                    }
                break;
            break;
    }    
}
