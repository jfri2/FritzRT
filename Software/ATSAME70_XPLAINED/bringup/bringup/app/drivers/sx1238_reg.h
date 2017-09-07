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
#include <stdbool.h>

/******************************************************************************
Defines
******************************************************************************/

/******************************************************************************
Public Data Types
******************************************************************************/
typedef enum
{
    SX1238_REG_FIFO = 0x00,
    SX1238_REG_OP_MODE,
    SX1238_REG_BITRATE_MSB,
    SX1238_REG_BITRATE_LSB,
    SX1238_REG_FDEV_MSB,
    SX1238_REG_FDEV_LSB,
    SX1238_REG_FRF_MSB,
    SX1238_REG_FRF_MID,
    SX1238_REG_FRF_LSB,
    SX1238_REG_PA_CONFIG,
    SX1238_REG_OCP,
    SX1238_REG_LNA,
    SX1238_REG_RX_CONFIG,
    SX1238_REG_RSSI_CONFIG,
    SX1238_REG_RSSI_COLLISION,
    SX1238_REG_RSSI_THRESH,
    SX1238_REG_RSSI_VALUE,
    SX1238_REG_RX_BW,
    SX1238_REG_AFC_BW,
    SX1238_REG_OOK_PEAK,
    SX1238_REG_OOK_FIX,
    SX1238_REG_OOK_AVG,
    SX1238_REG_RESERVED_17,
    SX1238_REG_RESERVED_18,
    SX1238_REG_RESERVED_19,
    SX1238_REG_AFC_FEI,
    SX1238_REG_AFC_MSB,
    SX1238_REG_AFC_LSB,
    SX1238_REG_FEI_MSB,
    SX1238_REG_FEI_LSB,
    SX1238_REG_PREAMBLE_DETECT,
    SX1238_REG_RX_TIMEOUT_1,
    SX1238_REG_RX_TIMEOUT_2,
    SX1238_REG_RX_TIMEOUT_3,
    SX1238_REG_RX_DELAY,
    SX1238_REG_OSC,
    SX1238_REG_PREAMBLE_MSB,
    SX1238_REG_PREAMBLE_LSB,
    SX1238_REG_SYNC_CONFIG,
    SX1238_REG_SYNC_VALUE_1,
    SX1238_REG_SYNC_VALUE_2,
    SX1238_REG_SYNC_VALUE_3,
    SX1238_REG_SYNC_VALUE_4,
    SX1238_REG_SYNC_VALUE_5,
    SX1238_REG_SYNC_VALUE_6,
    SX1238_REG_SYNC_VALUE_7,
    SX1238_REG_SYNC_VALUE_8,
    SX1238_REG_PACKET_CONFIG_1,
    SX1238_REG_PACKET_CONFIG_2,
    SX1238_REG_PAYLOAD_LENGTH,
    SX1238_REG_NODE_ADRS,
    SX1238_REG_BROADCAST_ADRS,
    SX1238_REG_FIFO_THRESH,
    SX1238_REG_SEQ_CONFIG_1,
    SX1238_REG_SEQ_CONFIG_2,
    SX1238_REG_TIMER_RESOL,
    SX1238_REG_TIMER1_COEF,
    SX1238_REG_TIMER2_COEF,
    SX1238_REG_IMAGE_CAL,
    SX1238_REG_TEMP,
    SX1238_REG_LOW_BAT,
    SX1238_REG_IRQ_FLAGS_1,
    SX1238_REG_IRQ_FLAGS_2,
    SX1238_REG_DIO_MAPPING_1,
    SX1238_REG_DIO_MAPPING_2,
    SX1238_REG_VERSION,
    SX1238_REG_AGC_REF,
    SX1238_REG_AGC_THRESH_1,
    SX1238_REG_AGC_THRESH_2,
    SX1238_REG_AGC_THRESH_3,
    SX1238_REG_TCXO,
    SX1238_REG_PA_DAC,
    SX1238_REG_PLL,
    SX1238_REG_PLL_LOW_PN,
    SX1238_REG_FORMER_TEMP,
    SX1238_REG_BITRATE_FRAC
} sx1238_reg_addr_t;

typedef enum
{
    SX1238_SLEEP = 0x00,
    SX1238_STDBY,
    SX1238_FS_MODE_TX,
    SX1238_TX,
    SX1238_FS_MODE_RX,
    SX1238_RX
} sx1238_mode_t;

