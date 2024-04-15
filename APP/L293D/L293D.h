/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        19 SEP, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 APP
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         19 SEP, 2023      Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/


#ifndef APP_L293D_L293D_H
#define APP_L293D_L293D_H


typedef struct {
	u8 L293D_EN1_PORT;
	u8 L293D_EN1_PIN;
    HBRIDGE_t HBRIDGE1;     /* RIGHT */
    u8 L293D_EN2_PORT;
	u8 L293D_EN2_PIN;
    HBRIDGE_t HBRIDGE2;     /* LEFT */
}L293D_t;


void L293D_voidInit(L293D_t* L293Dobj);
void L293D_voidMoveForward(L293D_t* L293Dobj);
void L293D_voidMoveBackward(L293D_t* L293Dobj);
void L293D_voidMoveStop(L293D_t* L293Dobj);
void L293D_voidMoveRight(L293D_t* L293Dobj);
void L293D_voidMoveLeft(L293D_t* L293Dobj);


#endif