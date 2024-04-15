/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        26 MAR, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 HAL
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         26 MAR, 2023      Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/STK/STK_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/RCC/RCC_interface.h"

#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"


void HLCD_voidInit(void)
{
	MRCC_voidInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB1, LCD_DATA_PORT);
	MRCC_voidEnablePeripheralClock(RCC_AHB1, LCD_CTRL_PORT);

	MSTK_voidInit();

    #if LCD_INIT_MODE == EIGHT_BIT_MODE

		MGPIO_voidSetHalfPortMode(LCD_DATA_PORT, LCD_HALF_DATA_PORT, OUTPUT_MODE);
    	MGPIO_voidSetHalfPortOutputType(LCD_DATA_PORT, LCD_HALF_DATA_PORT, PUSH_PULL);
    	MGPIO_voidSetHalfPortOutputSpeed(LCD_DATA_PORT, LCD_HALF_DATA_PORT, LOW_SPEED_2MHZ);

		MGPIO_voidSetPinMode(LCD_CTRL_PORT, LCD_RS_PIN, OUTPUT_MODE);
    	MGPIO_voidSetOutputType(LCD_CTRL_PORT, LCD_RS_PIN, PUSH_PULL);
    	MGPIO_voidSetOutputSpeed(LCD_CTRL_PORT, LCD_RS_PIN, LOW_SPEED_2MHZ);

		MGPIO_voidSetPinMode(LCD_CTRL_PORT, LCD_RW_PIN, OUTPUT_MODE);
    	MGPIO_voidSetOutputType(LCD_CTRL_PORT, LCD_RW_PIN, PUSH_PULL);
    	MGPIO_voidSetOutputSpeed(LCD_CTRL_PORT, LCD_RW_PIN, LOW_SPEED_2MHZ);

		MGPIO_voidSetPinMode(LCD_CTRL_PORT, LCD_EN_PIN, OUTPUT_MODE);
    	MGPIO_voidSetOutputType(LCD_CTRL_PORT, LCD_EN_PIN, PUSH_PULL);
    	MGPIO_voidSetOutputSpeed(LCD_CTRL_PORT, LCD_EN_PIN, LOW_SPEED_2MHZ);

		MSTK_voidSetMilliBusyWait(40);

		HLCD_voidSendCommand(FUNCTION_SET_CMD);
		HLCD_voidSendCommand(DISPLAY_ON_OFF_CMD);
		HLCD_voidSendCommand(DISPLAY_CLEAR_CMD);

    #elif LCD_INIT_MODE == FOUR_BIT_MODE

		MGPIO_voidSetNipplePortMode(LCD_DATA_PORT, LCD_NIPPLE_DATA_PORT, OUTPUT_MODE);
    	MGPIO_voidSetNipplePortOutputType(LCD_DATA_PORT, LCD_NIPPLE_DATA_PORT, PUSH_PULL);
    	MGPIO_voidSetNipplePortOutputSpeed(LCD_DATA_PORT, LCD_NIPPLE_DATA_PORT, LOW_SPEED_2MHZ);
		
		MGPIO_voidSetPinMode(LCD_CTRL_PORT, LCD_RS_PIN, OUTPUT_MODE);
    	MGPIO_voidSetOutputType(LCD_CTRL_PORT, LCD_RS_PIN, PUSH_PULL);
    	MGPIO_voidSetOutputSpeed(LCD_CTRL_PORT, LCD_RS_PIN, LOW_SPEED_2MHZ);

		MGPIO_voidSetPinMode(LCD_CTRL_PORT, LCD_RW_PIN, OUTPUT_MODE);
    	MGPIO_voidSetOutputType(LCD_CTRL_PORT, LCD_RW_PIN, PUSH_PULL);
    	MGPIO_voidSetOutputSpeed(LCD_CTRL_PORT, LCD_RW_PIN, LOW_SPEED_2MHZ);

		MGPIO_voidSetPinMode(LCD_CTRL_PORT, LCD_EN_PIN, OUTPUT_MODE);
    	MGPIO_voidSetOutputType(LCD_CTRL_PORT, LCD_EN_PIN, PUSH_PULL);
    	MGPIO_voidSetOutputSpeed(LCD_CTRL_PORT, LCD_EN_PIN, LOW_SPEED_2MHZ);

		MSTK_voidSetMilliBusyWait(40);

		HLCD_voidSendCommand(FUNCTION_SET_4BITM_CMD);
		HLCD_voidSendCommand(DISPLAY_ON_OFF_CMD);
		HLCD_voidSendCommand(DISPLAY_CLEAR_CMD);

    #else
        #error ("LCD_INIT_MODE Configuration Error")
    #endif
}

