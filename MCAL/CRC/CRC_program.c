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


#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "CRC_interface.h"
#include "CRC_private.h"
#include "CRC_config.h"


void MCRC_voidInit(void)
{
    /* Reset CRC Hardware */
    MCRC_voidResetCRC();
}

u32 MCRC_u32CalculateCRCWord(u32 Copy_u32DataWord)
{
    u32 Local_u32CRCValue = 0;

    /* Reset CRC Hardware */
    MCRC_voidResetCRC();

    /* Single Write */
    SET_REG((CRC->DR), Copy_u32DataWord);

    /* Single Read */
    Local_u32CRCValue = (CRC->DR);

    return Local_u32CRCValue;
}

u32 MCRC_u32CalculateCRCArray(u32* Copy_pu32DataArray, u8 Copy_u8ArraySize)
{
    u8 Local_u8Itirator;
    u32 Local_u32CRCValue = 0;

    /* Check null pointer */
    if (NULL != Copy_pu32DataArray)
    {
        /* Reset CRC Hardware */
        MCRC_voidResetCRC();

        /* Write Back-to-Back */
        for (Local_u8Itirator = 0; Local_u8Itirator < Copy_u8ArraySize; Local_u8Itirator++)
        {
            SET_REG((CRC->DR), Copy_pu32DataArray[Local_u8Itirator]);
        }

        /* Single Read */
        Local_u32CRCValue = (CRC->DR);
    }
    else
    {
        /* Null pointer detected */
    }

    return Local_u32CRCValue;
}

void MCRC_voidSetStorageByte(u8 Copy_u8StorageByte)
{
    SET_REG((CRC->IDR), Copy_u8StorageByte);
}

void MCRC_voidMoveStorageToCRC(void)
{
    SET_REG((CRC->DR), (u8) (CRC->IDR));
}

u32 MCRC_u32CalculateCRCStorageByte(u8 Copy_u8StorageByte)
{
    u32 Local_u32CRCValue = 0;
    
    /* Reset CRC Hardware */
    MCRC_voidResetCRC();
    SET_REG((CRC->IDR), RESET_BYTE_STORAGE);

    MCRC_voidSetStorageByte(Copy_u8StorageByte);
    MCRC_voidMoveStorageToCRC();

    /* Single Read */
    Local_u32CRCValue = (CRC->DR);

    return Local_u32CRCValue;
}

void MCRC_voidResetCRC(void)
{
    SET_WORD((CRC->CR), RESET_CRC, CR_RESET);
}

u32 MCRC_u32CalculateCRCShiftingAlgorithm(const u8* Copy_u8ByteArray, u8 Copy_u8ArraySize)
{
    u32 Copy_u32ByteIndex;
    u8 Copy_u8BitIndex;
    u32 Local_u32CRCValue = RESET_DATA_VALUE;

    /* Check Null pointer */
    if(NULL != Copy_u8ByteArray)
    {
        /* Process all Bytes */
        for(Copy_u32ByteIndex = 0; Copy_u32ByteIndex < Copy_u8ArraySize; ++Copy_u32ByteIndex)
        {
            /* XOR input byte into MSB of CRC */
            Local_u32CRCValue ^= (u32)(Copy_u8ByteArray[Copy_u32ByteIndex] << 24);

            /* Process all Bits */
            for(Copy_u8BitIndex = 0; Copy_u8BitIndex < 8; ++Copy_u8BitIndex)
            {
                /* Check the MSB bit if equal to 1 */
                if (CHECK_MSB_BIT_VALUE == (Local_u32CRCValue & CHECK_MSB_BIT_VALUE))
                {
                    /* Last bit is 1, shift it out, then XOR with poly */
                    Local_u32CRCValue = (u32)((Local_u32CRCValue << 1) ^ GENERATOR_POLYNOMIAL);
                }
                else
                {
                    /* Last bit is not 1, shift */
                    Local_u32CRCValue <<= 1;
                }
            }
        }
    }
    else
    {
        /* Null pointer detected */
    }

    return Local_u32CRCValue;
}

u32 MCRC_u32CalculateCRCLookupAlgorithm(const u8* Copy_u8ByteArray, u8 Copy_u8ArraySize)
{
    u32 Copy_u32ByteIndex;
    u32 Local_u32CRCValue = RESET_DATA_VALUE;

    /* CRC Look up Table Index */
    u8 Local_u8TableIndex = 0;

    /* Check Null pointer */
    if(NULL != Copy_u8ByteArray)
    {
        /* Process All Bytes */
        for(Copy_u32ByteIndex = 0; Copy_u32ByteIndex < Copy_u8ArraySize; ++Copy_u32ByteIndex)
        {
            /* XOR input byte into MSB of CRC and get table index, Get the remainder from the look up table */
            Local_u8TableIndex = (u8)((Local_u32CRCValue ^ (Copy_u8ByteArray[Copy_u32ByteIndex] << 24)) >> 24);

            /* Shift out the MSB of current CRC and XOR it with the current remainder to get the new CRC */
            Local_u32CRCValue = (u32)((Local_u32CRCValue << 8) ^ (u32)(CRCLookupTable[Local_u8TableIndex]));
        }
    }
    else
    {
        /* Null pointer detected */
    }

    return Local_u32CRCValue;
}