typedef enum 
{
    SX1238_NO_SHAPING = 0x00,
    SX1238_GAUS1_BTRATE,
    SX1238_GAUS05_2BITRATE,
    SX1238_GAUS03
} sx1238_modulation_shaping_t;

typedef enum
{
    SX1238_FSK = 0x00,
    SX1238_OOK
} sx1238_modulation_type_t;

typedef enum
{
    SX1238_MS_3_4,
    SX1238_MS_2,
    SX1238_MS_1,
    SX1238_US_500,
    SX1238_US_250,
    SX1238_US_125,
    SX1238_US_100,
    SX1238_US_62,
    SX1238_US_50,
    SX1238_US_40,
    SX1238_US_31,
    SX1238_US_25,
    SX1238_US_15,
    SX1238_US_12,
    SX1238_US_10
} sx1238_pa_ramp_t;

typedef enum
{
    SX1238_SAMPLES_2 = 0x00,
    SX1238_SAMPLES_4,
    SX1238_SAMPLES_8,
    SX1238_SAMPLES_16,
    SX1238_SAMPLES_32,
    SX1238_SAMPLES_64,
    SX1238_SAMPLES_128,
    SX1238_SAMPLES_256,
} sx1238_rssi_smoothing_t;

typedef enum
{
    SX1238_BW_MANT_16 = 0x00,
    SX1238_BW_MANT_20,
    SX1238_BW_MANT_24
} sx1238_rx_bw_mant_t;

typedef enum
{
    SX1238_1_PER_CHIP = 0x00,
    SX1238_1_PER_2_CHIP,
    SX1238_1_PER_4_CHIP,
    SX1238_1_PER_8_CHIP,
    SX1238_2_PER_1_CHIP,
    SX1238_4_PER_1_CHIP,
    SX1238_8_PER_1_CHIP,
    SX1238_16_PER_1_CHIP
} sx1238_ook_peak_thresh_step_t;

typedef enum
{
    SX1238_THRESH_FIXED = 0x00,
    SX1238_THRESH_PEAK,
    SX1238_THRESH_AVG
} sx1238_ook_thresh_type_t;

typedef enum
{
    TODO1
} sx1238_ook_avg_thresh_filt_t;

typedef enum
{
    TODO2
} sx1238_ook_avg_offset_t;

typedef enum
{
    TODO3
} sx1238_ook_peak_thresh_dec_t;

typedef enum
{
    TODO4
} sx1238_preamble_detector_size_t;

typedef enum
{
    TODO5
} sx1238_clk_out_t;

typedef enum
{
    TODO6
} sx1238_auto_restart_rx_t;

typedef enum
{
    TODO7
} sx1238_addr_filt_t;

typedef enum
{
    TODO8
} sx1238_dc_free_t;

typedef enum
{
    TODO9
} sx1238_seq_from_packet_rxd_t;

typedef enum
{
    TODOtodo
} sx1238_seq_from_rx_timeout_t;

typedef enum
{
    TODO10
} sx1238_seq_from_rx_t;

typedef enum
{
    TODO11
} sx1238_timer_2_res_t;

typedef enum
{
    TODO12
} sx1238_timer_1_res_t;

typedef enum
{
    TODO13
} sx1238_temp_threshold_t;

typedef enum
{
    TODO14
} sx1238_low_bat_trim_t;

typedef enum
{
    TODO15
} sx1238_pll_bandwidth_t;

typedef enum
{
    TODO16
} sx1238_pn_pll_bandwidth_t;

/******************************************************************************
Public Variable Declarations
******************************************************************************/
union
{
    uint8_t byte;
    struct
    {
        uint8_t fifo                            : 8;    // FIFO data input/output
    } bits;
} sx1238_reg_fifo;

union
{
    uint8_t byte;
    struct
    {
        sx1238_mode_t mode                              : 3;    // Transceiver Mode selection
        sx1238_modulation_shaping_t modulation_shaping  : 2;    // Data shaping
        sx1238_modulation_type_t modulation_type        : 2;    // Modulation scheme
        bool unused                                     : 1;
    } bits;
} sx1238_reg_op_mode;

union
{
    uint8_t byte;
    struct  
    {
        uint8_t bitrate                             : 8;    // MSB of bitrate. BitRate = FXOSC / (BitRate[15..0] + (BitrateFrac / 16))
    } bits;
} sx1238_reg_bitrate_msb;

union
{
    uint8_t byte;
    struct
    {
        uint8_t bitrate                             : 8;    // LSB of bitrate (chip rate w/Manchester Encoding)
    } bits;
} sx1238_reg_bitrate_lsb;

