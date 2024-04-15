/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        11 MAY, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 HAL
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         11 MAY, 2023      Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/


#ifndef MCAL_LEDMATRIX_LEDMATRIX_CONFIG_H
#define MCAL_LEDMATRIX_LEDMATRIX_CONFIG_H


/*
    OPTIONS:  PORT,PIN
        PORT:
            MGPIO_PORTA
            MGPIO_PORTB
            MGPIO_PORTC
        PIN:
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
#define ROW0      MGPIO_PORTA,PIN0
#define ROW1      MGPIO_PORTA,PIN1
#define ROW2      MGPIO_PORTA,PIN2
#define ROW3      MGPIO_PORTA,PIN3
#define ROW4      MGPIO_PORTA,PIN4
#define ROW5      MGPIO_PORTA,PIN5
#define ROW6      MGPIO_PORTA,PIN6
#define ROW7      MGPIO_PORTA,PIN7

#define COL0      MGPIO_PORTB,PIN0
#define COL1      MGPIO_PORTB,PIN1
#define COL2      MGPIO_PORTB,PIN5
#define COL3      MGPIO_PORTB,PIN6
#define COL4      MGPIO_PORTB,PIN7
#define COL5      MGPIO_PORTB,PIN8
#define COL6      MGPIO_PORTB,PIN9
#define COL7      MGPIO_PORTB,PIN10

/*
    OPTIONS:
    MGPIO_PORTA
    MGPIO_PORTB
    MGPIO_PORTC
*/
#define ROW_PORT      MGPIO_PORTA

#define COL_PORT      MGPIO_PORTB


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
#define LEDMATRIX_ROW0_PIN_ONLY              PIN0
#define LEDMATRIX_ROW1_PIN_ONLY              PIN1
#define LEDMATRIX_ROW2_PIN_ONLY              PIN2
#define LEDMATRIX_ROW3_PIN_ONLY              PIN3
#define LEDMATRIX_ROW4_PIN_ONLY              PIN4
#define LEDMATRIX_ROW5_PIN_ONLY              PIN5
#define LEDMATRIX_ROW6_PIN_ONLY              PIN6
#define LEDMATRIX_ROW7_PIN_ONLY              PIN7

#define LEDMATRIX_COL0_PIN_ONLY              PIN0
#define LEDMATRIX_COL1_PIN_ONLY              PIN1
#define LEDMATRIX_COL2_PIN_ONLY              PIN5
#define LEDMATRIX_COL3_PIN_ONLY              PIN6
#define LEDMATRIX_COL4_PIN_ONLY              PIN7
#define LEDMATRIX_COL5_PIN_ONLY              PIN8
#define LEDMATRIX_COL6_PIN_ONLY              PIN9    
#define LEDMATRIX_COL7_PIN_ONLY              PIN10


#endif