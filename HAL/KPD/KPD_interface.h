/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        28 MAR, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 HAL
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         28 MAR, 2023      Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/


#ifndef HAL_KPD_KPD_INTERFACE_H
#define HAL_KPD_KPD_INTERFACE_H


void HKPD_voidInit(void);

u8 HKPD_u8GetPressedKey(void);


#endif