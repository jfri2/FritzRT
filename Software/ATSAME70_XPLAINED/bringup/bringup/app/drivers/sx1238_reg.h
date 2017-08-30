/** @file sx1238_reg.h
*
* @brief @todo A description of the module’s purpose.
*
* @par
* COPYRIGHT NOTICE: (c) 2017 John Fritz
* All rights reserved.
*/

#ifndef _SX1238_REG_H
#define _SX1238_REG_H

/******************************************************************************
Includes
******************************************************************************/

/******************************************************************************
Defines
******************************************************************************/

/******************************************************************************
Public Data Types
******************************************************************************/
typedef enum sx1238_reg_addrs
{
    REG_FIFO = 0x00,
    REG_OP_MODE,
    REG_BITRATE_MSB,
    REG_BITRATE_LSB,
    REG_FDEV_MSB,
    REG_FDEV_LSB,
    REG_FRF_MSB,
    REG_FRF_MID,
    REG_FRF_LSB,
    REG_PA_CONFIG,
    REG_OCP,
    REG_LNA,
    REG_RX_CONFIG,
    REG_RSSI_CONFIG,
    REG_RSSI_COLLISION,
    REG_RSSI_THRESH,
    REG_RSSI_VALUE,
    REG_RX_BW,
    REG_AFC_BW,
    REG_OOK_PEAK,
    REG_OOK_FIX,
    REG_OOK_AVG,
    RESERVED_17,
    RESERVED_18,
    RESERVED_19,
    REG_AFC_FEI,
    REG_AFC_MSB,
    REG_AFC_LSB,
    REG_FEI_MSB,
    REG_FEI_LSB,
    REG_PREAMBLE_DETECT,
    REG_RX_TIMEOUT_1,
    REG_RX_TIMEOUT_2,
    REG_RX_TIMEOUT_3,
    REG_RX_DELAY,
    REG_OSC,
    REG_PREAMBLE_MSB,
    REG_PREAMBLE_LSB,
    REG_SYNC_CONFIG,
    REG_SYNC_VALUE_1,
    REG_SYNC_VALUE_2,
    REG_SYNC_VALUE_3,
    REG_SYNC_VALUE_4,
    REG_SYNC_VALUE_5,
    REG_SYNC_VALUE_6,
    REG_SYNC_VALUE_7,
    REG_SYNC_VALUE_8,
    REG_PACKET_CONFIG_1,
    REG_PACKET_CONFIG_2,
    REG_PAYLOAD_LENGTH,
    REG_NODE_ADRS,
    REG_BROADCAST_ADRS,
    REG_FIFO_THRESH,
    REG_SEQ_CONFIG_1,
    REG_SEQ_CONFIG_2,
    REG_TIMER_RESOL,
    REG_TIMER1_COEF,
    REG_TIMER2_COEF,
    REG_IMAGE_CAL,
    REG_TEMP,
    REG_LOW_BAT,
    REG_IRQ_FLAGS_1,
    REG_IRQ_FLAGS_2,
    REG_DIO_MAPPING_1,
    REG_DIO_MAPPING_2,
    REG_VERSION,
    REG_AGC_REF,
    REG_AGC_THRESH_1,
    REG_AGC_THRESH_2,
    REG_AGC_THRESH_3,
    REG_TCXO,
    REG_PA_DAC,
    REG_PLL,
    REG_PLL_LOW_PN,
    REG_FORMER_TEMP,
    REG_BITRATE_FRAC
} sx1238_reg_addr_t;

/******************************************************************************
Public Variable Declarations
******************************************************************************/
union
{
    //uint8_t reg;
    struct  
    {   
        uint8_t fifo                                : 8;
    } bits;
} sx1238_reg_fifo;

union
{
    uint8_t reg;
    struct
    {
        uint8_t mode                                : 3;
        uint8_t modulation_shaping                  : 2;
        uint8_t modulation_type                     : 2;
        uint8_t unused                              : 1;
    } bits;
} sx1238_reg_op_mode;

union
{
    uint8_t reg;
    struct  
    {
        uint8_t bitrate                             : 8;
    } bits;
} sx1238_reg_bitrate_msb;

