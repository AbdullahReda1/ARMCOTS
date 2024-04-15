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


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/RCC/RCC_interface.h"
#include "../../MCAL/STK/STK_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

#include "STP_interface.h"
#include "STP_config.h"
#include "STP_private.h"


void HSTP_voidInit(void)
{
    MRCC_voidInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB1, HSTP_DATA_PORT_NAME);
    MRCC_voidEnablePeripheralClock(RCC_AHB1, HSTP_LATCH_BIT_PORT_NAME);
    MRCC_voidEnablePeripheralClock(RCC_AHB1, HSTP_LATCH_BYTE_PORT_NAME);
    MRCC_voidEnablePeripheralClock(RCC_AHB1, HSTP_ENABLE_IC_PORT_NAME);
    MRCC_voidEnablePeripheralClock(RCC_AHB1, HSTP_RESET_IC_PORT_NAME);

    MGPIO_voidSetPinMode(HSTP_DATA_PORT_NAME, HSTP_DATA_PIN_NUMBER, OUTPUT_MODE);
    MGPIO_voidSetOutputType(HSTP_DATA_PORT_NAME, HSTP_DATA_PIN_NUMBER, PUSH_PULL);
    MGPIO_voidSetOutputSpeed(HSTP_DATA_PORT_NAME, HSTP_DATA_PIN_NUMBER, LOW_SPEED_2MHZ);

    MGPIO_voidSetPinMode(HSTP_LATCH_BIT_PORT_NAME, HSTP_LATCH_BIT_PIN_NUMBER, OUTPUT_MODE);
    MGPIO_voidSetOutputType(HSTP_LATCH_BIT_PORT_NAME, HSTP_LATCH_BIT_PIN_NUMBER, PUSH_PULL);
    MGPIO_voidSetOutputSpeed(HSTP_LATCH_BIT_PORT_NAME, HSTP_LATCH_BIT_PIN_NUMBER, LOW_SPEED_2MHZ);

    MGPIO_voidSetPinMode(HSTP_LATCH_BYTE_PORT_NAME, HSTP_LATCH_BYTE_PIN_NUMBER, OUTPUT_MODE);
    MGPIO_voidSetOutputType(HSTP_LATCH_BYTE_PORT_NAME, HSTP_LATCH_BYTE_PIN_NUMBER, PUSH_PULL);
    MGPIO_voidSetOutputSpeed(HSTP_LATCH_BYTE_PORT_NAME, HSTP_LATCH_BYTE_PIN_NUMBER, LOW_SPEED_2MHZ);

    MGPIO_voidSetPinMode(HSTP_ENABLE_IC_PORT_NAME, HSTP_ENABLE_IC_PIN_NUMBER, OUTPUT_MODE);
    MGPIO_voidSetOutputType(HSTP_ENABLE_IC_PORT_NAME, HSTP_ENABLE_IC_PIN_NUMBER, PUSH_PULL);
    MGPIO_voidSetOutputSpeed(HSTP_ENABLE_IC_PORT_NAME, HSTP_ENABLE_IC_PIN_NUMBER, LOW_SPEED_2MHZ);

    MGPIO_voidSetPinMode(HSTP_RESET_IC_PORT_NAME, HSTP_RESET_IC_PIN_NUMBER, OUTPUT_MODE);
    MGPIO_voidSetOutputType(HSTP_RESET_IC_PORT_NAME, HSTP_RESET_IC_PIN_NUMBER, PUSH_PULL);
    MGPIO_voidSetOutputSpeed(HSTP_RESET_IC_PORT_NAME, HSTP_RESET_IC_PIN_NUMBER, LOW_SPEED_2MHZ);

    MGPIO_voidSetPinValue(HSTP_ENABLE_IC_PORT_NAME, HSTP_ENABLE_IC_PIN_NUMBER, LOW);
    MGPIO_voidSetPinValue(HSTP_RESET_IC_PORT_NAME, HSTP_RESET_IC_PIN_NUMBER, HIGH);

	MSTK_voidInit();
}

void HSTP_voidWriteByte(u8 Copy_u8DataByte)
{
    u8 Local_u8Iterator;
    MGPIO_voidSetPinValue(HSTP_LATCH_BYTE_PORT_NAME, HSTP_LATCH_BYTE_PIN_NUMBER, LOW);
    for (Local_u8Iterator = 8; Local_u8Iterator > 0; Local_u8Iterator--)
    {
        MGPIO_voidSetPinValue(HSTP_DATA_PORT_NAME, HSTP_DATA_PIN_NUMBER, (GET_BIT(Copy_u8DataByte, (Local_u8Iterator - 1))));
        MGPIO_voidSetPinValue(HSTP_LATCH_BIT_PORT_NAME, HSTP_LATCH_BIT_PIN_NUMBER, HIGH);
        MSTK_voidSetMicroBusyWait(5);
        MGPIO_voidSetPinValue(HSTP_LATCH_BIT_PORT_NAME, HSTP_LATCH_BIT_PIN_NUMBER, LOW);
    }
    MGPIO_voidSetPinValue(HSTP_LATCH_BYTE_PORT_NAME, HSTP_LATCH_BYTE_PIN_NUMBER, HIGH);
    MSTK_voidSetMicroBusyWait(5);
    MGPIO_voidSetPinValue(HSTP_LATCH_BYTE_PORT_NAME, HSTP_LATCH_BYTE_PIN_NUMBER, LOW);
}