void HLCD_voidEnablePulse(void)
{
	MGPIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, LOW);
	MGPIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, HIGH);
	MSTK_voidSetMilliBusyWait(2);
	MGPIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, LOW);
	MSTK_voidSetMilliBusyWait(2);
}

void HLCD_voidDataPulse(void)
{
	MGPIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, HIGH);
	MGPIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, LOW);
}

void HLCD_voidCommandPulse(void)
{
	MGPIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, LOW);
	MGPIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, LOW);
}

void HLCD_voidReadPulse(void)
{
	MGPIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, LOW);
	MGPIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, HIGH);
}

void HLCD_voidSendData(u8 Copy_u8Data)
{
	#if LCD_INIT_MODE == EIGHT_BIT_MODE

		HLCD_voidDataPulse();
		MGPIO_voidSetHalfPortValue(LCD_DATA_PORT, LCD_HALF_DATA_PORT, Copy_u8Data);
		HLCD_voidEnablePulse();

	#elif LCD_INIT_MODE == FOUR_BIT_MODE

		HLCD_voidDataPulse();
		MGPIO_voidSetNipplePortValue(LCD_DATA_PORT, LCD_NIPPLE_DATA_PORT, (Copy_u8Data >> 4));
		HLCD_voidEnablePulse();

		HLCD_voidDataPulse();
		MGPIO_voidSetNipplePortValue(LCD_DATA_PORT, LCD_NIPPLE_DATA_PORT, (Copy_u8Data));
		HLCD_voidEnablePulse();

    #else
        #error ("LCD_INIT_MODE Configuration Error")
    #endif
}

void HLCD_voidSendCommand(u8 Copy_u8Command)
{
	#if LCD_INIT_MODE == EIGHT_BIT_MODE

		HLCD_voidCommandPulse();
		MGPIO_voidSetHalfPortValue(LCD_DATA_PORT, LCD_HALF_DATA_PORT, Copy_u8Command);
		HLCD_voidEnablePulse();

	#elif LCD_INIT_MODE == FOUR_BIT_MODE

		HLCD_voidCommandPulse();
		MGPIO_voidSetNipplePortValue(LCD_DATA_PORT, LCD_NIPPLE_DATA_PORT, (Copy_u8Command >> 4));
		HLCD_voidEnablePulse();

		HLCD_voidCommandPulse();
		MGPIO_voidSetNipplePortValue(LCD_DATA_PORT, LCD_NIPPLE_DATA_PORT, (Copy_u8Command));
		HLCD_voidEnablePulse();

    #else
        #error ("LCD_INIT_MODE Configuration Error")
    #endif
}

void HLCD_voidClearDisplay(void)
{
    HLCD_voidSendCommand(DISPLAY_CLEAR_CMD);
}

void HLCD_voidGoToXY(u8 Copy_u8RowPos, u8 Copy_u8ColPos)
{
    u8 Local_u8CharacterAddress = 0;
    if(Copy_u8RowPos == 1)
    {
        Local_u8CharacterAddress = (Copy_u8ColPos - 1) + 0x80;
    }
    else if (Copy_u8RowPos == 2)
    {
        Local_u8CharacterAddress = (Copy_u8ColPos - 1) + 0xC0;
    }
    HLCD_voidSendCommand(Local_u8CharacterAddress);
}

