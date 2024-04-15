/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        19 SEP, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 HAL
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         19 SEP, 2023      Abdullah R.Hebashi           Initial Creation 
*********************************************************************************/


#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "../../MCAL/RCC/RCC_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

#include "RGBLED_interface.h"
#include "RGBLED_config.h"
#include "RGBLED_private.h"


void HRGBLED_voidInit(RGBLED_t* RGBLedobj)
{
    MRCC_voidInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB1, RGBLedobj->PORT);

	MGPIO_voidSetPinMode(RGBLedobj->PORT, RGBLedobj->RPIN, OUTPUT_MODE);
	MGPIO_voidSetOutputType(RGBLedobj->PORT, RGBLedobj->RPIN, PUSH_PULL);
	MGPIO_voidSetOutputSpeed(RGBLedobj->PORT, RGBLedobj->RPIN, LOW_SPEED_2MHZ);

	MGPIO_voidSetPinMode(RGBLedobj->PORT, RGBLedobj->GPIN, OUTPUT_MODE);
	MGPIO_voidSetOutputType(RGBLedobj->PORT, RGBLedobj->GPIN, PUSH_PULL);
	MGPIO_voidSetOutputSpeed(RGBLedobj->PORT, RGBLedobj->GPIN, LOW_SPEED_2MHZ);
	
	MGPIO_voidSetPinMode(RGBLedobj->PORT, RGBLedobj->BPIN, OUTPUT_MODE);
	MGPIO_voidSetOutputType(RGBLedobj->PORT, RGBLedobj->BPIN, PUSH_PULL);
	MGPIO_voidSetOutputSpeed(RGBLedobj->PORT, RGBLedobj->BPIN, LOW_SPEED_2MHZ);

	MGPIO_voidSetPinMode(RGBLedobj->PORT, RGBLedobj->COMPIN, OUTPUT_MODE);
	MGPIO_voidSetOutputType(RGBLedobj->PORT, RGBLedobj->COMPIN, PUSH_PULL);
	MGPIO_voidSetOutputSpeed(RGBLedobj->PORT, RGBLedobj->COMPIN, LOW_SPEED_2MHZ);
}

void HRGBLED_voidSetColor(RGBLED_t* RGBLedobj, u8 Copy_u8Color)
{
	switch (RGBLedobj->COMMON_TYPE)
	{
		case CA:
			MGPIO_voidSetPinValue(RGBLedobj->PORT, RGBLedobj->COMPIN, HIGH);
			MGPIO_voidSetPinValue(RGBLedobj->PORT, RGBLedobj->RPIN, (!(GET_BIT(Copy_u8Color, 2))));
			MGPIO_voidSetPinValue(RGBLedobj->PORT, RGBLedobj->GPIN, (!(GET_BIT(Copy_u8Color, 1))));
			MGPIO_voidSetPinValue(RGBLedobj->PORT, RGBLedobj->BPIN, (!(GET_BIT(Copy_u8Color, 0))));
		break;
		case CC:
			MGPIO_voidSetPinValue(RGBLedobj->PORT, RGBLedobj->COMPIN, LOW);
			MGPIO_voidSetPinValue(RGBLedobj->PORT, RGBLedobj->RPIN, GET_BIT(Copy_u8Color, 2));
			MGPIO_voidSetPinValue(RGBLedobj->PORT, RGBLedobj->GPIN, GET_BIT(Copy_u8Color, 1));
			MGPIO_voidSetPinValue(RGBLedobj->PORT, RGBLedobj->BPIN, GET_BIT(Copy_u8Color, 0));
		break;
		default:
		break;
	}
}