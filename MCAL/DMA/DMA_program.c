/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        05 Jun, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 MCAL
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         05 Jun, 2023      Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/


#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_config.h"


static void (*pvCallBack1[8])(void) = {{NULL}};
static void (*pvCallBack2[8])(void) = {{NULL}};


void MDMA1_voidInit(void)
{
    SET_MASK(DMA1->STREAM[0].SCR, MASK_1_BIT, S0CR_EN);
    SET_MASK(DMA1->STREAM[1].SCR, MASK_1_BIT, S1CR_EN);
    SET_MASK(DMA1->STREAM[2].SCR, MASK_1_BIT, S2CR_EN);
    SET_MASK(DMA1->STREAM[3].SCR, MASK_1_BIT, S3CR_EN);
    SET_MASK(DMA1->STREAM[4].SCR, MASK_1_BIT, S4CR_EN);
    SET_MASK(DMA1->STREAM[5].SCR, MASK_1_BIT, S5CR_EN);
    SET_MASK(DMA1->STREAM[6].SCR, MASK_1_BIT, S6CR_EN);
    SET_MASK(DMA1->STREAM[7].SCR, MASK_1_BIT, S7CR_EN);
}

void MDMA2_voidInit(void)
{
    SET_MASK(DMA2->STREAM[0].SCR, MASK_1_BIT, S0CR_EN);
    SET_MASK(DMA2->STREAM[1].SCR, MASK_1_BIT, S1CR_EN);
    SET_MASK(DMA2->STREAM[2].SCR, MASK_1_BIT, S2CR_EN);
    SET_MASK(DMA2->STREAM[3].SCR, MASK_1_BIT, S3CR_EN);
    SET_MASK(DMA2->STREAM[4].SCR, MASK_1_BIT, S4CR_EN);
    SET_MASK(DMA2->STREAM[5].SCR, MASK_1_BIT, S5CR_EN);
    SET_MASK(DMA2->STREAM[6].SCR, MASK_1_BIT, S6CR_EN);
    SET_MASK(DMA2->STREAM[7].SCR, MASK_1_BIT, S7CR_EN);
}

