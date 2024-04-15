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


#ifndef MCAL_SEVENSEGMENT_SEVENSEGMENT_INTERFACE_H
#define MCAL_SEVENSEGMENT_SEVENSEGMENT_INTERFACE_H


typedef struct {
	u8 SEVENSEGMENT_PORT;
	u8 SEVENSEGMENT_PINA;
    u8 SEVENSEGMENT_PINB;
    u8 SEVENSEGMENT_PINC;
    u8 SEVENSEGMENT_PIND;
    u8 SEVENSEGMENT_PINE;
    u8 SEVENSEGMENT_PINF;
    u8 SEVENSEGMENT_PING;
}SEVENSEGMENT_t;


void HSEVENSEGMENT_voidInit(SEVENSEGMENT_t* SEVENSEGMENTobj);

void HSEVENSEGMENT_voidSendNumber(SEVENSEGMENT_t* SEVENSEGMENTobj, u8 Copy_u8Number);


#endif