union
{
    uint8_t byte;
    struct 
    {
        uint8_t fdev                                : 6;    // MSB of frequency deviation. Fdev = Fstep * Fdev[15..0]. Default value is 5 kHz
        uint8_t unused                              : 2;
    } bits;
} sx1238_reg_fdev_msb;

union
{
    uint8_t byte;
    struct
    {
        uint8_t fdev                                : 8;    // LSB of frequency deviation
    } bits;
} sx1238_reg_fdev_lsb;

union
{
    uint8_t byte;
    struct
    {
        uint8_t frf                                 : 8;    // MSB of RF Carrier Frequency. Frf = Fstep * Frf[23..0]. Default value is 915.000 MHz. Only changed when going into/out of FSRX/FSTX or restarting the receiver
    } bits;
} sx1238_reg_frf_msb;

union
{
    uint8_t byte;
    struct
    {
        uint8_t frf                                 : 8;    // MDB of RF Carrier Frequency
    } bits;
} sx1238_reg_frf_mid;

union
{
    uint8_t byte;
    struct
    {
        uint8_t frf                                 : 8;    // LSB of RF Carrier Frequency
    } bits;
} sx1238_reg_frf_lsb;

union
{
    uint8_t byte;
    struct
    {
        uint8_t output_power                        : 4;    // Output power setting in 1 dB steps. Pout (ANT) = 20 + OutputPower (dBm). Pout (RFO) = -1 + OutputPower (dBm)
        uint8_t unused                              : 3;
        bool pa_select                              : 1;    // 0 = RFO pin, 1 = Undefined
    } bits;
} sx1238_reg_pa_config;

union
{
    uint8_t byte;
    struct
    {
        sx1238_pa_ramp_t pa_ramp                    : 4;    // Rise/Fall time of ramp up / down in FSK
        bool low_pn_tx_pll_off                      : 1;    // 0 = Low Phase Noise PLL, 1 = Standard PLL
        uint8_t unused                              : 3;
    } bits;
} sx1238_reg_pa_ramp;

union
{
    uint8_t byte;
    struct
    {
        uint8_t ocp_trim                            : 5;    // Trimming of OCP current. Default 100 mA
        bool ocp_on                                 : 1;    // Enables overload current protection for the PA
        uint8_t unused                              : 2;
    } bits;
} sx1238_reg_ocp;

union
{
    uint8_t byte;
    struct
    {
        uint8_t lna_boost                           : 2;    // Improves system Noise Figure at expense of Rx current consumption
        uint8_t unused                              : 3;
        uint8_t lna_gain                            : 3;    // LNA Gain Setting. Reading this returns actual current LNA gain
    } bits;
} sx1238_reg_lna;

union
{
    uint8_t byte;
    struct
    {
        bool start_demod_on_rssi                 : 1;   // Condition required for the circuit to provide valid data to the baseband
        bool start_demod_on_preamble             : 1;   // Condition required for the circuit to provide valid data to the baseband
        bool agc_on_preamble                     : 1;   // 0 = AGC adjusts LNA gain based on RSSI, 1 = AGC adjusts LNA gain until preamble is detected, and fix LNA gain only when Preamble is detected (PreambleDetectSize)
        bool agc_auto_on                         : 1;   // 0 = LNA gain forced by LnaGain setting, 1 = LNA gain controlled by AGC
        bool afc_auto_on                         : 1;   // 1 = AFC is performed at each receiver startup 
        bool restart_rx_with_pll_lock            : 1;   // Triggers a manual restart of the rece3iver chain when set to 1. Use this bit when there is a freq change requireing some time for the PLL to re-lock
        bool restart_rx_without_pll_lock         : 1;   // Triggers a manual restart of the receiver chain when set to 1. Use this bit when there is no freq change. RestartRxWithPllLock otherwise
        bool restart_rx_on_collision             : 1;   // Turns on mechanism restarting the receiver automatically if it gets saturated or packet collision is detected. (1 = auto restart on)
    } bits;
} sx1238_reg_rx_config;

union
{
    uint8_t byte;
    struct
    {
        sx1238_rssi_smoothing_t rssi_smoothing              : 3;    // Defines number of samples taken to average RSSI result
        int8_t rssi_offset                          : 5;    // Signed RSSI offset to compensate for the possible losses/gains from the front end. 1 dB / LSB. 2's complement in dB
    } bits;
} sx1238_reg_rssi_config;

