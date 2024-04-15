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
 * v1.0         19 SEP, 2023      Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/


#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "../../MCAL/RCC/RCC_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

#include "LED_interface.h"
#include "LED_config.h"
#include "LED_private.h"


void HLED_voidInit(LED_t* Ledobj)
{
    MRCC_voidInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB1, Ledobj->LED_PORT);
	
    MGPIO_voidSetPinMode(Ledobj->LED_PORT, Ledobj->LED_PIN, OUTPUT_MODE);
	MGPIO_voidSetOutputType(Ledobj->LED_PORT, Ledobj->LED_PIN, PUSH_PULL);
	MGPIO_voidSetOutputSpeed(Ledobj->LED_PORT, Ledobj->LED_PIN, LOW_SPEED_2MHZ);
}

void HLED_voidTurnOn(LED_t* Ledobj)
{
	MGPIO_voidSetPinValue(Ledobj->LED_PORT , Ledobj->LED_PIN , HIGH);
}

void HLED_voidTurnOff(LED_t* Ledobj)
{
	MGPIO_voidSetPinValue(Ledobj->LED_PORT , Ledobj->LED_PIN , LOW);
}

void HLED_voidToggle(LED_t* Ledobj)
{
	MGPIO_voidTogPinValue(Ledobj->LED_PORT , Ledobj->LED_PIN);
}