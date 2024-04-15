/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        19 SEP, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 APP
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         19 SEP, 2023      Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/RCC/RCC_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

#include "../../HAL/HBRIDGE/HBRIDGE_interface.h"

#include "L293D.h"


void L293D_voidInit(L293D_t* L293Dobj)
{
    HHBRIDGE_voidInit(& (L293Dobj->HBRIDGE1));
    HHBRIDGE_voidInit(& (L293Dobj->HBRIDGE2));

    MRCC_voidEnablePeripheralClock(RCC_AHB1, L293Dobj->L293D_EN1_PORT);
    MRCC_voidEnablePeripheralClock(RCC_AHB1, L293Dobj->L293D_EN2_PORT);

    MGPIO_voidSetPinMode(L293Dobj->L293D_EN1_PORT, L293Dobj->L293D_EN1_PIN, OUTPUT_MODE);
	MGPIO_voidSetOutputType(L293Dobj->L293D_EN1_PORT, L293Dobj->L293D_EN1_PIN, PUSH_PULL);
	MGPIO_voidSetOutputSpeed(L293Dobj->L293D_EN1_PORT, L293Dobj->L293D_EN1_PIN, LOW_SPEED_2MHZ);

    MGPIO_voidSetPinMode(L293Dobj->L293D_EN2_PORT, L293Dobj->L293D_EN2_PIN, OUTPUT_MODE);
	MGPIO_voidSetOutputType(L293Dobj->L293D_EN2_PORT, L293Dobj->L293D_EN2_PIN, PUSH_PULL);
	MGPIO_voidSetOutputSpeed(L293Dobj->L293D_EN2_PORT, L293Dobj->L293D_EN2_PIN, LOW_SPEED_2MHZ);
}

void L293D_voidMoveForward(L293D_t* L293Dobj)
{
    MGPIO_voidSetPinValue(L293Dobj->L293D_EN1_PORT, L293Dobj->L293D_EN1_PIN, HIGH);
    MGPIO_voidSetPinValue(L293Dobj->L293D_EN2_PORT, L293Dobj->L293D_EN2_PIN, HIGH);

    HHBRIDGE_voidForward(& (L293Dobj->HBRIDGE1));
    HHBRIDGE_voidForward(& (L293Dobj->HBRIDGE2));
}

void L293D_voidMoveBackward(L293D_t* L293Dobj)
{
    MGPIO_voidSetPinValue(L293Dobj->L293D_EN1_PORT, L293Dobj->L293D_EN1_PIN, HIGH);
    MGPIO_voidSetPinValue(L293Dobj->L293D_EN2_PORT, L293Dobj->L293D_EN2_PIN, HIGH);

    HHBRIDGE_voidBackward(& (L293Dobj->HBRIDGE1));
    HHBRIDGE_voidBackward(& (L293Dobj->HBRIDGE2));
}

void L293D_voidMoveStop(L293D_t* L293Dobj)
{
    MGPIO_voidSetPinValue(L293Dobj->L293D_EN1_PORT, L293Dobj->L293D_EN1_PIN, LOW);
    MGPIO_voidSetPinValue(L293Dobj->L293D_EN2_PORT, L293Dobj->L293D_EN2_PIN, LOW);

    HHBRIDGE_voidStop(& (L293Dobj->HBRIDGE1));
    HHBRIDGE_voidStop(& (L293Dobj->HBRIDGE2));
}

void L293D_voidMoveRight(L293D_t* L293Dobj)
{
    MGPIO_voidSetPinValue(L293Dobj->L293D_EN1_PORT, L293Dobj->L293D_EN1_PIN, HIGH);
    MGPIO_voidSetPinValue(L293Dobj->L293D_EN2_PORT, L293Dobj->L293D_EN2_PIN, HIGH);

    HHBRIDGE_voidBackward(& (L293Dobj->HBRIDGE1));
    HHBRIDGE_voidForward(& (L293Dobj->HBRIDGE2));
}

void L293D_voidMoveLeft(L293D_t* L293Dobj)
{
    MGPIO_voidSetPinValue(L293Dobj->L293D_EN1_PORT, L293Dobj->L293D_EN1_PIN, HIGH);
    MGPIO_voidSetPinValue(L293Dobj->L293D_EN2_PORT, L293Dobj->L293D_EN2_PIN, HIGH);

    HHBRIDGE_voidForward(& (L293Dobj->HBRIDGE1));
    HHBRIDGE_voidBackward(& (L293Dobj->HBRIDGE2));
}