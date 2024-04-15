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


#ifndef MCAL_STP_STP_CONFIG_H
#define MCAL_STP_STP_CONFIG_H


/*
    OPTIONS:
    HSTP_GPIO_PORTA
    HSTP_GPIO_PORTB
    HSTP_GPIO_PORTC
*/
#define     HSTP_DATA_PORT_NAME             HSTP_GPIO_PORTA

#define     HSTP_LATCH_BIT_PORT_NAME        HSTP_GPIO_PORTA

#define     HSTP_LATCH_BYTE_PORT_NAME       HSTP_GPIO_PORTA

#define     HSTP_ENABLE_IC_PORT_NAME        HSTP_GPIO_PORTA

#define     HSTP_RESET_IC_PORT_NAME         HSTP_GPIO_PORTA


/*
    OPTIONS:
    HSTP_PIN0
    HSTP_PIN1
    HSTP_PIN2
    HSTP_PIN3
    HSTP_PIN4
    HSTP_PIN5
    HSTP_PIN6
    HSTP_PIN7
    HSTP_PIN8
    HSTP_PIN9
    HSTP_PIN10
    HSTP_PIN11
    HSTP_PIN12
    HSTP_PIN13
    HSTP_PIN14
    HSTP_PIN15
*/
#define     HSTP_DATA_PIN_NUMBER            HSTP_PIN0

#define     HSTP_LATCH_BIT_PIN_NUMBER       HSTP_PIN1

#define     HSTP_LATCH_BYTE_PIN_NUMBER      HSTP_PIN2

#define     HSTP_ENABLE_IC_PIN_NUMBER       HSTP_PIN3

#define     HSTP_RESET_IC_PIN_NUMBER        HSTP_PIN4


#endif