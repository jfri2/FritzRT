/*
 * gclk.c
 *
 * Created: 7/26/2017 10:59:49 PM
 *  Author: jfrit
 */ 

 #include "gclk.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
// Private Variables
///////////////////////////////////////////////////////////////////////////////////////////////////
 enum gclkGen
 {
    GCLKGEN0 = 0,
    GCLKGEN1,
    GCLKGEN2,
    GCLKGEN3,
    GCLKGEN4,
    GCLKGEN5,
    GCLKGEN6,
    GCLKGEN7,
    GCLKGEN8
 };

 enum something
 {
    GCLK_DFLL48M_REF = 0,
    GCLK_DPLL,
    GCLK_DPLL_32K,
    GCLK_WDT,
    GCLK_RTC,
    GCLK_EIC,
    GCLK_USB,
    GCLK_EVSYS_CHANNEL_0,
    GCLK_EVSYS_CHANNEL_1,
    GCLK_EVSYS_CHANNEL_2,
    GCLK_EVSYS_CHANNEL_3,
    GCLK_EVSYS_CHANNEL_4,
    GCLK_EVSYS_CHANNEL_5,
    GCLK_EVSYS_CHANNEL_6,
    GCLK_EVSYS_CHANNEL_7,
    GCLK_EVSYS_CHANNEL_8,
    GCLK_EVSYS_CHANNEL_9,
    GCLK_EVSYS_CHANNEL_10,
    GCLK_EVSYS_CHANNEL_11,
    GCLK_SERCOMX_SLOW,
    GCLK_SERCOM0_CORE,
    GCLK_SERCOM1_CORE,
    GCLK_SERCOM2_CORE,
    GCLK_SERCOM3_CORE,
    GCLK_SERCOM4_CORE,
    GCLK_SERCOM5_CORE,
    GCLK_TCC0_TCC1,
    GCLK_TCC2_TC3,
    GCLK_TC4_TC5,
    GCLK_TC6_TC7,
    GCLK_ADC,
    GCLK_AC_DIG,
    GCLK_AC_ANA = 0x21,
    GCLK_DAC = 0x23,
    GCLK_PTC,
    GCLK_I2S_0,
    GCLK_I2S_1
 };