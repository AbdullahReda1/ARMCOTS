/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        28 MAR, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 HAL
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         28 MAR, 2023      Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/


#ifndef HAL_KPD_KPD_CONFIG_H
#define HAL_KPD_KPD_CONFIG_H


/*
    OPTIONS:
    MGPIO_PORTA
    MGPIO_PORTB
    MGPIO_PORTC
*/
#define KPD_ROWS_PORT          MGPIO_PORTB

#define KPD_COLS_PORT          MGPIO_PORTB


/*
    OPTIONS:
    F1ST_NIPPLE_PORT
    S2ND_NIPPLE_PORT
    T3RD_NIPPLE_PORT
    F4TH_NIPPLE_PORT
*/
#define KPD_ROWS_NIPPLE        F1ST_NIPPLE_PORT

#define KPD_COLS_NIPPLE        S2ND_NIPPLE_PORT


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
#define KPD_START_ROW_PIN        PIN0

#define KPD_START_COL_PIN        PIN4


#endif