union
{
    uint8_t byte;
    struct
    {
        uint8_t rssi_collision_threshold            : 8;    // Sets the threshold used to consider that an interferer is detected, witnessing a packet collision. 1dB/LSB. Default 10 dB (0x0A).
    } bits;
} sx1238_reg_rssi_collision;

union
{
    uint8_t byte;
    struct
    {
        uint8_t rssi_threshold                      : 8;    // Rssi trigger level for Rssi interrupt: -RssiThreshold / 2 (dBm)
    } bits;
} sx1238_reg_rssi_threshold;

union
{
    uint8_t byte;
    struct
    {
        uint8_t rssi_value                          : 8;    // Absolute value of RSSI in dBm. 0.5 dB steps. RSSI = - RssiValue / 2
    } bits;
} sx1238_reg_rssi_value;

union
{
    uint8_t byte;
    struct
    {
        uint8_t rx_bw_exp                : 3;    // Channel filter bandwidth control: RxBw = (FXOSC) / (RxBwMant * (2 ^ (RxBwExp + 2))
        sx1238_rx_bw_mant_t rx_bw_mant          : 2;    // Channel Filter bandwidth control. 16, 20, or 24
        uint8_t reserved                 : 2;
        bool unused                      : 1;
    } bits;
} sx1238_reg_rx_bw;

union
{
    uint8_t byte;
    struct
    {
        uint8_t rx_bw_exp_afc                       : 3;    // RxBwExpAfc parameter used during the AFC
        uint8_t rx_bw_mant_afc                      : 2;    // RxBwMantAfc parameter used during the AFC
        uint8_t reserved                            : 3;
    } bits;
} sx1238_reg_afc_bw;

union
{
    uint8_t byte;
    struct
    {
        sx1238_ook_peak_thresh_step_t ook_peak_thesh_step   : 3;    // Size of each decrement of RSSI threshold in OOK demodulator
        sx1238_ook_thresh_type_t ook_thresh_type            : 2;    // Selects type of threshold in the OOK data slicer
        bool bit_sync_on                                    : 1;    // Enables the Bit Synchronizer (not possible in Packet Mode)
        uint8_t reserved                                    : 2;
    } bits;
} sx1238_reg_ook_peak;

union
{
    uint8_t byte;
    struct
    {
        uint8_t ook_fixed_threshold                 : 8;    // Fixed threshold for the Data Slicer in OOK mode. Floor threshold for the Data Slicer in OOK w/Peak Mode
    } bits;
} sx1238_reg_ook_fix;

union
{
    uint8_t byte;
    struct
    {
        sx1238_ook_avg_thresh_filt_t ook_average_thresh_filt   : 2;    // Filter coefficients in average mode of hte OOK demodulator
        sx1238_ook_avg_offset_t ook_average_offset             : 2;    // Static offset added to threshold in average mode in order to reduce glitching activity
        bool reserved                                   : 1;    
        sx1238_ook_peak_thresh_dec_t ook_peak_thresh_dec       : 3;    // Period of decrement of the RSSI threshold in the OOK demodulator
    } bits;
} sx1238_reg_ook_avg;

union
{
    uint8_t byte;
    struct
    {
        uint8_t reserved                            : 8;
    } bits;
} sx1238_reg_reserved_17;

union
{
    uint8_t byte;
    struct
    {
        uint8_t reserved                            : 8;
    } bits;
} sx1238_reg_reserved_18;

union
{
    uint8_t byte;
    struct
    {
        uint8_t reserved                            : 8;    
    } bits;
} sx1238_reg_reserved_19;

union
{
    uint8_t byte;
    struct
    {
        bool afc_auto_clear_on                      : 1;    // Only valid if AfcAutoOn is set. 0 = AFC register not cleared at beginning of auto AFC phase, 1 = AFC register cleared at beginning of auto AFC phase
        bool afc_clear                              : 1;    // Clears AFC register set in Rx Mode. Always reads 0
        bool unused1                                : 1;
        bool reserved                               : 1;
        bool agc_start                              : 1;    // Triggers an AGC sequence when set to 1
        uint8_t unused2                             : 3;
    } bits;
} sx1238_reg_afc_fei;

union
{
    uint8_t byte;
    struct
    {
        uint8_t afc_value                           : 8;    // MSB of AFC Value, 2's complement
    } bits;
} sx1238_reg_afc_msb;

union
{
    uint8_t byte;
    struct
    {
        uint8_t afc_value                           : 8;    // LSB of AFC Value, 2's complement
    } bits;
} sx1238_reg_afc_lsb;

