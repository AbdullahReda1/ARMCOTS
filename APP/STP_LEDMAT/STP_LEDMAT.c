/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        29 MAY, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 APP
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         29 MAY, 2023      Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/RCC/RCC_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/STK/STK_interface.h"

#include "STP_LEDMAT.h"


static void HSTPLEDMAT_voidWriteByteROW(STP_LEDMAT_t * STP_LEDMAT_ROW_obj, u8 Copy_u8DataByte);
static void HSTPLEDMAT_voidWriteByteCOL(STP_LEDMAT_t * STP_LEDMAT_COL_obj, u8 Copy_u8DataByte);
static void HSTPLEDMAT_voidDisableColumns(STP_LEDMAT_t * STP_LEDMAT_COL_obj);


void HSTPLEDMAT_voidInit(STP_LEDMAT_t * STP_LEDMAT_ROW_obj, STP_LEDMAT_t * STP_LEDMAT_COL_obj)
{
    MRCC_voidInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB1, (STP_LEDMAT_ROW_obj->PORT));
    MRCC_voidEnablePeripheralClock(RCC_AHB1, (STP_LEDMAT_COL_obj->PORT));

    MGPIO_voidSetPinMode((STP_LEDMAT_ROW_obj->PORT), (STP_LEDMAT_ROW_obj->DATA_PIN), OUTPUT_MODE);
    MGPIO_voidSetOutputType((STP_LEDMAT_ROW_obj->PORT), (STP_LEDMAT_ROW_obj->DATA_PIN), PUSH_PULL);
    MGPIO_voidSetOutputSpeed((STP_LEDMAT_ROW_obj->PORT), (STP_LEDMAT_ROW_obj->DATA_PIN), LOW_SPEED_2MHZ);

    MGPIO_voidSetPinMode((STP_LEDMAT_ROW_obj->PORT), (STP_LEDMAT_ROW_obj->SHIFT_BIT_PIN), OUTPUT_MODE);
    MGPIO_voidSetOutputType((STP_LEDMAT_ROW_obj->PORT), (STP_LEDMAT_ROW_obj->SHIFT_BIT_PIN), PUSH_PULL);
    MGPIO_voidSetOutputSpeed((STP_LEDMAT_ROW_obj->PORT), (STP_LEDMAT_ROW_obj->SHIFT_BIT_PIN), LOW_SPEED_2MHZ);

    MGPIO_voidSetPinMode((STP_LEDMAT_ROW_obj->PORT), (STP_LEDMAT_ROW_obj->SHIFT_BYTE_PIN), OUTPUT_MODE);
    MGPIO_voidSetOutputType((STP_LEDMAT_ROW_obj->PORT), (STP_LEDMAT_ROW_obj->SHIFT_BYTE_PIN), PUSH_PULL);
    MGPIO_voidSetOutputSpeed((STP_LEDMAT_ROW_obj->PORT), (STP_LEDMAT_ROW_obj->SHIFT_BYTE_PIN), LOW_SPEED_2MHZ);

    MGPIO_voidSetPinMode((STP_LEDMAT_COL_obj->PORT), (STP_LEDMAT_COL_obj->DATA_PIN), OUTPUT_MODE);
    MGPIO_voidSetOutputType((STP_LEDMAT_COL_obj->PORT), (STP_LEDMAT_COL_obj->DATA_PIN), PUSH_PULL);
    MGPIO_voidSetOutputSpeed((STP_LEDMAT_COL_obj->PORT), (STP_LEDMAT_COL_obj->DATA_PIN), LOW_SPEED_2MHZ);

    MGPIO_voidSetPinMode((STP_LEDMAT_COL_obj->PORT), (STP_LEDMAT_COL_obj->SHIFT_BIT_PIN), OUTPUT_MODE);
    MGPIO_voidSetOutputType((STP_LEDMAT_COL_obj->PORT), (STP_LEDMAT_COL_obj->SHIFT_BIT_PIN), PUSH_PULL);
    MGPIO_voidSetOutputSpeed((STP_LEDMAT_COL_obj->PORT), (STP_LEDMAT_COL_obj->SHIFT_BIT_PIN), LOW_SPEED_2MHZ);

    MGPIO_voidSetPinMode((STP_LEDMAT_COL_obj->PORT), (STP_LEDMAT_COL_obj->SHIFT_BYTE_PIN), OUTPUT_MODE);
    MGPIO_voidSetOutputType((STP_LEDMAT_COL_obj->PORT), (STP_LEDMAT_COL_obj->SHIFT_BYTE_PIN), PUSH_PULL);
    MGPIO_voidSetOutputSpeed((STP_LEDMAT_COL_obj->PORT), (STP_LEDMAT_COL_obj->SHIFT_BYTE_PIN), LOW_SPEED_2MHZ);

	MSTK_voidInit();

    HSTPLEDMAT_voidDisableColumns(STP_LEDMAT_COL_obj);
}

