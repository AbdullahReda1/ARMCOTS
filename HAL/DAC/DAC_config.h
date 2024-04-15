/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        29 MAY, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 HAL
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         29 MAY, 2023      Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/


#ifndef HAL_DAC_DAC_CONFIG_H
#define HAL_DAC_DAC_CONFIG_H


/*
    OPTIONS:
    HDAC_GPIO_PORTA
    HDAC_GPIO_PORTB
    HDAC_GPIO_PORTC
*/
#define     HDAC_PORT_NAME          HDAC_GPIO_PORTA

/*
    OPTIONS:
    HDAC_HIGH_HALF_PORT
    HDAC_LOW_HALF_PORT
*/
#define     HDAC_HALF_PORT_NAME     HDAC_LOW_HALF_PORT


#endif