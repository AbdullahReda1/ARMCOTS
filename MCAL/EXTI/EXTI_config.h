/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        22 MAY, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 MCAL
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         22 MAY, 2023      Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/


#ifndef MCAL_EXTI_EXTI_CONFIG_H
#define MCAL_EXTI_EXTI_CONFIG_H


/*
    OPTIONS:
    RISING_EDGE
    FALLING_EDGE
    ON_CHANGE
*/
#define     EXTI_SENSE_SIGNAL   RISING_EDGE

/*
    OPTIONS:
    LINE0
    LINE1
    LINE2
    LINE3
    LINE4
    LINE5
    LINE6
    LINE7
    LINE8
    LINE9
    LINE10
    LINE11
    LINE12
    LINE13
    LINE14
    LINE15
*/
#define     EXTI_LINE           LINE0


#endif