union
{
    uint8_t byte;
    struct
    {
        uint8_t fei_value                           : 8;    // MSB of measured frequency offset. 2's complement
    } bits;
} sx1238_reg_fei_msb;

union
{
    uint8_t byte;
    struct
    {
        uint8_t fei_value                           : 8;    // LSB of measured frequency offset. 2's complement
    } bits;
} sx1238_reg_fei_lsb;

union
{
    uint8_t byte;
    struct
    {
        uint8_t preamble_detector_tol                   : 5;    // Number or chip errors tolerated over PreambleDetectorSize. 4 Chips per bit
        sx1238_preamble_detector_size_t preamble_detector_size : 2;    // Number of Preamble bytes to detect to trigger an interrupt
        bool preamble_detector_on                       : 1;    // Enables preamble detector when set to 1. AGC settings supersede this bit during startup / AGC phase
    } bits;
} sx1238_reg_preamble_detect;

union
{
    uint8_t byte;
    struct
    {
        uint8_t timeout_rx_rssi                     : 8;    // Timeout interrupt is generated TimeoutRxRssi * 16 * Tbit after switching to Rx mode if RSSI interrupt doesn't occur. 0x00 disabled
    } bits;
} sx1238_reg_rx_timeout_1;

union
{
    uint8_t byte;
    struct
    {
        uint8_t timeout_rx_preamble                 : 8;    // Timeout interrupt is generated TimeoutRxPreamble * 16 * Tbit after switching to Rx Mode if Preamble interrupt doesn't occur. 0x00 disabled
    } bits;
} sx1238_reg_rx_timeout_2;

union
{
    uint8_t byte;
    struct
    {
        uint8_t timeout_signal_sync                 : 8;    // Timeout interrupt is generated TimeoutSignalSync * 16 * Tbit after Rx Mode is programmed if SyncAddress doesn't occur. 0x00 disabled
    } bits;
} sx1238_reg_rx_timeout_3;

union
{
    uint8_t byte;
    struct
    {
        uint8_t inter_packet_rx_delay               : 8;    // Additional delay before an auto receiver restart is launched. Delay = InterPacketRxDelay * 4 * Tbit
    } bits;
} sx1238_reg_rx_delay;

union
{
    uint8_t byte;
    struct
    {
        sx1238_clk_out_t clk_out                           : 3;    // Selects CLKOUT frequency
        bool rc_cal_start                           : 1;    // Triggers calibration of RC Oscillator when set. Always reads 0. RC Cal must be triggered in standby
        uint8_t unused                              : 4;
    } bits;
} sx1238_reg_osc;

union
{
    uint8_t byte;
    struct
    {
        uint8_t preamble_size                       : 8;    // Size of preamble to be sent (MSB)
    } bits;
} sx1238_reg_preamble_msb;

union
{
    uint8_t byte;
    struct
    {
        uint8_t preamble_size                       : 8;    // Size of preamble to be sent (LSB)
    } bits;
} sx1238_reg_preamble_lsb;

union
{
    uint8_t byte;
    struct
    {
        uint8_t sync_size                           : 3;    // Size of sync word: (SyncSize + 1) bytes, (SyncSize) bytes if ioHomeOn = 1
        bool fifo_fill_condition                    : 1;    // 0 = if SyncAddress interrupt occurs, 1 = as long as FifoFillCondition is set
        bool sync_on                                : 1;    // Enables Sync word generation & detection
        bool preamble_polarity                      : 1;    // 0 = 0xAA, 1 = 0x55
        sx1238_auto_restart_rx_t auto_restart_rx_mode      : 2;    // Controls auto restart of receiver after rx of a valid packet
    } bits;
} sx1238_reg_sync_config;

union
{
    uint8_t byte;
    struct
    {
        uint8_t sync_value                          : 8;    // 1st Byte of Sync Word
    } bits;
} sx1238_reg_sync_value_1;

union
{
    uint8_t byte;
    struct
    {
        uint8_t sync_value                          : 8;    // 2nd Byte of Sync Word        
    } bits;
} sx1238_reg_sync_value_2;

union
{
    uint8_t byte;
    struct
    {
        uint8_t sync_value                          : 8;    // 3rd Byte of Sync Word        
    } bits;
} sx1238_reg_sync_value_3;

union
{
    uint8_t byte;
    struct
    {
        uint8_t sync_value                          : 8;    // 4th Byte of Sync Word        
    } bits;
} sx1238_reg_sync_value_4;

union
{
    uint8_t byte;
    struct
    {
        uint8_t sync_value                          : 8;    // 5th Byte of Sync Word        
    } bits;
} sx1238_reg_sync_value_5;