void HLCD_voidSendCharacter(u8 Copy_u8Character)
{
	HLCD_voidSendData(Copy_u8Character);
}

void HLCD_voidSendString(u8 * Copy_pu8StringArray)
{
    u8 Local_u8LoopCounter = 0 ;
    while(Copy_pu8StringArray[Local_u8LoopCounter] != '\0')
    {
        HLCD_voidSendData(Copy_pu8StringArray[Local_u8LoopCounter]);
        Local_u8LoopCounter++;
    }
}

void HLCD_voidSendNumber(u32 Copy_u32Number)
{
    u8 Local_u8ArrayNumber[10];
    s8 Local_s8LoopCounter = 0;
    while(Copy_u32Number != 0)
    {
        Local_u8ArrayNumber[Local_s8LoopCounter] = Copy_u32Number % 10;
        Copy_u32Number /= 10;
        Local_s8LoopCounter++;
    }
    Local_s8LoopCounter--;
    while(Local_s8LoopCounter >= 0)
    {
        HLCD_voidSendData(Local_u8ArrayNumber[Local_s8LoopCounter] + '0');
        Local_s8LoopCounter--;
    }
}

void HLCD_voidReturnHome(void)
{
	HLCD_voidSendCommand(RETURN_HOME_CMD);
	MSTK_voidSetMilliBusyWait(10);
}

void HLCD_voidShiftCursorEntryLeft(void)
{
	HLCD_voidSendCommand(SHIFT_CURSOR_ENTRY_LEFT_CMD);
}

void HLCD_voidShiftCursorEntryRight(void)
{
	HLCD_voidSendCommand(SHIFT_CURSOR_ENTRY_RIGHT_CMD);
}

void HLCD_voidShiftDisplayEntryLeft(void)
{
	HLCD_voidSendCommand(SHIFT_DISPLAY_ENTRY_LEFT_CMD);
}

void HLCD_voidShiftDisplayEntryRight(void)
{
	HLCD_voidSendCommand(SHIFT_DISPLAY_ENTRY_RIGHT_CMD);
}

void HLCD_voidShiftCursorPositionLeft(void)
{
	HLCD_voidSendCommand(SHIFT_CURSOR_POSITION_LEFT_CMD);
}

void HLCD_voidShiftCursorPositionRight(void)
{
	HLCD_voidSendCommand(SHIFT_CURSOR_POSITION_RIGHT_CMD);
}

void HLCD_voidShiftDisplayPositionLeft(void)
{
	HLCD_voidSendCommand(SHIFT_DISPLAY_POSITION_LEFT_CMD);
}

void HLCD_voidShiftDisplayPositionRight(void)
{
	HLCD_voidSendCommand(SHIFT_DISPLAY_POSITION_RIGHT_CMD);
}

void HLCD_voidSetCGRAMAddress(u8 Copy_u8AddressNumber)
{
	u8 Local_u8CGRAMAddress = 0;
    Local_u8CGRAMAddress = (Copy_u8AddressNumber * 8);
    HLCD_voidSendCommand((SET_CGRAM_CMD | Local_u8CGRAMAddress));
}

void HLCD_voidSetDDRAMAddress(u8 Copy_u8AddressNumber)
{
	u8 Local_u8CGRAMAddress = 0;
    Local_u8CGRAMAddress = (Copy_u8AddressNumber * 8);
    HLCD_voidSendCommand((SET_DDRAM_CMD | Local_u8CGRAMAddress));
}

