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


#ifndef HAL_LCD_LCD_PRIVATE_H
#define HAL_LCD_LCD_PRIVATE_H


#define EIGHT_BIT_MODE     1
#define FOUR_BIT_MODE      0

#define FUNCTION_SET_CMD			       0x38
#define FUNCTION_SET_4BITM_CMD             0x28
#define DISPLAY_ON_OFF_CMD		    	   0x0F
#define DISPLAY_CLEAR_CMD			       0x01
#define RETURN_HOME_CMD                    0x02
#define SHIFT_CURSOR_ENTRY_LEFT_CMD        0x04
#define SHIFT_CURSOR_ENTRY_RIGHT_CMD       0x06
#define SHIFT_DISPLAY_ENTRY_LEFT_CMD       0x07
#define SHIFT_DISPLAY_ENTRY_RIGHT_CMD      0x05
#define SHIFT_CURSOR_POSITION_LEFT_CMD     0x10
#define SHIFT_CURSOR_POSITION_RIGHT_CMD    0x14
#define SHIFT_DISPLAY_POSITION_LEFT_CMD    0x18
#define SHIFT_DISPLAY_POSITION_RIGHT_CMD   0x1C
#define DISPLAY_CURSOR_BLINK_ON_CMD        0x0F
#define DISPLAY_CURSOR_ON_CMD              0x0E
#define DISPLAY_BLINK_ON_CMD               0x0D
#define DISPLAY_ON_CMD                     0x0C
#define CURSOR_BLINK_ON_CMD                0x0B
#define CURSOR_ON_CMD                      0x0A
#define BLINK_ON_CMD                       0x09
#define DISPLAY_CURSOR_BLINK_OFF_CMD       0x08
#define SET_CGRAM_CMD                      0x40
#define SET_DDRAM_CMD                      0x80
#define SINGLE_ROW_5X7_DOT_8BIT_MODE       0x30
#define SINGLE_ROW_5X7_DOT_4BIT_MODE       0x20
#define SINGLE_ROW_5X10_DOT_8BIT_MODE      0x34
#define SINGLE_ROW_5X10_DOT_4BIT_MODE      0x24

#define BUSY_FLAG_BIT_8BIT_MODE            7
#define BUSY_FLAG_BIT_4BIT_MODE            3


void HLCD_voidEnablePulse(void);

void HLCD_voidDataPulse(void);

void HLCD_voidCommandPulse(void);

void HLCD_voidReadPulse(void);

void HLCD_voidSendData(u8 Copy_u8Data);

void HLCD_voidSendCommand(u8 Copy_u8Command);


#endif