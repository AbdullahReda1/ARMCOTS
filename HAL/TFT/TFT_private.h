/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        30 MAY, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 HAL
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         30 MAY, 2023      Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/

#ifndef HAL_TFT_TFT_PRIVATE_H_
#define HAL_TFT_TFT_PRIVATE_H_


#define SLEEP_OUT					0x11
#define DISPLAY_OFF					0x28
#define DISPLAY_ON					0x29
#define MEMORY_ACCESS_DATA_CTRL		0x36
#define COLOR_MODE					0x3A
#define COLUMN_ADDRESS_SET			0x2A
#define ROW_ADDRESS_SET				0x2B
#define WRITE_MEM					0x2C

#define HTFT_X0     0
#define HTFT_X1     127
#define HTFT_Y0     0
#define HTFT_Y1     159

#define ZERO_DATA   0

static void HTFT_voidSendData(u8 Copy_u8Data);

static void HTFT_voidSendCommand(u8 Copy_u8Command);


#endif