union
{
    uint8_t byte;
    struct
    {
        uint8_t sync_value                          : 8;    // 6th Byte of Sync Word                
    } bits;
} sx1238_reg_sync_value_6;

union
{
    uint8_t byte;
    struct
    {
        uint8_t sync_value                          : 8;    // 7th Byte of Sync Word
    } bits;
} sx1238_reg_sync_value_7;

union
{
    uint8_t byte;
    struct
    {
        uint8_t sync_value                          : 8;    // 8th Byte of Sync Word
    } bits;
} sx1238_reg_sync_value_8;

union
{
    uint8_t byte;
    struct
    {
        bool crc_whitening_type                     : 1;    // 0 = CCITT CRC w/Standard Whitening, 1 = IBM CRC w/Alternate Whitening
        sx1238_addr_filt_t address_filtering               : 2;    // Defines addressed based filter in Rx
        bool crc_auto_clear_off                     : 1;    // Clear FIFO and restart new packet retention, no PayloadReady interrupt issued. FIFO not cleared, PayloadReady interrupt issued. 
        bool crc_on                                 : 1;    // Enables CRC calculations/check (Tx & Rx)
        sx1238_dc_free_t dc_free                           : 2;    // Defines DC-free encoding/decoding
        bool packet_format                          : 1;    // 0 = Fixed Length, 1 = Variable Length
    } bits;
} sx1238_reg_packet_config_1;

union
{
    uint8_t byte;
    struct
    {
        uint8_t payload_length                      : 3;    // Packet Length Most Significant Bits [10..8]
        bool beacon_on                              : 1;    // Enables beacon mode in Fixed packet format
        bool io_home_power_frame                    : 1;    // Reserved
        bool io_home_on                             : 1;    // Enables the ioHomeControl compatibility mode, 0 = Disabled, 1 = ioHome enables
        bool data_mode                              : 1;    // Data processing mode. 0 = Continuous mode, 1 = Packet mode
        bool unused                                 : 1;
    } bits;
} sx1238_reg_packet_config_2;

union
{
    uint8_t byte;
    struct
    {
        uint8_t payload_length                      : 8;    // If PacketFormat = 0 (fixed), payload length [8..0] . Else (variable) Max length in Rx, not used in Tx
    } bits;
} sx1238_reg_payload_length;

union
{
    uint8_t byte;
    struct
    {
        uint8_t node_address                        : 8;    // Node Address used in Address Filtering
    } bits;
} sx1238_reg_node_addrs;

union
{
    uint8_t byte;
    struct
    {
        uint8_t broadcast_address                   : 8;    // Broadcast Address used in Address Filtering
    } bits;
} sx1238_reg_broadcast_addrs;

union
{
    uint8_t byte;
    struct
    {
        uint8_t fifo_threshold                      : 6;    // Used to trigger FifoLevel interrupt when number of bytes in FIFO > FifoThreshold
        bool unused                                 : 1;
        bool tx_start_condition                     : 1;    // 0 = FifoLevel exceeds FifoThreshold, 1 = FifoEmpty goes low (at least one byte in FIFO)
    } bits;
} sx1238_reg_fifo_thresh;

union
{
    uint8_t byte;
    struct
    {
        bool sequencer_transition_from_transmit         : 1;    // 0 = to Rx state on PacketSent interrupt, 1 = to LowPower or Idle state on PacketSent interrupt depending on SequencerLowPowerState
        bool sequencer_transition_from_low_power        : 1;    // 0 = to Rx state on a Timer 1 interrupt, 1 = to Tx state on Timer 1 interrupt
        bool sequencer_low_power_state                  : 1;    // 0 = to Low Power state, 1 = to Idle state
        uint8_t sequencer_transition_from_idle          : 2;    // Controls state-machine transition from Idle state
        bool sequencer_low_power_mode                   : 1;    // 0 = Stdby Mode, 1 = Sleep Mode.
        bool sequencer_stop                             : 1;    // 1 = Forces sequencer to go to idle state. Always reads 0
        bool sequencer_start                            : 1;    // Controls top level sequencer. When set to 1 executes the "Start" transition
    } bits;
} sx1238_reg_seq_config_1;

union
{
    uint8_t byte;
    struct
    {
        sx1238_seq_from_packet_rxd_t sequencer_transition_from_packet_received     : 3;    // Controles Sequecer transition from Rx state
        sx1238_seq_from_rx_timeout_t sequencer_transition_from_rx_timeout          : 2;    // Controls state machine transition from Rx state on Rx Timeout interrupt
        sx1238_seq_from_rx_t sequencer_transition_from_receive                     : 3;    // Controls state machine transition from PacketReceivedState
    } bits;
} sx1238_reg_seq_config_2;