union
{
    uint8_t reg;
    struct
    {
        uint8_t bitrate                             : 8;
    } bits;
} sx1238_reg_bitrate_lsb;

union
{
    uint8_t reg;
    struct 
    {
        uint8_t fdev                                : 6;
        uint8_t unused                              : 2;
    } bits;
} sx1238_reg_fdev_msb;

union
{
    uint8_t reg;
    struct
    {
        uint8_t fdev                                : 8;
    } bits;
} sx1238_reg_fdev_lsb;

union
{
    uint8_t reg;
    struct
    {
        uint8_t frf                                 : 8;
    } bits;
} sx1238_reg_frf_msb;

union
{
    uint8_t reg;
    struct
    {
        uint8_t frf                                 : 8;
    } bits;
} sx1238_reg_frf_mid;

union
{
    uint8_t reg;
    struct
    {
        uint8_t frf                                 : 8;
    } bits;
} sx1238_reg_lsb;

union
{
    uint8_t reg;
    struct
    {
        uint8_t output_power                        : 4;
        uint8_t unused                              : 3;
        uint8_t pa_select                           : 1;
    } bits;
} sx1238_reg_pa_config;

union
{
    uint8_t reg;
    struct
    {
        uint8_t pa_ramp                             : 4;
        uint8_t low_pn_tx_pll_off                   : 1;
        uint8_t unused                              : 3;
    } bits;
} sx1238_reg_pa_ramp;

union
{
    uint8_t reg;
    struct
    {
        uint8_t ocp_trim                            : 5;
        uint8_t ocp_on                              : 1;
        uint8_t unused                              : 2;
    } bits;
} sx1238_reg_ocp;

union
{
    uint8_t reg;
    struct
    {
        uint8_t lna_boost                           : 2;
        uint8_t unused                              : 3;
        uint8_t lna_gain                            : 3;
    } bits;
} sx1238_reg_lna;

union
{
    uint8_t reg;
    struct
    {
        uint8_t start_demod_on_rssi                 : 1;
        uint8_t start_demod_on_preamble             : 1;
        uint8_t agc_on_preamble                     : 1;
        uint8_t agc_auto_on                         : 1;
        uint8_t afc_auto_on                         : 1;
        uint8_t restart_rx_with_pll_lock            : 1;
        uint8_t restart_rx_without_pll_lock         : 1;
        uint8_t restart_rx_on_collision             : 1;
    } bits;
} sx1238_reg_rx_config;

union
{
    uint8_t reg;
    struct
    {
        uint8_t rssi_smoothing                      : 3;
        uint8_t rssi_offset                         : 5;
    } bits;
} sx1238_reg_rssi_config;

union
{
    uint8_t reg;
    struct
    {
        uint8_t rssi_collision_threshold            : 8;
    } bits;
} sx1238_reg_rssi_collision;

union
{
    uint8_t reg;
    struct
    {
        uint8_t rssi_threshold                      : 8;
    } bits;
} sx1238_reg_rssi_threshold;

union
{
    uint8_t reg;
    struct
    {
        uint8_t rssi_value                          : 8;
    } bits;
} sx1238_reg_rssi_value;

union
{
    uint8_t reg;
    struct
    {
        uint8_t rx_bw_exp                           : 3;
        uint8_t rx_bw_mant                          : 2;
        uint8_t reserved                            : 2;
        uint8_t unused                              : 1;
    } bits;
} sx1238_reg_rx_bw;

union
{
    uint8_t reg;
    struct
    {
        uint8_t rx_bw_exp_afc                       : 3;
        uint8_t rx_bw_mant_afc                      : 2;
        uint8_t reserved                            : 3;
    } bits;
} sx1238_reg_afc_bw;

union
{
    uint8_t reg;
    struct
    {
        uint8_t ook_peak_thesh_step                 : 3;
        uint8_t ook_thresh_type                     : 2;
        uint8_t bit_sync_on                         : 1;
        uint8_t reserved                            : 2;
    } bits;
} sx1238_reg_ook_peak;

union
{
    uint8_t reg;
    struct
    {
        uint8_t ook_fixed_threshold                 : 8;
    } bits;
} sx1238_reg_ook_fix;

