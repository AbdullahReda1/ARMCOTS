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


#ifndef MCAL_LEDMATRIX_LEDMATRIX_INTERFACE_H
#define MCAL_LEDMATRIX_LEDMATRIX_INTERFACE_H


void HLEDMATRIX_voidInit(void);

void HLEDMATRIX_voidDisplay(const u8 * Copy_pu8DataArray);

void HLEDMATRIX_voidRotateCharacter(const u8 * Copy_pu8DataArray);

void HLEDMATRIX_voidRotateString(const u8* Copy_pu8StringArray, u8 Copy_u8CharecterWidth);

void HLEDMATRIX_voidRotateCustomSentence(const u8* Copy_pu8SentenceArray, u32 Copy_u32SentenceColumLength);


#endif