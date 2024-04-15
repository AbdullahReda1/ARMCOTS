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

#include "MPU_interface.h"
#include "MPU_private.h"
#include "MPU_config.h"


void MMPU_voidInit(void)
{
    if(0 == (MPU->TYPER))
    {
        /* MPU is not present */
        while(1)
        {
        }
    }
    else
    {
        /* MPU is OK */
    }

    __DMB();

    /* Disable MPU */
    MMPU_voidDisableMPU();
}

u8 MMPU_u8GetSeparationofMemoryMapStatus(void)
{
    u32 Local_u32RegisterValue;
    Local_u32RegisterValue = GET_REG((MPU->TYPER));
    return (GET_BIT(Local_u32RegisterValue, TYPER_SEPARATE));
}

u8 MMPU_u8GetNumberofDataRegions(void)
{
    u32 Local_u32RegisterValue;
    Local_u32RegisterValue = GET_REG((MPU->TYPER));
    return (GET_WORD(Local_u32RegisterValue, TYPER_DREGION0, TYPER_DREGION7));
}

u8 MMPU_u8GetNumberofInstructionRegions(void)
{
    u32 Local_u32RegisterValue;
    Local_u32RegisterValue = GET_REG((MPU->TYPER));
    return (GET_WORD(Local_u32RegisterValue, TYPER_IREGION0, TYPER_IREGION7));
}

void MMPU_voidEnableMPU(void)
{
    SET_WORD((MPU->CTRL), ENABLE, CTRL_ENABLE);
}

void MMPU_voidEnableMPUDuringHandler(void)
{
    SET_WORD((MPU->CTRL), ENABLE, CTRL_HFNMIENA);
}

void MMPU_voidEnablePriviligedSoftwareAccess(void)
{
    SET_WORD((MPU->CTRL), ENABLE, CTRL_PRIVDEFENA);
}

void MMPU_voidDisableMPU(void)
{
    SET_REG((MPU->CTRL), DISABLE);
}

void MMPU_voidDisableMPUDuringHandler(void)
{
    SET_MASK((MPU->CTRL), MASK_1_BIT, CTRL_HFNMIENA);
}

void MMPU_voidDisablePriviligedSoftwareAccess(void)
{
    SET_MASK((MPU->CTRL), MASK_1_BIT, CTRL_PRIVDEFENA);
}

void MMPU_voidSetRegionNumper(u8 Copy_u8RegionNumper)
{
    if ((Copy_u8RegionNumper >= 0) && (Copy_u8RegionNumper <= 7))
    {
        SET_REG((MPU->RNR), Copy_u8RegionNumper);
    }
}

u8 MMPU_u8GetRegionNumper(void)
{
    return (MPU->RNR);
}

void MMPU_voidSetRegionBaseAddress(u32 Copy_u32RegionBaseAddress)
{
    SET_REG((MPU->RBAR), Copy_u32RegionBaseAddress);
}

void MMPU_voidUpdateRegionBaseAddress(u8 Copy_u8RegionNumper, u32 Copy_u32RegionBaseAddress)
{
    if ((Copy_u8RegionNumper >= 0) && (Copy_u8RegionNumper <= 7))
    {
        SET_REG((MPU->RBAR), ((Copy_u32RegionBaseAddress) | (1 << RBAR_VALID) | (Copy_u8RegionNumper)));
    }
}

void MMPU_voidUpdateSimultaneouslyRegions(u8* Copy_pu8RegionNumperArray, u32* Copy_pu32RegionBaseAddressArray, u8 Copy_u8NumperofBaseAddresses)
{
    switch (Copy_u8NumperofBaseAddresses)
    {
        case 1:
            SET_REG((MPU->RBAR), ((Copy_pu32RegionBaseAddressArray[0]) | (1 << RBAR_VALID) | (Copy_pu8RegionNumperArray[0])));
        break;
        case 2:
            SET_REG((MPU->RBAR), ((Copy_pu32RegionBaseAddressArray[0]) | (1 << RBAR_VALID) | (Copy_pu8RegionNumperArray[0])));
            SET_REG((MPU->RBAR_A1), ((Copy_pu32RegionBaseAddressArray[1]) | (1 << RBAR_VALID) | (Copy_pu8RegionNumperArray[1])));
        break;
        case 3:
            SET_REG((MPU->RBAR), ((Copy_pu32RegionBaseAddressArray[0]) | (1 << RBAR_VALID) | (Copy_pu8RegionNumperArray[0])));
            SET_REG((MPU->RBAR_A1), ((Copy_pu32RegionBaseAddressArray[1]) | (1 << RBAR_VALID) | (Copy_pu8RegionNumperArray[1])));
            SET_REG((MPU->RBAR_A2), ((Copy_pu32RegionBaseAddressArray[2]) | (1 << RBAR_VALID) | (Copy_pu8RegionNumperArray[2])));
        break;
        case 4:
            SET_REG((MPU->RBAR), ((Copy_pu32RegionBaseAddressArray[0]) | (1 << RBAR_VALID) | (Copy_pu8RegionNumperArray[0])));
            SET_REG((MPU->RBAR_A1), ((Copy_pu32RegionBaseAddressArray[1]) | (1 << RBAR_VALID) | (Copy_pu8RegionNumperArray[1])));
            SET_REG((MPU->RBAR_A2), ((Copy_pu32RegionBaseAddressArray[2]) | (1 << RBAR_VALID) | (Copy_pu8RegionNumperArray[2])));
            SET_REG((MPU->RBAR_A3), ((Copy_pu32RegionBaseAddressArray[3]) | (1 << RBAR_VALID) | (Copy_pu8RegionNumperArray[3])));
        break;    
        default:
        break;
    }
}