static void HSTPLEDMAT_voidWriteByteROW(STP_LEDMAT_t * STP_LEDMAT_ROW_obj, u8 Copy_u8DataByte)
{
    u8 Local_u8Iterator;
    MGPIO_voidSetPinValue((STP_LEDMAT_ROW_obj->PORT), (STP_LEDMAT_ROW_obj->SHIFT_BYTE_PIN), LOW);
    for (Local_u8Iterator = 8; Local_u8Iterator > 0; Local_u8Iterator--)
    {
        MGPIO_voidSetPinValue((STP_LEDMAT_ROW_obj->PORT), (STP_LEDMAT_ROW_obj->DATA_PIN), (GET_BIT(Copy_u8DataByte, (Local_u8Iterator - 1))));
        MGPIO_voidSetPinValue((STP_LEDMAT_ROW_obj->PORT), (STP_LEDMAT_ROW_obj->SHIFT_BIT_PIN), HIGH);
        MSTK_voidSetMicroBusyWait(1);
        MGPIO_voidSetPinValue((STP_LEDMAT_ROW_obj->PORT), (STP_LEDMAT_ROW_obj->SHIFT_BIT_PIN), LOW);
    }
    MGPIO_voidSetPinValue((STP_LEDMAT_ROW_obj->PORT), (STP_LEDMAT_ROW_obj->SHIFT_BYTE_PIN), HIGH);
    MSTK_voidSetMicroBusyWait(1);
    MGPIO_voidSetPinValue((STP_LEDMAT_ROW_obj->PORT), (STP_LEDMAT_ROW_obj->SHIFT_BYTE_PIN), LOW);
}

static void HSTPLEDMAT_voidWriteByteCOL(STP_LEDMAT_t * STP_LEDMAT_COL_obj, u8 Copy_u8DataByte)
{
    u8 Local_u8Iterator;
    MGPIO_voidSetPinValue((STP_LEDMAT_COL_obj->PORT), (STP_LEDMAT_COL_obj->SHIFT_BYTE_PIN), LOW);
    for (Local_u8Iterator = 8; Local_u8Iterator > 0; Local_u8Iterator--)
    {
        MGPIO_voidSetPinValue((STP_LEDMAT_COL_obj->PORT), (STP_LEDMAT_COL_obj->DATA_PIN), (GET_BIT(Copy_u8DataByte, (Local_u8Iterator - 1))));
        MGPIO_voidSetPinValue((STP_LEDMAT_COL_obj->PORT), (STP_LEDMAT_COL_obj->SHIFT_BIT_PIN), HIGH);
        MSTK_voidSetMicroBusyWait(1);
        MGPIO_voidSetPinValue((STP_LEDMAT_COL_obj->PORT), (STP_LEDMAT_COL_obj->SHIFT_BIT_PIN), LOW);
    }
    MGPIO_voidSetPinValue((STP_LEDMAT_COL_obj->PORT), (STP_LEDMAT_COL_obj->SHIFT_BYTE_PIN), HIGH);
    MSTK_voidSetMicroBusyWait(1);
    MGPIO_voidSetPinValue((STP_LEDMAT_COL_obj->PORT), (STP_LEDMAT_COL_obj->SHIFT_BYTE_PIN), LOW);
}

static void HSTPLEDMAT_voidDisableColumns(STP_LEDMAT_t * STP_LEDMAT_COL_obj)
{
    HSTPLEDMAT_voidWriteByteCOL(STP_LEDMAT_COL_obj, 0xFF);
}

void HSTPLEDMAT_voidDisplay(STP_LEDMAT_t * STP_LEDMAT_ROW_obj, STP_LEDMAT_t * STP_LEDMAT_COL_obj, const u8 * Copy_pu8DataArray)
{
    u8 Local_u8Index;
    u8 Local_u8MaskCol = 0xFF;
    HSTPLEDMAT_voidDisableColumns(STP_LEDMAT_COL_obj);
    for(Local_u8Index = 0; Local_u8Index < 8; Local_u8Index++)
    {
		HSTPLEDMAT_voidDisableColumns(STP_LEDMAT_COL_obj);
        HSTPLEDMAT_voidWriteByteROW(STP_LEDMAT_ROW_obj, Copy_pu8DataArray[Local_u8Index]);
		HSTPLEDMAT_voidWriteByteCOL(STP_LEDMAT_COL_obj, (Local_u8MaskCol & (~(1 << Local_u8Index))));
		MSTK_voidSetMicroBusyWait(2000);
	}
}