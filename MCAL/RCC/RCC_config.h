/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        1 MAY, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 MCAL
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         1 MAY, 2023       Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/


#ifndef MCAL_RCC_RCC_CONFIG_H
#define MCAL_RCC_RCC_CONFIG_H


/*
    OPTIONS:
    HSI
    HSE
    PLL
*/
#define CPU_CLK_SOURCE        HSI

/*
    OPTIONS:
    AHB
    APB1
    APB2
*/
#define BUS_CLK        AHB

/*
    OPTIONS:
    TRIM_0
    TRIM_PLUS_40       |      TRIM_MINUS_40
    TRIM_PLUS_80       |      TRIM_MINUS_80
    TRIM_PLUS_120      |      TRIM_MINUS_120
    TRIM_PLUS_160      |      TRIM_MINUS_160
    TRIM_PLUS_200      |      TRIM_MINUS_200
    TRIM_PLUS_240      |      TRIM_MINUS_240
    TRIM_PLUS_280      |      TRIM_MINUS_280
    TRIM_PLUS_320      |      TRIM_MINUS_320
    TRIM_PLUS_360      |      TRIM_MINUS_360
    TRIM_PLUS_400      |      TRIM_MINUS_400
    TRIM_PLUS_440      |      TRIM_MINUS_440
    TRIM_PLUS_480      |      TRIM_MINUS_480
    TRIM_PLUS_520      |      TRIM_MINUS_520
    TRIM_PLUS_560      |      TRIM_MINUS_560
    TRIM_PLUS_600      |      TRIM_MINUS_600
*/
#define HSI_TRIM        TRIM_0

/*
    OPTIONS:
    HSI
    HSE
*/
#define PLL_PLLI2S_SOURCE            HSI

/*
    OPTIONS:
    INTERNAL_PLLI2S
    EXTERNAL_I2S_CKIN
*/
#define I2S_SOURCE            INTERNAL_PLLI2S

/*
    OPTIONS:
    2, ..., 63
*/
#define PLL_PLLI2S_PRE_VCO_PRESCALER_M         16

/*
    OPTIONS:
    PLLP_2
    PLLP_4
    PLLP_6
    PLLP_8
*/
#define PLL_OUTPUT_PRESCALER_P         PLLP_2

/*
    OPTIONS:
    2, ..., 7
*/
#define PLLI2S_OUTPUT_PRESCALER_R         2

/*
    OPTIONS:
    192, ..., 432
*/
#define PLL_VCO_MULTIPLICATION_FACTOR_N        192

/*
    OPTIONS:
    192, ..., 432
*/
#define PLLI2S_VCO_MULTIPLICATION_FACTOR_N        192

/*
    OPTIONS:
    2, ..., 15
*/
#define PLL_USB_OTG_FS_SDIO_PRESCALER_Q        4

/*
    OPTIONS:
    SYSCLOCK_DEVIDED_BY_1
    SYSCLOCK_DEVIDED_BY_2
    SYSCLOCK_DEVIDED_BY_4
    SYSCLOCK_DEVIDED_BY_8
    SYSCLOCK_DEVIDED_BY_16
    SYSCLOCK_DEVIDED_BY_64
    SYSCLOCK_DEVIDED_BY_128
    SYSCLOCK_DEVIDED_BY_256
    SYSCLOCK_DEVIDED_BY_512
*/
#define AHB_PRESCALER         SYSCLOCK_DEVIDED_BY_2

/*
    OPTIONS:
    AHB_DEVIDED_BY_1
    AHB_DEVIDED_BY_2
    AHB_DEVIDED_BY_4
    AHB_DEVIDED_BY_8
    AHB_DEVIDED_BY_16
*/
#define APB_1_PRESCALER       AHB_DEVIDED_BY_2

/*
    OPTIONS:
    AHB_DEVIDED_BY_1
    AHB_DEVIDED_BY_2
    AHB_DEVIDED_BY_4
    AHB_DEVIDED_BY_8
    AHB_DEVIDED_BY_16
*/
#define APB_2_PRESCALER       AHB_DEVIDED_BY_2

/*
    OPTIONS:
    CLOCK_SECURITY_SYSTEM_ENABLE
    CLOCK_SECURITY_SYSTEM_DISABLE
*/
#define CLOCK_SECURITY_SYSTEM        CLOCK_SECURITY_SYSTEM_DISABLE

/*
    OPTIONS:
    RTC_ENABLE
    RTC_DISABLE
*/
#define RTC_STATUS    RTC_DISABLE

/*
    OPTIONS:
    LSE
    LSI
    HSE
*/
#define RTC_CLOCK_SOURCE    LSI

/*
    OPTIONS:
    NO_CLK
    2, ..., 31
*/
#define RTC_CLOCK_BY_HSE_PRESCALER         NO_CLK

/*
    OPTIONS:
    MCO1_HSI
    MCO1_LSE
    MCO1_HSE
    MCO1_PLL
*/
#define MCO1_SOURCE    MCO1_HSI

/*
    OPTIONS:
    NO_DIVISION
    DIVISION_BY_2
    DIVISION_BY_3
    DIVISION_BY_4
    DIVISION_BY_5
*/
#define MCO1_PRESCALER    NO_DIVISION

/*
    OPTIONS:
    MCO2_SYSCLK
    MCO2_PLLI2S
    MCO2_HSE
    MCO2_PLL
*/
#define MCO2_SOURCE    MCO2_SYSCLK

/*
    OPTIONS:
    NO_DIVISION
    DIVISION_BY_2
    DIVISION_BY_3
    DIVISION_BY_4
    DIVISION_BY_5
*/
#define MCO2_PRESCALER    NO_DIVISION

/*
    OPTIONS:
    LSE
    LSI
*/
#define LOW_SPEED_CLK_SOURCE    LSE

/*
    OPTIONS:
    SPREAD_SPECTRUM_MUDULATION_ENABLE
    SPREAD_SPECTRUM_MUDULATION_DISABLE
*/
#define SPREAD_SPECTRUM_MUDULATION    SPREAD_SPECTRUM_MUDULATION_DISABLE

/*
    OPTIONS:
    CENTER_SPREAD_SPECTRUM_MUDULATION
    DOWN_SPREAD_SPECTRUM_MUDULATION
*/
#define SPREAD_SPECTRUM_TYPE    SPREAD_SPECTRUM_MUDULATION_DISABLE

/*
    OPTIONS:
    0, ..., 32768
*/
#define INCREMENTATION_STEP         0

/*
    OPTIONS:
    0, ..., 8192
*/
#define MODULATION_PERIOD         0

/*
    OPTIONS:
    TWICE
    FOUR_TIMES
*/
#define TIMERS_CLOCK_PRESCALER_SELECTION         TWICE


#endif