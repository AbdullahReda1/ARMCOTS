/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        28 MAY, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 MCAL
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         28 MAY, 2023      Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/


#ifndef MCAL_ADC_ADC_CONFIG_H
#define MCAL_ADC_ADC_CONFIG_H


/*
    OPTIONS:
    MADC_ON
    MADC_OFF
*/
#define MADC_ON_OFF             MADC_ON

/*
    OPTIONS:
    MADC_PCLK2_DIVIDED_BY_2
    MADC_PCLK2_DIVIDED_BY_4
    MADC_PCLK2_DIVIDED_BY_6
    MADC_PCLK2_DIVIDED_BY_8
*/
#define MADC_PRESCALER_CLK      MADC_PCLK2_DIVIDED_BY_2

/*
    OPTIONS:
    MADC_12_BIT_RESOLUTION
    MADC_10_BIT_RESOLUTION
    MADC_08_BIT_RESOLUTION
    MADC_06_BIT_RESOLUTION
*/
#define MADC_RESOLUTION         MADC_12_BIT_RESOLUTION

/*
    OPTIONS:
    MADC_RIGHT_ALIGNMENT
    MADC_LEFT_ALIGNMENT
*/
#define MADC_ALIGNMENT          MADC_RIGHT_ALIGNMENT

/*
    OPTIONS:
    MADC_ENABLE_INTERRUPT
    MADC_DISABLE_INTERRUPT
*/
#define MADC_INTERRUPT          MADC_ENABLE_INTERRUPT


#endif