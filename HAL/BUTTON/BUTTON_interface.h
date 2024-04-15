/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        20 SEP, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 HAL
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         20 SEP, 2023      Abdullah R.Hebashi           Initial Creation 
*********************************************************************************/


#ifndef HAL_BUTTON_BUTTON_INTERFACE_H
#define HAL_BUTTON_BUTTON_INTERFACE_H


typedef struct {
	u8 BUTTON_PORT;
	u8 BUTTON_PIN;
	u8 BUTTON_PP_TYPE;
}BUTTON_t;


void HBUTTON_voidInit(BUTTON_t* Buttonobj);

u8 HBUTTON_u8GetButtonStatus(BUTTON_t* Buttonobj);


#endif