void MDMA_voidSelectChannel(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8ChannelNumber)
{
    /* "Select channel" using individual input, "Peripheral request" using single input which contain all inputs */
    switch (Copy_u8DMANumber)
    {
        case MDMA1:
            SET_MASK((DMA1->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_EN);
            SET_MASK((DMA1->STREAM[Copy_u8StreamNumber].SCR), MASK_3_BIT, SXCR_CHSEL);
            SET_WORD((DMA1->STREAM[Copy_u8StreamNumber].SCR), Copy_u8ChannelNumber, SXCR_CHSEL);
        break;
        case MDMA2:
            SET_MASK((DMA2->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_EN);
            SET_MASK((DMA2->STREAM[Copy_u8StreamNumber].SCR), MASK_3_BIT, SXCR_CHSEL);
            SET_WORD((DMA2->STREAM[Copy_u8StreamNumber].SCR), Copy_u8ChannelNumber, SXCR_CHSEL);
        break;
        default:
        break;
    }
}

void MDMA_voidSetMemoryBurst(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8BurstBeat)
{
    switch (Copy_u8DMANumber)
    {
        case MDMA1:
            SET_MASK((DMA1->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_EN);
            SET_MASK((DMA1->STREAM[Copy_u8StreamNumber].SCR), MASK_2_BIT, SXCR_MBURST);
            SET_WORD((DMA1->STREAM[Copy_u8StreamNumber].SCR), Copy_u8BurstBeat, SXCR_MBURST);
        break;
        case MDMA2:
            SET_MASK((DMA2->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_EN);
            SET_MASK((DMA2->STREAM[Copy_u8StreamNumber].SCR), MASK_2_BIT, SXCR_MBURST);
            SET_WORD((DMA2->STREAM[Copy_u8StreamNumber].SCR), Copy_u8BurstBeat, SXCR_MBURST);
        break;
        default:
        break;
    }
}

void MDMA_voidSetPeripheralBurst(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8BurstBeat)
{
    switch (Copy_u8DMANumber)
    {
        case MDMA1:
            SET_MASK((DMA1->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_EN);
            SET_MASK((DMA1->STREAM[Copy_u8StreamNumber].SCR), MASK_2_BIT, SXCR_PBURST);
            SET_WORD((DMA1->STREAM[Copy_u8StreamNumber].SCR), Copy_u8BurstBeat, SXCR_PBURST);
        break;
        case MDMA2:
            SET_MASK((DMA2->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_EN);
            SET_MASK((DMA2->STREAM[Copy_u8StreamNumber].SCR), MASK_2_BIT, SXCR_PBURST);
            SET_WORD((DMA2->STREAM[Copy_u8StreamNumber].SCR), Copy_u8BurstBeat, SXCR_PBURST);
        break;
        default:
        break;
    }
}

void MDMA_voidSetCurrentTarget(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8CurrentTarget)
{
    switch (Copy_u8DMANumber)
    {
        case MDMA1:
            SET_MASK((DMA1->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_EN);
            SET_MASK((DMA1->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_CT);
            SET_WORD((DMA1->STREAM[Copy_u8StreamNumber].SCR), Copy_u8CurrentTarget, SXCR_CT);
        break;
        case MDMA2:
            SET_MASK((DMA2->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_EN);
            SET_MASK((DMA2->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_CT);
            SET_WORD((DMA2->STREAM[Copy_u8StreamNumber].SCR), Copy_u8CurrentTarget, SXCR_CT);
        break;
        default:
        break;
    }
}

void MDMA_voidDoubleBufferStatus(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8DoubleBufferStatus)
{
    switch (Copy_u8DMANumber)
    {
        case MDMA1:
            SET_MASK((DMA1->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_EN);
            SET_MASK((DMA1->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_DBM);
            SET_WORD((DMA1->STREAM[Copy_u8StreamNumber].SCR), Copy_u8DoubleBufferStatus, SXCR_DBM);
        break;
        case MDMA2:
            SET_MASK((DMA2->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_EN);
            SET_MASK((DMA2->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_DBM);
            SET_WORD((DMA2->STREAM[Copy_u8StreamNumber].SCR), Copy_u8DoubleBufferStatus, SXCR_DBM);
        break;
        default:
        break;
    }
}

void MDMA_voidSetPriorityLevel(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8PriorityLevel)
{
    switch (Copy_u8DMANumber)
    {
        case MDMA1:
            SET_MASK((DMA1->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_EN);
            SET_MASK((DMA1->STREAM[Copy_u8StreamNumber].SCR), MASK_2_BIT, SXCR_PL);
            SET_WORD((DMA1->STREAM[Copy_u8StreamNumber].SCR), Copy_u8PriorityLevel, SXCR_PL);
        break;
        case MDMA2:
            SET_MASK((DMA2->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_EN);
            SET_MASK((DMA2->STREAM[Copy_u8StreamNumber].SCR), MASK_2_BIT, SXCR_PL);
            SET_WORD((DMA2->STREAM[Copy_u8StreamNumber].SCR), Copy_u8PriorityLevel, SXCR_PL);
        break;
        default:
        break;
    }
}

void MDMA_voidPeripheralIncrementOffsetStatus(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8PeripheralIncrementOffsetStatus)
{
    switch (Copy_u8DMANumber)
    {
        case MDMA1:
            SET_MASK((DMA1->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_EN);
            SET_MASK((DMA1->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_PINCOS);
            SET_WORD((DMA1->STREAM[Copy_u8StreamNumber].SCR), Copy_u8PeripheralIncrementOffsetStatus, SXCR_PINCOS);
        break;
        case MDMA2:
            SET_MASK((DMA2->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_EN);
            SET_MASK((DMA2->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_PINCOS);
            SET_WORD((DMA2->STREAM[Copy_u8StreamNumber].SCR), Copy_u8PeripheralIncrementOffsetStatus, SXCR_PINCOS);
        break;
        default:
        break;
    }
}

void MDMA_voidSetMemoryDataSize(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8MemoryDataSize)
{
    switch (Copy_u8DMANumber)
    {
        case MDMA1:
            SET_MASK((DMA1->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_EN);
            SET_MASK((DMA1->STREAM[Copy_u8StreamNumber].SCR), MASK_2_BIT, SXCR_MSIZE);
            SET_WORD((DMA1->STREAM[Copy_u8StreamNumber].SCR), Copy_u8MemoryDataSize, SXCR_MSIZE);
        break;
        case MDMA2:
            SET_MASK((DMA2->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_EN);
            SET_MASK((DMA2->STREAM[Copy_u8StreamNumber].SCR), MASK_2_BIT, SXCR_MSIZE);
            SET_WORD((DMA2->STREAM[Copy_u8StreamNumber].SCR), Copy_u8MemoryDataSize, SXCR_MSIZE);
        break;
        default:
        break;
    }
}

void MDMA_voidSetPeripheralDataSize(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8PeripheralDataSize)
{
    switch (Copy_u8DMANumber)
    {
        case MDMA1:
            SET_MASK((DMA1->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_EN);
            SET_MASK((DMA1->STREAM[Copy_u8StreamNumber].SCR), MASK_2_BIT, SXCR_PSIZE);
            SET_WORD((DMA1->STREAM[Copy_u8StreamNumber].SCR), Copy_u8PeripheralDataSize, SXCR_PSIZE);
        break;
        case MDMA2:
            SET_MASK((DMA2->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_EN);
            SET_MASK((DMA2->STREAM[Copy_u8StreamNumber].SCR), MASK_2_BIT, SXCR_PSIZE);
            SET_WORD((DMA2->STREAM[Copy_u8StreamNumber].SCR), Copy_u8PeripheralDataSize, SXCR_PSIZE);
        break;
        default:
        break;
    }
}

void MDMA_voidSetMemoryIncrementMode(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8MemoryIncrementMode)
{
    switch (Copy_u8DMANumber)
    {
        case MDMA1:
            SET_MASK((DMA1->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_EN);
            SET_MASK((DMA1->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_MINC);
            SET_WORD((DMA1->STREAM[Copy_u8StreamNumber].SCR), Copy_u8MemoryIncrementMode, SXCR_MINC);
        break;
        case MDMA2:
            SET_MASK((DMA2->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_EN);
            SET_MASK((DMA2->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_MINC);
            SET_WORD((DMA2->STREAM[Copy_u8StreamNumber].SCR), Copy_u8MemoryIncrementMode, SXCR_MINC);
        break;
        default:
        break;
    }
}

void MDMA_voidSetPeripheralIncrementMode(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8PeripheralIncrementMode)
{
    switch (Copy_u8DMANumber)
    {
        case MDMA1:
            SET_MASK((DMA1->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_EN);
            SET_MASK((DMA1->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_PINC);
            SET_WORD((DMA1->STREAM[Copy_u8StreamNumber].SCR), Copy_u8PeripheralIncrementMode, SXCR_PINC);
        break;
        case MDMA2:
            SET_MASK((DMA2->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_EN);
            SET_MASK((DMA2->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_PINC);
            SET_WORD((DMA2->STREAM[Copy_u8StreamNumber].SCR), Copy_u8PeripheralIncrementMode, SXCR_PINC);
        break;
        default:
        break;
    }
}

void MDMA_voidCircularModeStatus(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8CircularModeStatus)
{
    switch (Copy_u8DMANumber)
    {
        case MDMA1:
            SET_MASK((DMA1->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_EN);
            SET_MASK((DMA1->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_CIRC);
            SET_WORD((DMA1->STREAM[Copy_u8StreamNumber].SCR), Copy_u8CircularModeStatus, SXCR_CIRC);
        break;
        case MDMA2:
            SET_MASK((DMA2->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_EN);
            SET_MASK((DMA2->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_CIRC);
            SET_WORD((DMA2->STREAM[Copy_u8StreamNumber].SCR), Copy_u8CircularModeStatus, SXCR_CIRC);
        break;
        default:
        break;
    }
}

void MDMA_voidSetDataTransferDirection(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8TransferDirection)
{
    switch (Copy_u8DMANumber)
    {
        case MDMA1:
            SET_MASK((DMA1->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_EN);
            SET_MASK((DMA1->STREAM[Copy_u8StreamNumber].SCR), MASK_2_BIT, SXCR_DIR);
            SET_WORD((DMA1->STREAM[Copy_u8StreamNumber].SCR), Copy_u8TransferDirection, SXCR_DIR);
        break;
        case MDMA2:
            SET_MASK((DMA2->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_EN);
            SET_MASK((DMA2->STREAM[Copy_u8StreamNumber].SCR), MASK_2_BIT, SXCR_DIR);
            SET_WORD((DMA2->STREAM[Copy_u8StreamNumber].SCR), Copy_u8TransferDirection, SXCR_DIR);
        break;
        default:
        break;
    }
}

void MDMA_voidSetPeripheralFlowController(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8PeripheralFlowController)
{
    switch (Copy_u8DMANumber)
    {
        case MDMA1:
            SET_MASK((DMA1->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_EN);
            SET_MASK((DMA1->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_PFCTRL);
            SET_WORD((DMA1->STREAM[Copy_u8StreamNumber].SCR), Copy_u8PeripheralFlowController, SXCR_PFCTRL);
        break;
        case MDMA2:
            SET_MASK((DMA2->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_EN);
            SET_MASK((DMA2->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_PFCTRL);
            SET_WORD((DMA2->STREAM[Copy_u8StreamNumber].SCR), Copy_u8PeripheralFlowController, SXCR_PFCTRL);
        break;
        default:
        break;
    }
}

void MDMA_voidStreamStatus(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8StreamStatus)
{
    switch (Copy_u8DMANumber)
    {
        case MDMA1:
            SET_MASK((DMA1->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_EN);
            SET_WORD((DMA1->STREAM[Copy_u8StreamNumber].SCR), Copy_u8StreamStatus, SXCR_EN);
        break;
        case MDMA2:
            SET_MASK((DMA2->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_EN);
            SET_WORD((DMA2->STREAM[Copy_u8StreamNumber].SCR), Copy_u8StreamStatus, SXCR_EN);
        break;
        default:
        break;
    }
}

u8 MDMA_u8GetFIFOStatus(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber)
{
    u32 Local_32RegisterValue = 0;
    u8 Local_u8StatusValue = 0;
    switch (Copy_u8DMANumber)
    {
        case MDMA1:
            Local_32RegisterValue = GET_REG((DMA1->STREAM[Copy_u8StreamNumber].SFCR));
        break;
        case MDMA2:
            Local_32RegisterValue = GET_REG((DMA2->STREAM[Copy_u8StreamNumber].SFCR));
        break;
        default:
        break;
    }
    Local_u8StatusValue = GET_WORD(Local_32RegisterValue, SXFCR_FS0, SXFCR_FS2);
    return Local_u8StatusValue;
}

void MDMA_voidSetDirectModeStatus(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8DirectModeStatus)
{
    switch (Copy_u8DMANumber)
    {
        case MDMA1:
            SET_MASK((DMA1->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_EN);
            SET_MASK((DMA1->STREAM[Copy_u8StreamNumber].SFCR), MASK_1_BIT, SXFCR_DMDIS);
            SET_WORD((DMA1->STREAM[Copy_u8StreamNumber].SFCR), Copy_u8DirectModeStatus, SXFCR_DMDIS);
        break;
        case MDMA2:
            SET_MASK((DMA2->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_EN);
            SET_MASK((DMA2->STREAM[Copy_u8StreamNumber].SFCR), MASK_1_BIT, SXFCR_DMDIS);
            SET_WORD((DMA2->STREAM[Copy_u8StreamNumber].SFCR), Copy_u8DirectModeStatus, SXFCR_DMDIS);
        break;
        default:
        break;
    }
}

void MDMA_voidSelectFIFOThreshold(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8FIFOThreshold)
{
    switch (Copy_u8DMANumber)
    {
        case MDMA1:
            SET_MASK((DMA1->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_EN);
            SET_MASK((DMA1->STREAM[Copy_u8StreamNumber].SFCR), MASK_2_BIT, SXFCR_FTH);
            SET_WORD((DMA1->STREAM[Copy_u8StreamNumber].SFCR), Copy_u8FIFOThreshold, SXFCR_FTH);
        break;
        case MDMA2:
            SET_MASK((DMA2->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, SXCR_EN);
            SET_MASK((DMA2->STREAM[Copy_u8StreamNumber].SFCR), MASK_2_BIT, SXFCR_FTH);
            SET_WORD((DMA2->STREAM[Copy_u8StreamNumber].SFCR), Copy_u8FIFOThreshold, SXFCR_FTH);
        break;
        default:
        break;
    }
}

void MDMA_voidSetNumberOfData(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u16 Copy_u16NumberOfData)
{
    switch (Copy_u8DMANumber)
    {
        case MDMA1:
            SET_REG((DMA1->STREAM[Copy_u8StreamNumber].SNDTR), Copy_u16NumberOfData);
        break;
        case MDMA2:
            SET_REG((DMA2->STREAM[Copy_u8StreamNumber].SNDTR), Copy_u16NumberOfData);
        break;
        default:
        break;
    }
}

void MDMA_voidSetPeripheralAddress(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u32 Copy_u32PeripheralAddress)
{
    switch (Copy_u8DMANumber)
    {
        case MDMA1:
            SET_REG((DMA1->STREAM[Copy_u8StreamNumber].SPAR), Copy_u32PeripheralAddress);
        break;
        case MDMA2:
            SET_REG((DMA2->STREAM[Copy_u8StreamNumber].SPAR), Copy_u32PeripheralAddress);
        break;
        default:
        break;
    }
}

void MDMA_voidSetMemory0Address(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u32 Copy_u32Memory0Address)
{
    switch (Copy_u8DMANumber)
    {
        case MDMA1:
            SET_REG((DMA1->STREAM[Copy_u8StreamNumber].SM0AR), Copy_u32Memory0Address);
        break;
        case MDMA2:
            SET_REG((DMA2->STREAM[Copy_u8StreamNumber].SM0AR), Copy_u32Memory0Address);
        break;
        default:
        break;
    }
}

void MDMA_voidSetMemory1Address(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u32 Copy_u32Memory1Address)
{
    switch (Copy_u8DMANumber)
    {
        case MDMA1:
            SET_REG((DMA1->STREAM[Copy_u8StreamNumber].SM1AR), Copy_u32Memory1Address);
        break;
        case MDMA2:
            SET_REG((DMA2->STREAM[Copy_u8StreamNumber].SM1AR), Copy_u32Memory1Address);
        break;
        default:
        break;
    }
}

void MDMA_voidSetInterruptStatus(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8InterruptType, u8 Copy_u8InterruptStatus)
{
    switch (Copy_u8DMANumber)
    {
        case MDMA1:
            if (Copy_u8InterruptType == FIFO_ERROR_INTERRUPT)
            {
                SET_MASK((DMA1->STREAM[Copy_u8StreamNumber].SFCR), MASK_1_BIT, Copy_u8InterruptType);
                SET_WORD((DMA1->STREAM[Copy_u8StreamNumber].SFCR), Copy_u8InterruptStatus, Copy_u8InterruptType);
            }
            else
            {
                SET_MASK((DMA1->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, Copy_u8InterruptType);
                SET_WORD((DMA1->STREAM[Copy_u8StreamNumber].SCR), Copy_u8InterruptStatus, Copy_u8InterruptType);
            }
        break;
        case MDMA2:
            if (Copy_u8InterruptType == FIFO_ERROR_INTERRUPT)
            {
                SET_MASK((DMA2->STREAM[Copy_u8StreamNumber].SFCR), MASK_1_BIT, Copy_u8InterruptType);
                SET_WORD((DMA2->STREAM[Copy_u8StreamNumber].SFCR), Copy_u8InterruptStatus, Copy_u8InterruptType);
            }
            else
            {
                SET_MASK((DMA2->STREAM[Copy_u8StreamNumber].SCR), MASK_1_BIT, Copy_u8InterruptType);
                SET_WORD((DMA2->STREAM[Copy_u8StreamNumber].SCR), Copy_u8InterruptStatus, Copy_u8InterruptType);
            }
        break;
        default:
        break;
    }
}

u8 MDMA_u8GetInterruptFlagStatus(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8InterruptFlag)
{
    u8 Local_u8FlagValue = 0;
    u8 Local_u8FlagBit = 0;
    switch (Copy_u8DMANumber)
    {
        case MDMA1:
            if (Copy_u8StreamNumber <= MDMA_STREAM3)
            {
                switch (Copy_u8StreamNumber)
                {
                    case MDMA_STREAM0:
                        Local_u8FlagBit = (Copy_u8InterruptFlag + LISR_FEIF0);
                    break;
                    case MDMA_STREAM1:
                        Local_u8FlagBit = (Copy_u8InterruptFlag + LISR_FEIF1);
                    break;
                    case MDMA_STREAM2:
                        Local_u8FlagBit = (Copy_u8InterruptFlag + LISR_FEIF2);
                    break;
                    case MDMA_STREAM3:
                        Local_u8FlagBit = (Copy_u8InterruptFlag + LISR_FEIF3);
                    break;                
                    default:
                    break;
                }
                Local_u8FlagValue = GET_BIT((DMA1->LISR), Local_u8FlagBit);
            }
            else if (Copy_u8StreamNumber <= MDMA_STREAM7)
            {
                switch (Copy_u8StreamNumber)
                {
                    case MDMA_STREAM0:
                        Local_u8FlagBit = (Copy_u8InterruptFlag + HISR_FEIF4);
                    break;
                    case MDMA_STREAM1:
                        Local_u8FlagBit = (Copy_u8InterruptFlag + HISR_FEIF5);
                    break;
                    case MDMA_STREAM2:
                        Local_u8FlagBit = (Copy_u8InterruptFlag + HISR_FEIF6);
                    break;
                    case MDMA_STREAM3:
                        Local_u8FlagBit = (Copy_u8InterruptFlag + HISR_FEIF7);
                    break;                
                    default:
                    break;
                }
                Local_u8FlagValue = GET_BIT((DMA1->HISR), Local_u8FlagBit);
            }
        break;
        case MDMA2:
            if (Copy_u8StreamNumber <= MDMA_STREAM3)
            {
                switch (Copy_u8StreamNumber)
                {
                    case MDMA_STREAM0:
                        Local_u8FlagBit = (Copy_u8InterruptFlag + LISR_FEIF0);
                    break;
                    case MDMA_STREAM1:
                        Local_u8FlagBit = (Copy_u8InterruptFlag + LISR_FEIF1);
                    break;
                    case MDMA_STREAM2:
                        Local_u8FlagBit = (Copy_u8InterruptFlag + LISR_FEIF2);
                    break;
                    case MDMA_STREAM3:
                        Local_u8FlagBit = (Copy_u8InterruptFlag + LISR_FEIF3);
                    break;                
                    default:
                    break;
                }
                Local_u8FlagValue = GET_BIT((DMA2->LISR), Local_u8FlagBit);
            }
            else if (Copy_u8StreamNumber <= MDMA_STREAM7)
            {
                switch (Copy_u8StreamNumber)
                {
                    case MDMA_STREAM0:
                        Local_u8FlagBit = (Copy_u8InterruptFlag + HISR_FEIF4);
                    break;
                    case MDMA_STREAM1:
                        Local_u8FlagBit = (Copy_u8InterruptFlag + HISR_FEIF5);
                    break;
                    case MDMA_STREAM2:
                        Local_u8FlagBit = (Copy_u8InterruptFlag + HISR_FEIF6);
                    break;
                    case MDMA_STREAM3:
                        Local_u8FlagBit = (Copy_u8InterruptFlag + HISR_FEIF7);
                    break;                
                    default:
                    break;
                }
                Local_u8FlagValue = GET_BIT((DMA2->HISR), Local_u8FlagBit);
            }
        break;
        default:
        break;
    }
    return Local_u8FlagValue;
}

void MDMA_voidClearInterruptFlag(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8InterruptFlag)
{
    u8 Local_u8FlagBit = 0;
    switch (Copy_u8DMANumber)
    {
        case MDMA1:
            if (Copy_u8StreamNumber <= MDMA_STREAM3)
            {
                switch (Copy_u8StreamNumber)
                {
                    case MDMA_STREAM0:
                        Local_u8FlagBit = (Copy_u8InterruptFlag + LIFCR_CFEIF0);
                    break;
                    case MDMA_STREAM1:
                        Local_u8FlagBit = (Copy_u8InterruptFlag + LIFCR_CFEIF1);
                    break;
                    case MDMA_STREAM2:
                        Local_u8FlagBit = (Copy_u8InterruptFlag + LIFCR_CFEIF2);
                    break;
                    case MDMA_STREAM3:
                        Local_u8FlagBit = (Copy_u8InterruptFlag + LIFCR_CFEIF3);
                    break;                
                    default:
                    break;
                }
                SET_BIT((DMA1->LIFCR), Local_u8FlagBit);
            }
            else if (Copy_u8StreamNumber <= MDMA_STREAM7)
            {
                switch (Copy_u8StreamNumber)
                {
                    case MDMA_STREAM0:
                        Local_u8FlagBit = (Copy_u8InterruptFlag + HIFCR_CFEIF4);
                    break;
                    case MDMA_STREAM1:
                        Local_u8FlagBit = (Copy_u8InterruptFlag + HIFCR_CFEIF5);
                    break;
                    case MDMA_STREAM2:
                        Local_u8FlagBit = (Copy_u8InterruptFlag + HIFCR_CFEIF6);
                    break;
                    case MDMA_STREAM3:
                        Local_u8FlagBit = (Copy_u8InterruptFlag + HIFCR_CFEIF7);
                    break;                
                    default:
                    break;
                }
                SET_BIT((DMA1->HIFCR), Local_u8FlagBit);
            }
        break;
        case MDMA2:
            if (Copy_u8StreamNumber <= MDMA_STREAM3)
            {
                switch (Copy_u8StreamNumber)
                {
                    case MDMA_STREAM0:
                        Local_u8FlagBit = (Copy_u8InterruptFlag + LIFCR_CFEIF0);
                    break;
                    case MDMA_STREAM1:
                        Local_u8FlagBit = (Copy_u8InterruptFlag + LIFCR_CFEIF1);
                    break;
                    case MDMA_STREAM2:
                        Local_u8FlagBit = (Copy_u8InterruptFlag + LIFCR_CFEIF2);
                    break;
                    case MDMA_STREAM3:
                        Local_u8FlagBit = (Copy_u8InterruptFlag + LIFCR_CFEIF3);
                    break;                
                    default:
                    break;
                }
                SET_BIT((DMA2->LIFCR), Local_u8FlagBit);
            }
            else if (Copy_u8StreamNumber <= MDMA_STREAM7)
            {
                switch (Copy_u8StreamNumber)
                {
                    case MDMA_STREAM0:
                        Local_u8FlagBit = (Copy_u8InterruptFlag + HIFCR_CFEIF4);
                    break;
                    case MDMA_STREAM1:
                        Local_u8FlagBit = (Copy_u8InterruptFlag + HIFCR_CFEIF5);
                    break;
                    case MDMA_STREAM2:
                        Local_u8FlagBit = (Copy_u8InterruptFlag + HIFCR_CFEIF6);
                    break;
                    case MDMA_STREAM3:
                        Local_u8FlagBit = (Copy_u8InterruptFlag + HIFCR_CFEIF7);
                    break;                
                    default:
                    break;
                }
                SET_BIT((DMA2->HIFCR), Local_u8FlagBit);
            }
        break;
        default:
        break;
    }
}

void MDMA_voidEnableAllInterrupts(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber)
{
    MDMA_voidSetInterruptStatus(Copy_u8DMANumber, Copy_u8StreamNumber, FIFO_ERROR_INTERRUPT, MDMA_INTERRUPT_ENABLE);
    MDMA_voidSetInterruptStatus(Copy_u8DMANumber, Copy_u8StreamNumber, TRANSFER_COMPLETE_INTERRUPT, MDMA_INTERRUPT_ENABLE);
    MDMA_voidSetInterruptStatus(Copy_u8DMANumber, Copy_u8StreamNumber, HALF_TRANSFER_INTERRUPT, MDMA_INTERRUPT_ENABLE);
    MDMA_voidSetInterruptStatus(Copy_u8DMANumber, Copy_u8StreamNumber, TRANSFER_ERROR_INTERRUPT, MDMA_INTERRUPT_ENABLE);
    MDMA_voidSetInterruptStatus(Copy_u8DMANumber, Copy_u8StreamNumber, DIRECT_MODE_ERROR_INTERRUPT, MDMA_INTERRUPT_ENABLE);
}

void MDMA_voidDisableAllInterrupts(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber)
{
    MDMA_voidSetInterruptStatus(Copy_u8DMANumber, Copy_u8StreamNumber, FIFO_ERROR_INTERRUPT, MDMA_INTERRUPT_DISABLE);
    MDMA_voidSetInterruptStatus(Copy_u8DMANumber, Copy_u8StreamNumber, TRANSFER_COMPLETE_INTERRUPT, MDMA_INTERRUPT_DISABLE);
    MDMA_voidSetInterruptStatus(Copy_u8DMANumber, Copy_u8StreamNumber, HALF_TRANSFER_INTERRUPT, MDMA_INTERRUPT_DISABLE);
    MDMA_voidSetInterruptStatus(Copy_u8DMANumber, Copy_u8StreamNumber, TRANSFER_ERROR_INTERRUPT, MDMA_INTERRUPT_DISABLE);
    MDMA_voidSetInterruptStatus(Copy_u8DMANumber, Copy_u8StreamNumber, DIRECT_MODE_ERROR_INTERRUPT, MDMA_INTERRUPT_DISABLE);
}

void MDMA_voidClearAllInterruptFlags(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber)
{
    MDMA_voidClearInterruptFlag(Copy_u8DMANumber, Copy_u8StreamNumber, TRANSFER_COMPLETE_FLAG);
    MDMA_voidClearInterruptFlag(Copy_u8DMANumber, Copy_u8StreamNumber, HALF_TRANSFER_FLAG);
    MDMA_voidClearInterruptFlag(Copy_u8DMANumber, Copy_u8StreamNumber, TRANSFER_ERROR_FLAG);
    MDMA_voidClearInterruptFlag(Copy_u8DMANumber, Copy_u8StreamNumber, DIRECT_MODE_ERROR_FLAG);
    MDMA_voidClearInterruptFlag(Copy_u8DMANumber, Copy_u8StreamNumber, FIFO_ERROR_FLAG);
}

void MDMA_voidDirectModeP2M(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8ChannelNumber, u16 Copy_u16NumberOfData,
                            u32 Copy_u32PeripheralAddress, u32 Copy_u32MemoryAddress, u8 Copy_u8PriorityLevel, u8 Copy_u8DataSize, 
                            u8 Copy_u8PeripheralIncrementMode, u8 Copy_u8MemoryIncrementMode, u8 Copy_u8PeripheralFlowController)
{
    MDMA_voidSelectChannel(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8ChannelNumber);
    MDMA_voidSetNumberOfData(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u16NumberOfData);
    MDMA_voidSetPeripheralAddress(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u32PeripheralAddress);
    MDMA_voidSetMemory0Address(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u32MemoryAddress);
    MDMA_voidSetMemoryBurst(Copy_u8DMANumber, Copy_u8StreamNumber, MDMA_SINGLE_TRANSFER);
    MDMA_voidSetPeripheralBurst(Copy_u8DMANumber, Copy_u8StreamNumber, MDMA_SINGLE_TRANSFER);
    MDMA_voidPeripheralIncrementOffsetStatus(Copy_u8DMANumber, Copy_u8StreamNumber, LINKED_TO_PSIZE);
    MDMA_voidSetPriorityLevel(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8PriorityLevel);
    MDMA_voidSetMemoryDataSize(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8DataSize);
    MDMA_voidSetPeripheralDataSize(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8DataSize);
    MDMA_voidSetMemoryIncrementMode(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8MemoryIncrementMode);
    MDMA_voidSetPeripheralIncrementMode(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8PeripheralIncrementMode);
    MDMA_voidSetDataTransferDirection(Copy_u8DMANumber, Copy_u8StreamNumber, PERIPHERAL_TO_MEMORY);
    MDMA_voidSetPeripheralFlowController(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8PeripheralFlowController);
    MDMA_voidSetDirectModeStatus(Copy_u8DMANumber, Copy_u8StreamNumber, DIRECT_MODE_ENABLE);
    MDMA_voidClearAllInterruptFlags(Copy_u8DMANumber, Copy_u8StreamNumber);
    MDMA_voidStreamStatus(Copy_u8DMANumber, Copy_u8StreamNumber, MDMA_STREAM_ENABLE);
}

void MDMA_voidFIFOModeP2M(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8ChannelNumber, u16 Copy_u16NumberOfData,
                          u32 Copy_u32PeripheralAddress, u32 Copy_u32MemoryAddress, u8 Copy_u8PriorityLevel, u8 Copy_u8PeripheralDataSize,
                          u8 Copy_u8MemoryDataSize, u8 Copy_u8PeripheralBurstBeat, u8 Copy_u8MemoryBurstBeat, u8 Copy_u8PeripheralIncrementOffsetStatus,
                          u8 Copy_u8PeripheralIncrementMode, u8 Copy_u8MemoryIncrementMode, u8 Copy_u8PeripheralFlowController, u8 Copy_u8FIFOThreshold)
{
    MDMA_voidSelectChannel(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8ChannelNumber);
    MDMA_voidSetNumberOfData(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u16NumberOfData);
    MDMA_voidSetPeripheralAddress(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u32PeripheralAddress);
    MDMA_voidSetMemory0Address(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u32MemoryAddress);
    MDMA_voidSetMemoryBurst(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8MemoryBurstBeat);
    MDMA_voidSetPeripheralBurst(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8PeripheralBurstBeat);
    MDMA_voidSetPriorityLevel(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8PriorityLevel);
    if ((Copy_u8PeripheralIncrementMode != ADDRESS_POINTER_FIXED) && (Copy_u8PeripheralBurstBeat == MDMA_SINGLE_TRANSFER))
    {
        MDMA_voidPeripheralIncrementOffsetStatus(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8PeripheralIncrementOffsetStatus);
    }
    MDMA_voidSetMemoryDataSize(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8MemoryDataSize);
    MDMA_voidSetPeripheralDataSize(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8PeripheralDataSize);
    MDMA_voidSetMemoryIncrementMode(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8MemoryIncrementMode);
    MDMA_voidSetPeripheralIncrementMode(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8PeripheralIncrementMode);
    MDMA_voidSetDataTransferDirection(Copy_u8DMANumber, Copy_u8StreamNumber, PERIPHERAL_TO_MEMORY);
    MDMA_voidSetPeripheralFlowController(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8PeripheralFlowController);
    MDMA_voidSetDirectModeStatus(Copy_u8DMANumber, Copy_u8StreamNumber, DIRECT_MODE_DISABLE);
    MDMA_voidSelectFIFOThreshold(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8FIFOThreshold);
    MDMA_voidClearAllInterruptFlags(Copy_u8DMANumber, Copy_u8StreamNumber);
    MDMA_voidStreamStatus(Copy_u8DMANumber, Copy_u8StreamNumber, MDMA_STREAM_ENABLE);
}

void MDMA_voidDirectModeM2P(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8ChannelNumber, u16 Copy_u16NumberOfData,
                            u32 Copy_u32PeripheralAddress, u32 Copy_u32MemoryAddress, u8 Copy_u8PriorityLevel, u8 Copy_u8DataSize, 
                            u8 Copy_u8PeripheralIncrementMode, u8 Copy_u8MemoryIncrementMode, u8 Copy_u8PeripheralFlowController)
{
    MDMA_voidSelectChannel(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8ChannelNumber);
    MDMA_voidSetNumberOfData(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u16NumberOfData);
    MDMA_voidSetPeripheralAddress(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u32PeripheralAddress);
    MDMA_voidSetMemory0Address(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u32MemoryAddress);
    MDMA_voidSetMemoryBurst(Copy_u8DMANumber, Copy_u8StreamNumber, MDMA_SINGLE_TRANSFER);
    MDMA_voidSetPeripheralBurst(Copy_u8DMANumber, Copy_u8StreamNumber, MDMA_SINGLE_TRANSFER);
    MDMA_voidPeripheralIncrementOffsetStatus(Copy_u8DMANumber, Copy_u8StreamNumber, LINKED_TO_PSIZE);
    MDMA_voidSetPriorityLevel(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8PriorityLevel);
    MDMA_voidSetMemoryDataSize(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8DataSize);
    MDMA_voidSetPeripheralDataSize(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8DataSize);
    MDMA_voidSetMemoryIncrementMode(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8MemoryIncrementMode);
    MDMA_voidSetPeripheralIncrementMode(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8PeripheralIncrementMode);
    MDMA_voidSetDataTransferDirection(Copy_u8DMANumber, Copy_u8StreamNumber, MEMORY_TO_PERIPHERAL);
    MDMA_voidSetPeripheralFlowController(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8PeripheralFlowController);
    MDMA_voidSetDirectModeStatus(Copy_u8DMANumber, Copy_u8StreamNumber, DIRECT_MODE_ENABLE);
    MDMA_voidClearAllInterruptFlags(Copy_u8DMANumber, Copy_u8StreamNumber);
    MDMA_voidStreamStatus(Copy_u8DMANumber, Copy_u8StreamNumber, MDMA_STREAM_ENABLE);
}

void MDMA_voidFIFOModeM2P(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8ChannelNumber, u16 Copy_u16NumberOfData,
                          u32 Copy_u32PeripheralAddress, u32 Copy_u32MemoryAddress, u8 Copy_u8PriorityLevel, u8 Copy_u8PeripheralDataSize,
                          u8 Copy_u8MemoryDataSize, u8 Copy_u8PeripheralBurstBeat, u8 Copy_u8MemoryBurstBeat, u8 Copy_u8PeripheralIncrementOffsetStatus,
                          u8 Copy_u8PeripheralIncrementMode, u8 Copy_u8MemoryIncrementMode, u8 Copy_u8PeripheralFlowController, u8 Copy_u8FIFOThreshold)
{
    MDMA_voidSelectChannel(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8ChannelNumber);
    MDMA_voidSetNumberOfData(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u16NumberOfData);
    MDMA_voidSetPeripheralAddress(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u32PeripheralAddress);
    MDMA_voidSetMemory0Address(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u32MemoryAddress);
    MDMA_voidSetMemoryBurst(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8MemoryBurstBeat);
    MDMA_voidSetPeripheralBurst(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8PeripheralBurstBeat);
    MDMA_voidSetPriorityLevel(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8PriorityLevel);
    if ((Copy_u8PeripheralIncrementMode != ADDRESS_POINTER_FIXED) && (Copy_u8PeripheralBurstBeat == MDMA_SINGLE_TRANSFER))
    {
        MDMA_voidPeripheralIncrementOffsetStatus(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8PeripheralIncrementOffsetStatus);
    }
    MDMA_voidSetMemoryDataSize(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8MemoryDataSize);
    MDMA_voidSetPeripheralDataSize(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8PeripheralDataSize);
    MDMA_voidSetMemoryIncrementMode(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8MemoryIncrementMode);
    MDMA_voidSetPeripheralIncrementMode(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8PeripheralIncrementMode);
    MDMA_voidSetDataTransferDirection(Copy_u8DMANumber, Copy_u8StreamNumber, MEMORY_TO_PERIPHERAL);
    MDMA_voidSetPeripheralFlowController(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8PeripheralFlowController);
    MDMA_voidSetDirectModeStatus(Copy_u8DMANumber, Copy_u8StreamNumber, DIRECT_MODE_DISABLE);
    MDMA_voidSelectFIFOThreshold(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8FIFOThreshold);
    MDMA_voidClearAllInterruptFlags(Copy_u8DMANumber, Copy_u8StreamNumber);
    MDMA_voidStreamStatus(Copy_u8DMANumber, Copy_u8StreamNumber, MDMA_STREAM_ENABLE);
}

void MDMA_voidM2M(u8 Copy_u8StreamNumber, u16 Copy_u16NumberOfData, u32 Copy_u32PeripheralAddress,
                  u32 Copy_u32MemoryAddress, u8 Copy_u8PriorityLevel, u8 Copy_u8PeripheralDataSize, u8 Copy_u8MemoryDataSize,
                  u8 Copy_u8PeripheralBurstBeat, u8 Copy_u8MemoryBurstBeat, u8 Copy_u8PeripheralIncrementOffsetStatus,
                  u8 Copy_u8PeripheralIncrementMode, u8 Copy_u8MemoryIncrementMode, u8 Copy_u8FIFOThreshold)
{
    MDMA_voidSetNumberOfData(MDMA2, Copy_u8StreamNumber, Copy_u16NumberOfData);
    MDMA_voidSetPeripheralAddress(MDMA2, Copy_u8StreamNumber, Copy_u32PeripheralAddress);
    MDMA_voidSetMemory0Address(MDMA2, Copy_u8StreamNumber, Copy_u32MemoryAddress);
    MDMA_voidSetMemoryBurst(MDMA2, Copy_u8StreamNumber, Copy_u8MemoryBurstBeat);
    MDMA_voidSetPeripheralBurst(MDMA2, Copy_u8StreamNumber, Copy_u8PeripheralBurstBeat);
    MDMA_voidSetPriorityLevel(MDMA2, Copy_u8StreamNumber, Copy_u8PriorityLevel);
    if ((Copy_u8PeripheralIncrementMode != ADDRESS_POINTER_FIXED) && (Copy_u8PeripheralBurstBeat == MDMA_SINGLE_TRANSFER))
    {
        MDMA_voidPeripheralIncrementOffsetStatus(MDMA2, Copy_u8StreamNumber, Copy_u8PeripheralIncrementOffsetStatus);
    }
    MDMA_voidSetMemoryDataSize(MDMA2, Copy_u8StreamNumber, Copy_u8MemoryDataSize);
    MDMA_voidSetPeripheralDataSize(MDMA2, Copy_u8StreamNumber, Copy_u8PeripheralDataSize);
    MDMA_voidSetMemoryIncrementMode(MDMA2, Copy_u8StreamNumber, Copy_u8MemoryIncrementMode);
    MDMA_voidSetPeripheralIncrementMode(MDMA2, Copy_u8StreamNumber, Copy_u8PeripheralIncrementMode);
    MDMA_voidSetDataTransferDirection(MDMA2, Copy_u8StreamNumber, MEMORY_TO_MEMORY);
    MDMA_voidSetPeripheralFlowController(MDMA2, Copy_u8StreamNumber, DMA_IS_FLOW_CONTROLLER);
    MDMA_voidSetDirectModeStatus(MDMA2, Copy_u8StreamNumber, DIRECT_MODE_DISABLE);
    MDMA_voidSelectFIFOThreshold(MDMA2, Copy_u8StreamNumber, Copy_u8FIFOThreshold);
    MDMA_voidClearAllInterruptFlags(MDMA2, Copy_u8StreamNumber);
    MDMA_voidStreamStatus(MDMA2, Copy_u8StreamNumber, MDMA_STREAM_ENABLE);
}

void MDMA_voidCircularDirectMode(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8ChannelNumber, u16 Copy_u16NumberOfData,
                                 u32 Copy_u32PeripheralAddress, u32 Copy_u32MemoryAddress, u8 Copy_u8PriorityLevel, u8 Copy_u8DataSize, 
                                 u8 Copy_u8PeripheralIncrementMode, u8 Copy_u8MemoryIncrementMode, u8 Copy_u8TransferDirection)
{
    MDMA_voidSelectChannel(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8ChannelNumber);
    MDMA_voidSetNumberOfData(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u16NumberOfData);
    MDMA_voidSetPeripheralAddress(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u32PeripheralAddress);
    MDMA_voidSetMemory0Address(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u32MemoryAddress);
    MDMA_voidSetMemoryBurst(Copy_u8DMANumber, Copy_u8StreamNumber, MDMA_SINGLE_TRANSFER);
    MDMA_voidSetPeripheralBurst(Copy_u8DMANumber, Copy_u8StreamNumber, MDMA_SINGLE_TRANSFER);
    MDMA_voidPeripheralIncrementOffsetStatus(Copy_u8DMANumber, Copy_u8StreamNumber, LINKED_TO_PSIZE);
    MDMA_voidSetPriorityLevel(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8PriorityLevel);
    MDMA_voidSetMemoryDataSize(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8DataSize);
    MDMA_voidSetPeripheralDataSize(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8DataSize);
    MDMA_voidSetMemoryIncrementMode(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8MemoryIncrementMode);
    MDMA_voidSetPeripheralIncrementMode(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8PeripheralIncrementMode);
    if (Copy_u8TransferDirection != MEMORY_TO_MEMORY)
    {
        MDMA_voidSetDataTransferDirection(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8TransferDirection);
    }
    MDMA_voidSetPeripheralFlowController(Copy_u8DMANumber, Copy_u8StreamNumber, DMA_IS_FLOW_CONTROLLER);
    MDMA_voidSetDirectModeStatus(Copy_u8DMANumber, Copy_u8StreamNumber, DIRECT_MODE_ENABLE);
    MDMA_voidCircularModeStatus(Copy_u8DMANumber, Copy_u8StreamNumber, ENABLE_CIRCULAR_MODE);
    MDMA_voidClearAllInterruptFlags(Copy_u8DMANumber, Copy_u8StreamNumber);
    MDMA_voidStreamStatus(Copy_u8DMANumber, Copy_u8StreamNumber, MDMA_STREAM_ENABLE);
}

void MDMA_voidCircularFIFOMode(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8ChannelNumber, u16 Copy_u16NumberOfData,
                               u32 Copy_u32PeripheralAddress, u32 Copy_u32MemoryAddress, u8 Copy_u8PriorityLevel, u8 Copy_u8PeripheralDataSize,
                               u8 Copy_u8MemoryDataSize, u8 Copy_u8PeripheralBurstBeat, u8 Copy_u8MemoryBurstBeat, u8 Copy_u8PeripheralIncrementOffsetStatus,
                               u8 Copy_u8PeripheralIncrementMode, u8 Copy_u8MemoryIncrementMode, u8 Copy_u8TransferDirection, u8 Copy_u8FIFOThreshold)
{
    MDMA_voidSelectChannel(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8ChannelNumber);
    MDMA_voidSetNumberOfData(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u16NumberOfData);
    MDMA_voidSetPeripheralAddress(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u32PeripheralAddress);
    MDMA_voidSetMemory0Address(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u32MemoryAddress);
    MDMA_voidSetMemoryBurst(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8MemoryBurstBeat);
    MDMA_voidSetPeripheralBurst(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8PeripheralBurstBeat);
    MDMA_voidSetPriorityLevel(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8PriorityLevel);
    if ((Copy_u8PeripheralIncrementMode != ADDRESS_POINTER_FIXED) && (Copy_u8PeripheralBurstBeat == MDMA_SINGLE_TRANSFER))
    {
        MDMA_voidPeripheralIncrementOffsetStatus(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8PeripheralIncrementOffsetStatus);
    }
    MDMA_voidSetMemoryDataSize(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8MemoryDataSize);
    MDMA_voidSetPeripheralDataSize(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8PeripheralDataSize);
    MDMA_voidSetMemoryIncrementMode(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8MemoryIncrementMode);
    if (Copy_u8TransferDirection != MEMORY_TO_MEMORY)
    {
        MDMA_voidSetDataTransferDirection(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8TransferDirection);
    }
    MDMA_voidSetPeripheralIncrementMode(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8PeripheralIncrementMode);
    MDMA_voidSetPeripheralFlowController(Copy_u8DMANumber, Copy_u8StreamNumber, DMA_IS_FLOW_CONTROLLER);
    MDMA_voidSetDirectModeStatus(Copy_u8DMANumber, Copy_u8StreamNumber, DIRECT_MODE_DISABLE);
    MDMA_voidCircularModeStatus(Copy_u8DMANumber, Copy_u8StreamNumber, ENABLE_CIRCULAR_MODE);
    MDMA_voidSelectFIFOThreshold(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8FIFOThreshold);
    MDMA_voidClearAllInterruptFlags(Copy_u8DMANumber, Copy_u8StreamNumber);
    MDMA_voidStreamStatus(Copy_u8DMANumber, Copy_u8StreamNumber, MDMA_STREAM_ENABLE);
}

void MDMA_voidDoubleBufferDirectMode(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8ChannelNumber, u16 Copy_u16NumberOfData,
                                     u32 Copy_u32PeripheralAddress, u32 Copy_u32Memory0Address, u32 Copy_u32Memory1Address, u8 Copy_u8CurrentTarget,
                                     u8 Copy_u8PriorityLevel, u8 Copy_u8DataSize, u8 Copy_u8PeripheralIncrementMode, u8 Copy_u8MemoryIncrementMode, u8 Copy_u8TransferDirection)
{
    MDMA_voidSelectChannel(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8ChannelNumber);
    MDMA_voidSetNumberOfData(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u16NumberOfData);
    MDMA_voidSetPeripheralAddress(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u32PeripheralAddress);
    MDMA_voidSetMemory0Address(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u32Memory0Address);
    MDMA_voidSetMemory1Address(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u32Memory1Address);
    MDMA_voidDoubleBufferStatus(Copy_u8DMANumber, Copy_u8StreamNumber, ENABLE_DOUBLE_BUFFER);
    MDMA_voidSetCurrentTarget(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8CurrentTarget);
    MDMA_voidSetMemoryBurst(Copy_u8DMANumber, Copy_u8StreamNumber, MDMA_SINGLE_TRANSFER);
    MDMA_voidSetPeripheralBurst(Copy_u8DMANumber, Copy_u8StreamNumber, MDMA_SINGLE_TRANSFER);
    MDMA_voidPeripheralIncrementOffsetStatus(Copy_u8DMANumber, Copy_u8StreamNumber, LINKED_TO_PSIZE);
    MDMA_voidSetPriorityLevel(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8PriorityLevel);
    MDMA_voidSetMemoryDataSize(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8DataSize);
    MDMA_voidSetPeripheralDataSize(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8DataSize);
    MDMA_voidSetMemoryIncrementMode(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8MemoryIncrementMode);
    MDMA_voidSetPeripheralIncrementMode(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8PeripheralIncrementMode);
    if (Copy_u8TransferDirection != MEMORY_TO_MEMORY)
    {
        MDMA_voidSetDataTransferDirection(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8TransferDirection);
    }
    MDMA_voidSetPeripheralFlowController(Copy_u8DMANumber, Copy_u8StreamNumber, DMA_IS_FLOW_CONTROLLER);
    MDMA_voidSetDirectModeStatus(Copy_u8DMANumber, Copy_u8StreamNumber, DIRECT_MODE_ENABLE);
    MDMA_voidCircularModeStatus(Copy_u8DMANumber, Copy_u8StreamNumber, ENABLE_CIRCULAR_MODE);
    MDMA_voidClearAllInterruptFlags(Copy_u8DMANumber, Copy_u8StreamNumber);
    MDMA_voidStreamStatus(Copy_u8DMANumber, Copy_u8StreamNumber, MDMA_STREAM_ENABLE);
}

void MDMA_voidDoubleBufferFIFOMode(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8ChannelNumber, u16 Copy_u16NumberOfData,
                                   u32 Copy_u32PeripheralAddress, u32 Copy_u32Memory0Address, u32 Copy_u32Memory1Address, u8 Copy_u8CurrentTarget,
                                   u8 Copy_u8PriorityLevel, u8 Copy_u8PeripheralDataSize, u8 Copy_u8MemoryDataSize, u8 Copy_u8PeripheralBurstBeat, 
                                   u8 Copy_u8MemoryBurstBeat, u8 Copy_u8PeripheralIncrementOffsetStatus, u8 Copy_u8PeripheralIncrementMode, 
                                   u8 Copy_u8MemoryIncrementMode, u8 Copy_u8TransferDirection, u8 Copy_u8FIFOThreshold)
{
    MDMA_voidSelectChannel(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8ChannelNumber);
    MDMA_voidSetNumberOfData(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u16NumberOfData);
    MDMA_voidSetPeripheralAddress(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u32PeripheralAddress);
    MDMA_voidSetMemory0Address(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u32Memory0Address);
    MDMA_voidSetMemory1Address(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u32Memory1Address);
    MDMA_voidDoubleBufferStatus(Copy_u8DMANumber, Copy_u8StreamNumber, ENABLE_DOUBLE_BUFFER);
    MDMA_voidSetCurrentTarget(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8CurrentTarget);
    MDMA_voidSetMemoryBurst(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8MemoryBurstBeat);
    MDMA_voidSetPeripheralBurst(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8PeripheralBurstBeat);
    MDMA_voidSetPriorityLevel(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8PriorityLevel);
    if ((Copy_u8PeripheralIncrementMode != ADDRESS_POINTER_FIXED) && (Copy_u8PeripheralBurstBeat == MDMA_SINGLE_TRANSFER))
    {
        MDMA_voidPeripheralIncrementOffsetStatus(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8PeripheralIncrementOffsetStatus);
    }
    MDMA_voidSetMemoryDataSize(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8MemoryDataSize);
    MDMA_voidSetPeripheralDataSize(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8PeripheralDataSize);
    MDMA_voidSetMemoryIncrementMode(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8MemoryIncrementMode);
    if (Copy_u8TransferDirection != MEMORY_TO_MEMORY)
    {
        MDMA_voidSetDataTransferDirection(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8TransferDirection);
    }
    MDMA_voidSetPeripheralIncrementMode(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8PeripheralIncrementMode);
    MDMA_voidSetPeripheralFlowController(Copy_u8DMANumber, Copy_u8StreamNumber, DMA_IS_FLOW_CONTROLLER);
    MDMA_voidSetDirectModeStatus(Copy_u8DMANumber, Copy_u8StreamNumber, DIRECT_MODE_DISABLE);
    MDMA_voidCircularModeStatus(Copy_u8DMANumber, Copy_u8StreamNumber, ENABLE_CIRCULAR_MODE);
    MDMA_voidSelectFIFOThreshold(Copy_u8DMANumber, Copy_u8StreamNumber, Copy_u8FIFOThreshold);
    MDMA_voidClearAllInterruptFlags(Copy_u8DMANumber, Copy_u8StreamNumber);
    MDMA_voidStreamStatus(Copy_u8DMANumber, Copy_u8StreamNumber, MDMA_STREAM_ENABLE);
}

void MDMA_voidSetCallBack(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, void (*pvNotificationFunction)(void))
{
    switch (Copy_u8DMANumber)
    {
        case MDMA1:
            pvCallBack1[Copy_u8StreamNumber] = pvNotificationFunction;
        break;
        case MDMA2:
            pvCallBack2[Copy_u8StreamNumber] = pvNotificationFunction;
        break;
        default:
        break;
    }
}

/************* DMA ISR ******************/

void DMA1_Stream0_IRQHandler(void)
{
    if (pvCallBack1[0] != NULL)
    {
        pvCallBack1[0]();
    }
}

void DMA1_Stream1_IRQHandler(void)
{
    if (pvCallBack1[1] != NULL)
    {
        pvCallBack1[1]();
    }
}

void DMA1_Stream2_IRQHandler(void)
{
    if (pvCallBack1[2] != NULL)
    {
        pvCallBack1[2]();
    }
}

void DMA1_Stream3_IRQHandler(void)
{
    if (pvCallBack1[3] != NULL)
    {
        pvCallBack1[3]();
    }
}

void DMA1_Stream4_IRQHandler(void)
{
    if (pvCallBack1[4] != NULL)
    {
        pvCallBack1[4]();
    }
}

void DMA1_Stream5_IRQHandler(void)
{
    if (pvCallBack1[5] != NULL)
    {
        pvCallBack1[5]();
    }
}

void DMA1_Stream6_IRQHandler(void)
{
    if (pvCallBack1[6] != NULL)
    {
        pvCallBack1[6]();
    }
}

void DMA1_Stream7_IRQHandler(void)
{
    if (pvCallBack1[7] != NULL)
    {
        pvCallBack1[7]();
    }
}

void DMA2_Stream0_IRQHandler(void)
{
    if (pvCallBack2[0] != NULL)
    {
        pvCallBack2[0]();
    }
}

void DMA2_Stream1_IRQHandler(void)
{
    if (pvCallBack2[1] != NULL)
    {
        pvCallBack2[1]();
    }
}

void DMA2_Stream2_IRQHandler(void)
{
    if (pvCallBack2[2] != NULL)
    {
        pvCallBack2[2]();
    }
}

void DMA2_Stream3_IRQHandler(void)
{
    if (pvCallBack2[3] != NULL)
    {
        pvCallBack2[3]();
    }
}

void DMA2_Stream4_IRQHandler(void)
{
    if (pvCallBack2[4] != NULL)
    {
        pvCallBack2[4]();
    }
}

void DMA2_Stream5_IRQHandler(void)
{
    if (pvCallBack2[5] != NULL)
    {
        pvCallBack2[5]();
    }
}

void DMA2_Stream6_IRQHandler(void)
{
    if (pvCallBack2[6] != NULL)
    {
        pvCallBack2[6]();
    }
}

void DMA2_Stream7_IRQHandler(void)
{
    if (pvCallBack2[7] != NULL)
    {
        pvCallBack2[7]();
    }
}