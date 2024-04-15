/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        21 MAY, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 MCAL
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         21 MAY, 2023      Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/


#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "NVIC_interface.h"
#include "NVIC_config.h"
#include "NVIC_private.h"


void MNVIC_voidInit(void)
{
    /* Simple Funcion for single specific group, Don't use with complex code */
    /* Set Group and Sub Priorities Distribution */
    SCB_AIRCR = ((AIRCR_PRIVKEY << NUMBER_16) | (MNVIC_GRP_SUB_DISTRIBUTION << NUMBER_8));
}

void MNVIC_voidEnablePeripheralInterrupt(u8 Copy_u8PeripheralID)
{
    u8 Local_u8ISERIndex;
    Local_u8ISERIndex = (Copy_u8PeripheralID / NUMBER_32);
    (NVIC -> ISER[Local_u8ISERIndex]) = (NUMBER_1 << (Copy_u8PeripheralID % NUMBER_32));
}

void MNVIC_voidDisablePeripheralInterrupt(u8 Copy_u8PeripheralID)
{
    u8 Local_u8ICERIndex;
    Local_u8ICERIndex = (Copy_u8PeripheralID / NUMBER_32);
    (NVIC -> ICER[Local_u8ICERIndex]) = (NUMBER_1 << (Copy_u8PeripheralID % NUMBER_32));
}

void MNVIC_voidSetPendingFlag(u8 Copy_u8PeripheralID)
{
    u8 Local_u8ISPRIndex;
    Local_u8ISPRIndex = (Copy_u8PeripheralID / NUMBER_32);
    (NVIC -> ISPR[Local_u8ISPRIndex]) = (NUMBER_1 << (Copy_u8PeripheralID % NUMBER_32));
}

void MNVIC_voidClearPendingFlag(u8 Copy_u8PeripheralID)
{
    u8 Local_u8ICPRIndex;
    Local_u8ICPRIndex = (Copy_u8PeripheralID / NUMBER_32);
    (NVIC -> ICPR[Local_u8ICPRIndex]) = (NUMBER_1 << (Copy_u8PeripheralID % NUMBER_32));
}

u8 MNVIC_u8GetActiveFlag(u8 Copy_u8PeripheralID)
{
    u8 Local_u8ActiveFlag;
    Local_u8ActiveFlag = GET_BIT((NVIC -> IABR[Copy_u8PeripheralID / NUMBER_32]), (Copy_u8PeripheralID % NUMBER_32));
	return Local_u8ActiveFlag;
}

void MNVIC_voidSetPeripheralPriority(s8 Copy_u8PeripheralID, u8 Copy_u8Priority)
{
    (NVIC -> IPR[Copy_u8PeripheralID]) = (Copy_u8Priority << NUMBER_4);
}

void MNVIC_voidSetSoftwareTriggerInterrupt(u16 Copy_u16InterruptID)
{
    /* ID is the number of IRQn (0:240) and exceptions by n-16 */
    (NVIC -> STIR) &= (~((STIR_MSK) << (STIR_INTID8 + 1)));
    (NVIC -> STIR) |= (Copy_u16InterruptID << STIR_INTID0);
}