union
{
    uint8_t reg;
    struct
    {
        uint8_t ook_average_thresh_filt             : 2;
        uint8_t ook_average_offset                  : 2;
        uint8_t reserved                            : 1;
        uint8_t ook_peak_thresh_dec                 : 3;
    } bits;
} sx1238_reg_ook_avg;

union
{
    uint8_t reg;
    struct
    {
        uint8_t reserved                            : 8;
    } bits;
} sx1238_reg_reserved_17;

union
{
    uint8_t reg;
    struct
    {
        uint8_t reserved                            : 8;
    } bits;
} sx1238_reg_reserved_18;

union
{
    uint8_t reg;
    struct
    {
        uint8_t reserved                            : 8;
    } bits;
} sx1238_reg_reserved_19;

union
{
    uint8_t reg;
    struct
    {
        uint8_t afc_auto_clear_on                   : 1;
        uint8_t afc_clear                           : 1;
        uint8_t unused1                             : 1;
        uint8_t reserved                            : 1;
        uint8_t agc_start                           : 1;
        uint8_t unused2                             : 3;
    } bits;
} sx1238_reg_afc_fei;

union
{
    uint8_t reg;
    struct
    {
        uint8_t afc_value                           : 8;
    } bits;
} sx1238_reg_afc_msb;

union
{
    uint8_t reg;
    struct
    {
        uint8_t afc_value                           : 8;
    } bits;
} sx1238_reg_afc_lsb;

union
{
    uint8_t reg;
    struct
    {
        uint8_t fei_value                           : 8;
    } bits;
} sx1238_reg_fei_msb;

union
{
    uint8_t reg;
    struct
    {
        uint8_t fei_value                           : 8;        
    } bits;
} sx1238_reg_fei_lsb;

union
{
    uint8_t reg;
    struct
    {
        uint8_t preamble_detector_tol               : 5;
        uint8_t preamble_detector_size              : 2;
        uint8_t preamble_detector_on                : 1;
    } bits;
} sx1238_reg_preamble_detect;

union
{
    uint8_t reg;
    struct
    {
        uint8_t timeout_rx_rssi                     : 8;
    } bits;
} sx1238_reg_rx_timeout_1;

union
{
    uint8_t reg;
    struct
    {
        uint8_t timeout_rx_preamble                 : 8;
    } bits;
} sx1238_reg_rx_timeout_2;

union
{
    uint8_t reg;
    struct
    {
        uint8_t timeout_signal_sync                 : 8;
    } bits;
} sx1238_reg_rx_timeout_3;

union
{
    uint8_t reg;
    struct
    {
        uint8_t inter_packet_rx_delay               : 8;
    } bits;
} sx1238_reg_rx_delay;

union
{
    uint8_t reg;
    struct
    {
        uint8_t clk_out                             : 3;
        uint8_t rc_cal_start                        : 1;
        uint8_t unused                              : 4;
    } bits;
} sx1238_reg_osc;

union
{
    uint8_t reg;
    struct
    {
        uint8_t preamble_size                       : 8;
    } bits;
} sx1238_reg_preamble_msb;

union
{
    uint8_t reg;
    struct
    {
        uint8_t preamble_size                       : 8;
    } bits;
} sx1238_reg_preamble_lsb;

union
{
    uint8_t reg;
    struct
    {
        uint8_t sync_size                           : 3;
        uint8_t fifo_fill_condition                 : 1;
        uint8_t sync_on                             : 1;
        uint8_t preamble_polarity                   : 1;
        uint8_t auto_restart_rx_mode                : 2;
    } bits;
} sx1238_reg_sync_config;

union
{
    uint8_t reg;
    struct
    {
        uint8_t sync_value                          : 8;
    } bits;
} sx1238_reg_sync_value_1;

union
{
    uint8_t reg;
    struct
    {
        uint8_t sync_value                          : 8;        
    } bits;
} sx1238_reg_sync_value_2;

union
{
    uint8_t reg;
    struct
    {
        uint8_t sync_value                          : 8;        
    } bits;
} sx1238_reg_sync_value_3;

