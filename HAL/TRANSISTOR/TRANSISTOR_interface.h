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


#ifndef HAL_TRANSISTOR_TRANSISTOR_INTERFACE_H
#define HAL_TRANSISTOR_TRANSISTOR_INTERFACE_H


typedef struct {
    u8 TRANSISTOR_TYPE;
	u8 TRANSISTOR_PORT;
	u8 TRANSISTOR_PIN;
}TRANSISTOR_t;


/* Transistor Type */
#define NPN     0
#define PNP     1


void HTRANSISTOR_voidInit(TRANSISTOR_t* TRANSISTORobj);
void HTRANSISTOR_voidSaturationMode(TRANSISTOR_t* TRANSISTORobj);
void HTRANSISTOR_voidCutoffMode(TRANSISTOR_t* TRANSISTORobj);


#endif