/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        19 SEP, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 HAL
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         19 SEP, 2023      Abdullah R.Hebashi           Initial Creation 
*********************************************************************************/


#ifndef HAL_LED_LED_INTERFACE_H
#define HAL_LED_LED_INTERFACE_H


typedef struct {
	u8 LED_PORT;
	u8 LED_PIN;
}LED_t;


void HLED_voidInit(LED_t* Ledobj);

void HLED_voidTurnOn(LED_t* Ledobj);

void HLED_voidTurnOff(LED_t* Ledobj);

void HLED_voidToggle(LED_t* Ledobj);


#endif