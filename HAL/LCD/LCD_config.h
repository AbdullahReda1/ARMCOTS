/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        26 MAR, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 HAL
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         26 MAR, 2023      Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/


#ifndef HAL_LCD_LCD_CONFIG_H
#define HAL_LCD_LCD_CONFIG_H


/*
    OPTIONS:
    MGPIO_PORTA
    MGPIO_PORTB
    MGPIO_PORTC
*/
#define LCD_DATA_PORT       MGPIO_PORTA

#define LCD_CTRL_PORT       MGPIO_PORTA


/* For 8-bit mode */
/*
    OPTIONS:
    HIGH_HALF_PORT
    LOW_HALF_PORT
*/
#define LCD_HALF_DATA_PORT       LOW_HALF_PORT


/* For 4-bit mode */
/*
    OPTIONS:
    F1ST_NIPPLE_PORT
    S2ND_NIPPLE_PORT
    T3RD_NIPPLE_PORT
    F4TH_NIPPLE_PORT
*/
#define LCD_NIPPLE_DATA_PORT       F1ST_NIPPLE_PORT


/*
    OPTIONS:
    PIN0
    PIN1
    PIN2
    PIN3
    PIN4
    PIN5
    PIN6
    PIN7
    PIN8
    PIN9
    PIN10
    PIN11
    PIN12
    PIN13
    PIN14
    PIN15
*/
#define LCD_RS_PIN          PIN8

#define LCD_RW_PIN          PIN9

#define LCD_EN_PIN          PIN10


/*
    Options:
    EIGHT_BIT_MODE
    FOUR_BIT_MODE
*/
#define LCD_INIT_MODE       EIGHT_BIT_MODE


#endif