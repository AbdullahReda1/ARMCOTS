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


#ifndef HAL_LCD_LCD_INTERFACE_H
#define HAL_LCD_LCD_INTERFACE_H


void HLCD_voidInit(void);

void HLCD_voidClearDisplay(void);

void HLCD_voidGoToXY(u8 Copy_u8RowPos, u8 Copy_u8ColPos);

void HLCD_voidSendCharacter(u8 Copy_u8Character);

void HLCD_voidSendNumber(u32 Copy_u32Number);

void HLCD_voidSendString(u8 * Copy_pu8StringArray);

void HLCD_voidReturnHome(void);

void HLCD_voidShiftCursorEntryLeft(void);

void HLCD_voidShiftCursorEntryRight(void);

void HLCD_voidShiftDisplayEntryLeft(void);

void HLCD_voidShiftDisplayEntryRight(void);

void HLCD_voidShiftCursorPositionLeft(void);

void HLCD_voidShiftCursorPositionRight(void);

void HLCD_voidShiftDisplayPositionLeft(void);

void HLCD_voidShiftDisplayPositionRight(void);

void HLCD_voidSetCGRAMAddress(u8 Copy_u8AddressNumber);

void HLCD_voidSetDDRAMAddress(u8 Copy_u8AddressNumber);

void HLCD_voidSendCustomCharacter(u8 * Copy_pu8CharacterArray, u8 Copy_u8PatternNumber, u8 Copy_u8XPosition, u8 Copy_u8YPosition);

void HLCD_voidDisplayCursorBlinkONOFF(u8 Copy_u8Display, u8 Copy_u8Cursor, u8 Copy_u8Blink);

void HLCD_voidSingleRow5X7DOT(void);

void HLCD_voidSingleRow5X10DOT(void);

u8 HLCD_voidGetBusyFlag(void);


#endif