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

#include "SYSCFG_interface.h"
#include "SYSCFG_private.h"
#include "SYSCFG_config.h"


void MSYSCFG_voidSetMemoryMapping(u8 Copy_u8MemoryMappingSelection)
{
	(SYSCFG -> MEMRMP) |= ((Copy_u8MemoryMappingSelection) << (MEMRMP_MEM_MODE));
}

u8 MSYSCFG_voidGetBOOTMode(void)
{
	u8 Local_u8BOOTValue = (((GET_REG((SYSCFG->MEMRMP))) << (31 - MEMRMP_MEM_MODE1)) >> (31 - MEMRMP_MEM_MODE1));
	return Local_u8BOOTValue;
}

void MSYSCFG_voidImproveADC1Accuracy(void)
{
	SET_BIT((SYSCFG->PMC),PMC_ADC1DC2);
}

void MSYSCFG_voidSetEXTIConfiguration(u8 Copy_u8EXTILINE, u8 Copy_u8PortMap)
{
	if (Copy_u8EXTILINE <= 3)
    {
        (SYSCFG -> EXTICR1) &= (~((PORT_MAP_MASK) << (Copy_u8EXTILINE * 4)));
	    (SYSCFG -> EXTICR1) |= ((Copy_u8PortMap) << (Copy_u8EXTILINE * 4));
	}
	else if (Copy_u8EXTILINE <= 7)
    {
		Copy_u8EXTILINE -= 4;
        (SYSCFG -> EXTICR2) &= (~((PORT_MAP_MASK) << (Copy_u8EXTILINE * 4)));
	    (SYSCFG -> EXTICR2) |= ((Copy_u8PortMap) << (Copy_u8EXTILINE * 4));
	}
	else if (Copy_u8EXTILINE <= 11)
    {
		Copy_u8EXTILINE -= 8;
        (SYSCFG -> EXTICR3) &= (~((PORT_MAP_MASK) << (Copy_u8EXTILINE * 4)));
	    (SYSCFG -> EXTICR3) |= ((Copy_u8PortMap) << (Copy_u8EXTILINE * 4));
	}
	else if (Copy_u8EXTILINE <= 15)
    {
		Copy_u8EXTILINE -= 12;
        (SYSCFG -> EXTICR4) &= (~((PORT_MAP_MASK) << (Copy_u8EXTILINE * 4)));
	    (SYSCFG -> EXTICR4) |= ((Copy_u8PortMap) << (Copy_u8EXTILINE * 4));
	}
}

u8 MSYSCFG_voidIsCompensationCellReady(void)
{
	return (GET_BIT((SYSCFG->CMPCR), CMPCR_READY));
}

void MSYSCFG_voidIsCompensationCellStatus(u8 Copy_u8CellStatus)
{
	if (Copy_u8CellStatus == MSYSCFG_COMPENSATION_CELL_POWER_DOWN)
	{
		CLR_BIT((SYSCFG->CMPCR), CMPCR_CMP_PD);
	}
	else if (Copy_u8CellStatus == MSYSCFG_COMPENSATION_CELL_ENABLE)
	{
		SET_BIT((SYSCFG->CMPCR), CMPCR_CMP_PD);
	}
}