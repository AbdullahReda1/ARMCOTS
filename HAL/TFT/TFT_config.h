/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        30 MAY, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 HAL
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         30 MAY, 2023      Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/

#ifndef HAL_TFT_TFT_CONFIG_H_
#define HAL_TFT_TFT_CONFIG_H_

/*
    OPTIONS:
    MGPIO_PORTA
    MGPIO_PORTB
    MGPIO_PORTC
*/
#define     HTFT_RESET_PORT      MGPIO_PORTA

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
#define     HTFT_RESET_PIN       PIN1


/*
    OPTIONS:
    MGPIO_PORTA
    MGPIO_PORTB
    MGPIO_PORTC
*/
#define     HTFT_A0_PORT         MGPIO_PORTA

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
#define     HTFT_A0_PIN          PIN0


#endif