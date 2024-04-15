/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        8 MAY, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 MCAL
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         8 MAY, 2023       Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/


#ifndef MCAL_STK_STK_CONFIG_H
#define MCAL_STK_STK_CONFIG_H


/*
    OPTIONS:
    AHB_DEVIDED_BY_8
    AHB_DEVIDED_BY_1
*/
#define MSTK_CLOCK_SOURCE        AHB_DEVIDED_BY_8

/*
    OPTIONS:
    ENABLE_INTERRUPT
    DISABLE_INTERRUPT
*/
#define MSTK_INTERRUPT           DISABLE_INTERRUPT

/*
    OPTIONS:
    STK_ENABLE
    STK_DISABLE
*/
#define MSTK_ENABLE              STK_ENABLE


#endif