void MMPU_voidSetRegionAttributes(u8 Copy_u8InstructionFetch, u8 Copy_u8AccessPermission, u8 Copy_u8MemoryAttribute)
{
    SET_REG((MPU->RASR), ((Copy_u8InstructionFetch << RASR_XN) | (Copy_u8AccessPermission << RASR_AP) | (Copy_u8MemoryAttribute << RASR_B) | (CLEAR_SDR << RASR_SDR)));
}

void MMPU_voidSetRegionSize(u8 Copy_u8RegionSize)
{
    SET_REG((MPU->RASR), (Copy_u8RegionSize << RASR_SIZE));
}

void MMPU_voidSetSubRegion(u8 Copy_u8SubRegionNumber)
{
    SET_REG((MPU->RASR), (Copy_u8SubRegionNumber << RASR_SDR));
}

void MMPU_voidEnableRegion(void)
{
    SET_WORD((MPU->RASR), ENABLE, RASR_ENABLE);
}

void MMPU_voidDisableRegion(void)
{
    SET_MASK((MPU->RASR), MASK_1_BIT, RASR_ENABLE);
}

void MMPU_voidSetSizeSubregionandAttributes(u8 Copy_u8InstructionFetch, u8 Copy_u8AccessPermission, u8 Copy_u8MemoryAttribute, u8 Copy_u8SubRegionNumber, u8 Copy_u8RegionSize)
{
    SET_REG((MPU->RASR), ((Copy_u8InstructionFetch << RASR_XN) | (Copy_u8AccessPermission << RASR_AP) | (Copy_u8MemoryAttribute << RASR_B) | (Copy_u8SubRegionNumber << RASR_SDR) | (Copy_u8RegionSize << RASR_SIZE) | (ENABLE << RASR_ENABLE)));
}