union
{
    uint8_t reg;
    struct
    {
        uint8_t sync_value                          : 8;        
    } bits;
} sx1238_reg_sync_value_4;

union
{
    uint8_t reg;
    struct
    {
        uint8_t sync_value                          : 8;        
    } bits;
} sx1238_reg_sync_value_5;

union
{
    uint8_t reg;
    struct
    {
        uint8_t sync_value                          : 8;                
    } bits;
} sx1238_reg_sync_value_6;

union
{
    uint8_t reg;
    struct
    {
        uint8_t sync_value                          : 8;
    } bits;
} sx1238_reg_sync_value_7;

union
{
    uint8_t reg;
    struct
    {
        uint8_t sync_value                          : 8;
    } bits;
} sx1238_reg_sync_value_8;

union
{
    uint8_t reg;
    struct
    {
        uint8_t crc_whitening_type                  : 1;
        uint8_t address_filtering                   : 2;
        uint8_t crc_auto_clear_off                  : 1;
        uint8_t crc_on                              : 1;
        uint8_t dc_free                             : 2;
        uint8_t packet_format                       : 1;
    } bits;
} sx1238_reg_packet_config_1;

union
{
    uint8_t reg;
    struct
    {
        uint8_t payload_length                      : 3;
        uint8_t beacon_on                           : 1;
        uint8_t io_home_power_frame                 : 1;
        uint8_t io_home_on                          : 1;
        uint8_t data_mode                           : 1;
        uint8_t unused                              : 1;
    } bits;
} sx1238_reg_packet_config_2;

union
{
    uint8_t reg;
    struct
    {
        uint8_t payload_length                      : 8;
    } bits;
} sx1238_reg_payload_length;

union
{
    uint8_t reg;
    struct
    {
        uint8_t node_address                        : 8;
    } bits;
} sx1238_reg_node_addrs;

union
{
    uint8_t reg;
    struct
    {
        uint8_t broadcast_address                   : 8;
    } bits;
} sx1238_reg_broadcast_addrs;

union
{
    uint8_t reg;
    struct
    {
        uint8_t fifo_threshold                      : 6;
        uint8_t unused                              : 1;
        uint8_t tx_start_condition                  : 1;
    } bits;
} sx1238_reg_fifo_thresh;

union
{
    uint8_t reg;
    struct
    {
        uint8_t sequencer_transition_from_transmit      : 1;
        uint8_t sequencer_transition_from_low_power     : 1;
        uint8_t sequencer_low_power_state               : 1;
        uint8_t sequencer_transition_from_idle          : 2;
        uint8_t sequencer_low_power_mode                : 1;
        uint8_t sequencer_stop                          : 1;
        uint8_t sequencer_start                         : 1;
    } bits;
} sx1238_reg_seq_config_1;

union
{
    uint8_t reg;
    struct
    {
        uint8_t sequencer_transition_from_packet_received   : 3;
        uint8_t sequencer_transition_from_rx_timeout        : 2;
        uint8_t sequencer_transition_from_receive           : 3;
    } bits;
} sx1238_reg_seq_config_2;

union
{
    uint8_t reg;
    struct
    {
        uint8_t timer_2_resolution                  : 2;
        uint8_t timer_1_resolution                  : 2;
        uint8_t unused                              : 4;
    } bits;
} sx1238_reg_timer_resol;

union
{
    uint8_t reg;
    struct
    {
        uint8_t timer_1_coefficient                 : 8;
    } bits;
} sx1238_reg_timer_1_coef;

union
{
    uint8_t reg;
    struct
    {
        uint8_t timer_2_coefficient                 : 8;        
    } bits;
} sx1238_reg_timer_2_coef;

union
{
    uint8_t reg;
    struct
    {
        uint8_t temp_monitor_off                    : 1;
        uint8_t temp_threshold                      : 2;
        uint8_t temp_change                         : 1;
        uint8_t unused                              : 1;
        uint8_t image_cal_running                   : 1;
        uint8_t image_cal_start                     : 1;
        uint8_t auto_image_cal_on                   : 1;
    } bits;
} sx1238_reg_image_cal;

union
{
    uint8_t reg;
    struct
    {
        uint8_t reg_temp                            : 8;
    } bits;
} sx1238_reg_temp;