void HLCD_voidSendCustomCharacter(u8 * Copy_pu8CharacterArray, u8 Copy_u8PatternNumber, u8 Copy_u8XPosition, u8 Copy_u8YPosition)
{
    u8 Local_u8LoopCounter;
    HLCD_voidSetCGRAMAddress(Copy_u8PatternNumber);
    for(Local_u8LoopCounter = 0; Local_u8LoopCounter < 8; Local_u8LoopCounter++)
    {
        HLCD_voidSendData(Copy_pu8CharacterArray[Local_u8LoopCounter]);
    }
    HLCD_voidGoToXY(Copy_u8XPosition, Copy_u8YPosition);
    HLCD_voidSendData(Copy_u8PatternNumber);
}

void HLCD_voidDisplayCursorBlinkONOFF(u8 Copy_u8Display, u8 Copy_u8Cursor, u8 Copy_u8Blink)
{
	if (HIGH == Copy_u8Display)
	{
		if (HIGH == Copy_u8Cursor)
		{
			if (HIGH == Copy_u8Blink)
			{
				HLCD_voidSendCommand(DISPLAY_CURSOR_BLINK_ON_CMD);
			} 
			else
			{
				HLCD_voidSendCommand(DISPLAY_CURSOR_ON_CMD);
			}
		} 
		else
		{
			if (HIGH == Copy_u8Blink)
			{
				HLCD_voidSendCommand(DISPLAY_BLINK_ON_CMD);
			} 
			else
			{
				HLCD_voidSendCommand(DISPLAY_ON_CMD);
			}
		}
	} 
	else
	{
		if (HIGH == Copy_u8Cursor)
		{
			if (HIGH == Copy_u8Blink)
			{
				HLCD_voidSendCommand(CURSOR_BLINK_ON_CMD);
			} 
			else
			{
				HLCD_voidSendCommand(CURSOR_ON_CMD);
			}
		} 
		else
		{
			if (HIGH == Copy_u8Blink)
			{
				HLCD_voidSendCommand(BLINK_ON_CMD);
			} 
			else
			{
				HLCD_voidSendCommand(DISPLAY_CURSOR_BLINK_OFF_CMD);
			}
		}
	}
}

void HLCD_voidSingleRow5X7DOT(void)
{
	#if LCD_INIT_MODE == EIGHT_BIT_MODE
		HLCD_voidSendCommand(SINGLE_ROW_5X7_DOT_8BIT_MODE);
	#elif LCD_INIT_MODE == FOUR_BIT_MODE
		HLCD_voidSendCommand(SINGLE_ROW_5X7_DOT_4BIT_MODE);
    #else
        #error ("LCD_INIT_MODE Configuration Error")
    #endif
}

void HLCD_voidSingleRow5X10DOT(void)
{
	#if LCD_INIT_MODE == EIGHT_BIT_MODE
		HLCD_voidSendCommand(SINGLE_ROW_5X10_DOT_8BIT_MODE);
	#elif LCD_INIT_MODE == FOUR_BIT_MODE
		HLCD_voidSendCommand(SINGLE_ROW_5X10_DOT_4BIT_MODE);
    #else
        #error ("LCD_INIT_MODE Configuration Error")
    #endif
}

u8 HLCD_voidGetBusyFlag(void)
{
	u8 Local_u8BF = 0;

	#if LCD_INIT_MODE == EIGHT_BIT_MODE

		HLCD_voidReadPulse();
		Local_u8BF = MGPIO_u8GetPinValue(LCD_DATA_PORT, BUSY_FLAG_BIT_8BIT_MODE);
		HLCD_voidEnablePulse();
		MGPIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, LOW);
		HLCD_voidEnablePulse();

	#elif LCD_INIT_MODE == FOUR_BIT_MODE

		HLCD_voidReadPulse();
		Local_u8BF = MGPIO_u8GetPinValue((LCD_DATA_PORT >> 4), BUSY_FLAG_BIT_4BIT_MODE);
		HLCD_voidEnablePulse();
		MGPIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, LOW);
		HLCD_voidEnablePulse();

    #else
        #error ("LCD_INIT_MODE Configuration Error")
    #endif

	return Local_u8BF;
}