void MMPU_voidSetSizeSubregionandAttributesSimultaneously(u8* Copy_pu8InstructionFetch, u8* Copy_pu8AccessPermission, u8* Copy_pu8MemoryAttribute, u8* Copy_pu8SubRegionNumber, u8* Copy_pu8RegionSize, u8 Copy_u8NumperofBaseAddresses)
{
    switch (Copy_u8NumperofBaseAddresses)
    {
        case 1:
            SET_REG((MPU->RASR), ((Copy_pu8InstructionFetch[0] << RASR_XN) | (Copy_pu8AccessPermission[0] << RASR_AP) | (Copy_pu8MemoryAttribute[0] << RASR_B) | (Copy_pu8SubRegionNumber[0] << RASR_SDR) | (Copy_pu8RegionSize[0] << RASR_SIZE) | (ENABLE << RASR_ENABLE)));
        break;
        case 2:
            SET_REG((MPU->RASR), ((Copy_pu8InstructionFetch[0] << RASR_XN) | (Copy_pu8AccessPermission[0] << RASR_AP) | (Copy_pu8MemoryAttribute[0] << RASR_B) | (Copy_pu8SubRegionNumber[0] << RASR_SDR) | (Copy_pu8RegionSize[0] << RASR_SIZE) | (ENABLE << RASR_ENABLE)));
            SET_REG((MPU->RASR_A1), ((Copy_pu8InstructionFetch[1] << RASR_XN) | (Copy_pu8AccessPermission[1] << RASR_AP) | (Copy_pu8MemoryAttribute[1] << RASR_B) | (Copy_pu8SubRegionNumber[1] << RASR_SDR) | (Copy_pu8RegionSize[1] << RASR_SIZE) | (ENABLE << RASR_ENABLE)));
        break;
        case 3:
            SET_REG((MPU->RASR), ((Copy_pu8InstructionFetch[0] << RASR_XN) | (Copy_pu8AccessPermission[0] << RASR_AP) | (Copy_pu8MemoryAttribute[0] << RASR_B) | (Copy_pu8SubRegionNumber[0] << RASR_SDR) | (Copy_pu8RegionSize[0] << RASR_SIZE) | (ENABLE << RASR_ENABLE)));
            SET_REG((MPU->RASR_A1), ((Copy_pu8InstructionFetch[1] << RASR_XN) | (Copy_pu8AccessPermission[1] << RASR_AP) | (Copy_pu8MemoryAttribute[1] << RASR_B) | (Copy_pu8SubRegionNumber[1] << RASR_SDR) | (Copy_pu8RegionSize[1] << RASR_SIZE) | (ENABLE << RASR_ENABLE)));
            SET_REG((MPU->RASR_A2), ((Copy_pu8InstructionFetch[2] << RASR_XN) | (Copy_pu8AccessPermission[2] << RASR_AP) | (Copy_pu8MemoryAttribute[2] << RASR_B) | (Copy_pu8SubRegionNumber[2] << RASR_SDR) | (Copy_pu8RegionSize[2] << RASR_SIZE) | (ENABLE << RASR_ENABLE)));
        break;
        case 4:
            SET_REG((MPU->RASR), ((Copy_pu8InstructionFetch[0] << RASR_XN) | (Copy_pu8AccessPermission[0] << RASR_AP) | (Copy_pu8MemoryAttribute[0] << RASR_B) | (Copy_pu8SubRegionNumber[0] << RASR_SDR) | (Copy_pu8RegionSize[0] << RASR_SIZE) | (ENABLE << RASR_ENABLE)));
            SET_REG((MPU->RASR_A1), ((Copy_pu8InstructionFetch[1] << RASR_XN) | (Copy_pu8AccessPermission[1] << RASR_AP) | (Copy_pu8MemoryAttribute[1] << RASR_B) | (Copy_pu8SubRegionNumber[1] << RASR_SDR) | (Copy_pu8RegionSize[1] << RASR_SIZE) | (ENABLE << RASR_ENABLE)));
            SET_REG((MPU->RASR_A2), ((Copy_pu8InstructionFetch[2] << RASR_XN) | (Copy_pu8AccessPermission[2] << RASR_AP) | (Copy_pu8MemoryAttribute[2] << RASR_B) | (Copy_pu8SubRegionNumber[2] << RASR_SDR) | (Copy_pu8RegionSize[2] << RASR_SIZE) | (ENABLE << RASR_ENABLE)));
            SET_REG((MPU->RASR_A3), ((Copy_pu8InstructionFetch[3] << RASR_XN) | (Copy_pu8AccessPermission[3] << RASR_AP) | (Copy_pu8MemoryAttribute[3] << RASR_B) | (Copy_pu8SubRegionNumber[3] << RASR_SDR) | (Copy_pu8RegionSize[3] << RASR_SIZE) | (ENABLE << RASR_ENABLE)));
        break;    
        default:
        break;
    }
}

void MMPU_voidStartRegion(u8 Copy_u8RegionNumper, u32 Copy_u32RegionBaseAddress, u8 Copy_u8InstructionFetch, u8 Copy_u8AccessPermission, u8 Copy_u8MemoryAttribute, u8 Copy_u8SubRegionNumber, u8 Copy_u8RegionSize)
{
    MMPU_voidUpdateRegionBaseAddress(Copy_u8RegionNumper, Copy_u32RegionBaseAddress);
    MMPU_voidSetSizeSubregionandAttributes(Copy_u8InstructionFetch, Copy_u8AccessPermission, Copy_u8MemoryAttribute, Copy_u8SubRegionNumber, Copy_u8RegionSize);
}

void MMPU_voidDisableUnusedRegions(u8 Copy_u8FirstUnusedRegion, u8 Copy_u8LastUnusedRegion)
{
    u8 Local_u8Iterator;
    for(Local_u8Iterator = Copy_u8FirstUnusedRegion; Local_u8Iterator <= Copy_u8LastUnusedRegion; Local_u8Iterator++)
    {
        MMPU_voidSetRegionNumper(Local_u8Iterator);
        MMPU_voidSetRegionBaseAddress(DISABLE);
        SET_REG((MPU->RASR), DISABLE);
    }
    MMPU_voidEnableMPU();
    __DSB();
    __ISB();
}