union
{
    uint8_t reg;
    struct
    {
        uint8_t low_bat_trim                        : 3;
        uint8_t low_bat_on                          : 1;
        uint8_t unused                              : 4;
    } bits;
} sx1238_reg_low_bat;

union
{
    uint8_t reg;
    struct
    {
        uint8_t sync_address_match                  : 1;
        uint8_t preamble_detector_on                : 1;
        uint8_t timeout                             : 1;
        uint8_t rssi                                : 1;
        uint8_t pll_lock                            : 1;
        uint8_t tx_ready                            : 1;
        uint8_t rx_ready                            : 1;
        uint8_t mode_ready                          : 1;
    } bits;
} sx1238_reg_irq_flags_1;

union
{
    uint8_t reg;
    struct
    {
        uint8_t low_bat                             : 1;
        uint8_t crc_ok                              : 1;
        uint8_t payload_ready                       : 1;
        uint8_t packet_sent                         : 1;
        uint8_t fifo_overrun                        : 1;
        uint8_t fifo_level                          : 1;
        uint8_t fifo_empty                          : 1;
        uint8_t fifo_full                           : 1;
    } bits;
} sx1238_reg_irq_flags_2;

union
{
    uint8_t reg;
    struct
    {
        uint8_t dio3_mapping                        : 2;
        uint8_t dio2_mapping                        : 2;
        uint8_t dio1_mapping                        : 2;
        uint8_t dio0_mapping                        : 2;
    } bits;
} sx1238_reg_dio_mapping_1;

union
{
    uint8_t reg;
    struct
    {
        uint8_t map_preamble_detect                 : 1;
        uint8_t reserved                            : 3;
        uint8_t dio5_mapping                        : 2;
        uint8_t dio4_mapping                        : 2;
    } bits;
} sx1238_reg_dio_mapping_2;

union
{
    uint8_t reg;
    struct
    {
        uint8_t version                             : 8;
    } bits;
} sx1238_reg_version;

union
{
    uint8_t reg;
    struct
    {
        uint8_t agc_reference_level                 : 6;
        uint8_t unused                              : 2;
    } bits;
} sx1238_reg_agc_ref;

union
{
    uint8_t reg;
    struct
    {
        uint8_t agc_step_1                          : 5;
        uint8_t unused                              : 3;
    } bits;
} sx1238_reg_agc_thresh_1;

union
{
    uint8_t reg;
    struct
    {
        uint8_t agc_step_2                          : 4;
        uint8_t agc_step_3                          : 4;
    } bits;
} sx1238_reg_agc_thresh_2;

union
{
    uint8_t reg;
    struct
    {
        uint8_t agc_step_4                          : 4;
        uint8_t agc_step_5                          : 4;
    } bits;
} sx1238_reg_agc_thresh_3;

union
{
    uint8_t reg;
    struct
    {
        uint8_t reserved1                           : 4;
        uint8_t tcxo_input_on                       : 1;
        uint8_t reserved2                           : 3;
    } bits;
} sx1238_reg_tcxo;

union
{
    uint8_t reg;
    struct
    {
        uint8_t pa_dac                              : 3;
        uint8_t reserved                            : 5;
    } bits;
} sx1238_reg_pa_dac;

union
{
    uint8_t reg;
    struct
    {
        uint8_t reserved                            : 6;
        uint8_t pll_bandwidth                       : 2;
    } bits;
} sx1238_reg_pll;

union
{
    uint8_t reg;
    struct
    {
        uint8_t reserved                            : 6;
        uint8_t pll_bandwidth                       : 2;
    } bits;
} sx1238_reg_pll_low_pn;

union
{
    uint8_t reg;
    struct
    {
        uint8_t former_temp                         : 8;
    } bits;
} sx1238_reg_former_temp;

union
{
    uint8_t reg;
    struct
    {
        uint8_t bit_rate_frac                       : 4;
        uint8_t unused                              : 4;
    } bits;
} sx1238_reg_bitrate_frac;

/******************************************************************************
Public Function Declarations
******************************************************************************/

#endif // _SX1238_REG_H