union
{
    uint8_t byte;
    struct
    {
        sx1238_timer_2_res_t timer_2_resolution            : 2;    // Resolution of Timer 2
        sx1238_timer_1_res_t timer_1_resolution            : 2;    // Resolution of Timer 1
        uint8_t unused                              : 4;
    } bits;
} sx1238_reg_timer_resol;

union
{
    uint8_t byte;
    struct
    {
        uint8_t timer_1_coefficient                 : 8;    // Multiplying coefficient for Timer 1
    } bits;
} sx1238_reg_timer_1_coef;

union
{
    uint8_t byte;
    struct
    {
        uint8_t timer_2_coefficient                 : 8;    // Multiplying coefficient for Timer 2
    } bits;
} sx1238_reg_timer_2_coef;

union
{
    uint8_t byte;
    struct
    {
        bool temp_monitor_off                       : 1;    // 0 = Temp monitoring done in all modes but sleep and standby, 1 = Temp monitoring stopped
        sx1238_temp_threshold_t temp_threshold             : 2;    // Sets temperature change threshold to trigger new IQ cal (degC)
        bool temp_change                            : 1;    // IRQ flag witnessing a temp change exceeding temp threshold since last Image & RSSI cal. 0 = No change, 1 = Change over threshold
        bool unused                                 : 1;
        bool image_cal_running                      : 1;    // Set to 1 while IQ & RSSI cal is running, cleared when complete
        bool image_cal_start                        : 1;    // Triggers the IQ and RSSI cal when set
        bool auto_image_cal_on                      : 1;    // Controls image cal mechanism. 0 = Cal of Receiver depending on temp is disabled, 1 = Cal of Receiver depending on temp is enabled
    } bits;
} sx1238_reg_image_cal;

union
{
    uint8_t byte;
    struct
    {
        int8_t reg_temp                             : 8;    // Measured temperature, -1 degC per LSB
    } bits;
} sx1238_reg_temp;

union
{
    uint8_t byte;
    struct
    {
        sx1238_low_bat_trim_t low_bat_trim                 : 3;    // Trimming of Low Battery threshold
        bool low_bat_on                             : 1;    // Low battery detector enable/disable signal
        uint8_t unused                              : 4;
    } bits;
} sx1238_reg_low_bat;

union
{
    uint8_t byte;
    struct
    {
        bool sync_address_match                  : 1;   // Set when Sync and Addr are detected. Cleared when leaving Rx or FIFO is emptied. RW in Packet mode, RWC in Continuous mode
        bool preamble_detector_on                : 1;   // Set when Preamble Detector has found valid Preamble, cleared when set to 1.
        bool timeout                             : 1;   // Set when a timeout occurs, cleared when leaving Rx or FIFO is emptied
        bool rssi                                : 1;   // Set in Rx when the RssiValue exceeds RssiThreshold. Cleared when leaving Rx or setting this bit to 1
        bool pll_lock                            : 1;   // Set when PLL is locked. Cleared when it is not
        bool tx_ready                            : 1;   // Set in Tx Mode after PA rampup. Cleared when leaving Tx
        bool rx_ready                            : 1;   // Set in Rx Mode, after RSSI, AGC, and AFC
        bool mode_ready                          : 1;   // Set when operation mode requested in Mode is ready. Sleep: Entering sleep, Standby: XO is running, FS: PLL locked, Rx: RSSI sampling starts, Tx: PA ramp-up completed. Cleared when changing modes
    } bits;
} sx1238_reg_irq_flags_1;

union
{
    uint8_t byte;
    struct
    {
        bool low_bat                             : 1;   // Set when battery voltage drops below low battery threshold, cleared when set to 1
        bool crc_ok                              : 1;   // Set in Rx when CRC of payload is OK. Cleared when FIFO is empty
        bool payload_ready                       : 1;   // Set in Rx when payload is ready (last byte Rx'd in packet mode + CRC is good). Cleared when FIFO is empty
        bool packet_sent                         : 1;   // Set in Tx when complete packet has been sent. Cleared when exiting Tx
        bool fifo_overrun                        : 1;   // Set when FIFO overrun occurs (except in sleep mode). Flags and FIFO are cleared when this bit is set. FIFO then becomes available for next Tx/Rx
        bool fifo_level                          : 1;   // Set when number of bytes in FIFO exceeds FifoThreshold, Else cleared
        bool fifo_empty                          : 1;   // Set when FIFO empty, cleared when there's at least 1 byte in FIFO
        bool fifo_full                           : 1;   // Set when FIFO is full, else cleared
    } bits;
} sx1238_reg_irq_flags_2;

