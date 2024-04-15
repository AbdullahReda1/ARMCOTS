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


#ifndef HAL_RELAY_RELAY_INTERFACE_H
#define HAL_RELAY_RELAY_INTERFACE_H


typedef struct {
    u8 RELAY_TYPE;
	u8 RELAY_PORT;
	u8 RELAY_PIN;
}RELAY_t;


/* Relay Type */
#define NORMAL_CLOSE      0
#define NORMAL_OPEN       1


void HRELAY_voidInit(RELAY_t* RELAYobj);
void HRELAY_voidOpen(RELAY_t* RELAYobj);
void HRELAY_voidClose(RELAY_t* RELAYobj);


#endif