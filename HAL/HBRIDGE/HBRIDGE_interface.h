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
 * v1.0         19 SEP, 2023      Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/


#ifndef HAL_HBRIDGE_HBRIDGE_INTERFACE_H
#define HAL_HBRIDGE_HBRIDGE_INTERFACE_H


typedef struct {
	u8 HBRIDGE_IN1_PORT;
	u8 HBRIDGE_IN1_PIN;
    u8 HBRIDGE_IN2_PORT;
	u8 HBRIDGE_IN2_PIN;
}HBRIDGE_t;


void HHBRIDGE_voidInit(HBRIDGE_t* HBRIDGEobj);
void HHBRIDGE_voidForward(HBRIDGE_t* HBRIDGEobj);
void HHBRIDGE_voidBackward(HBRIDGE_t* HBRIDGEobj);
void HHBRIDGE_voidStop(HBRIDGE_t* HBRIDGEobj);


#endif