union
{
    uint8_t byte;
    struct
    {
        uint8_t dio3_mapping                        : 2;    // See tables 24 and 25 for mapping in datasheet
        uint8_t dio2_mapping                        : 2;    // See tables 24 and 25 for mapping in datasheet
        uint8_t dio1_mapping                        : 2;    // See tables 24 and 25 for mapping in datasheet
        uint8_t dio0_mapping                        : 2;    // See tables 24 and 25 for mapping in datasheet
    } bits;
} sx1238_reg_dio_mapping_1;

union
{
    uint8_t byte;
    struct
    {
        uint8_t map_preamble_detect                 : 1;    // See tables 24 and 25 for mapping in datasheet. 0 = RSSI interrupt, 1 = PreambleDetect interrupt
        uint8_t reserved                            : 3;
        uint8_t dio5_mapping                        : 2;    // See tables 24 and 25 for mapping in datasheet
        uint8_t dio4_mapping                        : 2;    // See tables 24 and 25 for mapping in datasheet
    } bits;
} sx1238_reg_dio_mapping_2;

union
{
    uint8_t byte;
    struct
    {
        uint8_t version                             : 8;    // Default 0x21, version[7..4] = Fill rev number, version[3..0] = metal mask revision number
    } bits;
} sx1238_reg_version;

union
{
    uint8_t byte;
    struct
    {
        uint8_t agc_reference_level                 : 6;    // Sets the floor reference for all AGC thresholds
        uint8_t unused                              : 2;
    } bits;
} sx1238_reg_agc_ref;

union
{
    uint8_t byte;
    struct
    {
        uint8_t agc_step_1                          : 5;    // AGC Step 1 Threshold
        uint8_t unused                              : 3;
    } bits;
} sx1238_reg_agc_thresh_1;

union
{
    uint8_t byte;
    struct
    {
        uint8_t agc_step_2                          : 4;    // AGC Step 2 Threshold
        uint8_t agc_step_3                          : 4;    // AGC Step 3 Threshold
    } bits;
} sx1238_reg_agc_thresh_2;

union
{
    uint8_t byte;
    struct
    {
        uint8_t agc_step_4                          : 4;    // AGC Step 4 Threshold
        uint8_t agc_step_5                          : 4;    // AGC Step 5 Threshold
    } bits;
} sx1238_reg_agc_thresh_3;

union
{
    uint8_t byte;
    struct
    {
        uint8_t reserved1                           : 4;
        bool tcxo_input_on                          : 1;    // 0 = Crystal Oscillator with External Crystal, 1 = External Clipped Sine TCXO, AC coupled to XTA pin
        uint8_t reserved2                           : 3;
    } bits;
} sx1238_reg_tcxo;

union
{
    uint8_t byte;
    struct
    {
        uint8_t pa_dac                              : 3;    // 0x04, default value
        uint8_t reserved                            : 5;
    } bits;
} sx1238_reg_pa_dac;

union
{
    uint8_t byte;
    struct
    {
        uint8_t reserved                        : 6;
        sx1238_pll_bandwidth_t pll_bandwidth    : 2;    // Controls Standard PLL bandwidth
    } bits;
} sx1238_reg_pll;

union
{
    uint8_t byte;
    struct
    {
        uint8_t reserved                            : 6;
        sx1238_pn_pll_bandwidth_t pll_bandwidth     : 2;    // Controls Low Phase Noise PLL bandwidth
    } bits;
} sx1238_reg_pll_low_pn;

union
{
    uint8_t byte;
    struct
    {
        int8_t former_temp                          : 8;    // Temp saved during latest IQ (RSSI & Image) Calibration. -1 degC per LSB 
    } bits;
} sx1238_reg_former_temp;

union
{
    uint8_t byte;
    struct
    {
        uint8_t bit_rate_frac                       : 4;    // Fractional part of bit rate divider (FSK only). If BitRateFrac > 0: BitRate = FXOSC / (Bitrate[15..0] + (BitrateFrace / 16))
        uint8_t unused                              : 4;
    } bits;
} sx1238_reg_bitrate_frac;

/******************************************************************************
Public Function Declarations
******************************************************************************/

#endif // _SX1238_REG_H
