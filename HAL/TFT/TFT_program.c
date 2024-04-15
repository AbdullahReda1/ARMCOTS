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


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/RCC/RCC_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/STK/STK_interface.h"
#include "../../MCAL/SPI/SPI_interface.h"

#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"

#include "../../Services/ImageArray.h"


void HTFT_voidInit(void)
{
	MRCC_voidInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB1, HTFT_A0_PORT);
	MRCC_voidEnablePeripheralClock(RCC_APB2, RCC_SPI1);

	MGPIO_voidSetPinMode(HTFT_A0_PORT, HTFT_A0_PIN, OUTPUT_MODE);
	MGPIO_voidSetOutputSpeed(HTFT_A0_PORT, HTFT_A0_PIN, LOW_SPEED_2MHZ);
	MGPIO_voidSetOutputType(HTFT_A0_PORT, HTFT_A0_PIN, PUSH_PULL);

	MGPIO_voidSetPinMode(HTFT_RESET_PORT, HTFT_RESET_PIN, OUTPUT_MODE);
	MGPIO_voidSetOutputSpeed(HTFT_RESET_PORT, HTFT_RESET_PIN, LOW_SPEED_2MHZ);
	MGPIO_voidSetOutputType(HTFT_RESET_PORT, HTFT_RESET_PIN, PUSH_PULL);

	MGPIO_voidSetAlternativeFunction(MGPIO_PORTA, PIN5, AF5_SPI1_4);
	MGPIO_voidSetAlternativeFunction(MGPIO_PORTA, PIN7, AF5_SPI1_4);

	MSTK_voidInit();

	MSPI1_voidInit();

	MGPIO_voidSetPinValue(HTFT_RESET_PORT, HTFT_RESET_PIN, HIGH);
    MSTK_voidSetMicroBusyWait(100);
    MGPIO_voidSetPinValue(HTFT_RESET_PORT, HTFT_RESET_PIN, LOW);
    MSTK_voidSetMicroBusyWait(1);
    MGPIO_voidSetPinValue(HTFT_RESET_PORT, HTFT_RESET_PIN, HIGH);
    MSTK_voidSetMicroBusyWait(100);
    MGPIO_voidSetPinValue(HTFT_RESET_PORT, HTFT_RESET_PIN, LOW);
    MSTK_voidSetMicroBusyWait(100);
    MGPIO_voidSetPinValue(HTFT_RESET_PORT, HTFT_RESET_PIN, HIGH);
    MSTK_voidSetMicroBusyWait(120000);

	HTFT_voidSendCommand(SLEEP_OUT);
	MSTK_voidSetMicroBusyWait(150000);
	HTFT_voidSendCommand(COLOR_MODE);
	HTFT_voidSendData(0x05);
	HTFT_voidSendCommand(DISPLAY_ON);
	MSTK_voidSetMicroBusyWait(1000);
	HTFT_voidSendCommand(MEMORY_ACCESS_DATA_CTRL);
	HTFT_voidSendData(0xC0);
}

static void HTFT_voidSendData(u8 Copy_u8Data) 
{
	MGPIO_voidSetPinValue(HTFT_A0_PORT, HTFT_A0_PIN, HIGH);
	MSPI1_voidSendData(Copy_u8Data);
}

static void HTFT_voidSendCommand(u8 Copy_u8Command) 
{
	MGPIO_voidSetPinValue(HTFT_A0_PORT, HTFT_A0_PIN, LOW);
	MSPI1_voidSendData(Copy_u8Command);
}

void HTFT_voidDrawPixels(u8 Xaxis, u8 Yaxis, u16 Copy_u8Data)
{
	HTFT_voidSendCommand(COLUMN_ADDRESS_SET);
	HTFT_voidSendData(Xaxis);
	HTFT_voidSendData(Xaxis);
	HTFT_voidSendCommand(ROW_ADDRESS_SET);
	HTFT_voidSendData(Yaxis);
	HTFT_voidSendData(Yaxis);
	HTFT_voidSendCommand(WRITE_MEM);
	HTFT_voidSendData(Copy_u8Data >> 8);
	HTFT_voidSendData(Copy_u8Data & 0xFF);
}

void HTFT_voidSetWindow(u8 Copy_u8X0, u8 Copy_u8X1, u8 Copy_u8Y0, u8 Copy_u8Y1)
{
    HTFT_voidSendCommand(COLUMN_ADDRESS_SET);
    HTFT_voidSendData(ZERO_DATA);
    HTFT_voidSendData(Copy_u8X0);
    HTFT_voidSendData(ZERO_DATA);
    HTFT_voidSendData(Copy_u8X1);
    HTFT_voidSendCommand(ROW_ADDRESS_SET);
    HTFT_voidSendData(ZERO_DATA);
    HTFT_voidSendData(Copy_u8Y0);
    HTFT_voidSendData(ZERO_DATA);
    HTFT_voidSendData(Copy_u8Y1);
}

void HTFT_voidDisplayImage(void)
{
	HTFT_voidSetWindow(HTFT_X0, HTFT_X1, HTFT_Y0, HTFT_Y1);
    HTFT_voidSendCommand(WRITE_MEM);
    u16 Local_u16LoopCounter;
    u8 Local_u8Data = 0;
    for(Local_u16LoopCounter=0; Local_u16LoopCounter <= IMAGE_SIZE; Local_u16LoopCounter++)
    {
    	Local_u8Data = Image_Array[Local_u16LoopCounter] >> 8;
    	HTFT_voidSendData(Local_u8Data);
    	Local_u8Data = (u8) Image_Array[Local_u16LoopCounter];
    	HTFT_voidSendData(Local_u8Data);
    }
}