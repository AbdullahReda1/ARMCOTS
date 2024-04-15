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


#ifndef MCAL_STP_STP_INTERFACE_H
#define MCAL_STP_STP_INTERFACE_H


#define HSTP_ENABLE     1
#define HSTP_DISABLE    0


void HSTP_voidInit(void);

void HSTP_voidWriteByte(u8 Copy_u8DataByte);

void HSTP_voidWriteWord(u16 Copy_u16DataWord);

void HSTP_voidWriteNumberofWords(u32 Copy_u32DataWord, u8 Copy_u8WordsNumber); 

void HSTP_voidSetEnableStatus(u8 Copy_u8Status);

void HSTP_voidResetIC(void);


#endif