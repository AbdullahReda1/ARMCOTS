/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        8 MAY, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 APP
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         8 MAY, 2023       Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/RCC/RCC_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/STK/STK_interface.h"

#include "CLK_CASCADING_SIMULATE.h"


void SetClockCascadingOut(u8 Copy_u8MCOType)
{
	/* Just simulating function for learning about clk, so no input 
	   clk cause this feature does not exist in this MCU version  */

	MRCC_voidInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB1, RCC_GPIOA);

	MRCC_voidSetMCO1Source();

    /* The selected clock speed to output onto MCO must not exceed 100 MHz */
    MGPIO_voidSetPinMode(MGPIO_PORTA, Copy_u8MCOType, OUTPUT_MODE);
	MGPIO_voidSetOutputType(MGPIO_PORTA, Copy_u8MCOType, PUSH_PULL);
	MGPIO_voidSetOutputSpeed(MGPIO_PORTA, Copy_u8MCOType, LOW_SPEED_2MHZ);
}

void StartClockCascading(u8 Copy_u8MCOType)
{
	/* For HSI MCO1 & MCO2 source, and AHB prescaler /2 & and also all waiting is integer */
	u8 Local_u8PrescalerVal;
	u8 Local_u8Speed;
	switch (Copy_u8MCOType)
	{
		case MCO1:
			Local_u8PrescalerVal = MRCC_u8GetMCO1Prescaler();
		break;
		case MCO2:
			Local_u8PrescalerVal = MRCC_u8GetMCO2Prescaler();
		break;
		default:
		break;
	}

	if (Local_u8PrescalerVal ==  0)
	{
		Local_u8Speed = 8;
	}
	else if (Local_u8PrescalerVal ==  4)
	{
		Local_u8Speed = 4;
	}
	else if (Local_u8PrescalerVal ==  5)
	{
		Local_u8Speed = 3;
	}
	else if (Local_u8PrescalerVal ==  6)
	{
		Local_u8Speed = 2;
	}
	else if (Local_u8PrescalerVal ==  7)
	{
		Local_u8Speed = 1;
	}

    MGPIO_voidSetPinValue(MGPIO_PORTA, Copy_u8MCOType, HIGH);
	MSTK_voidSetMicroBusyWait(Local_u8Speed);
	MGPIO_voidSetPinValue(MGPIO_PORTA, Copy_u8MCOType, LOW);
	MSTK_voidSetMicroBusyWait(Local_u8Speed);
}