void HSTP_voidWriteWord(u16 Copy_u16DataWord)
{
    u8 Local_u8Iterator;
    MGPIO_voidSetPinValue(HSTP_LATCH_BYTE_PORT_NAME, HSTP_LATCH_BYTE_PIN_NUMBER, LOW);
    for (Local_u8Iterator = 16; Local_u8Iterator > 0; Local_u8Iterator--)
    {
        MGPIO_voidSetPinValue(HSTP_DATA_PORT_NAME, HSTP_DATA_PIN_NUMBER, (GET_BIT(Copy_u16DataWord, (Local_u8Iterator - 1))));
        MGPIO_voidSetPinValue(HSTP_LATCH_BIT_PORT_NAME, HSTP_LATCH_BIT_PIN_NUMBER, HIGH);
        MSTK_voidSetMicroBusyWait(5);
        MGPIO_voidSetPinValue(HSTP_LATCH_BIT_PORT_NAME, HSTP_LATCH_BIT_PIN_NUMBER, LOW);
    }
    MGPIO_voidSetPinValue(HSTP_LATCH_BYTE_PORT_NAME, HSTP_LATCH_BYTE_PIN_NUMBER, HIGH);
    MSTK_voidSetMicroBusyWait(5);
    MGPIO_voidSetPinValue(HSTP_LATCH_BYTE_PORT_NAME, HSTP_LATCH_BYTE_PIN_NUMBER, LOW);
}

void HSTP_voidWriteNumberofWords(u32 Copy_u32DataWord, u8 Copy_u8WordsNumber)
{
    /* Max is 4 words each one 8 bit */
    u8 Local_u8Iterator;
    u8 Local_u8Iterations = (Copy_u8WordsNumber * 8);
    MGPIO_voidSetPinValue(HSTP_LATCH_BYTE_PORT_NAME, HSTP_LATCH_BYTE_PIN_NUMBER, LOW);
    for (Local_u8Iterator = Local_u8Iterations; Local_u8Iterator > 0; Local_u8Iterator--)
    {
        MGPIO_voidSetPinValue(HSTP_DATA_PORT_NAME, HSTP_DATA_PIN_NUMBER, (GET_BIT(Copy_u32DataWord, (Local_u8Iterator - 1))));
        MGPIO_voidSetPinValue(HSTP_LATCH_BIT_PORT_NAME, HSTP_LATCH_BIT_PIN_NUMBER, HIGH);
        MSTK_voidSetMicroBusyWait(5);
        MGPIO_voidSetPinValue(HSTP_LATCH_BIT_PORT_NAME, HSTP_LATCH_BIT_PIN_NUMBER, LOW);
    }
    MGPIO_voidSetPinValue(HSTP_LATCH_BYTE_PORT_NAME, HSTP_LATCH_BYTE_PIN_NUMBER, HIGH);
    MSTK_voidSetMicroBusyWait(5);
    MGPIO_voidSetPinValue(HSTP_LATCH_BYTE_PORT_NAME, HSTP_LATCH_BYTE_PIN_NUMBER, LOW);
}

void HSTP_voidSetEnableStatus(u8 Copy_u8Status)
{
    switch (Copy_u8Status)
    {
        case HSTP_ENABLE:
            MGPIO_voidSetPinValue(HSTP_ENABLE_IC_PORT_NAME, HSTP_ENABLE_IC_PIN_NUMBER, LOW);
        break;
        case HSTP_DISABLE:
            MGPIO_voidSetPinValue(HSTP_ENABLE_IC_PORT_NAME, HSTP_ENABLE_IC_PIN_NUMBER, HIGH);
        break;
        default:
        break;
    }
}

void HSTP_voidResetIC(void)
{
    MGPIO_voidSetPinValue(HSTP_RESET_IC_PORT_NAME, HSTP_RESET_IC_PIN_NUMBER, LOW);
    MSTK_voidSetMicroBusyWait(5);
    MGPIO_voidSetPinValue(HSTP_RESET_IC_PORT_NAME, HSTP_RESET_IC_PIN_NUMBER, HIGH);
}