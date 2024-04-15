/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        22 MAY, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 MCAL
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         22 MAY, 2023      Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/


#ifndef MCAL_CRC_CRC_INTERFACE_H
#define MCAL_CRC_CRC_INTERFACE_H


void MCRC_voidInit(void);
u32 MCRC_u32CalculateCRCWord(u32 Copy_u32DataWord);
u32 MCRC_u32CalculateCRCArray(u32* Copy_pu32DataArray, u8 Copy_u8ArraySize);

void MCRC_voidSetStorageByte(u8 Copy_u8StorageByte);
void MCRC_voidMoveStorageToCRC(void);
u32 MCRC_u32CalculateCRCStorageByte(u8 Copy_u8StorageByte);

void MCRC_voidResetCRC(void);

u32 MCRC_u32CalculateCRCShiftingAlgorithm(const u8* Copy_u8ByteArray, u8 Copy_u8ArraySize);
u32 MCRC_u32CalculateCRCLookupAlgorithm(const u8* Copy_u8ByteArray, u8 Copy_u8ArraySize);


#endif